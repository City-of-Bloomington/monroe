<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Web\OperationsLog\Controllers;

use Domain\OperationsLog\Entities\LogEntry;
use Domain\OperationsLog\UseCases\Update\Response;

use Web\OperationsLog\Views\Update;
use Web\Controller;
use Web\View;

class UpdateController extends Controller
{
    public function __invoke(array $params): View
    {
        $id = !empty($_REQUEST['id']) ? (int)$_REQUEST['id'] : null;
        if (!$id) {
            return new \Web\Views\NotFoundView();
        }

        if (!empty($_POST['id'])) {
            $update = $this->di->get('Domain\OperationsLog\UseCases\Update\Command');
            $entry  = new LogEntry($_POST);
            $res    = $update($entry);
            if (!$res->errors) {
                $url   = View::generateUrl('operationsLog.view', ['id'=>$id]);
                header("Location: $url");
                exit();
            }
        }

        if (!isset($entry)) {
            $load = $this->di->get('Domain\OperationsLog\UseCases\Info\Command');
            $ir   = $load($id);
            if ($ir->errors) {
                return new \Web\Views\NotFoundView();
            }
            $entry = $ir->logEntry;
        }

        return new Update($entry ?? new LogEntry(),
                          $res   ?? new Response());
    }
}
