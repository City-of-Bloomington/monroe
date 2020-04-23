<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);

namespace Web\OperationsLog\Controllers;

use Web\OperationsLog\Views\Info;
use Web\Controller;
use Web\View;

class ViewController extends Controller
{
    public function __invoke(array $params): View
    {
        if (!empty($_REQUEST['id'])) {
            $info = $this->di->get('Domain\OperationsLog\UseCases\Info\Command');
            $res  = $info((int)$_REQUEST['id']);
            if ($res->logEntry) {
                return new Info($res);
            }
            else {
                $_SESSION['errorMessages'] = $res->errors;
            }
        }
        return new \Web\Views\NotFoundView();
    }
}
