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

namespace Phalcon\Test\Integration\Mvc\Model\Manager;

use IntegrationTester;

/**
 * Class ClearReusableObjectsCest
 */
class ClearReusableObjectsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: clearReusableObjects()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelManagerClearReusableObjects(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - clearReusableObjects()');
        $I->skipTest('Need implementation');
    }
}
