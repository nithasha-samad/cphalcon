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

namespace Phalcon\Test\Integration\Mvc\Model\Resultset\Simple;

use IntegrationTester;

/**
 * Class GetLastCest
 */
class GetLastCest
{
    /**
     * Tests Phalcon\Mvc\Model\Resultset\Simple :: getLast()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelResultsetSimpleGetLast(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Simple - getLast()');
        $I->skipTest('Need implementation');
    }
}
