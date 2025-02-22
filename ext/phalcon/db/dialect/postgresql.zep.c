
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Generates database specific SQL for the PostgreSQL RDBMS
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Postgresql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Postgresql, phalcon, db_dialect_postgresql, phalcon_db_dialect_ce, phalcon_db_dialect_postgresql_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_dialect_postgresql_ce, SL("escapeChar"), "\"", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, columnDefinition, _0, _1, _2, _3, _4, _7, _5$$3, _6$$3;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "ALTER TABLE ", &_0, " ADD COLUMN ");
	zephir_get_strval(&sql, &_1);
	ZEPHIR_CALL_METHOD(&_2, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVSV(&_3, "\"", &_2, "\" ", &columnDefinition);
	zephir_concat_self(&sql, &_3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, column, "hasdefault", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "castdefault", NULL, 0, column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, " DEFAULT ", &_5$$3);
		zephir_concat_self(&sql, &_6$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_7, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		zephir_concat_self_str(&sql, " NOT NULL", sizeof(" NOT NULL")-1 TSRMLS_CC);
	}
	RETURN_CTOR(&sql);

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, reference_sub, onDelete, onUpdate, _0, _1, _2, _5, _6, _7, _8, _9, _10, _3$$3, _4$$3, _11$$4, _12$$5;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "ALTER TABLE ", &_0, " ADD");
	zephir_get_strval(&sql, &_1);
	ZEPHIR_CALL_METHOD(&_2, reference, "getname", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&_3$$3, reference, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, " CONSTRAINT \"", &_3$$3, "\"");
		zephir_concat_self(&sql, &_4$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_6, reference, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 61, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, reference, "getreferencedtable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, reference, "getreferencedcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getcolumnlist", NULL, 61, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SVSSVSVS(&_10, " FOREIGN KEY (", &_5, ")", " REFERENCES \"", &_7, "\" (", &_8, ")");
	zephir_concat_self(&sql, &_10 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
		ZEPHIR_INIT_VAR(&_11$$4);
		ZEPHIR_CONCAT_SV(&_11$$4, " ON DELETE ", &onDelete);
		zephir_concat_self(&sql, &_11$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
		ZEPHIR_INIT_VAR(&_12$$5);
		ZEPHIR_CONCAT_SV(&_12$$5, " ON UPDATE ", &onUpdate);
		zephir_concat_self(&sql, &_12$$5 TSRMLS_CC);
	}
	RETURN_CTOR(&sql);

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, indexType, _0, _2, _3, _4, _5, _6, _7, _1$$4;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, index, "getname", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "PRIMARY")) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addprimarykey", NULL, 0, &tableName, &schemaName, index);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "CREATE");
	ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&indexType))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SV(&_1$$4, " ", &indexType);
		zephir_concat_self(&sql, &_1$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_2, index, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSV(&_4, " INDEX \"", &_2, "\" ON ", &_3);
	zephir_concat_self(&sql, &_4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_6, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 61, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SVS(&_7, " (", &_5, ")");
	zephir_concat_self(&sql, &_7 TSRMLS_CC);
	RETURN_CTOR(&sql);

}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, _0, _1, _2;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcolumnlist", NULL, 61, &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVSVS(return_value, "ALTER TABLE ", &_0, " ADD CONSTRAINT \"", &tableName, "_PRIMARY\" PRIMARY KEY (", &_1, ")");
	RETURN_MM();

}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition, createLines, primaryColumns;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, temporary, options, table, columns, column, indexes, index, reference, references, indexName, indexType, onDelete, onUpdate, columnDefinition, *_2, _3, _74, _75, _0$$5, _1$$6, _5$$7, _6$$7, _7$$7, _11$$7, _12$$7, _8$$8, _10$$8, _13$$10, _14$$11, _15$$11, _16$$11, _19$$11, _20$$11, _17$$12, _18$$12, _21$$14, _22$$15, _23$$15, *_24$$16, _25$$16, _26$$18, _27$$18, _28$$18, _29$$20, _30$$20, _31$$20, _32$$21, _33$$21, _34$$21, _35$$21, _36$$21, _37$$21, _38$$24, _39$$24, _40$$24, _41$$26, _42$$26, _43$$26, _44$$27, _45$$27, _46$$27, _47$$27, _48$$27, _49$$27, *_50$$29, _51$$29, _52$$30, _53$$30, _54$$30, _55$$30, _56$$30, _57$$30, _58$$30, _59$$30, _60$$30, _61$$31, _62$$32, _63$$33, _64$$33, _65$$33, _66$$33, _67$$33, _68$$33, _69$$33, _70$$33, _71$$33, _72$$34, _73$$35, _76$$36, _77$$36;
	zval tableName, schemaName, indexSql, indexSqlAfterCreate, columnLine, referenceSql, sql, _78;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&indexSql);
	ZVAL_UNDEF(&indexSqlAfterCreate);
	ZVAL_UNDEF(&columnLine);
	ZVAL_UNDEF(&referenceSql);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_78);
	ZVAL_UNDEF(&temporary);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&reference);
	ZVAL_UNDEF(&references);
	ZVAL_UNDEF(&indexName);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_74);
	ZVAL_UNDEF(&_75);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_37$$21);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_41$$26);
	ZVAL_UNDEF(&_42$$26);
	ZVAL_UNDEF(&_43$$26);
	ZVAL_UNDEF(&_44$$27);
	ZVAL_UNDEF(&_45$$27);
	ZVAL_UNDEF(&_46$$27);
	ZVAL_UNDEF(&_47$$27);
	ZVAL_UNDEF(&_48$$27);
	ZVAL_UNDEF(&_49$$27);
	ZVAL_UNDEF(&_51$$29);
	ZVAL_UNDEF(&_52$$30);
	ZVAL_UNDEF(&_53$$30);
	ZVAL_UNDEF(&_54$$30);
	ZVAL_UNDEF(&_55$$30);
	ZVAL_UNDEF(&_56$$30);
	ZVAL_UNDEF(&_57$$30);
	ZVAL_UNDEF(&_58$$30);
	ZVAL_UNDEF(&_59$$30);
	ZVAL_UNDEF(&_60$$30);
	ZVAL_UNDEF(&_61$$31);
	ZVAL_UNDEF(&_62$$32);
	ZVAL_UNDEF(&_63$$33);
	ZVAL_UNDEF(&_64$$33);
	ZVAL_UNDEF(&_65$$33);
	ZVAL_UNDEF(&_66$$33);
	ZVAL_UNDEF(&_67$$33);
	ZVAL_UNDEF(&_68$$33);
	ZVAL_UNDEF(&_69$$33);
	ZVAL_UNDEF(&_70$$33);
	ZVAL_UNDEF(&_71$$33);
	ZVAL_UNDEF(&_72$$34);
	ZVAL_UNDEF(&_73$$35);
	ZVAL_UNDEF(&_76$$36);
	ZVAL_UNDEF(&_77$$36);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&createLines);
	ZVAL_UNDEF(&primaryColumns);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	ZEPHIR_OBS_VAR(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/Db/Dialect/Postgresql.zep", 132);
		return;
	}
	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&temporary);
	ZVAL_BOOL(&temporary, 0);
	ZEPHIR_OBS_VAR(&options);
	if (zephir_array_isset_string_fetch(&options, &definition, SL("options"), 0)) {
		ZEPHIR_OBS_NVAR(&temporary);
		zephir_array_isset_string_fetch(&temporary, &options, SL("temporary"), 0);
	}
	if (zephir_is_true(&temporary)) {
		ZEPHIR_INIT_VAR(&_0$$5);
		ZEPHIR_CONCAT_SVS(&_0$$5, "CREATE TEMPORARY TABLE ", &table, " (\n\t");
		zephir_get_strval(&sql, &_0$$5);
	} else {
		ZEPHIR_INIT_VAR(&_1$$6);
		ZEPHIR_CONCAT_SVS(&_1$$6, "CREATE TABLE ", &table, " (\n\t");
		zephir_get_strval(&sql, &_1$$6);
	}
	ZEPHIR_INIT_VAR(&createLines);
	array_init(&createLines);
	ZEPHIR_INIT_VAR(&primaryColumns);
	array_init(&primaryColumns);
	zephir_is_iterable(&columns, 0, "phalcon/Db/Dialect/Postgresql.zep", 182);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _2)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _2);
			ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", &_4, 0, &column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5$$7, &column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_6$$7);
			ZEPHIR_CONCAT_SVSV(&_6$$7, "\"", &_5$$7, "\" ", &columnDefinition);
			zephir_get_strval(&columnLine, &_6$$7);
			ZEPHIR_CALL_METHOD(&_7$$7, &column, "hasdefault", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_7$$7)) {
				ZEPHIR_CALL_METHOD(&_8$$8, this_ptr, "castdefault", &_9, 0, &column);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_10$$8);
				ZEPHIR_CONCAT_SV(&_10$$8, " DEFAULT ", &_8$$8);
				zephir_concat_self(&columnLine, &_10$$8 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_11$$7, &column, "isnotnull", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_11$$7)) {
				zephir_concat_self_str(&columnLine, " NOT NULL", sizeof(" NOT NULL")-1 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_12$$7, &column, "isprimary", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_12$$7)) {
				ZEPHIR_CALL_METHOD(&_13$$10, &column, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_array_append(&primaryColumns, &_13$$10, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 176);
			}
			zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 179);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", &_4, 0, &column);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_14$$11, &column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_15$$11);
				ZEPHIR_CONCAT_SVSV(&_15$$11, "\"", &_14$$11, "\" ", &columnDefinition);
				zephir_get_strval(&columnLine, &_15$$11);
				ZEPHIR_CALL_METHOD(&_16$$11, &column, "hasdefault", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_16$$11)) {
					ZEPHIR_CALL_METHOD(&_17$$12, this_ptr, "castdefault", &_9, 0, &column);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_18$$12);
					ZEPHIR_CONCAT_SV(&_18$$12, " DEFAULT ", &_17$$12);
					zephir_concat_self(&columnLine, &_18$$12 TSRMLS_CC);
				}
				ZEPHIR_CALL_METHOD(&_19$$11, &column, "isnotnull", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_19$$11)) {
					zephir_concat_self_str(&columnLine, " NOT NULL", sizeof(" NOT NULL")-1 TSRMLS_CC);
				}
				ZEPHIR_CALL_METHOD(&_20$$11, &column, "isprimary", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_20$$11)) {
					ZEPHIR_CALL_METHOD(&_21$$14, &column, "getname", NULL, 0);
					zephir_check_call_status();
					zephir_array_append(&primaryColumns, &_21$$14, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 176);
				}
				zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 179);
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	if (!(ZEPHIR_IS_EMPTY(&primaryColumns))) {
		ZEPHIR_CALL_METHOD(&_22$$15, this_ptr, "getcolumnlist", NULL, 61, &primaryColumns);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_23$$15);
		ZEPHIR_CONCAT_SVS(&_23$$15, "PRIMARY KEY (", &_22$$15, ")");
		zephir_array_append(&createLines, &_23$$15, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 183);
	}
	ZEPHIR_INIT_VAR(&indexSqlAfterCreate);
	ZVAL_STRING(&indexSqlAfterCreate, "");
	ZEPHIR_OBS_VAR(&indexes);
	if (zephir_array_isset_string_fetch(&indexes, &definition, SL("indexes"), 0)) {
		zephir_is_iterable(&indexes, 0, "phalcon/Db/Dialect/Postgresql.zep", 216);
		if (Z_TYPE_P(&indexes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&indexes), _24$$16)
			{
				ZEPHIR_INIT_NVAR(&index);
				ZVAL_COPY(&index, _24$$16);
				ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&indexSql);
				ZVAL_STRING(&indexSql, "");
				if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
					ZEPHIR_CALL_METHOD(&_27$$18, &index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_26$$18, this_ptr, "getcolumnlist", NULL, 61, &_27$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_28$$18);
					ZEPHIR_CONCAT_SVS(&_28$$18, "CONSTRAINT \"PRIMARY\" PRIMARY KEY (", &_26$$18, ")");
					zephir_get_strval(&indexSql, &_28$$18);
				} else {
					if (!(ZEPHIR_IS_EMPTY(&indexType))) {
						ZEPHIR_CALL_METHOD(&_30$$20, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_29$$20, this_ptr, "getcolumnlist", NULL, 61, &_30$$20);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_31$$20);
						ZEPHIR_CONCAT_SVSVSVS(&_31$$20, "CONSTRAINT \"", &indexName, "\" ", &indexType, " (", &_29$$20, ")");
						zephir_get_strval(&indexSql, &_31$$20);
					} else {
						ZEPHIR_CALL_METHOD(&_32$$21, &index, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_33$$21, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_34$$21);
						ZEPHIR_CONCAT_SVSV(&_34$$21, "CREATE INDEX \"", &_32$$21, "\" ON ", &_33$$21);
						zephir_concat_self(&indexSqlAfterCreate, &_34$$21 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&_36$$21, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_35$$21, this_ptr, "getcolumnlist", NULL, 61, &_36$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_37$$21);
						ZEPHIR_CONCAT_SVS(&_37$$21, " (", &_35$$21, ");");
						zephir_concat_self(&indexSqlAfterCreate, &_37$$21 TSRMLS_CC);
					}
				}
				if (!(ZEPHIR_IS_EMPTY(&indexSql))) {
					zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 213);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_25$$16, &indexes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_25$$16)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&indexSql);
					ZVAL_STRING(&indexSql, "");
					if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
						ZEPHIR_CALL_METHOD(&_39$$24, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_38$$24, this_ptr, "getcolumnlist", NULL, 61, &_39$$24);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_40$$24);
						ZEPHIR_CONCAT_SVS(&_40$$24, "CONSTRAINT \"PRIMARY\" PRIMARY KEY (", &_38$$24, ")");
						zephir_get_strval(&indexSql, &_40$$24);
					} else {
						if (!(ZEPHIR_IS_EMPTY(&indexType))) {
							ZEPHIR_CALL_METHOD(&_42$$26, &index, "getcolumns", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_41$$26, this_ptr, "getcolumnlist", NULL, 61, &_42$$26);
							zephir_check_call_status();
							ZEPHIR_INIT_LNVAR(_43$$26);
							ZEPHIR_CONCAT_SVSVSVS(&_43$$26, "CONSTRAINT \"", &indexName, "\" ", &indexType, " (", &_41$$26, ")");
							zephir_get_strval(&indexSql, &_43$$26);
						} else {
							ZEPHIR_CALL_METHOD(&_44$$27, &index, "getname", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_45$$27, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
							zephir_check_call_status();
							ZEPHIR_INIT_LNVAR(_46$$27);
							ZEPHIR_CONCAT_SVSV(&_46$$27, "CREATE INDEX \"", &_44$$27, "\" ON ", &_45$$27);
							zephir_concat_self(&indexSqlAfterCreate, &_46$$27 TSRMLS_CC);
							ZEPHIR_CALL_METHOD(&_48$$27, &index, "getcolumns", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_47$$27, this_ptr, "getcolumnlist", NULL, 61, &_48$$27);
							zephir_check_call_status();
							ZEPHIR_INIT_LNVAR(_49$$27);
							ZEPHIR_CONCAT_SVS(&_49$$27, " (", &_47$$27, ");");
							zephir_concat_self(&indexSqlAfterCreate, &_49$$27 TSRMLS_CC);
						}
					}
					if (!(ZEPHIR_IS_EMPTY(&indexSql))) {
						zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 213);
					}
				ZEPHIR_CALL_METHOD(NULL, &indexes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&index);
	}
	ZEPHIR_OBS_VAR(&references);
	if (zephir_array_isset_string_fetch(&references, &definition, SL("references"), 0)) {
		zephir_is_iterable(&references, 0, "phalcon/Db/Dialect/Postgresql.zep", 244);
		if (Z_TYPE_P(&references) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&references), _50$$29)
			{
				ZEPHIR_INIT_NVAR(&reference);
				ZVAL_COPY(&reference, _50$$29);
				ZEPHIR_CALL_METHOD(&_52$$30, &reference, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_54$$30, &reference, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_53$$30, this_ptr, "getcolumnlist", NULL, 61, &_54$$30);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_55$$30);
				ZEPHIR_CONCAT_SVSVS(&_55$$30, "CONSTRAINT \"", &_52$$30, "\" FOREIGN KEY (", &_53$$30, ") REFERENCES ");
				zephir_get_strval(&referenceSql, &_55$$30);
				ZEPHIR_CALL_METHOD(&_57$$30, &reference, "getreferencedtable", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_56$$30, this_ptr, "preparetable", NULL, 0, &_57$$30, &schemaName);
				zephir_check_call_status();
				zephir_concat_self(&referenceSql, &_56$$30 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_59$$30, &reference, "getreferencedcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_58$$30, this_ptr, "getcolumnlist", NULL, 61, &_59$$30);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_60$$30);
				ZEPHIR_CONCAT_SVS(&_60$$30, " (", &_58$$30, ")");
				zephir_concat_self(&referenceSql, &_60$$30 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
					ZEPHIR_INIT_LNVAR(_61$$31);
					ZEPHIR_CONCAT_SV(&_61$$31, " ON DELETE ", &onDelete);
					zephir_concat_self(&referenceSql, &_61$$31 TSRMLS_CC);
				}
				ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
					ZEPHIR_INIT_LNVAR(_62$$32);
					ZEPHIR_CONCAT_SV(&_62$$32, " ON UPDATE ", &onUpdate);
					zephir_concat_self(&referenceSql, &_62$$32 TSRMLS_CC);
				}
				zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 242);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &references, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_51$$29, &references, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_51$$29)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&reference, &references, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_63$$33, &reference, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_65$$33, &reference, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_64$$33, this_ptr, "getcolumnlist", NULL, 61, &_65$$33);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_66$$33);
					ZEPHIR_CONCAT_SVSVS(&_66$$33, "CONSTRAINT \"", &_63$$33, "\" FOREIGN KEY (", &_64$$33, ") REFERENCES ");
					zephir_get_strval(&referenceSql, &_66$$33);
					ZEPHIR_CALL_METHOD(&_68$$33, &reference, "getreferencedtable", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_67$$33, this_ptr, "preparetable", NULL, 0, &_68$$33, &schemaName);
					zephir_check_call_status();
					zephir_concat_self(&referenceSql, &_67$$33 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_70$$33, &reference, "getreferencedcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_69$$33, this_ptr, "getcolumnlist", NULL, 61, &_70$$33);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_71$$33);
					ZEPHIR_CONCAT_SVS(&_71$$33, " (", &_69$$33, ")");
					zephir_concat_self(&referenceSql, &_71$$33 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
						ZEPHIR_INIT_LNVAR(_72$$34);
						ZEPHIR_CONCAT_SV(&_72$$34, " ON DELETE ", &onDelete);
						zephir_concat_self(&referenceSql, &_72$$34 TSRMLS_CC);
					}
					ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
						ZEPHIR_INIT_LNVAR(_73$$35);
						ZEPHIR_CONCAT_SV(&_73$$35, " ON UPDATE ", &onUpdate);
						zephir_concat_self(&referenceSql, &_73$$35 TSRMLS_CC);
					}
					zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 242);
				ZEPHIR_CALL_METHOD(NULL, &references, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&reference);
	}
	ZEPHIR_INIT_VAR(&_74);
	zephir_fast_join_str(&_74, SL(",\n\t"), &createLines TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_75);
	ZEPHIR_CONCAT_VS(&_75, &_74, "\n)");
	zephir_concat_self(&sql, &_75 TSRMLS_CC);
	if (zephir_array_isset_string(&definition, SL("options"))) {
		ZEPHIR_CALL_METHOD(&_76$$36, this_ptr, "gettableoptions", NULL, 0, &definition);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_77$$36);
		ZEPHIR_CONCAT_SV(&_77$$36, " ", &_76$$36);
		zephir_concat_self(&sql, &_77$$36 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&_78);
	ZEPHIR_CONCAT_SV(&_78, ";", &indexSqlAfterCreate);
	zephir_concat_self(&sql, &_78 TSRMLS_CC);
	RETURN_CTOR(&sql);

}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createView) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName_param = NULL, viewSql, _0;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&viewSql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &definition_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	ZEPHIR_OBS_VAR(&viewSql);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&viewSql, &definition, SL("sql"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/Db/Dialect/Postgresql.zep", 265);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &viewName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE VIEW ", &_0, " AS ", &viewSql);
	RETURN_MM();

}

