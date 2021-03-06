<?php
/**
 * @copyright 2018-2019 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
namespace Web\Authentication;

interface AuthenticationInterface
{
    public function  __construct(array $config);
    public function     identify(string $username): ?ExternalIdentity;
    public function authenticate(string $username, string $password): bool;
}
