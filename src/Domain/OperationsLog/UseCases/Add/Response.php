<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Domain\OperationsLog\UseCases\Add;

class Response
{
    public $id;
    public $logtime;
    public $errors;

    public function __construct(?int $id=null, ?\DateTime $logtime=null, ?array $errors=null)
    {
        $this->id      = $id;
        $this->logtime = $logtime;
        $this->errors  = $errors;
    }
}
