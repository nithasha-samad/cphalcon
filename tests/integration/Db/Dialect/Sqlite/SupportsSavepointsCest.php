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

namespace Phalcon\Test\Integration\Db\Dialect\Sqlite;

use IntegrationTester;
use Phalcon\Db\Dialect\Sqlite;

class SupportsSavepointsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: supportsSavepoints()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-02-26
     */
    public function dbDialectSqliteSupportsSavepoints(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - supportsSavepoints()');

        $dialect = new Sqlite();

        $I->assertTrue(
            $dialect->supportsSavepoints()
        );
    }
}
