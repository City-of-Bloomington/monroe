<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 * @param LogEntry $this->logEntry
 * @param array    $this->available_logtimes
 * @param array    $this->weather_conditions
 */
declare (strict_types=1);
$h = $this->template->getHelper('field');
?>
<section>
    <form method="post">
        <fieldset>
            <legend>Time</legend>
            <?php
                echo $h->field([
                    'name'     => 'logtime',
                    'id'       => 'logtime',
                    'label'    => 'Log Time',
                    'type'     => 'select',
                    'value'    => $this->logEntry->logtime,
                    'required' => true
                ]);
            ?>
        </fieldset>
        <?php
            $this->_include('operations/partials/entryFields.inc');
        ?>
        <fieldset><legend>Submit</legend>
        <?php
            $h = $this->template->getHelper('saveAndCancelButtons');
            echo $h->saveAndCancelButtons(parent::generateUri('operationsLog.index'));
        ?>
        </fieldset>
    </form>
</section>
