<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Web\OperationsLog\Controllers;

use Domain\OperationsLog\Entities\LogEntry;
use Domain\OperationsLog\UseCases\Add\Response;

use Web\OperationsLog\Views\Add;
use Web\Controller;
use Web\View;

class AddController extends Controller
{
    public function __invoke(array $params): View
    {
        if (!empty($_POST['logtime'])) {
            $add   = $this->di->get('Domain\OperationsLog\UseCases\Add\Command');
            $entry = new LogEntry($_POST);
            $res   = $add($entry);
            if (!$res->errors) {
                $date  = $res->logtime->format('Y-m-d');
                $url   = View::generateUrl('operationsLog.index')."?date=$date";
                header("Location: $url");
                exit();
            }
        }
        return new Add($entry ?? new LogEntry(),
                       $res   ?? new Response(),
                       $this->di->get('Domain\OperationsLog\Metadata'));
    }
}
