
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
 *     new Equal(
 *         [
 *             "size"     => "2M",
 *             "included" => true,
 *             "message"  => ":field exceeds the equal filesize (:size)",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Equal(
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
 *                 "file"        => "file does not have the rigth filesize",
 *                 "anotherFile" => "anotherFile wrong filesize (4MB)",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File_Size_Equal) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator\\File\\Size, Equal, phalcon, validation_validator_file_size_equal, phalcon_validation_validator_file_abstractfile_ce, phalcon_validation_validator_file_size_equal_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_file_size_equal_ce, SL("template"), "File :field does not have the exact :size filesize", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_File_Size_Equal, validate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, bytes, fileSize, replacePairs, size, value, _0, _1, _3, _4, _5, _6, _7, _2$$4, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&fileSize);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



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
		zephir_array_fetch(&_2$$4, &size, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Size/Equal.zep", 82 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&size, &_2$$4);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getfilesizeinbytes", NULL, 0, &size);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 6);
	ZEPHIR_INIT_VAR(&bytes);
	zephir_round(&bytes, &_3, &_4, NULL TSRMLS_CC);
	zephir_array_fetch_string(&_5, &value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Size/Equal.zep", 86 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_6, "floatval", NULL, 14, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_7, 6);
	ZEPHIR_INIT_VAR(&fileSize);
	zephir_round(&fileSize, &_6, &_7, NULL TSRMLS_CC);
	if (!ZEPHIR_IS_IDENTICAL(&bytes, &fileSize)) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":size"), &size, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_8$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

