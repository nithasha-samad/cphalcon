
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Validates that a string has the specified maximum constraints
 * The test is passed if for a string's length L, L<=max, i.e. L must
 * be at most max.
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\StringLength\Max;
 *
 * $validator = new Validation();
 *
 * $validation->add(
 *     "name_last",
 *     new Max(
 *         [
 *             "max"      => 50,
 *             "message"  => "We don't like really long names",
 *             "included" => true
 *         ]
 *     )
 * );
 *
 * $validation->add(
 *     [
 *         "name_last",
 *         "name_first",
 *     ],
 *     new Max(
 *         [
 *             "max" => [
 *                 "name_last"  => 50,
 *                 "name_first" => 40,
 *             ],
 *             "message" => [
 *                 "name_last"  => "We don't like really long last names",
 *                 "name_first" => "We don't like really long first names",
 *             ],
 *             "included" => [
 *                 "name_last"  => false,
 *                 "name_first" => true,
 *             ]
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_StringLength_Max) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator\\StringLength, Max, phalcon, validation_validator_stringlength_max, phalcon_validation_abstractvalidator_ce, phalcon_validation_validator_stringlength_max_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_stringlength_max_ce, SL("template"), "Field :field must not exceed :max characters long", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_StringLength_Max, validate) {

	double _3$$6, _4$$7;
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, length, maximum, replacePairs, included, _0, _1$$5, _2$$6, _5$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&maximum);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_5$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	if ((zephir_function_exists_ex(SL("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 275, &value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&length);
		ZVAL_LONG(&length, zephir_fast_strlen_ev(&value));
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "max");
	ZEPHIR_CALL_METHOD(&maximum, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&maximum) == IS_ARRAY) {
		zephir_array_fetch(&_1$$5, &maximum, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/StringLength/Max.zep", 87 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&maximum, &_1$$5);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "included");
	ZEPHIR_CALL_METHOD(&included, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&included) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&_2$$6);
		zephir_array_fetch(&_2$$6, &included, field, PH_NOISY, "phalcon/Validation/Validator/StringLength/Max.zep", 93 TSRMLS_CC);
		_3$$6 = zephir_get_boolval(&_2$$6);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _3$$6);
	} else {
		_4$$7 = zephir_get_boolval(&included);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _4$$7);
	}
	if (zephir_is_true(&included)) {
		result = ZEPHIR_GE(&length, &maximum);
	} else {
		result = ZEPHIR_GT(&length, &maximum);
	}
	if (result) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_5$$10, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_5$$10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

