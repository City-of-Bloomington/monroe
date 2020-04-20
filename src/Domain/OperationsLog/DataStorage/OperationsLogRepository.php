<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Domain\OperationsLog\DataStorage;

use Domain\OperationsLog\Entities\LogEntry;
use Domain\OperationsLog\UseCases\Find\Request as FindRequest;

interface OperationsLogRepository
{
    // Read Functions
    public function find(FindRequest $request): array;
    public function load(int $id): LogEntry;

    // Write Functions
    public function save(LogEntry $logEntry): int;
}
