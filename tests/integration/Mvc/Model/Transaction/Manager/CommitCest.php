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

namespace Phalcon\Test\Integration\Mvc\Model\Transaction\Manager;

use IntegrationTester;

/**
 * Class CommitCest
 */
class CommitCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: commit()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelTransactionManagerCommit(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction\Manager - commit()');
        $I->skipTest('Need implementation');
    }
}
