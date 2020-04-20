<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 * @param array     $this->entries
 * @param int       $this->total
 * @param int       $this->itemsPerPage
 * @param int       $this->currentPage
 * @param DateTime  $this->date
 */
declare (strict_types=1);
use Web\Block;

$h = $this->template->getHelper('field');
?>
<section>
    <header>
        <h1>Operations</h1>
        <form method="get">
            <fieldset>
                <?php
                    echo $h->field([
                        'name'  => 'date',
                        'id'    => 'date',
                        'type'  => 'date',
                        'value' => $this->date
                    ]);
                ?>
                <button type="submit">Submit</button>
            </fieldset>
        </form>
        <?php
            if (parent::isAllowed('operationsLog', 'add')) {
                $block = new Block('toolbox.inc', ['actions' => [
                    'add' => ['uri'   => parent::generateUri('operationsLog.add'),
                              'class' => 'add',
                              'help'  => 'Add a new log entry']
                ]]);
                echo $block->render('html', $this->template);
            }
        ?>
    </header>
    <?php
        if ($this->entries) {
            $this->_include('operations/entries.inc');
        }
        else {
            echo sprintf($this->_('no_results', 'messages'), 'entries');
        }

        if ($this->total > $this->itemsPerPage) {
            $block = new Block('pageNavigation.inc', [
                'paginator' => new Paginator(
                    $this->total,
                    $this->itemsPerPage,
                    $this->currentPage
            )]);
            echo $block->render('html', $this->template);
        }
    ?>
</section>
