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
$h = $this->template->getHelper('field');
?>
<section>
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
</section>
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
