
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Represents a single annotation in an annotations collection
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Annotation) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Annotation, phalcon, annotations_annotation, phalcon_annotations_annotation_method_entry, 0);

	/**
	 * Annotation Arguments
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("arguments"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Annotation ExprArguments
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("exprArguments"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Annotation Name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_annotations_annotation_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Annotations\Annotation constructor
 */
PHP_METHOD(Phalcon_Annotations_Annotation, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *reflectionData_param = NULL, name, exprArguments, argument, resolvedArgument, _0, *_1$$3, _2$$3, _3$$4, _5$$7;
	zval reflectionData, arguments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflectionData);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&exprArguments);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&resolvedArgument);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &reflectionData_param);

	ZEPHIR_OBS_COPY_OR_DUP(&reflectionData, reflectionData_param);


	zephir_array_fetch_string(&_0, &reflectionData, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 50 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("name"), &_0);
	ZEPHIR_OBS_VAR(&exprArguments);
	if (zephir_array_isset_string_fetch(&exprArguments, &reflectionData, SL("arguments"), 0)) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
		zephir_is_iterable(&exprArguments, 0, "phalcon/Annotations/Annotation.zep", 70);
		if (Z_TYPE_P(&exprArguments) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&exprArguments), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&argument);
				ZVAL_COPY(&argument, _1$$3);
				zephir_array_fetch_string(&_3$$4, &argument, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 61 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&resolvedArgument, this_ptr, "getexpression", &_4, 0, &_3$$4);
				zephir_check_call_status();
				if (zephir_array_isset_string_fetch(&name, &argument, SL("name"), 1)) {
					zephir_array_update_zval(&arguments, &name, &resolvedArgument, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_append(&arguments, &resolvedArgument, PH_SEPARATE, "phalcon/Annotations/Annotation.zep", 66);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &exprArguments, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, &exprArguments, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&argument, &exprArguments, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_fetch_string(&_5$$7, &argument, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 61 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&resolvedArgument, this_ptr, "getexpression", &_4, 0, &_5$$7);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&name);
					if (zephir_array_isset_string_fetch(&name, &argument, SL("name"), 0)) {
						zephir_array_update_zval(&arguments, &name, &resolvedArgument, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&arguments, &resolvedArgument, PH_SEPARATE, "phalcon/Annotations/Annotation.zep", 66);
					}
				ZEPHIR_CALL_METHOD(NULL, &exprArguments, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&argument);
		zephir_update_property_zval(this_ptr, SL("arguments"), &arguments);
		zephir_update_property_zval(this_ptr, SL("exprArguments"), &exprArguments);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns an argument in a specific position
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getArgument) {

	zval *position, position_sub, argument, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&position_sub);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &position);



	zephir_read_property(&_0, this_ptr, SL("arguments"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&argument, &_0, position, 1 TSRMLS_CC)) {
		RETURN_CTORW(&argument);
	}

}

/**
 * Returns the expression arguments
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getArguments) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "arguments");

}

/**
 * Returns the expression arguments without resolving
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getExprArguments) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "exprArguments");

}

/**
 * Resolves an annotation expression
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getExpression) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, value, item, resolvedItem, arrayValue, name, type, _0$$7, *_1$$7, _2$$7, _3$$8, _5$$11, _6$$15, _7$$15;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&resolvedItem);
	ZVAL_UNDEF(&arrayValue);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0$$7);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$15);
	ZVAL_UNDEF(&_7$$15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_OBS_VAR(&type);
	zephir_array_fetch_string(&type, &expr, SL("type"), PH_NOISY, "phalcon/Annotations/Annotation.zep", 110 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(&type, 301) || ZEPHIR_IS_LONG(&type, 302) || ZEPHIR_IS_LONG(&type, 303) || ZEPHIR_IS_LONG(&type, 307)) {
			ZEPHIR_OBS_VAR(&value);
			zephir_array_fetch_string(&value, &expr, SL("value"), PH_NOISY, "phalcon/Annotations/Annotation.zep", 117 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 304)) {
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_NULL(&value);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 305)) {
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_BOOL(&value, 0);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 306)) {
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_BOOL(&value, 1);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 308)) {
			ZEPHIR_INIT_VAR(&arrayValue);
			array_init(&arrayValue);
			zephir_array_fetch_string(&_0$$7, &expr, SL("items"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 135 TSRMLS_CC);
			zephir_is_iterable(&_0$$7, 0, "phalcon/Annotations/Annotation.zep", 147);
			if (Z_TYPE_P(&_0$$7) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0$$7), _1$$7)
				{
					ZEPHIR_INIT_NVAR(&item);
					ZVAL_COPY(&item, _1$$7);
					zephir_array_fetch_string(&_3$$8, &item, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 138 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&resolvedItem, this_ptr, "getexpression", &_4, 141, &_3$$8);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&name);
					if (zephir_array_isset_string_fetch(&name, &item, SL("name"), 0)) {
						zephir_array_update_zval(&arrayValue, &name, &resolvedItem, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&arrayValue, &resolvedItem, PH_SEPARATE, "phalcon/Annotations/Annotation.zep", 143);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0$$7, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$7, &_0$$7, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&item, &_0$$7, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_fetch_string(&_5$$11, &item, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Annotations/Annotation.zep", 138 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&resolvedItem, this_ptr, "getexpression", &_4, 141, &_5$$11);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&name);
						if (zephir_array_isset_string_fetch(&name, &item, SL("name"), 0)) {
							zephir_array_update_zval(&arrayValue, &name, &resolvedItem, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_append(&arrayValue, &resolvedItem, PH_SEPARATE, "phalcon/Annotations/Annotation.zep", 143);
						}
					ZEPHIR_CALL_METHOD(NULL, &_0$$7, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&item);
			RETURN_CCTOR(&arrayValue);
		}
		if (ZEPHIR_IS_LONG(&type, 300)) {
			object_init_ex(return_value, phalcon_annotations_annotation_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 142, &expr);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_6$$15);
		object_init_ex(&_6$$15, phalcon_annotations_exception_ce);
		ZEPHIR_INIT_VAR(&_7$$15);
		ZEPHIR_CONCAT_SVS(&_7$$15, "The expression ", &type, " is unknown");
		ZEPHIR_CALL_METHOD(NULL, &_6$$15, "__construct", NULL, 5, &_7$$15);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$15, "phalcon/Annotations/Annotation.zep", 153 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	RETURN_CCTOR(&value);

}

/**
 * Returns the annotation's name
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * Returns a named argument
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getNamedArgument) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, argument, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("arguments"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&argument, &_0, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(&argument);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a named parameter
 */
PHP_METHOD(Phalcon_Annotations_Annotation, getNamedParameter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getnamedargument", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an argument in a specific position
 */
PHP_METHOD(Phalcon_Annotations_Annotation, hasArgument) {

	zval *position, position_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&position_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &position);



	zephir_read_property(&_0, this_ptr, SL("arguments"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, position));

}

/**
 * Returns the number of arguments that the annotation has
 */
PHP_METHOD(Phalcon_Annotations_Annotation, numberArguments) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("arguments"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

