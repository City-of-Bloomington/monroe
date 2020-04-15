<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 * @param array  $this->entries
 * @param int    $this->total
 * @param int    $this->itemsPerPage
 * @param int    $this->currentPage
 */
declare (strict_types=1);

$this->_include('operations/entries.inc');

if ($this->total > $this->itemsPerPage) {
    $block = new Block('pageNavigation.inc', [
        'paginator' => new Paginator(
            $this->total,
            $this->itemsPerPage,
            $this->currentPage
    )]);
    echo $block->render('html', $this->template);
}
