<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 * @param array $this->entries  An array of LogEntry objects
 */
declare (strict_types=1);
?>
<table id="logtable">
    <colgroup span="1" class="time" />
    <colgroup span="3" class="weather" />
    <colgroup span="4" class="turbidity" />
    <colgroup span="12" class="chlorine" />
    <colgroup span="6" class="ph" />
    <colgroup span="6" class="temperature" />
    <colgroup span="1" class="fluoride" />
    <colgroup span="2" class="hardness" />
    <colgroup span="2" class="alkalinity" />
    <colgroup span="2" class="odor" />
    <colgroup span="2" class="chloride" />
    <colgroup span="1" class="stability" />
    <colgroup span="3" class="uv254" />
    <colgroup span="1" class="benchNTU" />
    <colgroup snap="2" class="flow" />
    <colgroup span="1" class="logRemoval" />
    <colgroup span="2" class="toc" />
    <colgroup span="1" class="comments" />

    <thead>
        <tr><th rowspan= "3" scope="col" class="time">Time</th>
            <th colspan= "3" scope="colgroup">Weather</th>
            <th colspan= "4" scope="colgroup">Turbidity</th>
            <th colspan="12" scope="colgroup">Chlorine</th>
            <th colspan= "6" scope="colgroup">pH</th>
            <th colspan= "6" scope="colgroup">Temperature</th>
            <th              scope="col"     >Fluoride</th>
            <th colspan= "2" scope="colgroup">Hardness</th>
            <th colspan= "2" scope="colgroup">Alkalinity</th>
            <th colspan= "2" scope="colgroup">Odor</th>
            <th colspan= "2" scope="colgroup">Chloride</th>
            <th rowspan= "3" scope="col"     >Stability</th>
            <th colspan= "3" scope="colgroup">UV 254</th>
            <th rowspan= "3" scope="col"     >Bench NTU</th>
            <th colspan= "2" scope="colgroup">Flow</th>
            <th rowspan= "3" scope="col"     >Log Removal</th>
            <th colspan= "2" scope="colgroup">Total Organic Carbon</th>
            <th rowspan= "3" scope="col"     >Comments</th>
        </tr>
        <tr class="subheadings">
            <!-- Weather -->
            <th rowspan="2">Temperature</th>
            <th rowspan="2">Conditions</th>
            <th rowspan="2">Precipitation</th>

            <!-- Turbidity -->
            <th rowspan="2">Raw</th>
            <th rowspan="2">Basin</th>
            <th rowspan="2">Filter</th>
            <th rowspan="2">Finish</th>

            <!-- Chlorine -->
            <th colspan="2">Basin</th>
            <th colspan="2">Pre Filter</th>
            <th colspan="2">Filter</th>
            <th colspan="2">B Filter</th>
            <th colspan="2">Clrwll</th>
            <th colspan="2">Finish</th>

            <!-- pH -->
            <th rowspan="2">Raw</th>
            <th rowspan="2">Basin</th>
            <th rowspan="2">Filter</th>
            <th rowspan="2">B Filter</th>
            <th rowspan="2">Clrwll</th>
            <th rowspan="2">Finish</th>

            <!-- Temperature -->
            <th rowspan="2">Raw</th>
            <th rowspan="2">Basin</th>
            <th rowspan="2">Filter</th>
            <th rowspan="2">B Filter</th>
            <th rowspan="2">Clrwll</th>
            <th rowspan="2">Finish</th>

            <!-- Fluoride -->
            <th rowspan="2">Finish</th>

            <!-- Hardness -->
            <th rowspan="2">Raw</th>
            <th rowspan="2">Finish</th>
            <!-- Alkalinity -->
            <th rowspan="2">Raw</th>
            <th rowspan="2">Finish</th>
            <!-- Odor -->
            <th rowspan="2">Raw</th>
            <th rowspan="2">Finish</th>
            <!-- Chloride -->
            <th rowspan="2">Raw</th>
            <th rowspan="2">Finish</th>

            <!-- UV 254 -->
            <th rowspan="2">Raw</th>
            <th rowspan="2">Box</th>
            <th rowspan="2">Finish</th>

            <!-- Flow -->
            <th rowspan="2">Basin</th>
            <th rowspan="2">Finish</th>
            <!-- TOC -->
            <th rowspan="2">Raw</th>
            <th rowspan="2">Finish</th>
        </tr>
        <tr>
            <!-- Chlorine -->
            <th>Free</th>
            <th>Total</th>
            <th>Free</th>
            <th>Total</th>
            <th>Free</th>
            <th>Total</th>
            <th>Free</th>
            <th>Total</th>
            <th>Free</th>
            <th>Total</th>
            <th>Free</th>
            <th>Total</th>
        </tr>
    </thead>
    <tbody>
    <?php
        foreach ($this->entries as $r) {
            echo "
            <tr><th>{$r->logtime->format('g a')}</th>
                <td>{$r->weather_temperature   }</td>
                <td>{$r->weather_conditions    }</td>
                <td>{$r->weather_precipitation }</td>
                <td>{$r->turbidity_raw         }</td>
                <td>{$r->turbidity_basin       }</td>
                <td>{$r->turbidity_filter      }</td>
                <td>{$r->turbidity_finish      }</td>
                <td>{$r->chlorine_basin_free   }</td>
                <td>{$r->chlorine_basin_total  }</td>
                <td>{$r->chlorine_prefilt_free }</td>
                <td>{$r->chlorine_prefilt_total}</td>
                <td>{$r->chlorine_filter_free  }</td>
                <td>{$r->chlorine_filter_total }</td>
                <td>{$r->chlorine_bfilt_free   }</td>
                <td>{$r->chlorine_bfilt_total  }</td>
                <td>{$r->chlorine_clrwll_free  }</td>
                <td>{$r->chlorine_clrwll_total }</td>
                <td>{$r->chlorine_finish_free  }</td>
                <td>{$r->chlorine_finish_total }</td>
                <td>{$r->ph_raw                }</td>
                <td>{$r->ph_basin              }</td>
                <td>{$r->ph_filter             }</td>
                <td>{$r->ph_bfilt              }</td>
                <td>{$r->ph_clrwll             }</td>
                <td>{$r->ph_finish             }</td>
                <td>{$r->temperature_raw       }</td>
                <td>{$r->temperature_basin     }</td>
                <td>{$r->temperature_filter    }</td>
                <td>{$r->temperature_bfilt     }</td>
                <td>{$r->temperature_clrwll    }</td>
                <td>{$r->temperature_finish    }</td>
                <td>{$r->fluoride_finish       }</td>
                <td>{$r->hardness_raw          }</td>
                <td>{$r->hardness_finish       }</td>
                <td>{$r->alkalinity_raw        }</td>
                <td>{$r->alkalinity_finish     }</td>
                <td>{$r->odor_raw              }</td>
                <td>{$r->odor_finish           }</td>
                <td>{$r->chloride_raw          }</td>
                <td>{$r->chloride_finish       }</td>
                <td>{$r->stability             }</td>
                <td>{$r->uv_254_raw            }</td>
                <td>{$r->uv_254_box            }</td>
                <td>{$r->uv_254_finish         }</td>
                <td>{$r->bench_ntu             }</td>
                <td>{$r->flow_basin            }</td>
                <td>{$r->flow_finish           }</td>
                <td>{$r->log_removal           }</td>
                <td>{$r->toc_raw               }</td>
                <td>{$r->toc_finish            }</td>
                <td>{$r->comments              }</td>
            </tr>
            ";
        }
    ?>
    </tbody>
</table>
