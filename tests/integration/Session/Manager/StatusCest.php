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

namespace Phalcon\Test\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;

class StatusCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * Tests Phalcon\Session\Manager :: status()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionManagerStatus(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - status()');
        $manager = new Manager();
        $files   = $this->getSessionStream();
        $manager->setAdapter($files);

        $expected = $manager::SESSION_NONE;
        $actual   = $manager->status();
        $I->assertEquals($expected, $actual);

        $actual = $manager->start();
        $I->assertTrue($actual);

        $expected = $manager::SESSION_ACTIVE;
        $actual   = $manager->status();
        $I->assertEquals($expected, $actual);

        $manager->destroy();

        $expected = $manager::SESSION_NONE;
        $actual   = $manager->status();
        $I->assertEquals($expected, $actual);
    }
}
