
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
 * Checks if a file has the rigth resolution
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File\Resolution\Min;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Min(
 *         [
 *             "resolution" => "800x600",
 *             "message"    => "Min resolution of :field is :resolution",
 *             "included"   => true,
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Min(
 *         [
 *             "resolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "included" => [
 *                 "file"        => false,
 *                 "anotherFile" => true,
 *             ],
 *             "message" => [
 *                 "file"        => "Min resolution of file is 800x600",
 *                 "anotherFile" => "Min resolution of file is 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File_Resolution_Min) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator\\File\\Resolution, Min, phalcon, validation_validator_file_resolution_min, phalcon_validation_validator_file_abstractfile_ce, phalcon_validation_validator_file_resolution_min_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_file_resolution_min_ce, SL("template"), "File :field can not have the minimum resolution of :resolution", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_File_Resolution_Min, validate) {

	double _5$$5, _6$$6;
	zend_bool result = 0, _7$$7, _8$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, height, minHeight, minWidth, resolution, resolutionArray, tmp, value, width, replacePairs, included, _0, _1, _2, _3$$4, _4$$5, _9$$9, _10$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&minHeight);
	ZVAL_UNDEF(&minWidth);
	ZVAL_UNDEF(&resolution);
	ZVAL_UNDEF(&resolutionArray);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$10);

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
	zephir_array_fetch_string(&_1, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Resolution/Min.zep", 79 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 356, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&width);
	zephir_array_fetch_long(&width, &tmp, 0, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Min.zep", 80 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&height);
	zephir_array_fetch_long(&height, &tmp, 1, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Min.zep", 81 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "resolution");
	ZEPHIR_CALL_METHOD(&resolution, this_ptr, "getoption", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&resolution) == IS_ARRAY) {
		zephir_array_fetch(&_3$$4, &resolution, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Resolution/Min.zep", 86 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&resolution, &_3$$4);
	}
	ZEPHIR_INIT_VAR(&resolutionArray);
	zephir_fast_explode_str(&resolutionArray, SL("x"), &resolution, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(&minWidth);
	zephir_array_fetch_long(&minWidth, &resolutionArray, 0, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Min.zep", 90 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&minHeight);
	zephir_array_fetch_long(&minHeight, &resolutionArray, 1, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Min.zep", 91 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "included");
	ZEPHIR_CALL_METHOD(&included, this_ptr, "getoption", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&included) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&_4$$5);
		zephir_array_fetch(&_4$$5, &included, field, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Min.zep", 96 TSRMLS_CC);
		_5$$5 = zephir_get_boolval(&_4$$5);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _5$$5);
	} else {
		_6$$6 = zephir_get_boolval(&included);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _6$$6);
	}
	if (zephir_is_true(&included)) {
		_7$$7 = ZEPHIR_LE(&width, &minWidth);
		if (!(_7$$7)) {
			_7$$7 = ZEPHIR_LE(&height, &minHeight);
		}
		result = _7$$7;
	} else {
		_8$$8 = ZEPHIR_LT(&width, &minWidth);
		if (!(_8$$8)) {
			_8$$8 = ZEPHIR_LT(&height, &minHeight);
		}
		result = _8$$8;
	}
	if (Z_TYPE_P(&resolution) == IS_ARRAY) {
		zephir_array_fetch(&_9$$9, &resolution, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Resolution/Min.zep", 108 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&resolution, &_9$$9);
	}
	if (result) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":resolution"), &resolution, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_10$$10, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_10$$10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

