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

namespace Phalcon\Test\Integration\Session\Adapter\Redis;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;
use function uniqid;

class DestroyCest
{
    use DiTrait;
    use SessionTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Redis :: destroy()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterRedisDestroy(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Redis - destroy()');

        $adapter = $this->getSessionRedis();

        $value = uniqid();

        $I->haveInRedis(
            'string',
            'sess-reds-test1',
            serialize($value)
        );

        $I->assertTrue(
            $adapter->destroy('test1')
        );

        $I->dontSeeInRedis('sess-reds-test1');
    }
}
