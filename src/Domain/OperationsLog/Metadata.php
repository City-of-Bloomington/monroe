<?php
/**
 * @copyright 2020 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Domain\OperationsLog;

use Domain\OperationsLog\DataStorage\OperationsLogRepository;

class Metadata
{
    private $repo;

    public function __construct(OperationsLogRepository $repository)
    {
        $this->repo = $repository;
    }

    public static function weather_conditions()
    {
        return [
            'Clear',
            'Cloudy',
            'Rain',
            'Partly Cloudy',
            'Fog',
            'Drizzle',
            'Snow',
            'Freezing Rain',
            'Thunderstorms'
        ];
    }

    public function availableLogTimes(): array
    {
        $now         = mktime((int)date('H'), 0, 0);
        $lastLogTime = $this->repo->maxLogTime();
        if ($lastLogTime) {
            return self::generateHourlyDatetimes((int)$lastLogTime->format('U'), $now);
        }

        $datetime = new \DateTime();
        $datetime->setTimestamp($now);
        return [$datetime];
    }

    public static function generateHourlyDatetimes(int $start, int $end)
    {
        $times  = [];
        $hour   = 3600;
        $limit  = $end - (24 * $hour);
        $begin  = $start > $limit ? $start : $limit;

        for ($i = $end; $i > $begin; $i-=$hour) {
            $times[] = new \DateTime(date('Y-m-d H:00:00', $i));
        }
        return $times;
    }
}
