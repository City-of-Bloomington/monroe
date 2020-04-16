<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Web\OperationsLog\Views;

use Domain\OperationsLog\UseCases\Find\Request;
use Domain\OperationsLog\UseCases\Find\Response;

use Web\Block;
use Web\Template;
use Web\Paginator;

class Search extends Template
{
    public function __construct(Request  $request, Response $response)
    {
        $format = !empty($_REQUEST['format']) ? $_REQUEST['format'] : 'html';
        parent::__construct('default', $format);

        if ($response->errors) {
            $_SESSION['errorMessages'] = $response->errors;
        }

        $vars = [
            'entries'      => $response->entries,
            'total'        => $response->total,
            'itemsPerPage' => $request ->itemsPerPage,
            'currentPage'  => $request ->currentPage,
            'date'         => $request ->date
        ];

        $this->blocks = [
            new Block('operations/findForm.inc', $vars)
        ];
    }
}
