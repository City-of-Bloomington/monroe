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

    //---------------------------------------------------------------
    // Read Functions
    //---------------------------------------------------------------
    public function load(int $id): LogEntry
    {
        $select = $this->baseSelect()->where('id=?', $id);
        $result = $this->performSelect($select);
        if (count($result['rows'])) {
            return self::hydrate($result['rows'][0]);
        }
        throw new \Exception('operationsLog/unknown');
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

    //---------------------------------------------------------------
    // Write Functions
    //---------------------------------------------------------------
    public function save(LogEntry $logEntry): int
    {
        $data            = (array)$logEntry;
        $data['logtime'] = $logEntry->logtime->format('Y-m-d H:00:00');
        return parent::saveToTable($data, self::TABLE);
    }

    //---------------------------------------------------------------
    // Metadata Functions
    //---------------------------------------------------------------
    public function maxLogTime(): ?\DateTime
    {
        $sql    = 'select max(logtime) as logtime from operations';
        $query  = $this->pdo->query($sql);
        $result = $query->fetchAll(\PDO::FETCH_ASSOC);
        if ($result) {
            return new \DateTime($result[0]['logtime']);
        }
        return null;
    }
}
