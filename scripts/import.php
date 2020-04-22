<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
include '../src/Web/bootstrap.php';
define('DATETIME', 2);


$pdo  = $DI->get('db.default');
$CSV  = fopen('mwtp_MASTER.csv', 'r');
$UTC  = new \DateTimeZone('UTC');
$cols = [
        'logtime'                =>  DATETIME,
        'weather_temperature'    =>  4,
        'weather_conditions'     =>  5,
        'weather_precipitation'  =>  6,
        'turbidity_raw'          =>  7,
        'turbidity_basin'        =>  8,
        'turbidity_filter'       =>  9,
        'turbidity_finish'       => 10,
        'chlorine_basin_free'    => 11,
        'chlorine_basin_total'   => 12,
        'chlorine_prefilt_free'  => 13,
        'chlorine_prefilt_total' => 14,
        'chlorine_filter_free'   => 15,
        'chlorine_filter_total'  => 16,
        'chlorine_bfilt_free'    => 17,
        'chlorine_bfilt_total'   => 18,
        'chlorine_clrwll_free'   => 19,
        'chlorine_clrwll_total'  => 20,
        'chlorine_finish_free'   => 21,
        'chlorine_finish_total'  => 22,
        'ph_raw'                 => 23,
        'ph_basin'               => 24,
        'ph_filter'              => 25,
        'ph_bfilt'               => 26,
        'ph_clrwll'              => 27,
        'ph_finish'              => 28,
        'temperature_raw'        => 29,
        'temperature_basin'      => 30,
        'temperature_filter'     => 31,
        'temperature_bfilt'      => 32,
        'temperature_clrwll'     => 33,
        'temperature_finish'     => 34,
        'fluoride_finish'        => 35,
        'hardness_raw'           => 36,
        'hardness_finish'        => 37,
        'alkalinity_raw'         => 38,
        'alkalinity_finish'      => 39,
        'odor_raw'               => 40,
        'odor_finish'            => 41,
        'chloride_raw'           => 42,
        'chloride_finish'        => 43,
        'stability'              => 44,
        'uv_254_raw'             => 45,
        'uv_254_box'             => 46,
        'uv_254_finish'          => 47,
        'bench_ntu'              => 48,
        'comments'               => 49
];

$columns = implode(',', array_keys($cols));
$binds   = [];
foreach (array_keys($cols) as $k) { $binds[] = ":$k"; }
$binds   = implode(',', $binds);
$sql     = "insert into operations ($columns) values($binds)";
$insert  = $pdo->prepare($sql);


while ($line = fgetcsv($CSV, 1024)) {
    // Skip the header row
    if ($line[DATETIME] == 'DATETIME') { continue; }

    // Reformat the datetime field for mysql
    $line[DATETIME] = \DateTime::createFromFormat('n/j/Y G:i', $line[DATETIME], $UTC)->format('Y-m-d H:i:s');

    foreach ($cols as $field => $i) {
        $params[":$field"] = $line[$i] ? $line[$i] : null;
    }
    $success = $insert->execute($params);
    if (!$success) {
        print_r($insert->errorInfo());
        echo "CSV line ID: $line[0]\n";
        print_r($params);
        exit();
    }
}
