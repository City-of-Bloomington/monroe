<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Web\OperationsLog\Views;

use Domain\OperationsLog\Entities\LogEntry;
use Domain\OperationsLog\Metadata;
use Domain\OperationsLog\UseCases\Update\Response;

use Web\Block;
use Web\Template;

class Update extends Template
{
    public function __construct(LogEntry $entry, Response $response)
    {
        parent::__construct('default', 'html');

        if ($response->errors) {
            $_SESSION['errorMessages'] = $response->errors;
        }

        $vars = [
            'logEntry'           => $entry,
            'weather_conditions' => Metadata::weather_conditions()
        ];

        $this->blocks = [
            new Block('operations/updateForm.inc', $vars)
        ];
    }
}
