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

namespace Phalcon\Test\Unit\Config\Config;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class GetPathDelimiterCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: getPathDelimiter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function configGetPathDelimiter(UnitTester $I)
    {
        $I->wantToTest('Config - getPathDelimiter()');
        $this->checkGetPathDelimiter($I);
    }
}
