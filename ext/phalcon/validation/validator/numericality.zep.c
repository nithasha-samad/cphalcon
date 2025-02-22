
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
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
 * Check for a valid numeric value
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Numericality;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "price",
 *     new Numericality(
 *         [
 *             "message" => ":field is not numeric",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "price",
 *         "amount",
 *     ],
 *     new Numericality(
 *         [
 *             "message" => [
 *                 "price"  => "price is not numeric",
 *                 "amount" => "amount is not numeric",
 *             ]
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Numericality) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Numericality, phalcon, validation_validator_numericality, phalcon_validation_abstractvalidator_ce, phalcon_validation_validator_numericality_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_numericality_ce, SL("template"), "Field :field does not have a valid numeric format", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Numericality, validate) {

	zval pattern, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, _1, _2, _3, _4, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	zephir_get_strval(&_0, &value);
	ZEPHIR_CPY_WRT(&value, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, " ");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	zephir_fast_str_replace(&_1, &_2, &_3, &value TSRMLS_CC);
	ZEPHIR_CPY_WRT(&value, &_1);
	ZEPHIR_INIT_VAR(&pattern);
	ZVAL_STRING(&pattern, "/((^[-]?[0-9,]+(.[0-9]+)?$)|(^[-]?[0-9.]+(,[0-9]+)?$))/");
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_preg_match(&_1, &pattern, &value, &_4, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "messagefactory", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_5$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

