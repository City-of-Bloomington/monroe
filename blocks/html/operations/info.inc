<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 * @param LogEntry $this->logEntry
 */
declare (strict_types=1);
?>
<section>
    <header>
        <h1><?= $this->logEntry->logtime->format('F jS, Y'); ?></h1>
    </header>
    <details>
        <summary>Weather</summary>
        <table>
            <tr><th>Temperature  </th><td><?= $this->logEntry->weather_temperature;   ?></td></tr>
            <tr><th>Conditions   </th><td><?= $this->logEntry->weather_conditions;    ?></td></tr>
            <tr><th>Precipitation</th><td><?= $this->logEntry->weather_precipitation; ?></td></tr>
        </table>
    </details>
    <details>
        <summary>Turbidity</summary>
        <table>
            <tr><th>Raw   </th><td><?= $this->logEntry->turbidity_raw;    ?></td></tr>
            <tr><th>Basin </th><td><?= $this->logEntry->turbidity_basin;  ?></td></tr>
            <tr><th>Filter</th><td><?= $this->logEntry->turbidity_filter; ?></td></tr>
            <tr><th>Finish</th><td><?= $this->logEntry->turbidity_finish; ?></td></tr>
        </table>
    </details>
    <details>
        <summary>Chlorine</summary>
        <table>
            <thead>
                <tr><th></th>
                    <th>Free</th>
                    <th>Total</th>
                </tr>
            </thead>
            <tbody>
                <tr><th>Basin</th>
                    <td><?= $this->logEntry->chlorine_basin_free;  ?></td>
                    <td><?= $this->logEntry->chlorine_basin_total; ?></td>
                </tr>
                <tr><th>Pre Filter</th>
                    <td><?= $this->logEntry->chlorine_prefilt_free;  ?></td>
                    <td><?= $this->logEntry->chlorine_prefilt_total; ?></td>
                </tr>
                <tr><th>Filter</th>
                    <td><?= $this->logEntry->chlorine_filter_free;  ?></td>
                    <td><?= $this->logEntry->chlorine_filter_total; ?></td>
                </tr>
                <tr><th>BFilt</th>
                    <td><?= $this->logEntry->chlorine_bfilt_free;  ?></td>
                    <td><?= $this->logEntry->chlorine_bfilt_total; ?></td>
                </tr>
                <tr><th>Clear Well</th>
                    <td><?= $this->logEntry->chlorine_clrwll_free;  ?></td>
                    <td><?= $this->logEntry->chlorine_clrwll_total; ?></td>
                </tr>
                <tr><th>Finish</th>
                    <td><?= $this->logEntry->chlorine_finish_free;  ?></td>
                    <td><?= $this->logEntry->chlorine_finish_total; ?></td>
                </tr>
            </tbody>
        </table>
    </details>
    <details>
        <summary>pH</summary>
        <table>
            <tr><th>Raw       </th><td><?= $this->logEntry->ph_raw;    ?></td></tr>
            <tr><th>Basin     </th><td><?= $this->logEntry->ph_basin;  ?></td></tr>
            <tr><th>Filter    </th><td><?= $this->logEntry->ph_filter; ?></td></tr>
            <tr><th>bfilt     </th><td><?= $this->logEntry->ph_bfilt;  ?></td></tr>
            <tr><th>Clear Well</th><td><?= $this->logEntry->ph_clrwll; ?></td></tr>
            <tr><th>Finish    </th><td><?= $this->logEntry->ph_finish; ?></td></tr>
        </table>
    </details>
    <details>
        <summary>Temperature</summary>
        <table>
            <tr><th>Raw       </th><td><?= $this->logEntry->temperature_raw;    ?></td></tr>
            <tr><th>Basin     </th><td><?= $this->logEntry->temperature_basin;  ?></td></tr>
            <tr><th>Filter    </th><td><?= $this->logEntry->temperature_filter; ?></td></tr>
            <tr><th>bfilt     </th><td><?= $this->logEntry->temperature_bfilt;  ?></td></tr>
            <tr><th>Clear Well</th><td><?= $this->logEntry->temperature_clrwll; ?></td></tr>
            <tr><th>Finish    </th><td><?= $this->logEntry->temperature_finish; ?></td></tr>
        </table>
    </details>
    <details>
        <summary>Fluoride</summary>
        <table>
            <tr><th>Finish</th><td><?= $this->logEntry->fluoride_finish; ?></td></tr>
        </table>
    </details>
    <details>
        <summary>Hardness</summary>
        <table>
            <tr><th>Raw      </th><td><?= $this->logEntry->hardness_raw;    ?></td></tr>
            <tr><th>Finish   </th><td><?= $this->logEntry->hardness_finish; ?></td></tr>
            <tr><th>Stability</th><td><?= $this->logEntry->stability;       ?></td></tr>
        </table>
    </details>
    <details>
        <summary>Alkalinity</summary>
        <table>
            <tr><th>Raw   </th><td><?= $this->logEntry->alkalinity_raw;    ?></td></tr>
            <tr><th>Finish</th><td><?= $this->logEntry->alkalinity_finish; ?></td></tr>
        </table>
    </details>
    <details>
        <summary>Odor</summary>
        <table>
            <tr><th>Raw   </th><td><?= $this->logEntry->odor_raw;    ?></td></tr>
            <tr><th>Finish</th><td><?= $this->logEntry->odor_finish; ?></td></tr>
        </table>
    </details>
    <details>
        <summary>Chloride</summary>
        <table>
            <tr><th>Raw   </th><td><?= $this->logEntry->chloride_raw;    ?></td></tr>
            <tr><th>Finish</th><td><?= $this->logEntry->chloride_finish; ?></td></tr>
        </table>
    </details>
    <details>
        <summary>UV 254</summary>
        <table>
            <tr><th>Raw      </th><td><?= $this->logEntry->uv_254_raw;    ?></td></tr>
            <tr><th>Box      </th><td><?= $this->logEntry->uv_254_box;    ?></td></tr>
            <tr><th>Finish   </th><td><?= $this->logEntry->uv_254_finish; ?></td></tr>
            <tr><th>Bench NTU</th><td><?= $this->logEntry->bench_ntu;     ?></td></tr>
        </table>
    </details>
    <details>
        <summary>Flow</summary>
        <table>
            <tr><th>Basin </th><td><?= $this->logEntry->flow_basin;  ?></td></tr>
            <tr><th>Finish</th><td><?= $this->logEntry->flow_finish; ?></td></tr>
        </table>
    </details>
    <details>
        <summary>Log Removal</summary>
        <table>
            <tr><th>Log Removal</th><td><?= $this->logEntry->log_removal; ?></td></tr>
        </table>
    </details>
    <details>
        <summary>Total Organic Carbon</summary>
        <table>
            <tr><th>Raw   </th><td><?= $this->logEntry->toc_raw;    ?></td></tr>
            <tr><th>Finish</th><td><?= $this->logEntry->toc_finish; ?></td></tr>
        </table>
    </details>

    <p><?= parent::escape($this->logEntry->comments); ?></p>
</section>
