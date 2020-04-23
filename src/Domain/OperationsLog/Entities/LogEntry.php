<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);

namespace Domain\OperationsLog\Entities;

class LogEntry
{
    public $id;
    public $logtime;

    public $weather_temperature;
    public $weather_conditions;
    public $weather_precipitation;

    public $turbidity_raw;
    public $turbidity_basin;
    public $turbidity_filter;
    public $turbidity_finish;

    public $chlorine_basin_free;
    public $chlorine_basin_total;
    public $chlorine_prefilt_free;
    public $chlorine_prefilt_total;
    public $chlorine_filter_free;
    public $chlorine_filter_total;
    public $chlorine_bfilt_free;
    public $chlorine_bfilt_total;
    public $chlorine_clrwll_free;
    public $chlorine_clrwll_total;
    public $chlorine_finish_free;
    public $chlorine_finish_total;

    public $ph_raw;
    public $ph_basin;
    public $ph_filter;
    public $ph_bfilt;
    public $ph_clrwll;
    public $ph_finish;

    public $temperature_raw;
    public $temperature_basin;
    public $temperature_filter;
    public $temperature_bfilt;
    public $temperature_clrwll;
    public $temperature_finish;

    public $fluoride_finish;
    public $hardness_raw;
    public $hardness_finish;
    public $alkalinity_raw;
    public $alkalinity_finish;
    public $odor_raw;
    public $odor_finish;
    public $chloride_raw;
    public $chloride_finish;

    public $stability;
    public $uv_254_raw;
    public $uv_254_box;
    public $uv_254_finish;
    public $bench_ntu;

    public $flow_basin;
    public $flow_finish;
    public $log_removal;
    public $toc_raw;
    public $toc_finish;

    public $comments;

    public function __construct(?array $data=null)
    {
        if ($data) {
            foreach ($this as $k => $v) {
                switch ($k) {
                    case 'logtime':
                        $this->$k = new \DateTime($data[$k]);
                    break;

                    case 'weather_precipitation':
                    case 'turbidity_raw':
                    case 'turbidity_basin':
                    case 'turbidity_filter':
                    case 'turbidity_finish':
                    case 'chlorine_basin_free':
                    case 'chlorine_basin_total':
                    case 'chlorine_prelift_free':
                    case 'chlorine_prelift_total':
                    case 'chlorine_filter_free':
                    case 'chlorine_filter_total':
                    case 'chlorine_bfilt_free':
                    case 'chlorine_bfilt_total':
                    case 'chlorine_clrwll_free':
                    case 'chlorine_clrwll_total':
                    case 'chlorine_finish_free':
                    case 'chlorine_finish_total':
                    case 'ph_raw':
                    case 'ph_basin':
                    case 'ph_filter':
                    case 'ph_bfilt':
                    case 'ph_clrwll':
                    case 'ph_finish':
                    case 'fluoride_finish':
                    case 'odor_raw':
                    case 'odor_finish':
                    case 'chloride_raw':
                    case 'chloride_finish':
                    case 'stability':
                    case 'uv_254_raw':
                    case 'uv_254_box':
                    case 'uv_254_finish':
                    case 'bench_ntu':
                    case 'log_removal':
                    case 'toc_raw':
                    case 'toc_finish':
                        if ($data[$k] != '') {
                            $this->$k = (float)$data[$k];
                        }
                    break;

                    case 'weather_temperature':
                    case 'temperature_raw':
                    case 'temperature_basin':
                    case 'temperature_filter':
                    case 'temperature_bfilt':
                    case 'temperature_clrwll':
                    case 'temperature_finish':
                    case 'hardness_raw':
                    case 'hardness_finish':
                    case 'alkalinity_raw':
                    case 'alkalinity_finish':
                    case 'flow_basin':
                    case 'flow_finish':
                        if ($data[$k] != '') {
                            $this->$k = (int)$data[$k];
                        }
                    break;

                    default:
                        $this->$k = $data[$k];
                }
            }
        }
    }
}
