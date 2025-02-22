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

namespace Phalcon\Test\Integration\Forms\Form;

use IntegrationTester;

/**
 * Class GetActionCest
 */
class GetActionCest
{
    /**
     * Tests Phalcon\Forms\Form :: getAction()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsFormGetAction(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getAction()');
        $I->skipTest('Need implementation');
    }
}
