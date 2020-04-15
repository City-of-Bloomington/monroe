<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Web\OperationsLog\Controllers;

use Domain\OperationsLog\UseCases\Find\Request;
use Web\OperationsLog\Views\Search as SearchView;
use Web\Controller;
use Web\View;

class ListController extends Controller
{
    public function __invoke(array $params): View
    {
        if (!empty($_GET['date'])) {
            try { $date = new \DateTime($_GET['date']); }
            catch (\Exception $e) { $_SESSION['errorMessages'][] = $e->getMessage(); }
        }

        $date = $date ?? new \DateTime();

        $find = $this->di->get('Domain\OperationsLog\UseCases\Find\Command');
        $req  = new Request(['date'=>$date]);
        $res  = $find($req);

        return new SearchView($req, $res);
    }
}
