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

namespace Phalcon\Test\Unit\Storage\Adapter\Stream;

use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use UnitTester;
use function outputDir;

class ConstructCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function storageAdapterStreamConstruct(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - __construct()');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'cacheDir' => outputDir(),
            ]
        );

        $I->assertInstanceOf(
            Stream::class,
            $adapter
        );

        $I->assertInstanceOf(
            AdapterInterface::class,
            $adapter
        );
    }

    /**
     * Tests Phalcon\Storage\Adapter\Stream :: __construct() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function storageAdapterStreamConstructException(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - __construct() - exception');

        $I->expectThrowable(
            new Exception("The 'cacheDir' must be specified in the options"),
            function () {
                $serializer = new SerializerFactory();
                $adapter    = new Stream($serializer);
            }
        );
    }
}
