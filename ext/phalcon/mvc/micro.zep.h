
extern zend_class_entry *phalcon_mvc_micro_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro);

PHP_METHOD(Phalcon_Mvc_Micro, __construct);
PHP_METHOD(Phalcon_Mvc_Micro, after);
PHP_METHOD(Phalcon_Mvc_Micro, afterBinding);
PHP_METHOD(Phalcon_Mvc_Micro, before);
PHP_METHOD(Phalcon_Mvc_Micro, delete);
PHP_METHOD(Phalcon_Mvc_Micro, error);
PHP_METHOD(Phalcon_Mvc_Micro, finish);
PHP_METHOD(Phalcon_Mvc_Micro, get);
PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler);
PHP_METHOD(Phalcon_Mvc_Micro, getBoundModels);
PHP_METHOD(Phalcon_Mvc_Micro, getHandlers);
PHP_METHOD(Phalcon_Mvc_Micro, getModelBinder);
PHP_METHOD(Phalcon_Mvc_Micro, getReturnedValue);
PHP_METHOD(Phalcon_Mvc_Micro, getRouter);
PHP_METHOD(Phalcon_Mvc_Micro, getService);
PHP_METHOD(Phalcon_Mvc_Micro, getSharedService);
PHP_METHOD(Phalcon_Mvc_Micro, handle);
PHP_METHOD(Phalcon_Mvc_Micro, hasService);
PHP_METHOD(Phalcon_Mvc_Micro, head);
PHP_METHOD(Phalcon_Mvc_Micro, map);
PHP_METHOD(Phalcon_Mvc_Micro, mount);
PHP_METHOD(Phalcon_Mvc_Micro, notFound);
PHP_METHOD(Phalcon_Mvc_Micro, offsetExists);
PHP_METHOD(Phalcon_Mvc_Micro, offsetGet);
PHP_METHOD(Phalcon_Mvc_Micro, offsetSet);
PHP_METHOD(Phalcon_Mvc_Micro, offsetUnset);
PHP_METHOD(Phalcon_Mvc_Micro, options);
PHP_METHOD(Phalcon_Mvc_Micro, patch);
PHP_METHOD(Phalcon_Mvc_Micro, post);
PHP_METHOD(Phalcon_Mvc_Micro, put);
PHP_METHOD(Phalcon_Mvc_Micro, setActiveHandler);
PHP_METHOD(Phalcon_Mvc_Micro, setDI);
PHP_METHOD(Phalcon_Mvc_Micro, setModelBinder);
PHP_METHOD(Phalcon_Mvc_Micro, setResponseHandler);
PHP_METHOD(Phalcon_Mvc_Micro, setService);
PHP_METHOD(Phalcon_Mvc_Micro, stop);
zend_object *zephir_init_properties_Phalcon_Mvc_Micro(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_after, 0, 1, Phalcon\\Mvc\\Micro, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_after, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Micro", 0)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_afterbinding, 0, 1, Phalcon\\Mvc\\Micro, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_afterbinding, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Micro", 0)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_before, 0, 1, Phalcon\\Mvc\\Micro, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_before, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Micro", 0)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_delete, 0, 2, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_delete, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routePattern)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_error, 0, 1, Phalcon\\Mvc\\Micro, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_error, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Micro", 0)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_finish, 0, 1, Phalcon\\Mvc\\Micro, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_finish, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Micro", 0)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_get, 0, 2, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_get, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routePattern)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_getboundmodels, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_getboundmodels, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_gethandlers, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_gethandlers, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_getmodelbinder, 0, 0, Phalcon\\Mvc\\Model\\BinderInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_getmodelbinder, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\BinderInterface", 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_getrouter, 0, 0, Phalcon\\Mvc\\RouterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_getrouter, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\RouterInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_getservice, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_getsharedservice, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_handle, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_hasservice, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_hasservice, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_head, 0, 2, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_head, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routePattern)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_map, 0, 2, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_map, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routePattern)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_mount, 0, 1, Phalcon\\Mvc\\Micro, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_mount, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Micro", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_notfound, 0, 1, Phalcon\\Mvc\\Micro, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_notfound, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Micro", 0)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_offsetexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_offsetexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_offsetset, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_offsetset, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_offsetset, 0, 0, 2)
#define arginfo_phalcon_mvc_micro_offsetset NULL
#endif

	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_offsetunset, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_offsetunset, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_offsetunset, 0, 0, 1)
