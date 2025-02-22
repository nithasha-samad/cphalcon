
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
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 */
/**
 * Holds the payload
 */
ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_Payload) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Domain\\Payload, Payload, phalcon, domain_payload_payload, phalcon_domain_payload_payload_method_entry, 0);

	/**
	 * Extra information
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_domain_payload_payload_ce, SL("extras"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Input
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_domain_payload_payload_ce, SL("input"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Messages
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_domain_payload_payload_ce, SL("messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Status
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_domain_payload_payload_ce, SL("status"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Output
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_domain_payload_payload_ce, SL("output"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_domain_payload_payload_ce TSRMLS_CC, 1, phalcon_domain_payload_payloadinterface_ce);
	return SUCCESS;

}

/**
 * Extra information
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, getExtras) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "extras");

}

/**
 * Input
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, getInput) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "input");

}

/**
 * Messages
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, getMessages) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "messages");

}

/**
 * Status
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, getStatus) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "status");

}

/**
 * Output
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, getOutput) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "output");

}

/**
 * Sets arbitrary extra domain information.
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, setExtras) {

	zval *extras, extras_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extras_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &extras);



	zephir_update_property_zval(this_ptr, SL("extras"), extras);
	RETURN_THISW();

}

/**
 * Sets the domain input.
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, setInput) {

	zval *input, input_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &input);



	zephir_update_property_zval(this_ptr, SL("input"), input);
	RETURN_THISW();

}

/**
 * Sets the domain messages.
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, setMessages) {

	zval *messages, messages_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &messages);



	zephir_update_property_zval(this_ptr, SL("messages"), messages);
	RETURN_THISW();

}

/**
 * Sets the domain output.
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, setOutput) {

	zval *output, output_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&output_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &output);



	zephir_update_property_zval(this_ptr, SL("output"), output);
	RETURN_THISW();

}

/**
 * Sets the payload status.
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, setStatus) {

	zval *status, status_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&status_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &status);



	zephir_update_property_zval(this_ptr, SL("status"), status);
	RETURN_THISW();

}