/**
 * Generates SQL describing a table
 *
 * ```php
 * print_r(
 *     $dialect->describeColumns("posts")
 * );
 * ```
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeColumns) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&schema, "")) {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_STRING(&schema, "public");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='", &schema, "' AND c.table_name='", &table, "' ORDER BY c.ordinal_position");
	RETURN_MM();

}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeIndexes) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = 'r' AND t.relname = '", &table, "' ORDER BY t.relname, i.relname;");
	RETURN_MM();

}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&schema, "")) {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_STRING(&schema, "public");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "SELECT DISTINCT tc.table_name AS TABLE_NAME, kcu.column_name AS COLUMN_NAME, tc.constraint_name AS CONSTRAINT_NAME, tc.table_catalog AS REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME, rc.update_rule AS UPDATE_RULE, rc.delete_rule AS DELETE_RULE FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name JOIN information_schema.referential_constraints rc ON tc.constraint_catalog = rc.constraint_catalog AND tc.constraint_schema = rc.constraint_schema AND tc.constraint_name = rc.constraint_name AND tc.constraint_type = 'FOREIGN KEY' WHERE constraint_type = 'FOREIGN KEY' AND tc.table_schema = '", &schema, "' AND tc.table_name='", &table, "'");
	RETURN_MM();

}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, _0;
	zval tableName, schemaName, columnName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &columnName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(columnName_param) != IS_STRING && Z_TYPE_P(columnName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'columnName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(columnName_param) == IS_STRING)) {
		zephir_get_strval(&columnName, columnName_param);
	} else {
		ZEPHIR_INIT_VAR(&columnName);
		ZVAL_EMPTY_STRING(&columnName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP COLUMN \"", &columnName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL, _0;
	zval tableName, schemaName, referenceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&referenceName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &referenceName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(referenceName_param) != IS_STRING && Z_TYPE_P(referenceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceName_param) == IS_STRING)) {
		zephir_get_strval(&referenceName, referenceName_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceName);
		ZVAL_EMPTY_STRING(&referenceName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP CONSTRAINT \"", &referenceName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropIndex) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL;
	zval tableName, schemaName, indexName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&indexName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(indexName_param) != IS_STRING && Z_TYPE_P(indexName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'indexName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(indexName_param) == IS_STRING)) {
		zephir_get_strval(&indexName, indexName_param);
	} else {
		ZEPHIR_INIT_VAR(&indexName);
		ZVAL_EMPTY_STRING(&indexName);
	}


	ZEPHIR_CONCAT_SVS(return_value, "DROP INDEX \"", &indexName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, _0;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP CONSTRAINT \"", &tableName, "_PRIMARY\"");
	RETURN_MM();

}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, table;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&table);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tableName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(ifExists_param) != IS_TRUE && Z_TYPE_P(ifExists_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ifExists = (Z_TYPE_P(ifExists_param) == IS_TRUE);
	}


	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	if (ifExists) {
		ZEPHIR_CONCAT_SV(return_value, "DROP TABLE IF EXISTS ", &table);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SV(return_value, "DROP TABLE ", &table);
	RETURN_MM();

}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropView) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, view;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&view);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &viewName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(ifExists_param) != IS_TRUE && Z_TYPE_P(ifExists_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ifExists = (Z_TYPE_P(ifExists_param) == IS_TRUE);
	}


	ZEPHIR_CALL_METHOD(&view, this_ptr, "preparetable", NULL, 0, &viewName, &schemaName);
	zephir_check_call_status();
	if (ifExists) {
		ZEPHIR_CONCAT_SV(return_value, "DROP VIEW IF EXISTS ", &view);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SV(return_value, "DROP VIEW ", &view);
	RETURN_MM();

}

/**
 * Gets the column name in PostgreSQL
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnDefinition) {

	zval valueSql$$36;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, columnType, columnSql, typeValues, _0$$4, _1$$9, _2$$15, _3$$20, _4$$31, _5$$34, _6$$34, _7$$34, value$$36, *_8$$36, _9$$36, _17$$36, _18$$36, _19$$36, _20$$36, _10$$37, _11$$37, _13$$37, _14$$38, _15$$38, _16$$38, _21$$39, _22$$39, _23$$39;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&columnSql);
	ZVAL_UNDEF(&typeValues);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_2$$15);
	ZVAL_UNDEF(&_3$$20);
	ZVAL_UNDEF(&_4$$31);
	ZVAL_UNDEF(&_5$$34);
	ZVAL_UNDEF(&_6$$34);
	ZVAL_UNDEF(&_7$$34);
	ZVAL_UNDEF(&value$$36);
	ZVAL_UNDEF(&_9$$36);
	ZVAL_UNDEF(&_17$$36);
	ZVAL_UNDEF(&_18$$36);
	ZVAL_UNDEF(&_19$$36);
	ZVAL_UNDEF(&_20$$36);
	ZVAL_UNDEF(&_10$$37);
	ZVAL_UNDEF(&_11$$37);
	ZVAL_UNDEF(&_13$$37);
	ZVAL_UNDEF(&_14$$38);
	ZVAL_UNDEF(&_15$$38);
	ZVAL_UNDEF(&_16$$38);
	ZVAL_UNDEF(&_21$$39);
	ZVAL_UNDEF(&_22$$39);
	ZVAL_UNDEF(&_23$$39);
	ZVAL_UNDEF(&valueSql$$36);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&columnSql, this_ptr, "checkcolumntypesql", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnType, this_ptr, "checkcolumntype", NULL, 0, column);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(&columnType, 14)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				ZEPHIR_CALL_METHOD(&_0$$4, column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_0$$4)) {
					zephir_concat_self_str(&columnSql, SL("BIGSERIAL") TSRMLS_CC);
				} else {
					zephir_concat_self_str(&columnSql, SL("BIGINT") TSRMLS_CC);
				}
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 8)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BOOLEAN") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 5)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_1$$9, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_1$$9 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 1)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATE") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 4)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 3)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("NUMERIC") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_2$$15, this_ptr, "getcolumnsizeandscale", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_2$$15 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 7)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("FLOAT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 0)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				ZEPHIR_CALL_METHOD(&_3$$20, column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_3$$20)) {
					zephir_concat_self_str(&columnSql, SL("SERIAL") TSRMLS_CC);
				} else {
					zephir_concat_self_str(&columnSql, SL("INT") TSRMLS_CC);
				}
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 15)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("JSON") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 16)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("JSONB") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 17)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 6)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TEXT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 2)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER VARYING") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_4$$31, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_4$$31 TSRMLS_CC);
			break;
		}
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&columnSql))) {
			ZEPHIR_INIT_VAR(&_5$$34);
			object_init_ex(&_5$$34, phalcon_db_exception_ce);
			ZEPHIR_CALL_METHOD(&_6$$34, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$34);
			ZEPHIR_CONCAT_SV(&_7$$34, "Unrecognized PostgreSQL data type at column ", &_6$$34);
			ZEPHIR_CALL_METHOD(NULL, &_5$$34, "__construct", NULL, 5, &_7$$34);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$34, "phalcon/Db/Dialect/Postgresql.zep", 493 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&typeValues))) {
			if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&valueSql$$36);
				ZVAL_STRING(&valueSql$$36, "");
				zephir_is_iterable(&typeValues, 0, "phalcon/Db/Dialect/Postgresql.zep", 508);
				if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&typeValues), _8$$36)
					{
						ZEPHIR_INIT_NVAR(&value$$36);
						ZVAL_COPY(&value$$36, _8$$36);
						ZEPHIR_INIT_NVAR(&_10$$37);
						ZVAL_STRING(&_10$$37, "\\'");
						ZEPHIR_CALL_FUNCTION(&_11$$37, "addcslashes", &_12, 190, &value$$36, &_10$$37);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_13$$37);
						ZEPHIR_CONCAT_SVS(&_13$$37, "'", &_11$$37, "', ");
						zephir_concat_self(&valueSql$$36, &_13$$37 TSRMLS_CC);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &typeValues, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_9$$36, &typeValues, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_9$$36)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&value$$36, &typeValues, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_14$$38);
							ZVAL_STRING(&_14$$38, "\\'");
							ZEPHIR_CALL_FUNCTION(&_15$$38, "addcslashes", &_12, 190, &value$$36, &_14$$38);
							zephir_check_call_status();
							ZEPHIR_INIT_LNVAR(_16$$38);
							ZEPHIR_CONCAT_SVS(&_16$$38, "'", &_15$$38, "', ");
							zephir_concat_self(&valueSql$$36, &_16$$38 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(NULL, &typeValues, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&value$$36);
				ZVAL_LONG(&_17$$36, 0);
				ZVAL_LONG(&_18$$36, -2);
				ZEPHIR_INIT_VAR(&_19$$36);
				zephir_substr(&_19$$36, &valueSql$$36, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(&_20$$36);
				ZEPHIR_CONCAT_SVS(&_20$$36, "(", &_19$$36, ")");
				zephir_concat_self(&columnSql, &_20$$36 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(&_21$$39);
				ZVAL_STRING(&_21$$39, "\\'");
				ZEPHIR_CALL_FUNCTION(&_22$$39, "addcslashes", &_12, 190, &typeValues, &_21$$39);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_23$$39);
				ZEPHIR_CONCAT_SVS(&_23$$39, "('", &_22$$39, "')");
				zephir_concat_self(&columnSql, &_23$$39 TSRMLS_CC);
			}
		}
	} while(0);

	RETURN_CCTOR(&columnSql);

}

/**
 * List all tables in database
 *
 * ```php
 * print_r(
 *     $dialect->listTables("blog")
 * );
 * ```
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listTables) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *schemaName_param = NULL;
	zval schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&schemaName, "")) {
		ZEPHIR_INIT_NVAR(&schemaName);
		ZVAL_STRING(&schemaName, "public");
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT table_name FROM information_schema.tables WHERE table_schema = '", &schemaName, "' ORDER BY table_name");
	RETURN_MM();

}

/**
 * Generates the SQL to list all views of a schema or user
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listViews) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *schemaName_param = NULL;
	zval schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&schemaName, "")) {
		ZEPHIR_INIT_NVAR(&schemaName);
		ZVAL_STRING(&schemaName, "public");
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT viewname AS view_name FROM pg_views WHERE schemaname = '", &schemaName, "' ORDER BY view_name");
	RETURN_MM();

}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn) {

	zend_bool _21$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, defaultValue, columnDefinition, _0, _1, _2, _3, _7, _8, _11, _12, _18, _19, _4$$4, _5$$4, _6$$4, _9$$5, _10$$5, _13$$6, _14$$7, _15$$7, _16$$8, _17$$8, _20$$9, _22$$9, _25$$9, _23$$10, _24$$10, _26$$11, _27$$12, _28$$12, _29$$13, _30$$13;
	zval tableName, schemaName, sql, sqlAlterTable;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&sqlAlterTable);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (!currentColumn) {
		currentColumn = &currentColumn_sub;
		ZEPHIR_CPY_WRT(currentColumn, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(currentColumn);
	}


	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "");
	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "ALTER TABLE ", &_0);
	zephir_get_strval(&sqlAlterTable, &_1);
	if (Z_TYPE_P(currentColumn) != IS_OBJECT) {
		ZEPHIR_CPY_WRT(currentColumn, column);
	}
	ZEPHIR_CALL_METHOD(&_2, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, currentColumn, "getname", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_2, &_3)) {
		ZEPHIR_CALL_METHOD(&_4$$4, currentColumn, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$4, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CONCAT_VSVSVS(&_6$$4, &sqlAlterTable, " RENAME COLUMN \"", &_4$$4, "\" TO \"", &_5$$4, "\";");
		zephir_concat_self(&sql, &_6$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_7, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, currentColumn, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_7, &_8)) {
		ZEPHIR_CALL_METHOD(&_9$$5, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$5);
		ZEPHIR_CONCAT_VSVSVS(&_10$$5, &sqlAlterTable, " ALTER COLUMN \"", &_9$$5, "\" TYPE ", &columnDefinition, ";");
		zephir_concat_self(&sql, &_10$$5 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_11, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, currentColumn, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_11, &_12)) {
		ZEPHIR_CALL_METHOD(&_13$$6, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_13$$6)) {
			ZEPHIR_CALL_METHOD(&_14$$7, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_15$$7);
			ZEPHIR_CONCAT_VSVS(&_15$$7, &sqlAlterTable, " ALTER COLUMN \"", &_14$$7, "\" SET NOT NULL;");
			zephir_concat_self(&sql, &_15$$7 TSRMLS_CC);
		} else {
			ZEPHIR_CALL_METHOD(&_16$$8, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_17$$8);
			ZEPHIR_CONCAT_VSVS(&_17$$8, &sqlAlterTable, " ALTER COLUMN \"", &_16$$8, "\" DROP NOT NULL;");
			zephir_concat_self(&sql, &_17$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_18, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_19, currentColumn, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_18, &_19)) {
		ZEPHIR_CALL_METHOD(&_20$$9, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		_21$$9 = ZEPHIR_IS_EMPTY(&_20$$9);
		if (_21$$9) {
			ZEPHIR_CALL_METHOD(&_22$$9, currentColumn, "getdefault", NULL, 0);
			zephir_check_call_status();
			_21$$9 = !(ZEPHIR_IS_EMPTY(&_22$$9));
		}
		if (_21$$9) {
			ZEPHIR_CALL_METHOD(&_23$$10, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_24$$10);
			ZEPHIR_CONCAT_VSVS(&_24$$10, &sqlAlterTable, " ALTER COLUMN \"", &_23$$10, "\" DROP DEFAULT;");
			zephir_concat_self(&sql, &_24$$10 TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_25$$9, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_25$$9)) {
			ZEPHIR_CALL_METHOD(&defaultValue, this_ptr, "castdefault", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_26$$11);
			zephir_fast_strtoupper(&_26$$11, &columnDefinition);
			if (zephir_memnstr_str(&_26$$11, SL("BOOLEAN"), "phalcon/Db/Dialect/Postgresql.zep", 591)) {
				ZEPHIR_CALL_METHOD(&_27$$12, column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_28$$12);
				ZEPHIR_CONCAT_SVSV(&_28$$12, " ALTER COLUMN \"", &_27$$12, "\" SET DEFAULT ", &defaultValue);
				zephir_concat_self(&sql, &_28$$12 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_METHOD(&_29$$13, column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_30$$13);
				ZEPHIR_CONCAT_VSVSV(&_30$$13, &sqlAlterTable, " ALTER COLUMN \"", &_29$$13, "\" SET DEFAULT ", &defaultValue);
				zephir_concat_self(&sql, &_30$$13 TSRMLS_CC);
			}
		}
	}
	RETURN_CTOR(&sql);

}

/**
 * Returns a SQL modified a shared lock statement. For now this method
 * returns the original query
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, sharedLock) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sqlQuery_param = NULL;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}


	RETURN_CTOR(&sqlQuery);

}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * ```php
 * echo $dialect->tableExists("posts", "blog");
 *
 * echo $dialect->tableExists("posts");
 * ```
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableExists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&schemaName, "")) {
		ZEPHIR_INIT_NVAR(&schemaName);
		ZVAL_STRING(&schemaName, "public");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = '", &schemaName, "' AND table_name='", &tableName, "'");
	RETURN_MM();

}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableOptions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	RETURN_MM_STRING("");

}

/**
 * Generates SQL to truncate a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, truncateTable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, table;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&table);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName);
		zephir_check_call_status();
	}
	ZEPHIR_CONCAT_SV(return_value, "TRUNCATE TABLE ", &table);
	RETURN_MM();

}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, viewExists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *viewName_param = NULL, *schemaName_param = NULL;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&schemaName, "")) {
		ZEPHIR_INIT_NVAR(&schemaName);
		ZVAL_STRING(&schemaName, "public");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", &viewName, "' AND schemaname='", &schemaName, "'");
	RETURN_MM();

}

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, castDefault) {

	zend_bool _2, _3, _4, _5;
	zval preparedValue, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, defaultValue, columnDefinition, columnType, _0, _1, _7$$6, _8$$6, _9$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&preparedValue);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnType, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtoupper(&_0, &columnDefinition);
	if (zephir_memnstr_str(&_0, SL("BOOLEAN"), "phalcon/Db/Dialect/Postgresql.zep", 674)) {
		RETURN_CCTOR(&defaultValue);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtoupper(&_1, &defaultValue);
	if (zephir_memnstr_str(&_1, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Postgresql.zep", 678)) {
		RETURN_MM_STRING("CURRENT_TIMESTAMP");
	}
	_2 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 0);
	if (!(_2)) {
		_2 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 14);
	}
	_3 = _2;
	if (!(_3)) {
		_3 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 3);
	}
	_4 = _3;
	if (!(_4)) {
		_4 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 7);
	}
	_5 = _4;
	if (!(_5)) {
		_5 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 9);
	}
	if (_5) {
		zephir_get_strval(&_6$$5, &defaultValue);
		ZEPHIR_CPY_WRT(&preparedValue, &_6$$5);
	} else {
		ZEPHIR_INIT_VAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "\\'");
		ZEPHIR_CALL_FUNCTION(&_8$$6, "addcslashes", NULL, 190, &defaultValue, &_7$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$6);
		ZEPHIR_CONCAT_SVS(&_9$$6, "'", &_8$$6, "'");
		zephir_get_strval(&preparedValue, &_9$$6);
	}
	RETURN_CTOR(&preparedValue);

}

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getTableOptions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *definition_param = NULL;
	zval definition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition_param);

	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	RETURN_MM_STRING("");

}

