
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * `Phalcon\Collection` is a supercharged object oriented array. It implements [ArrayAccess](https://www.php.net/manual/en/class.arrayaccess.php), [Countable](https://www.php.net/manual/en/class.countable.php), [IteratorAggregate](https://www.php.net/manual/en/class.iteratoraggregate.php), [JsonSerializable](https://www.php.net/manual/en/class.jsonserializable.php), [Serializable](https://www.php.net/manual/en/class.serializable.php)
 *
 * It can be used in any part of the application that needs collection of data
 * Such implementations are for instance accessing globals `$_GET`, `$_POST`
 * etc.
 */
ZEPHIR_INIT_CLASS(Phalcon_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Collection, phalcon, collection, phalcon_collection_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_collection_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_collection_ce, SL("insensitive"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_collection_ce, SL("lowerKeys"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_collection_ce->create_object = zephir_init_properties_Phalcon_Collection;

	zend_class_implements(phalcon_collection_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_collection_ce TSRMLS_CC, 1, zend_ce_aggregate);
	zend_class_implements(phalcon_collection_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
	zend_class_implements(phalcon_collection_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Collection constructor.
 */
PHP_METHOD(Phalcon_Collection, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool insensitive;
	zval *data_param = NULL, *insensitive_param = NULL, __$true, __$false;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data_param, &insensitive_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		insensitive = zephir_get_boolval(insensitive_param);
	}


	if (insensitive) {
		zephir_update_property_zval(this_ptr, SL("insensitive"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("insensitive"), &__$false);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic getter to get an element from the collection
 */
PHP_METHOD(Phalcon_Collection, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	zephir_get_strval(&element, element_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &element);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic isset to check whether an element exists or not
 */
PHP_METHOD(Phalcon_Collection, __isset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	zephir_get_strval(&element, element_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &element);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic setter to assign values to an element
 */
PHP_METHOD(Phalcon_Collection, __set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element_param = NULL, *value, value_sub;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element_param, &value);

	zephir_get_strval(&element, element_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic unset to remove an element from the collection
 */
PHP_METHOD(Phalcon_Collection, __unset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	zephir_get_strval(&element, element_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, &element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears the internal collection
 */
PHP_METHOD(Phalcon_Collection, clear) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("data"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, SL("lowerKeys"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Count elements of an object.
 * See [count](https://php.net/manual/en/countable.count.php)
 */
PHP_METHOD(Phalcon_Collection, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * Get the element from the collection
 */
PHP_METHOD(Phalcon_Collection, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *element_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, key, _0, _2, _1$$3, _3$$4, _4$$4, _5$$4;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &element_param, &defaultValue);

	zephir_get_strval(&element, element_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("insensitive"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_strtolower(&_1$$3, &element);
		zephir_get_strval(&element, &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, SL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
	if (EXPECTED(zephir_array_isset(&_2, &element))) {
		zephir_read_property(&_3$$4, this_ptr, SL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&key, &_3$$4, &element, PH_NOISY | PH_READONLY, "phalcon/Collection.zep", 121 TSRMLS_CC);
		zephir_read_property(&_4$$4, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_5$$4, &_4$$4, &key, PH_NOISY | PH_READONLY, "phalcon/Collection.zep", 123 TSRMLS_CC);
		RETURN_CTOR(&_5$$4);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Returns the iterator of the class
 */
PHP_METHOD(Phalcon_Collection, getIterator) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SL("arrayiterator")));
	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the element from the collection
 */
PHP_METHOD(Phalcon_Collection, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *element_param = NULL, _0, _2, _1$$3;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	zephir_get_strval(&element, element_param);


	zephir_read_property(&_0, this_ptr, SL("insensitive"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_strtolower(&_1$$3, &element);
		zephir_get_strval(&element, &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, SL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_2, &element));

}

/**
 * Initialize internal array
 */
PHP_METHOD(Phalcon_Collection, init) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, key, value, *_0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	zephir_is_iterable(&data, 0, "phalcon/Collection.zep", 159);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", &_4, 0, &key, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", &_4, 0, &key, &value);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Specify data which should be serialized to JSON
 * See [jsonSerialize](https://php.net/manual/en/jsonserializable.jsonserialize.php)
 */
PHP_METHOD(Phalcon_Collection, jsonSerialize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "data");

}

/**
 * Whether a offset exists
 * See [offsetExists](https://php.net/manual/en/arrayaccess.offsetexists.php)
 */
PHP_METHOD(Phalcon_Collection, offsetExists) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);

	ZEPHIR_SEPARATE_PARAM(element);


	zephir_get_strval(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, element);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Offset to retrieve
 * See [offsetGet](https://php.net/manual/en/arrayaccess.offsetget.php)
 */
PHP_METHOD(Phalcon_Collection, offsetGet) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);

	ZEPHIR_SEPARATE_PARAM(element);


	zephir_get_strval(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, element);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Offset to set
 * See [offsetSet](https://php.net/manual/en/arrayaccess.offsetset.php)
 */
PHP_METHOD(Phalcon_Collection, offsetSet) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &value);

	ZEPHIR_SEPARATE_PARAM(element);


	zephir_get_strval(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Offset to unset
 * See [offsetUnset](https://php.net/manual/en/arrayaccess.offsetunset.php)
 */
PHP_METHOD(Phalcon_Collection, offsetUnset) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);

	ZEPHIR_SEPARATE_PARAM(element);


	zephir_get_strval(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Delete the element from the collection
 */
PHP_METHOD(Phalcon_Collection, remove) {

	zval lowerKeys, data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element_param = NULL, key, _0, _1$$3, _3$$3, _4$$3, _2$$4;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&lowerKeys);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	zephir_get_strval(&element, element_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &element);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("insensitive"), PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(zephir_is_true(&_1$$3))) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_fast_strtolower(&_2$$4, &element);
			zephir_get_strval(&element, &_2$$4);
		}
		zephir_read_property(&_3$$3, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&data, &_3$$3);
		zephir_read_property(&_4$$3, this_ptr, SL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&lowerKeys, &_4$$3);
		zephir_array_fetch(&key, &lowerKeys, &element, PH_NOISY | PH_READONLY, "phalcon/Collection.zep", 229 TSRMLS_CC);
		zephir_array_unset(&lowerKeys, &element, PH_SEPARATE);
		zephir_array_unset(&data, &key, PH_SEPARATE);
		zephir_update_property_zval(this_ptr, SL("data"), &data);
		zephir_update_property_zval(this_ptr, SL("lowerKeys"), &lowerKeys);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set an element in the collection
 */
PHP_METHOD(Phalcon_Collection, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element_param = NULL, *value, value_sub;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element_param, &value);

	zephir_get_strval(&element, element_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, &element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * String representation of object
 * See [serialize](https://php.net/manual/en/serializable.serialize.php)
 */
PHP_METHOD(Phalcon_Collection, serialize) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 10, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the object in an array format
 */
PHP_METHOD(Phalcon_Collection, toArray) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "data");

}

/**
 * Returns the object in a JSON format
 *
 * The default string uses the following options for json_encode
 *
 * `JSON_HEX_TAG`, `JSON_HEX_APOS`, `JSON_HEX_AMP`, `JSON_HEX_QUOT`,
 * `JSON_UNESCAPED_SLASHES`
 *
 * See [rfc4627](https://www.ietf.org/rfc/rfc4627.txt)
 */
PHP_METHOD(Phalcon_Collection, toJson) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, _0, _1;
	zend_long options, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		options = 79;
	} else {
		options = zephir_get_intval(options_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, options);
	zephir_json_encode(return_value, &_0, zephir_get_intval(&_1) );
	RETURN_MM();

}

/**
 * Constructs the object
 * See [unserialize](https://php.net/manual/en/serializable.unserialize.php)
 */
PHP_METHOD(Phalcon_Collection, unserialize) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serialized = NULL, serialized_sub, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serialized_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serialized);

	ZEPHIR_SEPARATE_PARAM(serialized);


	zephir_get_strval(&_0, serialized);
	ZEPHIR_CPY_WRT(serialized, &_0);
	ZEPHIR_CALL_FUNCTION(&data, "unserialize", NULL, 11, serialized);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Internal method to set data
 */
PHP_METHOD(Phalcon_Collection, setData) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *element_param = NULL, *value, value_sub, key, _0, _1;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element_param, &value);

	zephir_get_strval(&element, element_param);


	zephir_read_property(&_0, this_ptr, SL("insensitive"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_fast_strtolower(&_1, &element);
		ZEPHIR_CPY_WRT(&key, &_1);
	} else {
		ZEPHIR_CPY_WRT(&key, &element);
	}
	zephir_update_property_array(this_ptr, SL("data"), &element, value);
	zephir_update_property_array(this_ptr, SL("lowerKeys"), &key, &element);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Collection(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("lowerKeys"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("data"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

