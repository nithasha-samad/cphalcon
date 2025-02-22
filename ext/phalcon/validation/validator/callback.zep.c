
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Calls user function for validation
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Callback as CallbackValidator;
 * use Phalcon\Validation\Validator\Numericality as NumericalityValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     ["user", "admin"],
 *     new CallbackValidator(
 *         [
 *             "message" => "There must be only an user or admin set",
 *             "callback" => function($data) {
 *                 if (!empty($data->getUser()) && !empty($data->getAdmin())) {
 *                     return false;
 *                 }
 *
 *                 return true;
 *             }
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     "amount",
 *     new CallbackValidator(
 *         [
 *             "callback" => function($data) {
 *                 if (!empty($data->getProduct())) {
 *                     return new NumericalityValidator(
 *                         [
 *                             "message" => "Amount must be a number."
 *                         ]
 *                     );
 *                 }
 *             }
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Callback) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Callback, phalcon, validation_validator_callback, phalcon_validation_abstractvalidator_ce, phalcon_validation_validator_callback_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_callback_ce, SL("template"), "Field :field must match the callback function", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Callback, validate) {

	zend_bool _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, callback, returnedValue, data, _0, _2$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&returnedValue);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "callback");
	ZEPHIR_CALL_METHOD(&callback, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_callable(&callback TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&data, validation, "getentity", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&data)) {
			ZEPHIR_CALL_METHOD(&data, validation, "getdata", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_FUNCTION(&returnedValue, "call_user_func", NULL, 251, &callback, &data);
		zephir_check_call_status();
		_1$$3 = Z_TYPE_P(&returnedValue) == IS_OBJECT;
		if (_1$$3) {
			_1$$3 = zephir_instance_of_ev(&returnedValue, phalcon_validation_validatorinterface_ce TSRMLS_CC);
		}
		if (((Z_TYPE_P(&returnedValue) == IS_TRUE || Z_TYPE_P(&returnedValue) == IS_FALSE) == 1)) {
			if (!(zephir_is_true(&returnedValue))) {
				ZEPHIR_CALL_METHOD(&_2$$6, this_ptr, "messagefactory", NULL, 0, validation, field);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_2$$6);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
			RETURN_MM_BOOL(1);
		} else if (_1$$3) {
			ZEPHIR_RETURN_CALL_METHOD(&returnedValue, "validate", NULL, 0, validation, field);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_validator_exception_ce, "Callback must return bool or Phalcon\\Validation\\Validator object", "phalcon/Validation/Validator/Callback.zep", 100);
		return;
	}
	RETURN_MM_BOOL(1);

}

