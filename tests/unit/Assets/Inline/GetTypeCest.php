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

namespace Phalcon\Test\Unit\Assets\Inline;

use Codeception\Example;
use Phalcon\Assets\Inline;
use UnitTester;

class GetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline :: getType()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsInlineGetType(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Inline - getType()');

        $asset = new Inline(
            $example['type'],
            $example['content']
        );

        $I->assertEquals(
            $example['type'],
            $asset->getType()
        );
    }

    protected function provider(): array
    {
        return [
            [
                'type'    => 'css',
                'content' => 'p {color: #000099}',
            ],
            [
                'type'    => 'js',
                'content' => '<script>alert("Hello");</script>',
            ],
        ];
    }
}
