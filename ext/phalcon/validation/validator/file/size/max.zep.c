
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/math.h"
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
 * Checks if a value has a correct file
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File\Size;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Max(
 *         [
 *             "size"     => "2M",
 *             "included" => true,
 *             "message"  => ":field exceeds the max filesize (:size)",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Max(
 *         [
 *             "size" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "included" => [
 *                 "file"        => false,
 *                 "anotherFile" => true,
 *             ],
 *             "message" => [
 *                 "file"        => "file exceeds the max filesize 2M",
 *                 "anotherFile" => "anotherFile exceeds the max filesize 4M",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File_Size_Max) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator\\File\\Size, Max, phalcon, validation_validator_file_size_max, phalcon_validation_validator_file_abstractfile_ce, phalcon_validation_validator_file_size_max_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_file_size_max_ce, SL("template"), "File :field exceeds the size of :size", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_File_Size_Max, validate) {

	double _9$$5, _10$$6;
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, bytes, fileSize, included, replacePairs, size, value, _0, _1, _3, _4, _5, _6, _7, _2$$4, _8$$5, _11$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&fileSize);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_INIT_VAR(&included);
	ZVAL_BOOL(&included, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkupload", NULL, 0, validation, field);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "size");
	ZEPHIR_CALL_METHOD(&size, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&size) == IS_ARRAY) {
		zephir_array_fetch(&_2$$4, &size, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Size/Max.zep", 82 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&size, &_2$$4);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getfilesizeinbytes", NULL, 0, &size);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 6);
	ZEPHIR_INIT_VAR(&bytes);
	zephir_round(&bytes, &_3, &_4, NULL TSRMLS_CC);
	zephir_array_fetch_string(&_5, &value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Size/Max.zep", 86 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_6, "floatval", NULL, 14, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_7, 6);
	ZEPHIR_INIT_VAR(&fileSize);
	zephir_round(&fileSize, &_6, &_7, NULL TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "included");
	ZEPHIR_CALL_METHOD(&included, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&included) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&_8$$5);
		zephir_array_fetch(&_8$$5, &included, field, PH_NOISY, "phalcon/Validation/Validator/File/Size/Max.zep", 91 TSRMLS_CC);
		_9$$5 = zephir_get_boolval(&_8$$5);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _9$$5);
	} else {
		_10$$6 = zephir_get_boolval(&included);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _10$$6);
	}
	if (zephir_is_true(&included)) {
		result = ZEPHIR_GE(&fileSize, &bytes);
	} else {
		result = ZEPHIR_GT(&fileSize, &bytes);
	}
	if (result) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":size"), &size, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_11$$9, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_11$$9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

