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

namespace Phalcon\Test\Integration\Mvc\Model\Query;

use IntegrationTester;

/**
 * Class CleanCest
 */
class CleanCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query :: clean()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQueryClean(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query - clean()');
        $I->skipTest('Need implementation');
    }
}
