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

namespace Phalcon\Test\Unit\Flash\Session;

use UnitTester;

class GetAutoescapeCest
{
    /**
     * Tests Phalcon\Flash\Session :: getAutoescape()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function flashSessionGetAutoescape(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - getAutoescape()');

        $I->skipTest('Need implementation');
    }
}
