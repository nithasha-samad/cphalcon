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

namespace Phalcon\Test\Integration\Mvc\Model\Query\Builder;

use IntegrationTester;

/**
 * Class OrWhereCest
 */
class OrWhereCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: orWhere()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQueryBuilderOrWhere(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - orWhere()');
        $I->skipTest('Need implementation');
    }
}
