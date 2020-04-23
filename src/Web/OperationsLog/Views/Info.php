<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Web\OperationsLog\Views;

use Domain\OperationsLog\UseCases\Info\Response;
use Web\Block;
use Web\Template;

class Info extends Template
{
    public function __construct(Response $res)
    {
        $format = !empty($_REQUEST['format']) ? $_REQUEST['format'] : 'html';
        parent::__construct('default', $format);

        $vars = [
            'logEntry' => $res->logEntry
        ];
        $this->blocks = [
            new Block('operations/info.inc', $vars)
        ];
    }
}
