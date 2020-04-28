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

$day       = new \DateInterval('P1D');
$yesterday = clone($this->date); $yesterday->sub($day);
$tomorrow  = clone($this->date);  $tomorrow->add($day);
$uri       = parent::generateUri('operationsLog.index');
$back      = "$uri?date=".$yesterday->format('Y-m-d');
$next      = "$uri?date=". $tomorrow->format('Y-m-d');

$date = $this->date->format('F j, Y');

?>
<section id="findForm">
    <header>
        <h1><?= $date; ?></h1>
        <form method="get">
            <fieldset>
                <a href="<?= $back; ?>" class="back">Back</a>
                <?php
                    $h = $this->template->getHelper('field');
                    echo $h->field([
                        'name'  => 'date',
                        'id'    => 'date',
                        'type'  => 'date',
                        'value' => $this->date
                    ]);
                ?>
                <button type="submit">Go</button>
                <a href="<?= $next; ?>" class="next">Next</a>
                <a href="<?= $uri;  ?>">Today</a>
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