#define arginfo_phalcon_mvc_micro_offsetunset NULL
#endif

	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_options, 0, 2, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_options, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routePattern)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_patch, 0, 2, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_patch, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routePattern)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_post, 0, 2, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_post, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routePattern)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_put, 0, 2, Phalcon\\Mvc\\Router\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_put, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Router\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routePattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routePattern)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_setactivehandler, 0, 0, 1)
	ZEND_ARG_INFO(0, activeHandler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_setdi, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_setdi, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_setdi, 0, 0, 1)
#define arginfo_phalcon_mvc_micro_setdi NULL
#endif

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_setmodelbinder, 0, 1, Phalcon\\Mvc\\Micro, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_setmodelbinder, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Micro", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, modelBinder, Phalcon\\Mvc\\Model\\BinderInterface, 0)
	ZEND_ARG_INFO(0, cache)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_setresponsehandler, 0, 1, Phalcon\\Mvc\\Micro, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_setresponsehandler, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Micro", 0)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_micro_setservice, 0, 2, Phalcon\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_setservice, 0, 2, IS_OBJECT, "Phalcon\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
	ZEND_ARG_INFO(0, definition)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, shared, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, shared)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_micro_method_entry) {
	PHP_ME(Phalcon_Mvc_Micro, __construct, arginfo_phalcon_mvc_micro___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Micro, after, arginfo_phalcon_mvc_micro_after, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, afterBinding, arginfo_phalcon_mvc_micro_afterbinding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, before, arginfo_phalcon_mvc_micro_before, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, delete, arginfo_phalcon_mvc_micro_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, error, arginfo_phalcon_mvc_micro_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, finish, arginfo_phalcon_mvc_micro_finish, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, get, arginfo_phalcon_mvc_micro_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getActiveHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getBoundModels, arginfo_phalcon_mvc_micro_getboundmodels, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getHandlers, arginfo_phalcon_mvc_micro_gethandlers, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getModelBinder, arginfo_phalcon_mvc_micro_getmodelbinder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getReturnedValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getRouter, arginfo_phalcon_mvc_micro_getrouter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getService, arginfo_phalcon_mvc_micro_getservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getSharedService, arginfo_phalcon_mvc_micro_getsharedservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, handle, arginfo_phalcon_mvc_micro_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, hasService, arginfo_phalcon_mvc_micro_hasservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, head, arginfo_phalcon_mvc_micro_head, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, map, arginfo_phalcon_mvc_micro_map, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, mount, arginfo_phalcon_mvc_micro_mount, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, notFound, arginfo_phalcon_mvc_micro_notfound, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, offsetExists, arginfo_phalcon_mvc_micro_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, offsetGet, arginfo_phalcon_mvc_micro_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, offsetSet, arginfo_phalcon_mvc_micro_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, offsetUnset, arginfo_phalcon_mvc_micro_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, options, arginfo_phalcon_mvc_micro_options, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, patch, arginfo_phalcon_mvc_micro_patch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, post, arginfo_phalcon_mvc_micro_post, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, put, arginfo_phalcon_mvc_micro_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, setActiveHandler, arginfo_phalcon_mvc_micro_setactivehandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, setDI, arginfo_phalcon_mvc_micro_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, setModelBinder, arginfo_phalcon_mvc_micro_setmodelbinder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, setResponseHandler, arginfo_phalcon_mvc_micro_setresponsehandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, setService, arginfo_phalcon_mvc_micro_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
