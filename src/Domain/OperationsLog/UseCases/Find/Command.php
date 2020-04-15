<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Domain\OperationsLog\UseCases\Find;

use Domain\OperationsLog\DataStorage\OperationsLogRepository;

class Command
{
    private $repo;

    public function __construct(OperationsLogRepository $repository)
    {
        $this->repo = $repository;
    }

    public function __invoke(Request $req): Response
    {
        try {
            $result = $this->repo->find($req);
            return new Response($result['rows'], $result['total']);
        }
        catch (\Exception $e) {
            return new Response(null, null, [$e->getMessage()]);
        }
    }
}
