<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Domain\OperationsLog\UseCases\Find;

class Response
{
    public $entries = [];
    public $errors  = [];
    public $total   = 0;

    public function __construct(?array $entries=null, ?int $total=null, ?array $errors=null)
    {
        $this->entries = $entries;
        $this->errors  = $errors;
        $this->total   = $total;
    }
}
