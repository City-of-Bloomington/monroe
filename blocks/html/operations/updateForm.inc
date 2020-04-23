<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 * @param LogEntry $this->logEntry
 * @param array    $this->weather_conditions
 */
declare (strict_types=1);
?>
<section>
    <form method="post">
        <fieldset>
            <legend>Time</legend>
            <input name="id" type="hidden" value="<?= $this->logEntry->id; ?>" />
            <?php
                $h       = $this->template->getHelper('field');
                echo $h->field([
                    'name'     => 'logtime',
                    'id'       => 'logtime',
                    'label'    => 'Log Time',
                    'type'     => 'datetime-local',
                    'attr'     => ['step' => 3600],
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
            echo $h->saveAndCancelButtons(parent::generateUri('operationsLog.view', ['id'=>$this->logEntry->id]));
        ?>
        </fieldset>
    </form>
</section>
