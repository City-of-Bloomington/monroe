<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Web\OperationsLog;

use Aura\SqlQuery\Common\SelectInterface;
use Domain\OperationsLog\DataStorage\OperationsLogRepository;
use Domain\OperationsLog\Entities\LogEntry;
use Domain\OperationsLog\UseCases\Find\Request as FindRequest;
use Web\PdoRepository;

class PdoOperationsLogRepository extends PdoRepository implements OperationsLogRepository
{
    const TABLE = 'operations';
    public static $DEFAULT_SORT = ['logtime'];
    public static function columns(): array
    {
        static $columns;
        if (!$columns) { $columns = array_keys(get_class_vars('Domain\OperationsLog\Entities\LogEntry')); }
        return $columns;
    }

    public static function hydrate(array $row): LogEntry
    {
        return new LogEntry($row);
    }

    private function baseSelect(): SelectInterface
    {
        $select = $this->queryFactory->newSelect();
        $select->cols(self::columns())
               ->from(self::TABLE);
        return $select;
    }

    public function find(FindRequest $req): array
    {
        $select = $this->baseSelect();
        if (!empty($req->date)) {
            $select->where('date(logtime)=?', $req->date->format('Y-m-d'));
        }
        return parent::performHydratedSelect($select,
                                             __CLASS__.'::hydrate',
                                             self::$DEFAULT_SORT,
                                             $req->itemsPerPage,
                                             $req->currentPage);
    }
}
