
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
/**
 * PSR-7 UploadedFile
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_UploadedFile) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, UploadedFile, phalcon, http_message_uploadedfile, phalcon_http_message_uploadedfile_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * If the file has already been moved, we hold that status here
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_message_uploadedfile_ce, SL("alreadyMoved"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve the filename sent by the client.
	 *
	 * Do not trust the value returned by this method. A client could send
	 * a malicious filename with the intention to corrupt or hack your
	 * application.
	 *
	 * Implementations SHOULD return the value stored in the 'name' key of
	 * the file in the $_FILES array.
	 *
	 * @var string | null
	 */
	zend_declare_property_null(phalcon_http_message_uploadedfile_ce, SL("clientFilename"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve the media type sent by the client.
	 *
	 * Do not trust the value returned by this method. A client could send
	 * a malicious media type with the intention to corrupt or hack your
	 * application.
	 *
	 * Implementations SHOULD return the value stored in the 'type' key of
	 * the file in the $_FILES array.
	 *
	 * @var string | null
	 */
	zend_declare_property_null(phalcon_http_message_uploadedfile_ce, SL("clientMediaType"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve the error associated with the uploaded file.
	 *
	 * The return value MUST be one of PHP's UPLOAD_ERR_XXX constants.
	 *
	 * If the file was uploaded successfully, this method MUST return
	 * UPLOAD_ERR_OK.
	 *
	 * Implementations SHOULD return the value stored in the 'error' key of
	 * the file in the $_FILES array.
	 *
	 * @see http://php.net/manual/en/features.file-upload.errors.php
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_http_message_uploadedfile_ce, SL("error"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * If the stream is a string (file name) we store it here
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_http_message_uploadedfile_ce, SL("fileName"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Retrieve the file size.
	 *
	 * Implementations SHOULD return the value stored in the 'size' key of
	 * the file in the $_FILES array if available, as PHP calculates this based
	 * on the actual size transmitted.
	 *
	 * @var int | null
	 */
	zend_declare_property_null(phalcon_http_message_uploadedfile_ce, SL("size"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Holds the stream/string for the uploaded file
	 *
	 * @var StreamInterface|string|null
	 */
	zend_declare_property_null(phalcon_http_message_uploadedfile_ce, SL("stream"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(phalcon_http_message_uploadedfile_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\uploadedfileinterface")));
	return SUCCESS;

}

/**
 * Retrieve the filename sent by the client.
 *
 *
 * Do not trust the value returned by this method. A client could send
 * a malicious filename with the intention to corrupt or hack your
 * application.
 * 
 * Implementations SHOULD return the value stored in the 'name' key of
 * the file in the $_FILES array.
 *
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getClientFilename) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "clientFilename");

}

/**
 * Retrieve the media type sent by the client.
 *
 *
 * Do not trust the value returned by this method. A client could send
 * a malicious media type with the intention to corrupt or hack your
 * application.
 * 
 * Implementations SHOULD return the value stored in the 'type' key of
 * the file in the $_FILES array.
 *
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getClientMediaType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "clientMediaType");

}

/**
 * Retrieve the error associated with the uploaded file.
 *
 *
 * The return value MUST be one of PHP's UPLOAD_ERR_XXX constants.
 * 
 * If the file was uploaded successfully, this method MUST return
 * UPLOAD_ERR_OK.
 * 
 * Implementations SHOULD return the value stored in the 'error' key of
 * the file in the $_FILES array.
 *
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getError) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "error");

}

/**
 * Retrieve the file size.
 *
 *
 * Implementations SHOULD return the value stored in the 'size' key of
 * the file in the $_FILES array if available, as PHP calculates this based
 * on the actual size transmitted.
 *
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getSize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "size");

}

/**
 * UploadedFile constructor.
 *
 * @param StreamInterface|string|null $stream
 * @param int|null                    $size
 * @param int                         $error
 * @param string|null                 $clientFilename
 * @param string|null                 $clientMediaType
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval clientFilename, clientMediaType;
	zend_long size, error, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *size_param = NULL, *error_param = NULL, *clientFilename_param = NULL, *clientMediaType_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&clientFilename);
	ZVAL_UNDEF(&clientMediaType);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &stream, &size_param, &error_param, &clientFilename_param, &clientMediaType_param);

	if (!size_param) {
		size = 0;
	} else {
		size = zephir_get_intval(size_param);
	}
	if (!error_param) {
		error = 0;
	} else {
		error = zephir_get_intval(error_param);
	}
	if (!clientFilename_param) {
		ZEPHIR_INIT_VAR(&clientFilename);
		ZVAL_STRING(&clientFilename, "");
	} else {
		zephir_get_strval(&clientFilename, clientFilename_param);
	}
	if (!clientMediaType_param) {
		ZEPHIR_INIT_VAR(&clientMediaType);
		ZVAL_STRING(&clientMediaType, "");
	} else {
		zephir_get_strval(&clientMediaType, clientMediaType_param);
	}


	ZVAL_LONG(&_0, error);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstream", NULL, 315, stream, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, error);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkerror", NULL, 316, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, size);
	zephir_update_property_zval(this_ptr, SL("size"), &_0);
	zephir_update_property_zval(this_ptr, SL("clientFilename"), &clientFilename);
	zephir_update_property_zval(this_ptr, SL("clientMediaType"), &clientMediaType);
	ZEPHIR_MM_RESTORE();

}

/**
 * Retrieve a stream representing the uploaded file.
 *
 * This method MUST return a StreamInterface instance, representing the
 * uploaded file. The purpose of this method is to allow utilizing native
 * PHP stream functionality to manipulate the file upload, such as
 * stream_copy_to_stream() (though the result will need to be decorated in
 * a native PHP stream wrapper to work with such functions).
 *
 * If the moveTo() method has been called previously, this method MUST
 * raise an exception.
 *
 * @return StreamInterface Stream representation of the uploaded file.
 * @throws RuntimeException in cases when no stream is available or can be created.
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getStream) {

	zval _0, _4, _5, _1$$3, _2$$3, _3$$3, _6$$5, _7$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_http_message_exception_invalidargumentexception_ce);
		zephir_read_property(&_3$$3, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "geterrordescription", NULL, 317, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 35, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Http/Message/UploadedFile.zep", 160 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("alreadyMoved"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_is_true(&_4))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "The file has already been moved to the target location", "phalcon/Http/Message/UploadedFile.zep", 166);
		return;
	}
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("stream"), PH_NOISY_CC);
	if (UNEXPECTED(!(zephir_is_instance_of(&_5, SL("Psr\\Http\\Message\\StreamInterface") TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, phalcon_http_message_stream_ce);
		zephir_read_property(&_7$$5, this_ptr, SL("fileName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 38, &_7$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("stream"), &_6$$5);
	}
	RETURN_MM_MEMBER(getThis(), "stream");

}

/**
 * Move the uploaded file to a new location.
 *
 * Use this method as an alternative to move_uploaded_file(). This method is
 * guaranteed to work in both SAPI and non-SAPI environments.
 * Implementations must determine which environment they are in, and use the
 * appropriate method (move_uploaded_file(), rename(), or a stream
 * operation) to perform the operation.
 *
 * $targetPath may be an absolute path, or a relative path. If it is a
 * relative path, resolution should be the same as used by PHP's rename()
 * function.
 *
 * The original file or stream MUST be removed on completion.
 *
 * If this method is called more than once, any subsequent calls MUST raise
 * an exception.
 *
 * When used in an SAPI environment where $_FILES is populated, when writing
 * files via moveTo(), is_uploaded_file() and move_uploaded_file() SHOULD be
 * used to ensure permissions and upload status are verified correctly.
 *
 * If you wish to move to a stream, use getStream(), as SAPI operations
 * cannot guarantee writing to stream destinations.
 *
 * @see http://php.net/is_uploaded_file
 * @see http://php.net/move_uploaded_file
 *
 * @param string $targetPath Path to which to move the uploaded file.
 *
 * @throws InvalidArgumentException if the $targetPath specified is invalid.
 * @throws RuntimeException on any error during the move operation, or on
 *     the second or subsequent call to the method.
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, moveTo) {

	zend_bool _5, _6, _9, _13, _15, _16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *targetPath, targetPath_sub, __$true, __$false, sapi, _0, _1, _7, _8, _10, _11, _12, _14, _2$$4, _3$$4, _4$$4, _17$$7, _18$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&sapi);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath);



	zephir_read_property(&_0, this_ptr, SL("alreadyMoved"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "File has already been moved", "phalcon/Http/Message/UploadedFile.zep", 215);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&_1, 0))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_http_message_exception_invalidargumentexception_ce);
		zephir_read_property(&_4$$4, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "geterrordescription", NULL, 317, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 35, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Http/Message/UploadedFile.zep", 221 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = Z_TYPE_P(targetPath) == IS_STRING;
	if (_5) {
		_5 = !(ZEPHIR_IS_EMPTY(targetPath));
	}
	_6 = _5;
	if (_6) {
		ZEPHIR_CALL_FUNCTION(&_7, "dirname", NULL, 318, targetPath);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_8, "is_dir", NULL, 125, &_7);
		zephir_check_call_status();
		_6 = zephir_is_true(&_8);
	}
	_9 = _6;
	if (_9) {
		ZEPHIR_CALL_FUNCTION(&_10, "dirname", NULL, 318, targetPath);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_11, "is_writable", NULL, 319, &_10);
		zephir_check_call_status();
		_9 = zephir_is_true(&_11);
	}
	if (UNEXPECTED(!(_9))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Target folder is empty string, not a folder or not writable", "phalcon/Http/Message/UploadedFile.zep", 233);
		return;
	}
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "PHP_SAPI");
	ZEPHIR_CALL_FUNCTION(&sapi, "constant", NULL, 116, &_12);
	zephir_check_call_status();
	_13 = ZEPHIR_IS_EMPTY(&sapi);
	if (!(_13)) {
		ZEPHIR_OBS_VAR(&_14);
		zephir_read_property(&_14, this_ptr, SL("fileName"), PH_NOISY_CC);
		_13 = !(ZEPHIR_IS_EMPTY(&_14));
	}
	_15 = _13;
	if (!(_15)) {
		_15 = zephir_start_with_str(&sapi, SL("cli"));
	}
	_16 = _15;
	if (!(_16)) {
		_16 = zephir_start_with_str(&sapi, SL("phpdbg"));
	}
	if (UNEXPECTED(_16)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "storefile", NULL, 320, targetPath);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_17$$7, this_ptr, SL("fileName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_18$$7, "move_uploaded_file", NULL, 321, &_17$$7, targetPath);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_18$$7)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "The file cannot be moved to the target folder", "phalcon/Http/Message/UploadedFile.zep", 247);
			return;
		}
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("alreadyMoved"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("alreadyMoved"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks the passed error code and if not in the range throws an exception
 *
 * @param int $error
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, checkError) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *error_param = NULL, _0, _2, _3, _4;
	zend_long error, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &error_param);

	error = zephir_get_intval(error_param);


	ZVAL_LONG(&_2, error);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 8);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_number_ce, "between", &_1, 281, &_2, &_3, &_4);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid error. Must be one of the UPLOAD_ERR_* constants", "phalcon/Http/Message/UploadedFile.zep", 264);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, error);
	zephir_update_property_zval(this_ptr, SL("error"), &_2);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks the passed error code and if not in the range throws an exception
 *
 * @param StreamInterface|resource|string $stream
 * @param int                             $error
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, checkStream) {

	zend_bool _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long error, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *error_param = NULL, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &stream, &error_param);

	error = zephir_get_intval(error_param);


	if (UNEXPECTED(0 == error)) {
		do {
			_0$$3 = 1;
			if (_0$$3 == (Z_TYPE_P(stream) == IS_STRING)) {
				zephir_update_property_zval(this_ptr, SL("fileName"), stream);
				break;
			}
			if (_0$$3 == (Z_TYPE_P(stream) == IS_RESOURCE)) {
				ZEPHIR_INIT_VAR(&_1$$5);
				object_init_ex(&_1$$5, phalcon_http_message_stream_ce);
				ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 38, stream);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("stream"), &_1$$5);
				break;
			}
			if (_0$$3 == (zephir_is_instance_of(stream, SL("Psr\\Http\\Message\\StreamInterface") TSRMLS_CC))) {
				zephir_update_property_zval(this_ptr, SL("stream"), stream);
				break;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Invalid stream or file passed", "phalcon/Http/Message/UploadedFile.zep", 290);
			return;
		} while(0);

	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a description string depending on the upload error code passed
 *
 * @param int $error
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getErrorDescription) {

	zval errors;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *error_param = NULL, _1, _2;
	zend_long error, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&errors);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &error_param);

	error = zephir_get_intval(error_param);


	ZEPHIR_INIT_VAR(&errors);
	zephir_create_array(&errors, 8, 0 TSRMLS_CC);
	add_index_stringl(&errors, 0, SL("There is no error, the file uploaded with success."));
	add_index_stringl(&errors, 1, SL("The uploaded file exceeds the upload_max_filesize directive in php.ini."));
	add_index_stringl(&errors, 2, SL("The uploaded file exceeds the MAX_FILE_SIZE directive that was specified in the HTML form."));
	add_index_stringl(&errors, 3, SL("The uploaded file was only partially uploaded."));
	add_index_stringl(&errors, 4, SL("No file was uploaded."));
	add_index_stringl(&errors, 6, SL("Missing a temporary folder."));
	add_index_stringl(&errors, 7, SL("Failed to write file to disk."));
	add_index_stringl(&errors, 8, SL("A PHP extension stopped the file upload."));
	ZVAL_LONG(&_1, error);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Unknown upload error");
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_arr_ce, "get", &_0, 12, &errors, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Store a file in the new location (stream)
 *
 * @param string $targetPath
 */
PHP_METHOD(Phalcon_Http_Message_UploadedFile, storeFile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *targetPath_param = NULL, data, handle, stream, _0, _1, _2$$4;
	zval targetPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&stream);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath_param);

	zephir_get_strval(&targetPath, targetPath_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "w+b");
	ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 81, &targetPath, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&handle))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_message_exception_invalidargumentexception_ce, "Cannot write to file.", "phalcon/Http/Message/UploadedFile.zep", 331);
		return;
	}
	ZEPHIR_CALL_METHOD(&stream, this_ptr, "getstream", NULL, 322);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &stream, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_1, &stream, "eof", NULL, 0);
		zephir_check_call_status();
		if (!(!ZEPHIR_IS_TRUE_IDENTICAL(&_1))) {
			break;
		}
		ZVAL_LONG(&_2$$4, 2048);
		ZEPHIR_CALL_METHOD(&data, &stream, "read", &_3, 0, &_2$$4);
		zephir_check_call_status();
		zephir_fwrite(NULL, &handle, &data TSRMLS_CC);
	}
	zephir_fclose(&handle TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

