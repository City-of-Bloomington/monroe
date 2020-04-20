<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Web\OperationsLog\Views;

use Domain\OperationsLog\Entities\LogEntry;
use Domain\OperationsLog\Metadata;
use Domain\OperationsLog\UseCases\Add\Response;

use Web\Block;
use Web\Template;

class Add extends Template
{
    public function __construct(LogEntry $entry, Response $response, Metadata $metadata)
    {
        parent::__construct('default', 'html');

        if ($response->errors) {
            $_SESSION['errorMessages'] = $response->errors;
        }

        $vars = [
            'logEntry'           => $entry,
            'weather_conditions' => Metadata::weather_conditions(),
            'available_logtimes' => $metadata->availableLogTimes()
        ];

        $this->blocks = [
            new Block('operations/addForm.inc', $vars)
        ];
    }
}
