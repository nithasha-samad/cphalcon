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

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;

/**
 * Class GetHandlerClassCest
 */
class GetHandlerClassCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: getHandlerClass()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherGetHandlerClass(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getHandlerClass()');
        $I->skipTest('Need implementation');
    }
}
