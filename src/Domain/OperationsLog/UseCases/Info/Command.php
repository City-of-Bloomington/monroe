<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Domain\OperationsLog\UseCases\Info;

use Domain\OperationsLog\DataStorage\OperationsLogRepository;

class Command
{
    private $repo;

    public function __construct(OperationsLogRepository $repository)
    {
        $this->repo = $repository;
    }

    public function __invoke(int $id): Response
    {
        try {
            return new Response($this->repo->loadById($id));
        }
        catch (\Exception $e) {
            return new Response(null, [$e->getMessage()]);
        }
    }
}
