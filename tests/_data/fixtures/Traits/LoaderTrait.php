<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use UnitTester;

trait LoaderTrait
{
    protected $loaders;
    protected $includePath;

    /**
     * executed before each test
     */
    protected function _before(UnitTester $I)
    {
        $this->loaders = spl_autoload_functions();

        if (!is_array($this->loaders)) {
            $this->loaders = [];
        }

        $this->includePath = get_include_path();
    }

    /**
     * executed after each test
     */
    protected function _after(UnitTester $I)
    {
        $loaders = spl_autoload_functions();

        if (is_array($loaders)) {
            foreach ($loaders as $loader) {
                spl_autoload_unregister($loader);
            }
        }

        foreach ($this->loaders as $loader) {
            spl_autoload_register($loader);
        }

        set_include_path(
            $this->includePath
        );
    }
}
