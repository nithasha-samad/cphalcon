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

namespace Phalcon\Test\Unit\Collection\Collection;

use Phalcon\Collection;
use UnitTester;

class ToArrayCest
{
    /**
     * Tests Phalcon\Collection :: toArray()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionToArray(UnitTester $I)
    {
        $I->wantToTest('Collection\Collection - toArray()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection($data);

        $I->assertEquals(
            $data,
            $collection->toArray()
        );
    }
}
