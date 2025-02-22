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

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Reference;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class AddForeignKeyCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: addForeignKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-02-26
     *
     * @dataProvider getAddForeignKeyFixtures
     */
    public function dbDialectMysqlAddForeignKey(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Db\Dialect\Mysql - addForeignKey()");

        $schema    = $example[0];
        $reference = $example[1];
        $expected  = $example[2];

        $dialect    = new Mysql();
        $references = $this->getReferences();

        $actual = $dialect->addForeignKey('table', $schema, $references[$reference]);

        $I->assertEquals($expected, $actual);
    }

    public function issue14378MissingReferenceSchema(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Mysql - addForeignKey() for missing referenceSchema');
        $reference = new Reference(
            "fk_id_user",
            [
                'referencedTable' => 'users',
                'referencedSchema' => 'database2',
                'columns' => ['id_user'],
                'referencedColumns' => ['id'],
                'onUpdate' => 'CASCADE',
                'onDelete' => 'SET NULL',
            ]
        );
        $dialect = new Mysql();
        $actual  = $dialect->addForeignKey("table", "schema", $reference);

        $expect = "ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk_id_user` FOREIGN KEY (`id_user`) REFERENCES `database2`.`users`(`id`) ON DELETE SET NULL ON UPDATE CASCADE";
        $I->assertEquals($expect, $actual);
    }

    protected function getAddForeignKeyFixtures(): array
    {
        return [
            [
                '',
                'fk1',
                'ALTER TABLE `table` ADD CONSTRAINT `fk1` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`)',
            ],
            [
                'schema',
                'fk1',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk1` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`)',
            ],
            [
                '',
                'fk2',
                'ALTER TABLE `table` ADD CONSTRAINT `fk2` ' .
                'FOREIGN KEY (`column3`, `column4`) REFERENCES `ref_table`(`column5`, `column6`)',
            ],
            [
                'schema',
                'fk2',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk2` ' .
                'FOREIGN KEY (`column3`, `column4`) REFERENCES `ref_table`(`column5`, `column6`)',
            ],
            [
                '',
                'fk3',
                'ALTER TABLE `table` ADD CONSTRAINT `fk3` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE',
            ],
            [
                'schema',
                'fk3',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk3` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE',
            ],
            [
                '',
                'fk4',
                'ALTER TABLE `table` ADD CONSTRAINT `fk4` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON UPDATE SET NULL',
            ],
            [
                'schema',
                'fk4',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk4` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON UPDATE SET NULL',
            ],
            [
                '',
                'fk5',
                'ALTER TABLE `table` ADD CONSTRAINT `fk5` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE ON UPDATE NO ACTION',
            ],
            [
                'schema',
                'fk5',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk5` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE ON UPDATE NO ACTION',
            ],
        ];
    }
}
