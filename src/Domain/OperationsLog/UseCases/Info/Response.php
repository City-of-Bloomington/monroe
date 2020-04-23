<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Domain\OperationsLog\UseCases\Info;
use Domain\OperationsLog\Entities\LogEntry;

class Response
{
    public $logEntry;
    public $errors = [];

    public function __construct(?LogEntry $logEntry=null, ?array $errors=null)
    {
        $this->logEntry = $logEntry;
        $this->errors   = $errors;
    }
}
