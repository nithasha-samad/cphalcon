
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
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
 * Dispatching is the process of taking the request object, extracting the
 * module name, controller name, action name, and optional parameters contained
 * in it, and then instantiating a controller and calling an action of that
 * controller.
 *
 *```php
 * $di = new \Phalcon\Di();
 *
 * $dispatcher = new \Phalcon\Mvc\Dispatcher();
 *
 * $dispatcher->setDI($di);
 *
 * $dispatcher->setControllerName("posts");
 * $dispatcher->setActionName("index");
 * $dispatcher->setParams([]);
 *
 * $controller = $dispatcher->dispatch();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Dispatcher, phalcon, mvc_dispatcher, phalcon_dispatcher_abstractdispatcher_ce, phalcon_mvc_dispatcher_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("defaultHandler"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("handlerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_dispatcher_ce TSRMLS_CC, 1, phalcon_mvc_dispatcherinterface_ce);
	return SUCCESS;

}

/**
 * Forwards the execution flow to another controller/action.
 *
 * ```php
 * use Phalcon\Events\Event;
 * use Phalcon\Mvc\Dispatcher;
 * use App\Backend\Bootstrap as Backend;
 * use App\Frontend\Bootstrap as Frontend;
 *
 * // Registering modules
 * $modules = [
 *     "frontend" => [
 *         "className" => Frontend::class,
 *         "path"      => __DIR__ . "/app/Modules/Frontend/Bootstrap.php",
 *         "metadata"  => [
 *             "controllersNamespace" => "App\Frontend\Controllers",
 *         ],
 *     ],
 *     "backend" => [
 *         "className" => Backend::class,
 *         "path"      => __DIR__ . "/app/Modules/Backend/Bootstrap.php",
 *         "metadata"  => [
 *             "controllersNamespace" => "App\Backend\Controllers",
 *         ],
 *     ],
 * ];
 *
 * $application->registerModules($modules);
 *
 * // Setting beforeForward listener
 * $eventsManager  = $di->getShared("eventsManager");
 *
 * $eventsManager->attach(
 *     "dispatch:beforeForward",
 *     function(Event $event, Dispatcher $dispatcher, array $forward) use ($modules) {
 *         $metadata = $modules[$forward["module"]]["metadata"];
 *
 *         $dispatcher->setModuleName(
 *             $forward["module"]
 *         );
 *
 *         $dispatcher->setNamespaceName(
 *             $metadata["controllersNamespace"]
 *         );
 *     }
 * );
 *
 * // Forward
 * $this->dispatcher->forward(
 *     [
 *         "module"     => "backend",
 *         "controller" => "posts",
 *         "action"     => "index",
 *     ]
 * );
 * ```
 *
 * @param array forward
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, forward) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *forward, forward_sub, eventsManager, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&forward_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &forward);



	zephir_read_property(&_0, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "dispatch:beforeForward");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_1$$3, this_ptr, forward);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_dispatcher_ce, getThis(), "forward", &_2, 0, forward);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the active controller in the dispatcher
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getActiveController) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeHandler");

}

/**
 * Possible controller class name that will be located to dispatch the
 * request
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerClass) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethandlerclass", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets last dispatched controller name
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handlerName");

}

/**
 * Returns the latest dispatched controller
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getLastController) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "lastHandler");

}

/**
 * Gets previous dispatched action name
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousActionName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "previousActionName");

}

/**
 * Gets previous dispatched controller name
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousControllerName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "previousHandlerName");

}

/**
 * Gets previous dispatched namespace name
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousNamespaceName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "previousNamespaceName");

}

/**
 * Sets the controller name to be dispatched
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *controllerName_param = NULL;
	zval controllerName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerName_param);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(&controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerName);
		ZVAL_EMPTY_STRING(&controllerName);
	}


	zephir_update_property_zval(this_ptr, SL("handlerName"), &controllerName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default controller suffix
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *controllerSuffix_param = NULL;
	zval controllerSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerSuffix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerSuffix_param);

	if (UNEXPECTED(Z_TYPE_P(controllerSuffix_param) != IS_STRING && Z_TYPE_P(controllerSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerSuffix' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerSuffix_param) == IS_STRING)) {
		zephir_get_strval(&controllerSuffix, controllerSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerSuffix);
		ZVAL_EMPTY_STRING(&controllerSuffix);
	}


	zephir_update_property_zval(this_ptr, SL("handlerSuffix"), &controllerSuffix);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default controller name
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *controllerName_param = NULL;
	zval controllerName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerName_param);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(&controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerName);
		ZVAL_EMPTY_STRING(&controllerName);
	}


	zephir_update_property_zval(this_ptr, SL("defaultHandler"), &controllerName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles a user exception
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, handleException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, eventsManager, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &exception);



	zephir_read_property(&_0, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "dispatch:beforeException");
		ZEPHIR_CALL_METHOD(&_1$$3, &eventsManager, "fire", NULL, 0, &_2$$3, this_ptr, exception);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Throws an internal exception
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, throwDispatchException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long exceptionCode, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *exceptionCode_param = NULL, container, response, exception, _0, _6, _7, _1$$3, _2$$3, _4$$3, _5$$3;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &exceptionCode_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!exceptionCode_param) {
		exceptionCode = 0;
	} else {
		exceptionCode = zephir_get_intval(exceptionCode_param);
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_dispatcher_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "the 'response' service");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_mvc_dispatcher_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 5, &_2$$3, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Dispatcher.zep", 230 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "response");
	ZEPHIR_CALL_METHOD(&_6, &container, "getshared", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&response, &_6);
	ZVAL_LONG(&_0, 404);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "Not Found");
	ZEPHIR_CALL_METHOD(NULL, &response, "setstatuscode", NULL, 0, &_0, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&exception);
	object_init_ex(&exception, phalcon_mvc_dispatcher_exception_ce);
	ZVAL_LONG(&_0, exceptionCode);
	ZEPHIR_CALL_METHOD(NULL, &exception, "__construct", NULL, 5, &message, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "handleexception", NULL, 0, &exception);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_6)) {
		RETURN_MM_BOOL(0);
	}
	zephir_throw_exception_debug(&exception, "phalcon/Mvc/Dispatcher.zep", 252 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

