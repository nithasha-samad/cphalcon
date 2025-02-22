
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
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
 * Phalcon\Translate\Adapter
 *
 * Base class for Phalcon\Translate adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_AbstractAdapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Adapter, AbstractAdapter, phalcon, translate_adapter_abstractadapter, phalcon_translate_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_translate_adapter_abstractadapter_ce, SL("defaultInterpolator"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var InterpolatorFactory
	 */
	zend_declare_property_null(phalcon_translate_adapter_abstractadapter_ce, SL("interpolatorFactory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_translate_adapter_abstractadapter_ce TSRMLS_CC, 1, phalcon_translate_adapter_adapterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval options;
	zval *interpolator, interpolator_sub, *options_param = NULL, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &interpolator, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "defaultInterpolator");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "associativeArray");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_arr_ce, "get", &_1, 12, &options, &_2, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("defaultInterpolator"), &_0);
	zephir_update_property_zval(this_ptr, SL("interpolatorFactory"), interpolator);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the translation string of the given key (alias of method 't')
 *
 * @param array   placeholders
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, _) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey_param = NULL, *placeholders = NULL, placeholders_sub, __$null;
	zval translateKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translateKey_param, &placeholders);

	if (UNEXPECTED(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(&translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(&translateKey);
		ZVAL_EMPTY_STRING(&translateKey);
	}
	if (!placeholders) {
		placeholders = &placeholders_sub;
		placeholders = &__$null;
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, &translateKey, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether a translation key exists
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetExists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey, translateKey_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &translateKey);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "exists", NULL, 0, translateKey);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the translation related to the given key
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetGet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey, translateKey_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &translateKey);



	ZVAL_NULL(&_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, translateKey, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a translation value
 *
 * @param string value
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetSet) {

	zval *offset, offset_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &offset, &value);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object", "phalcon/Translate/Adapter/AbstractAdapter.zep", 74);
	return;

}

/**
 * Unsets a translation from the dictionary
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetUnset) {

	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &offset);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object", "phalcon/Translate/Adapter/AbstractAdapter.zep", 82);
	return;

}

/**
 * Returns the translation string of the given key
 *
 * @param array   placeholders
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, t) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey_param = NULL, *placeholders = NULL, placeholders_sub, __$null;
	zval translateKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translateKey_param, &placeholders);

	if (UNEXPECTED(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(&translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(&translateKey);
		ZVAL_EMPTY_STRING(&translateKey);
	}
	if (!placeholders) {
		placeholders = &placeholders_sub;
		placeholders = &__$null;
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, &translateKey, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Replaces placeholders by the values passed
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, replacePlaceholders) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *translation_param = NULL, *placeholders = NULL, placeholders_sub, __$null, interpolator, _0, _1;
	zval translation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&interpolator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translation_param, &placeholders);

	if (UNEXPECTED(Z_TYPE_P(translation_param) != IS_STRING && Z_TYPE_P(translation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translation' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(translation_param) == IS_STRING)) {
		zephir_get_strval(&translation, translation_param);
	} else {
		ZEPHIR_INIT_VAR(&translation);
		ZVAL_EMPTY_STRING(&translation);
	}
	if (!placeholders) {
		placeholders = &placeholders_sub;
		placeholders = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("interpolatorFactory"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("defaultInterpolator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&interpolator, &_0, "newinstance", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&interpolator, "replaceplaceholders", NULL, 0, &translation, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

