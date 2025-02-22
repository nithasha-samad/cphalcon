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

namespace Phalcon\Test\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

class LastCest
{
    /**
     * Tests Phalcon\Helper\Arr :: last()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperArrLast(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - last()');

        $collection = [
            'Phalcon',
            'Framework',
        ];

        $I->assertEquals(
            'Framework',
            Arr::last($collection)
        );
    }

    /**
     * Tests Phalcon\Helper\Arr :: last() - function
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperArrLastFunction(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - last() - function');

        $collection = [
            'Phalcon',
            'Framework',
        ];

        $actual = Arr::last(
            $collection,
            function ($element) {
                return strlen($element) < 8;
            }
        );

        $I->assertEquals(
            'Phalcon',
            $actual
        );
    }
}
