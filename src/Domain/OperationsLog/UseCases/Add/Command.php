<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Domain\OperationsLog\UseCases\Add;

use Domain\OperationsLog\Entities\LogEntry;
use Domain\OperationsLog\DataStorage\OperationsLogRepository;

class Command
{
    private $repo;

    public function __construct(OperationsLogRepository $repository)
    {
        $this->repo = $repository;
    }

    public function __invoke(LogEntry $entry): Response
    {
        $errors = $this->validate($entry);

        try {
            $id  = $this->repo->save($entry);
            $new = $this->repo->loadById($id);
            return new Response($id, $new->logtime);
        }
        catch (\Exception $e) {
            return new Response(null, null, [$e->getMessage()]);
        }
    }

    private function validate(LogEntry $entry): array
    {
        $errors = [];
        if (!$entry->logtime) { $errors[] = 'missingTime'; }

        try {
            $duplicate = $this->repo->loadByLogTime($entry->logtime);
            if ($duplicate) {
                $errors[] = 'operations/duplicate';
            }
        }
        catch (\Exception $e) { }

        return $errors;
    }
}
