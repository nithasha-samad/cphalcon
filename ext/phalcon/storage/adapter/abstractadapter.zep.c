
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/date/php_date.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_AbstractAdapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Storage\\Adapter, AbstractAdapter, phalcon, storage_adapter_abstractadapter, phalcon_storage_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_storage_adapter_abstractadapter_ce, SL("adapter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Name of the default serializer class
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_abstractadapter_ce, SL("defaultSerializer"), "Php", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Name of the default TTL (time to live)
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_storage_adapter_abstractadapter_ce, SL("lifetime"), 3600, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_abstractadapter_ce, SL("prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Serializer
	 *
	 * @var <SerializerInterface>
	 */
	zend_declare_property_null(phalcon_storage_adapter_abstractadapter_ce, SL("serializer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Serializer Factory
	 *
	 * @var <SerializerFactory>
	 */
	zend_declare_property_null(phalcon_storage_adapter_abstractadapter_ce, SL("serializerFactory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_storage_adapter_abstractadapter_ce TSRMLS_CC, 1, phalcon_storage_adapter_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Name of the default serializer class
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getDefaultSerializer) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultSerializer");

}

/**
 * Name of the default serializer class
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, setDefaultSerializer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaultSerializer_param = NULL;
	zval defaultSerializer;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultSerializer);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultSerializer_param);

	zephir_get_strval(&defaultSerializer, defaultSerializer_param);


	zephir_update_property_zval(this_ptr, SL("defaultSerializer"), &defaultSerializer);
	RETURN_THIS();

}

/**
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getPrefix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "prefix");

}

/**
 * Sets parameters based on options
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval options;
	zval *factory = NULL, factory_sub, *options_param = NULL, __$null, _0, _2, _3, _4, _5, _6, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &factory, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	if (!factory) {
		factory = &factory_sub;
		factory = &__$null;
	}


	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "defaultSerializer");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Php");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_arr_ce, "get", &_1, 12, &options, &_2, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("defaultSerializer"), &_0);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "lifetime");
	ZVAL_LONG(&_5, 3600);
	ZEPHIR_CALL_CE_STATIC(&_4, phalcon_helper_arr_ce, "get", &_1, 12, &options, &_2, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("lifetime"), &_4);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "serializer");
	ZVAL_NULL(&_5);
	ZEPHIR_CALL_CE_STATIC(&_6, phalcon_helper_arr_ce, "get", &_1, 12, &options, &_2, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("serializer"), &_6);
	zephir_update_property_zval(this_ptr, SL("serializerFactory"), factory);
	if (zephir_array_isset_string(&options, SL("prefix"))) {
		zephir_array_fetch_string(&_7$$3, &options, SL("prefix"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/AbstractAdapter.zep", 75 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("prefix"), &_7$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Flushes/clears the cache
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, clear) {

}

/**
 * Decrements a stored number
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, decrement) {

}

/**
 * Deletes data from the adapter
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, delete) {

}

/**
 * Reads data from the adapter
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, get) {

}

/**
 * Returns the adapter - connects to the storage if not connected
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getAdapter) {

}

/**
 * Returns all the keys stored
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getKeys) {

}

/**
 * Checks if an element exists in the cache
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, has) {

}

/**
 * Increments a stored number
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, increment) {

}

/**
 * Stores data in the adapter
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, set) {

}

/**
 * Returns the key requested, prefixed
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getPrefixedKey) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key = NULL, key_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	zephir_get_strval(&_0, key);
	ZEPHIR_CPY_WRT(key, &_0);
	zephir_read_property(&_1, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_1, key);
	RETURN_MM();

}

/**
 * Returns serialized data
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getSerializedData) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);

	ZEPHIR_SEPARATE_PARAM(content);


	zephir_read_property(&_0, this_ptr, SL("defaultSerializer"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_0, "")) {
		zephir_read_property(&_1$$3, this_ptr, SL("serializer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "setdata", NULL, 0, content);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, SL("serializer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(content, &_2$$3, "serialize", NULL, 0);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(content, 1, 0);
	RETURN_MM();

}

/**
 * Calculates the TTL for a cache item
 *
 * @param DateInterval|int|null $ttl
 *
 * @return int
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getTtl) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ttl, ttl_sub, dateTime, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ttl_sub);
	ZVAL_UNDEF(&dateTime);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ttl);



	if (Z_TYPE_P(ttl) == IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "lifetime");
	}
	_0 = Z_TYPE_P(ttl) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(ttl, zephir_get_internal_ce(SL("dateinterval")) TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&dateTime);
		object_init_ex(&dateTime, php_date_get_date_ce());
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "@0");
		ZEPHIR_CALL_METHOD(NULL, &dateTime, "__construct", NULL, 0, &_1$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$4, &dateTime, "add", NULL, 0, ttl);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_2$$4, "gettimestamp", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_LONG(zephir_get_intval(ttl));

}

/**
 * Returns unserialized data
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getUnserializedData) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &content, &defaultValue);

	ZEPHIR_SEPARATE_PARAM(content);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	if (!(zephir_is_true(content))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	zephir_read_property(&_0, this_ptr, SL("defaultSerializer"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_0, "")) {
		zephir_read_property(&_1$$4, this_ptr, SL("serializer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "unserialize", NULL, 0, content);
		zephir_check_call_status();
		zephir_read_property(&_2$$4, this_ptr, SL("serializer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(content, &_2$$4, "getdata", NULL, 0);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(content, 1, 0);
	RETURN_MM();

}

/**
 * Initializes the serializer
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, initSerializer) {

	zend_bool _1, _4;
	zval _0, _2, _3, _5, _6$$4, _7$$4, _8$$4;
	zval className;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("serializer"), PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) == IS_NULL;
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("serializerFactory"), PH_NOISY_CC | PH_READONLY);
		_1 = Z_TYPE_P(&_2) == IS_NULL;
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "A valid serializer is required", "phalcon/Storage/Adapter/AbstractAdapter.zep", 196);
		return;
	}
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("serializer"), PH_NOISY_CC);
	_4 = Z_TYPE_P(&_3) == IS_OBJECT;
	if (_4) {
		ZEPHIR_OBS_VAR(&_5);
		zephir_read_property(&_5, this_ptr, SL("serializer"), PH_NOISY_CC);
		_4 = zephir_instance_of_ev(&_5, phalcon_storage_serializer_serializerinterface_ce TSRMLS_CC);
	}
	if (!(_4)) {
		zephir_read_property(&_6$$4, this_ptr, SL("defaultSerializer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&className);
		zephir_fast_strtolower(&className, &_6$$4);
		zephir_read_property(&_7$$4, this_ptr, SL("serializerFactory"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_8$$4, &_7$$4, "newinstance", NULL, 0, &className);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("serializer"), &_8$$4);
	}
	ZEPHIR_MM_RESTORE();

}

