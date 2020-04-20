<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 * @param LogEntry $this->logEntry
 * @param array    $this->available_logtimes
 * @param array    $this->weather_conditions
 */
declare (strict_types=1);
$h     = $this->template->getHelper('field');
$entry = $this->logEntry;
?>
<section>
    <form method="post">
        <fieldset>
            <legend>Weather</legend>
            <?php
                $options = [['value'=>'']];
                foreach ($this->available_logtimes as $c) { $options[] = ['value' => $c->format('Y-m-d H:00:00'), 'label'=>$c->format('n/j/y ga')]; }
                echo $h->field([
                    'name'     => 'logtime',
                    'id'       => 'logtime',
                    'label'    => 'Log Time',
                    'type'     => 'select',
                    'options'  => $options,
                    'value'    => $entry->logtime,
                    'required' => true
                ]);

                echo $h->field([
                    'name'    => 'weather_temperature',
                    'id'      => 'weather_temperature',
                    'label'   => 'Temerature',
                    'type'    => 'number',
                    'value'   => $entry->weather_temperature,
                    'attr'    => ['step' => 1]
                ]);

                $options = [['value'=>'']];
                foreach ($this->weather_conditions as $c) { $options[] = ['value' => $c]; }
                echo $h->field([
                    'name'    => 'weather_conditions',
                    'id'      => 'weather_conditions',
                    'label'   => 'Conditions',
                    'type'    => 'select',
                    'options' => $options,
                    'value'   => $entry->weather_conditions
                ]);

                echo $h->field([
                    'name'    => 'weather_precipitation',
                    'id'      => 'weather_precipitation',
                    'label'   => 'Precipitation',
                    'type'    => 'number',
                    'value'   => $entry->weather_precipitation,
                    'attr'    => ['step' => .1]
                ]);
            ?>
        </fieldset>
        <fieldset>
            <legend>Turbidity</legend>
            <?php
                echo $h->field([
                    'name'    => 'turbidity_raw',
                    'id'      => 'turbidity_raw',
                    'label'   => 'Raw',
                    'type'    => 'number',
                    'value'   => $entry->turbidity_raw,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'turbidity_basin',
                    'id'      => 'turbidity_basin',
                    'label'   => 'Basin',
                    'type'    => 'number',
                    'value'   => $entry->turbidity_basin,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'turbidity_filter',
                    'id'      => 'turbidity_filter',
                    'label'   => 'Filter',
                    'type'    => 'number',
                    'value'   => $entry->turbidity_filter,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'turbidity_finish',
                    'id'      => 'turbidity_finish',
                    'label'   => 'Finish',
                    'type'    => 'number',
                    'value'   => $entry->turbidity_finish,
                    'attr'    => ['step' => .1]
                ]);
            ?>
        </fieldset>
        <fieldset>
            <legend>Chlorine</legend>
            <?php
                echo $h->field([
                    'name'    => 'chlorine_basin_free',
                    'id'      => 'chlorine_basin_free',
                    'label'   => 'Basin Free',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_basin_free,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chlorine_basin_total',
                    'id'      => 'chlorine_basin_total',
                    'label'   => 'Basin Total',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_basin_total,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chlorine_prelift_free',
                    'id'      => 'chlorine_prelift_free',
                    'label'   => 'Prelift Free',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_prelift_free,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chlorine_prelift_total',
                    'id'      => 'chlorine_prelift_total',
                    'label'   => 'Prelift Total',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_prelift_total,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chlorine_filter_free',
                    'id'      => 'chlorine_filter_free',
                    'label'   => 'Filter Free',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_filter_free,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chlorine_filter_total',
                    'id'      => 'chlorine_filter_total',
                    'label'   => 'Filter Total',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_filter_total,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chlorine_bfilt_free',
                    'id'      => 'chlorine_bfilt_free',
                    'label'   => 'BFilt Free',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_bfilt_free,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chlorine_bfilt_total',
                    'id'      => 'chlorine_bfilt_total',
                    'label'   => 'BFilt Total',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_bfilt_total,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chlorine_clrwll_free',
                    'id'      => 'chlorine_clrwll_free',
                    'label'   => 'clrwll Free',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_clrwll_free,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chlorine_clrwll_total',
                    'id'      => 'chlorine_clrwll_total',
                    'label'   => 'clrwll Total',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_clrwll_total,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chlorine_finish_free',
                    'id'      => 'chlorine_finish_free',
                    'label'   => 'Finish Free',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_finish_free,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chlorine_finish_total',
                    'id'      => 'chlorine_finish_total',
                    'label'   => 'Finish Total',
                    'type'    => 'number',
                    'value'   => $entry->chlorine_finish_total,
                    'attr'    => ['step' => .1]
                ]);
            ?>
        </fieldset>
        <fieldset>
            <legend>pH</legend>
            <?php
                echo $h->field([
                    'name'    => 'ph_raw',
                    'id'      => 'ph_raw',
                    'label'   => 'pH Raw',
                    'type'    => 'number',
                    'value'   => $entry->ph_raw,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'ph_basin',
                    'id'      => 'ph_basin',
                    'label'   => 'pH Basin',
                    'type'    => 'number',
                    'value'   => $entry->ph_basin,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'ph_filter',
                    'id'      => 'ph_filter',
                    'label'   => 'pH Filter',
                    'type'    => 'number',
                    'value'   => $entry->ph_filter,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'ph_bfilt',
                    'id'      => 'ph_bfilt',
                    'label'   => 'pH BFilt',
                    'type'    => 'number',
                    'value'   => $entry->ph_bfilt,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'ph_clrwll',
                    'id'      => 'ph_clrwll',
                    'label'   => 'pH clrwll',
                    'type'    => 'number',
                    'value'   => $entry->ph_clrwll,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'ph_finish',
                    'id'      => 'ph_finish',
                    'label'   => 'pH Finish',
                    'type'    => 'number',
                    'value'   => $entry->ph_finish,
                    'attr'    => ['step' => .1]
                ]);
            ?>
        </fieldset>
        <fieldset>
            <legend>Temperature</legend>
            <?php
                echo $h->field([
                    'name'    => 'temperature_raw',
                    'id'      => 'temperature_raw',
                    'label'   => 'Raw',
                    'type'    => 'number',
                    'value'   => $entry->temperature_raw,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'temperature_basin',
                    'id'      => 'temperature_basin',
                    'label'   => 'Basin',
                    'type'    => 'number',
                    'value'   => $entry->temperature_basin,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'temperature_filter',
                    'id'      => 'temperature_filter',
                    'label'   => 'Filter',
                    'type'    => 'number',
                    'value'   => $entry->temperature_filter,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'temperature_bfilt',
                    'id'      => 'temperature_bfilt',
                    'label'   => 'BFilt',
                    'type'    => 'number',
                    'value'   => $entry->temperature_bfilt,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'temperature_clrwll',
                    'id'      => 'temperature_clrwll',
                    'label'   => 'clrwll',
                    'type'    => 'number',
                    'value'   => $entry->temperature_clrwll,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'temperature_finish',
                    'id'      => 'temperature_finish',
                    'label'   => 'Finish',
                    'type'    => 'number',
                    'value'   => $entry->temperature_finish,
                    'attr'    => ['step' => .1]
                ]);
            ?>
        </fieldset>
        <fieldset>
            <legend>Fluoride</legend>
            <?php
                echo $h->field([
                    'name'    => 'fluoride_finish',
                    'id'      => 'fluoride_finish',
                    'label'   => 'Finish',
                    'type'    => 'number',
                    'value'   => $entry->fluoride_finish,
                    'attr'    => ['step' => .1]
                ]);
            ?>
        </fieldset>
        <fieldset>
            <legend>Hardness</legend>
            <?php
                echo $h->field([
                    'name'    => 'hardness_raw',
                    'id'      => 'hardness_raw',
                    'label'   => 'Raw',
                    'type'    => 'number',
                    'value'   => $entry->hardness_raw,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'hardness_finish',
                    'id'      => 'hardness_finish',
                    'label'   => 'Finish',
                    'type'    => 'number',
                    'value'   => $entry->hardness_finish,
                    'attr'    => ['step' => .1]
                ]);
            ?>
        </fieldset>
        <fieldset>
            <legend>Alkalinity</legend>
            <?php
                echo $h->field([
                    'name'    => 'alkalinity_raw',
                    'id'      => 'alkalinity_raw',
                    'label'   => 'Raw',
                    'type'    => 'number',
                    'value'   => $entry->alkalinity_raw,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'alkalinity_finish',
                    'id'      => 'alkalinity_finish',
                    'label'   => 'Finish',
                    'type'    => 'number',
                    'value'   => $entry->alkalinity_finish,
                    'attr'    => ['step' => .1]
                ]);
            ?>
        </fieldset>
        <fieldset>
            <legend>Odor</legend>
            <?php
                echo $h->field([
                    'name'    => 'odor_raw',
                    'id'      => 'odor_raw',
                    'label'   => 'Raw',
                    'type'    => 'number',
                    'value'   => $entry->odor_raw,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'odor_finish',
                    'id'      => 'odor_finish',
                    'label'   => 'Finish',
                    'type'    => 'number',
                    'value'   => $entry->odor_finish,
                    'attr'    => ['step' => .1]
                ]);
            ?>
        </fieldset>
        <fieldset>
            <legend>Chloride</legend>
            <?php
                echo $h->field([
                    'name'    => 'chloride_raw',
                    'id'      => 'chloride_raw',
                    'label'   => 'Raw',
                    'type'    => 'number',
                    'value'   => $entry->chloride_raw,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'chloride_finish',
                    'id'      => 'chloride_finish',
                    'label'   => 'Finish',
                    'type'    => 'number',
                    'value'   => $entry->chloride_finish,
                    'attr'    => ['step' => .1]
                ]);
            ?>
        </fieldset>
        <fieldset>
            <legend>UV 254</legend>
            <?php
                echo $h->field([
                    'name'    => 'stability',
                    'id'      => 'stability',
                    'label'   => 'Stability',
                    'type'    => 'number',
                    'value'   => $entry->stability,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'uv_254_raw',
                    'id'      => 'uv_254_raw',
                    'label'   => 'Raw',
                    'type'    => 'number',
                    'value'   => $entry->uv_254_raw,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'uv_254_box',
                    'id'      => 'uv_254_box',
                    'label'   => 'Box',
                    'type'    => 'number',
                    'value'   => $entry->uv_254_box,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'uv_254_finish',
                    'id'      => 'uv_254_finish',
                    'label'   => 'Finish',
                    'type'    => 'number',
                    'value'   => $entry->uv_254_finish,
                    'attr'    => ['step' => .1]
                ]);
                echo $h->field([
                    'name'    => 'bench_ntu',
                    'id'      => 'bench_ntu',
                    'label'   => 'Bench NTU',
                    'type'    => 'number',
                    'value'   => $entry->bench_ntu,
                    'attr'    => ['step' => .1]
                ]);
            ?>
        </fieldset>
        <fieldset>
            <legend>Comments</legend>
            <textarea name="comments" id="comments"></textarea>
            <div>
            <?php
                $h = $this->template->getHelper('saveAndCancelButtons');
                echo $h->saveAndCancelButtons(parent::generateUri('operationsLog.index'));
            ?>
            </div>
        </fieldset>
    </form>
</section>
