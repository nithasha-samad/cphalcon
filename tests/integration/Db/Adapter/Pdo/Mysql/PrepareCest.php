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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;

/**
 * Class PrepareCest
 */
class PrepareCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: prepare()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlPrepare(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - prepare()');
        $I->skipTest('Need implementation');
    }
}
