
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Checks if a value is a valid date
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Date as DateValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "date",
 *     new DateValidator(
 *         [
 *             "format"  => "d-m-Y",
 *             "message" => "The date is invalid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "date",
 *         "anotherDate",
 *     ],
 *     new DateValidator(
 *         [
 *             "format" => [
 *                 "date"        => "d-m-Y",
 *                 "anotherDate" => "Y-m-d",
 *             ],
 *             "message" => [
 *                 "date"        => "The date is invalid",
 *                 "anotherDate" => "The another date is invalid",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Date) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Date, phalcon, validation_validator_date, phalcon_validation_abstractvalidator_ce, phalcon_validation_validator_date_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_date_ce, SL("template"), "Field :field is not a valid date", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Date, validate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, format, _0, _2, _1$$3, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "format");
	ZEPHIR_CALL_METHOD(&format, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&format) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, &format, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Date.zep", 72 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&format, &_1$$3);
	}
	if (ZEPHIR_IS_EMPTY(&format)) {
		ZEPHIR_INIT_NVAR(&format);
		ZVAL_STRING(&format, "Y-m-d");
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "checkdate", NULL, 0, &value, &format);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "messagefactory", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_3$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Validation_Validator_Date, checkDate) {

	zend_bool _3;
	zend_class_entry *_0, *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *format, format_sub, date, errors, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&format_sub);
	ZVAL_UNDEF(&date);
	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &format);



	if (!(Z_TYPE_P(value) == IS_STRING)) {
		RETURN_MM_BOOL(0);
	}
	_0 = zephir_fetch_class_str_ex(SL("DateTime"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&date, _0, "createfromformat", NULL, 0, format, value);
	zephir_check_call_status();
	_1 = zephir_fetch_class_str_ex(SL("DateTime"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&errors, _1, "getlasterrors", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &errors, SL("warning_count"), PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Date.zep", 101 TSRMLS_CC);
	_3 = ZEPHIR_IS_LONG(&_2, 0);
	if (_3) {
		zephir_array_fetch_string(&_4, &errors, SL("error_count"), PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Date.zep", 101 TSRMLS_CC);
		_3 = ZEPHIR_IS_LONG(&_4, 0);
	}
	RETURN_MM_BOOL(_3);

}

