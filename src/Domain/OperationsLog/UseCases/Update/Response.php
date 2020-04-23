<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Domain\OperationsLog\UseCases\Update;

class Response
{
    public $id;
    public $errors;

    public function __construct(?int $id=null, ?array $errors=null)
    {
        $this->id      = $id;
        $this->errors  = $errors;
    }
}
