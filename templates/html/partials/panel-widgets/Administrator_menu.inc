<?php
/**
 * @copyright 2015-2019 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
?>
<nav>
    <header>
        <h1><?= $this->_('admin'); ?></h1>
    </header>
    <?php
        $links  = [];
        $routes = [
            'people'        => 'person',
            'users'         => 'user'
        ];
        foreach ($routes as $plural=>$singular) {
            if (parent::isAllowed($plural, 'index')) {
                $url   = parent::generateUri("$plural.index");
                $label = $this->_([$singular, $plural, 2]);
                echo "<a href=\"$url\">$label</a>";
            }
        }
    ?>
</nav>
