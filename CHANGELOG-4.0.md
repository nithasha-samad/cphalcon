# [4.0.0-rc.1](https://github.com/phalcon/cphalcon/releases/tag/v4.0.0-rc.1) (2019-09-23)

## Added
- Added optional boolean parameter to `Phalcon\Http\Request::getURI()` (as well as its interface) which indicates whether or not the method should return only the path without the query string

## Changed
- Changed `Phalcon\Url::get` to use implementation behind `Phalcon\Helper\Str::reduceSlashes` to reduce slashes [#14331](https://github.com/phalcon/cphalcon/issues/14331)
- Changed `Phalcon\Http\Headers\set()` to return self for a more fluent interface
- Changed `Phalcon\Assets\Manager`, `Phalcon\Cli\Router`, `Phalcon\Dispatcher\AbstractDispatcher`, `Phalcon\Html\Tag`,  `Phalcon\Http\Cookie`, `Phalcon\Http\Request`, `Phalcon\Http\Response\Cookies`, `Phalcon\Mvc\Model`, `Phalcon\Mvc\Router`, `Phalcon\Security`, `Phalcon\Session\Manager` to use `Phalcon\Di\AbstractDiAware` for container functionality [#14351](https://github.com/phalcon/cphalcon/pull/14351)
- Changed `Phalcon\Security` to allow `session` and `request` in the constructor [#14351](https://github.com/phalcon/cphalcon/pull/14351)
- Changed `Phalcon\Session\Manager` to allow `router` in the constructor [#14351](https://github.com/phalcon/cphalcon/pull/14351)
- Changed `Phalcon\Flash\Direct` to allow `escaper` in the constructor [#14349](https://github.com/phalcon/cphalcon/issues/14349)
- Changed `Phalcon\Flash\Session` to allow `escaper` in the constructor [#14349](https://github.com/phalcon/cphalcon/issues/14349)
- Changed `Phalcon\Di\AbstractDIAware` to `Phalcon\Di\AbstractInjectionAware` [#14359](https://github.com/phalcon/cphalcon/issues/14359)
- Changed `Phalcon\Di\Service` to use DI to initialize `string` based services when possible [#14342](https://github.com/phalcon/cphalcon/pull/14342)
- Changed `Phalcon\Mvc\Router\Annotations` to be able to handle patterns az prefixes [#14259](https://github.com/phalcon/cphalcon/pull/14259)
- Changed `Phalcon\Mvc\Router\Group::routes` to an array as default [#14259](https://github.com/phalcon/cphalcon/pull/14259)
- Changed `Phalcon\Mvc\Model::assign` changed order of parameters to $data, $whiteList, $dataColumnMap [#14386](https://github.com/phalcon/cphalcon/pull/14386)
- Changed `Phalcon\Helper\Arr::arrayToObject` to `toObject` [#14389](https://github.com/phalcon/cphalcon/pull/14389)
- Changed `Phalcon\Events\EventsAwareInterface::getEventsManager` and `Phalcon\Di\Injectable::getEventsManager` to return also `null` [#14404](https://github.com/phalcon/cphalcon/pull/14404)
- Changed `Phalcon\Logger\Adapter\AbstractAdapter::add` to now return `this` [#14404](https://github.com/phalcon/cphalcon/pull/14404)
- Changed `Phalcon\Mvc\RouterInterface` methods signature to return `RouteInterface` instead of `void`:
  - `Phalcon\Mvc\RouterInterface::setDefaultAction`
  - `Phalcon\Mvc\RouterInterface::setDefaultAction`
  - `Phalcon\Mvc\RouterInterface::setDefaultController`
  - `Phalcon\Mvc\RouterInterface::setDefaultModule`
  - `Phalcon\Mvc\RouterInterface::setDefaults`
- Changed return types for following interfaces:
  - `Phalcon\Mvc\Router\RouteInterface::setName` from `void` to `RouteInterface`
  - `Phalcon\Mvc\Router\RouteInterface::via` from `void` to `RouteInterface`
  - `Phalcon\Session\ManagerInterface::__get` from `void` to `var`

## Fixed
- Fixed `Phalcon\Helper\Str::includes` to return correct result [#14301](https://github.com/phalcon/cphalcon/issues/14301)
- Fixed `Phalcon\Logger` moved to correct namespace [#14263](https://github.com/phalcon/cphalcon/issues/14263)
- Fixed `Phalcon\Session\Adapter\AbstractAdapter::read()` to return ""(empty string) when `Session/Adapter/*::get()` returns null [#14314](https://github.com/phalcon/cphalcon/issues/14314)
- Fixed `Phalcon\Cache\Exception` to extend Phalcon\Exception
- Fixed `Phalcon\Cache\InvalidArgumentException` to extend Phalcon\Exception
- Fixed `Phalcon\Collection\Exception` to extend Phalcon\Exception
- Fixed `Phalcon\Storage\Adapter\AbstractAdapter::initSerializer` to throw exception if `null === $this->serializerFactory && null === $this->serializer` [#14324](https://github.com/phalcon/cphalcon/issues/14324)
- Fixed `Phalcon\Storage\Adapter\Redis::getAdapter()` to provide a persistent id for redis persistent connection [#14334](https://github.com/phalcon/cphalcon/issues/14334)
- Fixed `Phalcon\Session\Adapter\Stream` to not override configured save path [#14265](https://github.com/phalcon/cphalcon/issues/14265)
- Fixed `Phalcon\Http\Response::setFileToSend` to properly handle non-ASCII filenames [#13919](https://github.com/phalcon/cphalcon/issues/13919)
- Fixed `Phalcon\Security::getSessionToken` return value [#14346](https://github.com/phalcon/cphalcon/issues/14346)
- Fixed `Phalcon\Flash\*` interfaces for `message()` to return `string/null` [#14349](https://github.com/phalcon/cphalcon/issues/14349)
- Fixed `Phalcon\Paginator\Adapter\AbstractAdapter` throw exception if `limit <= 0` [#14303](https://github.com/phalcon/cphalcon/issues/14303)
- Fixed `Phalcon\Mvc\Model\Query\Builder` Empty table alias in query [#14366](https://github.com/phalcon/cphalcon/issues/14366)
- Fixed `Phalcon\Db\Adapter\PdoFactory` to reference the correct interface [#14381](https://github.com/phalcon/cphalcon/pull/14381)
- Fixed `Phalcon\Db\Dialect\Mysql` Fixed missing schema in constraint for create table [#14378](https://github.com/phalcon/cphalcon/issues/14378)
- Fixed `Phalcon\Mvc\Model::hasChanged()` and `getChangedFields()` returning false values when `castOnHydrate` option is on. [#14376](https://github.com/phalcon/cphalcon/issues/14376)
- Fixed `Phalcon\Mvc\Model::create()` Using write connection to prevent replica lag [#14256](https://github.com/phalcon/cphalcon/issues/14256)
- Fixed return types for following methods to satisfy interface declaration:
  - `Phalcon\Acl\Adapter\AbstractAdapter::setDefaultAction`
  - `Phalcon\Application\AbstractApplication::setEventsManager`
  - `Phalcon\Firewall\Adapter\AbstractAdapter::setAlwaysResolvingRole`
  - `Phalcon\Firewall\Adapter\AbstractAdapter::setEventsManager`
  - `Phalcon\Mvc\Router::handle`
  - `Phalcon\Storage\Serializer\AbstractSerializer::getData`
  - `Phalcon\Storage\Serializer\AbstractSerializer::setData`
  - `Phalcon\Mvc\Dispatcher::forward`
  - `Phalcon\Mvc\Model::setConnectionService`
  - `Phalcon\Mvc\Model::setReadConnectionService`
  - `Phalcon\Mvc\Model::setWriteConnectionService`
  - `Phalcon\Mvc\Model\Query\Builder::setDI`
  - `Phalcon\Mvc\Router\Annotations::handle`
  - `Phalcon\Session\Bag::set`
  - `Phalcon\Session\Manager::remove`
- Fixed `Phalcon\Di::remove()` to remove service. [#14396](https://github.com/phalcon/cphalcon/issues/14396)

## Removed
- Removed `Phalcon\Plugin` - duplicate of `Phalcon\DI\Injectable` [#14359](https://github.com/phalcon/cphalcon/issues/14359)
- Removed `Phalcon\Mvc\Collection` and all related references. 4.0 will not support mongo as it is being re-implemented to take advantage of the latest Mongo driver (see [#13697](https://github.com/phalcon/cphalcon/issues/13697)) [#14361](https://github.com/phalcon/cphalcon/pull/14361)
- Removed `Phalcon\Session\Manager::registerHandler` - duplicate functionality [#14381](https://github.com/phalcon/cphalcon/pull/14381)
- Removed `Phalcon\Html\Tag` - duplicate functionality [#14381](https://github.com/phalcon/cphalcon/pull/14381)
- Removed `void` return type for all constructors [#14401](https://github.com/phalcon/cphalcon/pull/14401)

# [4.0.0-beta.2](https://github.com/phalcon/cphalcon/releases/tag/v4.0.0-beta.2) (2019-08-18)

## Fixed
- Fixed missing imports in `Phalcon\Db\Adapter\AbstractAdapter`, `Phalcon\Db\Adapter\AdapterInterface`, `Phalcon\Db\Result\Pdo`, `Phalcon\Html\Tag` and `Phalcon\Tag\Select`. [#14249](https://github.com/phalcon/cphalcon/issues/14249)
- Fixed `isSerializable` in `Phalcon\Storage\Serializer\AbstractSerializer` to return true when the data is seriazable and false when it's not.
- Fixed `Phalcon\Storage\Adapter\Redis::delete()` and `Phalcon\Storage\Adapter\Redis::getKeys()` deprecated warning from php-redis [#14281](https://github.com/phalcon/cphalcon/issues/14281)
- Fixed `Phalcon\Mvc\Model\ResultSet::Update()` to return correct status [#14291](https://github.com/phalcon/cphalcon/issues/14291)
- `Phalcon\Mvc\Collection::cancelOperation()` now returns `true` on success.
- Fixed `Phalcon\Application\AbstractApplication` interfaces for `registerModules()`, `setDefaultModule()` and `setEventsManager()` [#14293](https://github.com/phalcon/cphalcon/issues/14293)
- Fixed `Phalcon\Paginator\Adapter\QueryBuilder` to throw exception on incorrect parameter [#14299](https://github.com/phalcon/cphalcon/issues/14299)

## Removed
- Removed dead libsodium-related code. It was never called in PHP >= 7.0.

# [4.0.0-beta.1](https://github.com/phalcon/cphalcon/releases/tag/v4.0.0-beta.1) (2019-07-14)

## Added
- Added `Phalcon\Factory\Exception` for factory exceptions. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Added `Phalcon\Filter\FilterInterface` for custom filter implementations. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Added `Phalcon\Db\Adapter\PdoFactory`: Factory to create PDO adapters. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Added `Phalcon\Image\ImageFactory`: Factory to create image adapters. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Added `Phalcon\Logger\LoggerFactory`: Factory to create logger objects. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Added `Phalcon\Translate\InterpolatorFactory`: Factory to create interpolator objects. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Added `Phalcon\Translate\TranslateFactory`: Factory to create translate objects. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Added `Phalcon\Domain\Payload` to help in transferring messages between layers of the application. [#14123](https://github.com/phalcon/cphalcon/issues/14123)
- Added `Phalcon\Domain\PayloadFactory`: Factory to create payload objects. [#14123](https://github.com/phalcon/cphalcon/issues/14123)
- Added `Phalcon\Http\Message\ServerRequestFactory::load`: Method to create a `ServerRequest` object from globals. [#14154](https://github.com/phalcon/cphalcon/pull/14154)
- Added `saslAuthData` as option to `Phalcon\Storage\Adapter\Libmemcached` to authenticate using SASL [#13394](https://github.com/phalcon/cphalcon/issues/13394)
- Added `Phalcon\Collection\ReadOnly`: Read only collection. [#14154](https://github.com/phalcon/cphalcon/pull/14154)
- Added `whiteList()` to `Phalcon\Helper\Arr` [#13954](https://github.com/phalcon/cphalcon/pull/13954)
- Added `Phalcon\Config\ConfigFactory::newInstance()`: Factory to create config objects. [#13201](https://github.com/phalcon/cphalcon/issues/13201), [#13768](https://github.com/phalcon/cphalcon/issues/13768)
- Added `Phalcon\Db\Enum` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Added `Phalcon\Dispatcher\Exception` [#14213](https://github.com/phalcon/cphalcon/issues/14213)

## Changed
- Renamed `Phalcon\Annotations\Adapter\Files` to `Phalcon\Annotations\Adapter\Stream`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Annotations\Adapter` to `Phalcon\Annotations\Adapter\AbstractAdapter`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Annotations\AdapterInterface` to `Phalcon\Annotations\Adapter\AdapterInterface`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Annotations\Factory` to `Phalcon\Annotations\AnnotationsFactory`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Config\Factory` to `Phalcon\Config\ConfigFactory`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Filter\FilterLocator` to `Phalcon\Filter\Filter`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Filter\FilterLocatorFactory` to `Phalcon\Filter\FilterFactory`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Image\Adapter` to `Phalcon\Image\Adapter\AbstractAdapter`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Image\AdapterInterface` to `Phalcon\Image\Adapter\AdapterInterface`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Paginator\Adapter` to `Phalcon\Paginator\Adapter\AbstractAdapter`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Paginator\AdapterInterface` to `Phalcon\Paginator\Adapter\AdapterInterface`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Paginator\Factory` to `Phalcon\Paginator\PaginatorFactory`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Translate\Adapter` to `Phalcon\Translate\Adapter\AbstractAdapter`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Renamed `Phalcon\Translate\AdapterInterface` to `Phalcon\Translate\Adapter\AdapterInterface`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- `Phalcon\Plugin` is now abstract.
- Moved `method` parameter in `Phalcon\Mvc\Model\Manager::getRelationRecords()` to the last position. [#14115](https://github.com/phalcon/cphalcon/issues/14115)
- Moved `method` parameter in `Phalcon\Mvc\Model\Manager::getBelongsToRecords()` to the last position. [#14115](https://github.com/phalcon/cphalcon/issues/14115)
- Moved `method` parameter in `Phalcon\Mvc\Model\Manager::getHasOneRecords()` to the last position. [#14115](https://github.com/phalcon/cphalcon/issues/14115)
- Moved `method` parameter in `Phalcon\Mvc\Model\Manager::getHasManyRecords()` to the last position. [#14115](https://github.com/phalcon/cphalcon/issues/14115)
- Validator messages were moved into each validator. [#13208](https://github.com/phalcon/cphalcon/issues/13208)
- `Phalcon\Paginator\Repository::getProperty()` now uses `Phalcon\Helper\Arr::get()`.
- Refactored `Phalcon\Collection` to allow conditional key case sensitivity. [#14154](https://github.com/phalcon/cphalcon/pull/14154)
- Refactored `Phalcon\Registry` to align with the `Phalcon\Collection` interface. [#14154](https://github.com/phalcon/cphalcon/pull/14154)
- `Phalcon\Mvc\Micro::setModelBinder()` now uses the Factory Default DI if none is set. [#14171](https://github.com/phalcon/cphalcon/pull/14171)
- `Phalcon\Mvc\Model\ValidationFailed` now works with `ModelInterface`.
- Refactored `Phalcon\Config` to extend `Phalcon\Collection` [#13201](https://github.com/phalcon/cphalcon/issues/13201), [#13768](https://github.com/phalcon/cphalcon/issues/13768)
- Renamed `Phalcon\Config` to extend `Phalcon\Config\Config` [#13201](https://github.com/phalcon/cphalcon/issues/13201), [#13768](https://github.com/phalcon/cphalcon/issues/13768)
- Renamed `Phalcon\Acl` to  `Phalcon\Acl\Enum` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Acl\Adapter` to `Phalcon\Acl\Adapter\AbstractAdapter` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Acl\AdapterInterface` to `Phalcon\Acl\Adapter\AdapterInterface` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Application` to `Phalcon\Application\AbstractApplication` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\CryptInterface` to `Phalcon\Crypt\CryptInterface` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Db\Adapter` to `Phalcon\Db\Adapter\AbstractAdapter` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Db\AdapterInterface` to `Phalcon\Db\Adapter\AdapterInterface` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Db` to `Phalcon\Db\AdapterDb` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Db\Adapter\Pdo` to `Phalcon\Db\Adapter\Pdo\AbstractPdo` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Dispatcher` to `Phalcon\Dispatcher\AbstractDispatcher` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\DispatcherInterface` to `Phalcon\Dispatcher\DispatcherInterface` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\EscaperInterface` to `Phalcon\Escaper\EscaperInterface` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Firewall\Adapter` to `Phalcon\Firewall\Adapter\AbstractAdapter` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Firewall\AdapterInterface` to `Phalcon\Firewall\Adapter\AdapterInterface` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Flash` to `Phalcon\Flash\AbstractFlash` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\FlashInterface` to `Phalcon\Flash\FlashInterface` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Forms\Element` to `Phalcon\Forms\Element\AbstractElement` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Forms\ElementInterface` to `Phalcon\Forms\Element\ElementInterface` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Image` to `Phalcon\Image\Enum` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Mvc\View\Engine` to `Phalcon\Mvc\View\Engine\AbstractEngine` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Mvc\View\EngineInterface` to `Phalcon\Mvc\View\Engine\EngineInterface` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\UrlInterface` to `Phalcon\Url\UrlInterface`
- Renamed `Phalcon\Validator` to `Phalcon\Validator\Validator` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Validator\Validator` to `Phalcon\Validator\AbstractValidator` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Validator\ValidatorComposite` to `Phalcon\Validator\AbstractValidatorComposite` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Validator\CombinedFieldsValidator` to `Phalcon\Validator\AbstractCombinedFields` [#14213](https://github.com/phalcon/cphalcon/issues/14213)
- Renamed `Phalcon\Validator\Validator\File\FileAbstract` to `Phalcon\Validator\Validator\File\AbstractFile` [#14213](https://github.com/phalcon/cphalcon/issues/14213)

## Fixed
- Fixed `Phalcon\Mvc\View::getRender()` to call `view->finish()` instead of `ob_end_clean()`. [#14095](https://github.com/phalcon/cphalcon/issues/14095)
- Fixed `Phalcon\Cache\Adapter\Libmemcached` failing to set values when `Phalcon\Mvc\Model\MetaData\Libmemcached` was in use. [#14100](https://github.com/phalcon/cphalcon/issues/14100)
- Fixed `Phalcon\Db\Column` to recognize `tinyint`, `smallint`, `mediumint`, `integer` as valid autoIncrement columns. [#14102](https://github.com/phalcon/cphalcon/issues/14102)
- Fixed `method` parameter in `Phalcon\Mvc\Model\Manager::getRelationRecords()`, it's not always a string, null by default. [#14115](https://github.com/phalcon/cphalcon/issues/14115)
- Fixed `method` parameter in `Phalcon\Mvc\Model\Manager::getBelongsToRecords()`, it's not always a string, null by default. [#14115](https://github.com/phalcon/cphalcon/issues/14115)
- Fixed `method` parameter in `Phalcon\Mvc\Model\Manager::getHasOneRecords()`, it's not always a string, null by default. [#14115](https://github.com/phalcon/cphalcon/issues/14115)
- Fixed `method` parameter in `Phalcon\Mvc\Model\Manager::getHasManyRecords()`, it's not always a string, null by default. [#14115](https://github.com/phalcon/cphalcon/issues/14115)
- Fixed `handlers` property in `Phalcon\Mvc\Micro\Collection` to now always an array.
- Fixed crash in `Phalcon\Mvc\Model::save()` when saving a circular model relation. [#13354](https://github.com/phalcon/cphalcon/pull/13354)
- Fixed `Phalcon\Db\Dialect\Postgresql::truncateTable()` to now escape table names. [#14125](https://github.com/phalcon/cphalcon/pull/14125)
- Fixed `Phalcon\Mvc\Model\MetaData::write()` to throw an exception if `orm.exception_on_failed_metadata_save` is set to true. [#13433](https://github.com/phalcon/cphalcon/issues/13433)
- Fixed `Phalcon\Image\Adapter\Gd` to throw an error with `imagecolorat`. [#14139](https://github.com/phalcon/cphalcon/issues/14139)
- `Phalcon\Mvc\Model\Criteria::limit()` now corrects negative offsets.
- `Phalcon\Di\FactoryDefault\Cli` can now use the new Filter system.
- Fixed `Phalcon\Mvc\Router` now parses and uses path. [#14087](https://github.com/phalcon/cphalcon/issues/14087)
- Fixed various areas in `Phalcon\Acl\Adapter` and `Phalcon\Acl\Adapter\Memory` including comments, logic, `denyComponentAccess` and `AdapterInterface`. Added tests. [#13870](https://github.com/phalcon/cphalcon/issues/13870)
- Fixed `Phalcon\Config::merge()` not merging numeric values properly [#13201](https://github.com/phalcon/cphalcon/issues/13201), [#13768](https://github.com/phalcon/cphalcon/issues/13768)
- Fixed `Phalcon\Validation\Validator\File\AbstractFile` missing the resolution of the `value` property [#14198](https://github.com/phalcon/cphalcon/issues/14198)
- Fixed `Phalcon\Storage\Adapter\Stream` [#14190](https://github.com/phalcon/cphalcon/issues/14190)
- `Phalcon\Form\Form::clear()` now correctly clears single fields. [#14217](https://github.com/phalcon/cphalcon/issues/14217)
- Fixed `Phalcon\Form\Form::getValue()` not to call `getAttributes()` when an element is named "attributes" [#14226](https://github.com/phalcon/cphalcon/issues/14226)
- Fixed `Phalcon\Model::delete()` array to string conversion [#14080](https://github.com/phalcon/cphalcon/issues/14080)
- Fixed segfault in `Phalcon\Mvc\Micro\LazyLoader::callMethod()` when handler contains syntax error.

## Removed
- Removed `Phalcon\Session\Factory`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Removed `Phalcon\Factory` and `Phalcon\FactoryInterface`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Removed `Phalcon\Translate`. [#13672](https://github.com/phalcon/cphalcon/issues/13672)
- Removed `Phalcon\Db\Column::getSchemaName()` as its not relevant or settable.
- Removed `Phalcon\Config::__set_state()` as it does not serve any purpose and skipped the constructor. [#13201](https://github.com/phalcon/cphalcon/issues/13201), [#13768](https://github.com/phalcon/cphalcon/issues/13768)
- Removed `Phalcon\Annotations\Reflection::__set_state()`, `Phalcon\Db\ColumnInterface::__set_state()`, `Phalcon\Db\Column::__set_state()`, `Phalcon\Db\IndexInterface::__set_state()`, `Phalcon\Db\Index::__set_state()`, `Phalcon\Db\ReferenceInterface::__set_state()`, `Phalcon\Db\Reference::__set_state()`, `Phalcon\Di\ServiceInterface::__set_state()`, `Phalcon\Di\Service::__set_state()`, `Phalcon\Http\Response\HeadersInterface::__set_state()`, `Phalcon\Http\Response\Headers::__set_state()`, `Phalcon\Http\Request::__set_state()`, `Phalcon\Messages\Message::__set_state()` [#14212](https://github.com/phalcon/cphalcon/issues/14212)

# [4.0.0-alpha.5](https://github.com/phalcon/cphalcon/releases/tag/v4.0.0-alpha.5) (2019-05-18)

## Added
- Added `Phalcon\Cli\Router\Route::setDescription()` to sets the route's description [#13936](https://github.com/phalcon/cphalcon/pull/13936)
- Added `Phalcon\Cli\Router\Route::getDescription()` returns the route's description [#13936](https://github.com/phalcon/cphalcon/pull/13936)
- Added `Phalcon\Image\Adapter\Gd::getVersion()`.
- Added `chunk()`, `first()`, `firstKey()`, `flatten()`, `group()`, `isUnique()`, `last()`, `lastKey()`, `order()`, `pluck()`, `sliceLeft()`, `sliceRight()`, `split()`, `tail()`, `validateAll()`, `validateAny()` to `Phalcon\Helper\Arr` [#13954](https://github.com/phalcon/cphalcon/pull/13954)
- Added `camelize()`, `concat()`, `countVowels()`, `decapitalize()`, `dynamic()`, `endsWith()`, `firstStringBetween()`, `includes()`, `increment()`, `isAnagram()`, `isLower()`, `isPalindrome()`, `isUpper()`, `lower()`, `random()`, `reduceSlashes()`, `startsWith()`, `uncamelize()`, `underscore()`, `upper()` to `Phalcon\Helper\Str` [#13954](https://github.com/phalcon/cphalcon/pull/13954)
- Added `Phalcon\Mvc\Model\Query\BuilderInterface::getModels()` returns the models involved in the query
- Added `addConnect()`, `addPurge()` and `addTrace()` to `Phalcon\Mvc\Router\Group` and its interface. [#14001](https://github.com/phalcon/cphalcon/pull/14001)
- Added `Phalcon\Mvc\Model\Transaction::throwRollbackException()` which allows a transaction to throw an exception or not on a rollback. [#13949](https://github.com/phalcon/cphalcon/issues/13949)
- Added `Phalcon\Cache` class implementing PSR-16. Introducing:
    - `Phalcon\Cache\Adapter`
        - `Phalcon\Cache\Adapter\Apcu`
        - `Phalcon\Cache\Adapter\Libmemcached`
        - `Phalcon\Cache\Adapter\Memory`
        - `Phalcon\Cache\Adapter\Redis`
        - `Phalcon\Cache\Adapter\Stream`
    - `Phalcon\Cache\AdapterFactory`: Factory to create adapters
    - `Phalcon\Cache\CacheFactory`: Factory to create cache objects
 [#13439](https://github.com/phalcon/cphalcon/issues/13439)
- Added `Str::dirSeparator()` to ensure a path has a trailing slash [#13439](https://github.com/phalcon/cphalcon/issues/13439)
- Added assets versioning `Phalcon\Assets\Manager:addCss`, `Phalcon\Assets\Manager::addJs`, `Phalcon\Assets\Collection:addCss`,  `Phalcon\Assets\Collection:addJs` accepts two additional parameters - `version` and `autoVersion`  [#12591](https://github.com/phalcon/cphalcon/pull/12591)
- Added setting `orm.resultset_prefetch_records` instructing the ORM (resultset) to prefetch the rows if the rows returned are less or equal to the setting. [#13387](https://github.com/phalcon/cphalcon/issues/13387)
- Added `Phalcon\Mvc\View::toString()` to return the rendered view as a string [#13825](https://github.com/phalcon/cphalcon/issues/13825)
- Added `Phalcon\Helper\Arr::arrayToObject()` to convert arrays to objects.
- Added `Phalcon\Firewall` component  [#13648](https://github.com/phalcon/cphalcon/issues/13648)
- Added `orm.cast_last_insert_id_to_int` option for `Phalcon\Mvc\Model::setup()` (`castLastInsertIdToInt`) to cast the `lastInsertId` on `save()` to `int` [#13002](https://github.com/phalcon/cphalcon/issues/13002)
- Added `Attributes` collection class like a new Html component [#13646](https://github.com/phalcon/cphalcon/issues/13646)
- Added `Attributes` into `Phalcon\Forms\Form` [#13646](https://github.com/phalcon/cphalcon/issues/13646)

## Changed
- Refactored `Phalcon\Events\Manager` to only use `SplPriorityQueue` to store events. [#13924](https://github.com/phalcon/cphalcon/pull/13924)
- `Phalcon\Translate\InterpolatorInterface` now only accepts placeholder arrays. [#13939](https://github.com/phalcon/cphalcon/pull/13939)
- `Phalcon\Dispatcher::forward()` and `Phalcon\Dispatcher::setParams()` now require an array as a parameter. [#13935](https://github.com/phalcon/cphalcon/pull/13935)
- CLI Routes with bad class names (eg. `MyApp\\Tasks\\`) now throw an exception instead of suppressing the error. [#13936](https://github.com/phalcon/cphalcon/pull/13936)
- Refactored `Phalcon\Mvc\Collection\Behavior\SoftDelete` and `Phalcon\Mvc\Model\Behavior\SoftDelete`. [#13930](https://github.com/phalcon/cphalcon/pull/13930)
- Model methods that extend Model Manager functionality are now `final`. [#13950](https://github.com/phalcon/cphalcon/pull/13950)
- Changed `Phalcon\Text` to call methods from `Phalcon\Helper\Str` [#13954](https://github.com/phalcon/cphalcon/pull/13954)
- Setting the views directory no longer requires a trailing slash when using Simple View.
- `Phalcon\Mvc\View\Simple::viewParams` is now always an array.
- `Phalcon\Mvc\View\Simple::render()` `params` property is now always an array.
- `Phalcon\Mvc\Model\CriteriaInterface::limit()` now takes `offset` as an integer. [#13977](https://github.com/phalcon/cphalcon/pull/13977)
- Changed `Phalcon\Mvc\Model\Manager::getModelSource()` to use `setModelSource()` internally instead of setting the source manually [#13987](https://github.com/phalcon/cphalcon/pull/13987)
- The property `options` is always an array in `Phalcon\Mvc\Model\Relation`. [#13989](https://github.com/phalcon/cphalcon/pull/13989)
- `Phalcon\Logger\Adapter\AbstractAdapter::process()` is now actually abstract. [#14012](https://github.com/phalcon/cphalcon/pull/14012)
- `Phalcon\Mvc\ModelInterface::getRelated()` return type declaration has changed (not always `ResultsetInterface`) [#14035](https://github.com/phalcon/cphalcon/pull/14035/)
- In `Phalcon\Mvc\Model`, relations fetched using magic methods are now handled by `Phalcon\Mvc\Model::getRelated()` internally.  [#14035](https://github.com/phalcon/cphalcon/pull/14035/)
- Changed `Phalcon\Mvc\Model\Transaction::rollback()` to not throw a transaction by default. [#13949](https://github.com/phalcon/cphalcon/issues/13949)
- Changed `Phalcon\Cache` namespace and relevant classes to handle storing data to different stores. Introducing:
    - `Phalcon\Storage\Serializer` offering classes that implement the `\Serializable` interface.
        - `Phalcon\Storage\Serializer\Base64`
        - `Phalcon\Storage\Serializer\Igbinary`
        - `Phalcon\Storage\Serializer\Json`
        - `Phalcon\Storage\Serializer\Msgpack`
        - `Phalcon\Storage\Serializer\None`
        - `Phalcon\Storage\Serializer\Php`
        - `Phalcon\Storage\Serializer\SerializerInterface`
    - `Phalcon\Storage\SerializerFactory`: Factory to create serializers
    - `Phalcon\Storage\Adapter` offering classes that implement the `Phalcon\Storage\Adapter\AdapterInterface` interface.
        - `Phalcon\Storage\Adapter\Apcu`
        - `Phalcon\Storage\Adapter\Libmemcached`
        - `Phalcon\Storage\Adapter\Memory`
        - `Phalcon\Storage\Adapter\Redis`
        - `Phalcon\Storage\Adapter\Stream`
    - `Phalcon\Storage\AdapterFactory`: Factory to create adapters
 [#13439](https://github.com/phalcon/cphalcon/issues/13439)
- Changed `Phalcon\Mvc\Model\Query` to not call `numRows` when selecting data  [#13387](https://github.com/phalcon/cphalcon/issues/13387)
- Bind parameters and bind types are now always arrays in `Phalcon\Mvc\Model\Query`.
- Changed `Phalcon\Validation\Validator\Url` to work with passed options. (`FILTER_FLAG_PATH_REQUIRED`, `FILTER_FLAG_QUERY_REQUIRED`) [#13548](https://github.com/phalcon/cphalcon/issues/13548)
- `Phalcon\Mvc\Model\Query\Builder` will now omit offsets if they are set as 0.
- `Phalcon\Mvc\Model\Transaction::__construct()` service parameter must be a string or omitted.
- `Phalcon\Logger\Formatter\Line::__construct()` service parameters must be a string or omitted.
- `Phalcon\Logger\Formatter\Json::__construct()` service parameters must be a string or omitted.
- Removed deprecated code from `Phalcon\Forms\Form::getMessages()`.
- Loading a Module (either MVC or CLI) now throws an exception if the path does not exists regardless of whether the class is already loaded.
- Changed `Phalcon\Crypt` to accept auth tag, tag length and data for "gcm" and "ccm" modes. Removed insecure algorithms with modes: `des*`, `rc2*`, `rc4*`, `des*`, `*ecb` [#13869](https://github.com/phalcon/cphalcon/issues/13869)
- Changed `Phalcon\Mvc\Model` to copy the unset default values from the `MetaData` to the `Model` after a successful insert. [#13781](https://github.com/phalcon/cphalcon/issues/13781)
- Changed `Phalcon\Mvc\Model::findFirst()` now returns `null`. `Phalcon\Mvc\Model::getRelated()` for one to one relationships returns `null` [#14044](https://github.com/phalcon/cphalcon/issues/14044)

## Fixed
- Fixed `Mvc\Collection::isInitialized()` now works as intended. [#13931](https://github.com/phalcon/cphalcon/pull/13931)
- Update docblocks to show that we can no longer assign properties via `save()` in models (as per #12317). [#13945](https://github.com/phalcon/cphalcon/pull/13945)
- Fixed `Mvc\Model` and `Mvc\ModelInterface` `findFirst` to return `ModelInterface` or `bool` [#13947](https://github.com/phalcon/cphalcon/issues/13947)
- `Phalcon\Acl\Adapter\Memory::dropComponentAccess()` now properly unsets values.
- Volt options 'separator' and 'extension' now work again. [#13971](https://github.com/phalcon/cphalcon/issues/13971)
- Query Builder's `GROUP BY` field is now always an array. [#13962](https://github.com/phalcon/cphalcon/pull/13962)
- Renamed `Phalcon\Paginator\Adapter::getPaginate()` to `paginate()` in documentation/tests (originally renamed in 4.0.0-alpha.1). [#13973](https://github.com/phalcon/cphalcon/pull/13973)
- Fixed the exception message in `Phalcon\Security::computeHmac()` by removing `"%s"` from output.
- `Phalcon\Mvc\Model\Relation::isForeignKey()` now returns false if the `foreignKey` option is set to `false`.
- Fixed `Phalcon\Flash\Session::output()` not to throw an exception when there are no messages stored in session. [#14023](https://github.com/phalcon/cphalcon/issues/14023)
- Fixed `Phalcon\Config\Adapter\Ini()` to handle arrays correctly in .ini files. [#14025](https://github.com/phalcon/cphalcon/issues/14025)
- Fixed non-reusable relations in `Phalcon\Mvc\Model`, now returning fresh records. [#13531](https://github.com/phalcon/cphalcon/issues/13531)
- `Phalcon\Mvc\Model::isRelationshipLoaded()` is now working for every type of relations. [#14035](https://github.com/phalcon/cphalcon/pull/14035)
- Fixed `Phalcon\Mvc\Model::writeAttribute()` to handle associative arrays correctly. [#14021](https://github.com/phalcon/cphalcon/issues/14021)
- Fixed `Phalcon\Html\Tag::appendTitle()` and `Phalcon\Html\Tag::prependTitle()`to mirror `Phalcon\Tag`. [#14039](https://github.com/phalcon/cphalcon/issues/14039)
- Fixed `Phalcon\Validation::validate()` with `cancelOnFail`. The validator will validate all elements and will stop processing validators on a per element basis if `cancelOnFail` is present. [#13149](https://github.com/phalcon/cphalcon/issues/13149)
- Fixed `Phalcon\Mvc\Models\Manager::getRelations()` to return the many-to-many relationships also. [#10839](https://github.com/phalcon/cphalcon/issues/10839)
- Fixed `Phalcon\Validation\Validator\Numericality::validate()` to parse non `en` locale numbers. [#13843](https://github.com/phalcon/cphalcon/issues/13843)
- Fixed `Phalcon\Mvc\Model::save()` failing after a successful insert when default database fields are not updated. [#13781](https://github.com/phalcon/cphalcon/issues/13781)

## Removed
- Removed `arrayHelpers` property from the Volt compiler. [#13925](https://github.com/phalcon/cphalcon/pull/13925)
- Removed legacy (PHP <5.5) code from GD image adapter.
- Removed support for HTTP_CONTENT_TYPE header (a bug in PHP 5). [#14013](https://github.com/phalcon/cphalcon/pull/14013)
- Removed `Mvc\Model\MetaData\Session` adapter (no longer supported) [#13439](https://github.com/phalcon/cphalcon/pull/13439)
- Removed `Phalcon\Cache`, `Phalcon\Cache\Backend`, `Phalcon\Cache\BackendInterface`, `Phalcon\Cache\Backend\Apcu`, `Phalcon\Cache\Backend\Factory`, `Phalcon\Cache\Backend\File`, `Phalcon\Cache\Backend\Libmemcached`, `Phalcon\Cache\Backend\Memory`, `Phalcon\Cache\Backend\Mongo`, `Phalcon\Cache\Backend\Redis`, `Phalcon\Cache\Frontend`, `Phalcon\Cache\Frontend\Base64`, `Phalcon\Cache\Frontend\Data`, `Phalcon\Cache\Frontend\Factory`, `Phalcon\Cache\Frontend\Igbinary`, `Phalcon\Cache\Frontend\Json`, `Phalcon\Cache\Frontend\Msgpack`, `Phalcon\Cache\Frontend\None`, `Phalcon\Cache\Frontend\Output`, `Phalcon\Cache\FrontendInterface`, `Phalcon\Cache\Multiple` [#13439](https://github.com/phalcon/cphalcon/issues/13439)
- Removed caching from the view (simple/view)
    - `Phalcon\Mvc\View::cache()`
    - `Phalcon\Mvc\View::getCache()`
    - `Phalcon\Mvc\View\Simple::cache()`
    - `Phalcon\Mvc\View\Simple::getCache()`
[#13439](https://github.com/phalcon/cphalcon/issues/13439)
- Removed multiple Cache Adapter `Phalcon\Cache\Multiple` [#13439](https://github.com/phalcon/cphalcon/issues/13439)
- Removed old cache classes
    - `Phalcon\Cache\Backend`
    - `Phalcon\Cache\BackendInterface`
    - `Phalcon\Cache\Backend\Apcu`
    - `Phalcon\Cache\Backend\Factory`
    - `Phalcon\Cache\Backend\File`
    - `Phalcon\Cache\Backend\Libmemcached`
    - `Phalcon\Cache\Backend\Memory`
    - `Phalcon\Cache\Backend\Mongo`
    - `Phalcon\Cache\Backend\Redis`
    - `Phalcon\Cache\Frontend`
    - `Phalcon\Cache\FrontendInterface`
    - `Phalcon\Cache\Frontend\Base64`
    - `Phalcon\Cache\Frontend\Data`
    - `Phalcon\Cache\Frontend\Factory`
    - `Phalcon\Cache\Frontend\Igbinary`
    - `Phalcon\Cache\Frontend\Json`
    - `Phalcon\Cache\Frontend\Msgpack`
    - `Phalcon\Cache\Frontend\None`
    - `Phalcon\Cache\Frontend\Output`
[#13439](https://github.com/phalcon/cphalcon/issues/13439)
- Removed model namespace aliases.

# [4.0.0-alpha.4](https://github.com/phalcon/cphalcon/releases/tag/v4.0.0-alpha.4) (2019-03-31)
## Added
- Added `delimiter` and `enclosure` options to *Phalcon\Translate\Adapter\Csv* constructor
- Added `Phalcon\Http\Message\*` namespace implementing PSR-7 and PSR-17. Introducing:
    - `Phalcon\Http\Message\Request`
    - `Phalcon\Http\Message\RequestFactory`
    - `Phalcon\Http\Message\Response`
    - `Phalcon\Http\Message\ResponseFactory`
    - `Phalcon\Http\Message\ServerRequest`
    - `Phalcon\Http\Message\ServerRequestFactory`
    - `Phalcon\Http\Message\Stream`
    - `Phalcon\Http\Message\StreamFactory`
    - `Phalcon\Http\Message\UploadedFile`
    - `Phalcon\Http\Message\UploadedFileFactory`
    - `Phalcon\Http\Message\Uri`
    - `Phalcon\Http\Message\UriFactory`
    - `Phalcon\Http\Message\Stream\Input`
    - `Phalcon\Http\Message\Stream\Memory`
    - `Phalcon\Http\Message\Stream\Temp`
The implementation offers PSR-7/PSR-17 compatible components in a different namespace to allow usage of both `Request` and `Response` implementations for this version. [#11789](https://github.com/phalcon/cphalcon/pull/11789)
- Added `Phalcon\Helper\*` namespace, offering easy manipulations for arrays, numbers etc..
    - `Phalcon\Helper\Arr`
    - `Phalcon\Helper\Number`
[#13889](https://github.com/phalcon/cphalcon/pull/13889)
- Added `Phalcon\Collection`, an object implementing `ArrayAccess`, `Countable`, `IteratorAggregate`, `JsonSerializable`, `Serializable`, offering an easy way to handle collections of data such as arrays, superglobals etc. [#13886](https://github.com/phalcon/cphalcon/issues/13886)
- Added `Phalcon\Collection`, in `Phalcon\Http\Message\Request` and `Phalcon\Http\Message\ServerRequest` to handle the headers [#13907](https://github.com/phalcon/cphalcon/issues/13907)

## Fixed
- Fixed `Phalcon\Image\Adapter\Imagick::_watermark`, `setImageAlpha()` fills the alpha channel with black before execution (replaced by `evaluateImage()`). Improved imagick compatibility. [#13911](https://github.com/phalcon/cphalcon/pull/13911)
- Fixed Assets Manager hard reference to \Phalcon\Tag, should use DI [#12261](https://github.com/phalcon/cphalcon/issues/12261)
- Fixed `Annotations\Reader::parse` to always return an array [#13923](https://github.com/phalcon/cphalcon/pull/13923)

## Changed
- Refactored `Phalcon\Registry` to use the `Phalcon\Collection` class [#13893](https://github.com/phalcon/cphalcon/issues/13893)
- Refactored `Phalcon\Session\Bag` to use the `Phalcon\Collection` class [#13893](https://github.com/phalcon/cphalcon/issues/13893)
- Refactored almost all files of the project to abide by the new coding standard for Phalcon. Certain files have been intentionally left untouched because they will be replaced later on. [#13915](https://github.com/phalcon/cphalcon/issues/13915)

## Removed
- Removed `Phalcon\Session\BagInterface` [#13893](https://github.com/phalcon/cphalcon/issues/13893)


# [4.0.0-alpha.3](https://github.com/phalcon/cphalcon/releases/tag/v4.0.0-alpha.3) (2019-02-31)
## Added
- Added `view:afterCompile` and `view:beforeCompile` events for the Volt compiler [#2182](https://github.com/phalcon/cphalcon/pull/2182)
- Added array merge support to `Phalcon\Config::merge`
- Added `setBlacklist` in `Phalcon\Debug` to allow the developer to "blacklist" certain variables from the `$_REQUEST` or `$_SERVER` superglobals being displayed on screen [#13687](https://github.com/phalcon/cphalcon/pull/13687)

## Fixed
- Fixed router and controller parameter inconsistencies (camelize etc.) [#13555](https://github.com/phalcon/cphalcon/issues/13555)
- Fixed `invalid opcode` in `phalcon.so` when using docker [#13143](https://github.com/phalcon/cphalcon/issues/13143)
- Fixed storing related model data in `Phalcon\Messages\Message`. The method is now `setMetadata` and can be used to store any metadata from any component that emits messages [#13811](https://github.com/phalcon/cphalcon/issues/13811)
- Fixed Dispatcher calling camelize twice and producing incorrect results [#12829](https://github.com/phalcon/cphalcon/issues/12829)
- Fixed `Phalcon\Mvc\Model:findFirst` to throw an exception when the passed parameter for a primary key is not an array, string or numeric [#13336](https://github.com/phalcon/cphalcon/issues/13336)
- Added `Phalcon\Http\ResponseInterface::isSent`, that was already used. [#13836](https://github.com/phalcon/cphalcon/pull/13836)

## Changed
- Changed view engine service closures to no longer receive the dependency injector as the second parameter. Instead use `$this` for the DI. [#11926](https://github.com/phalcon/cphalcon/issues/11926)
- Renamed `Phalcon\Acl\Subject` to `Phalcon\Acl\Component` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\SubjectInterface` to `Phalcon\Acl\ComponentInterface` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\SubjectAware` to `Phalcon\Acl\ComponentAware` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\Operation` to `Phalcon\Acl\Role` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\OperationInterface` to `Phalcon\Acl\RoleInterface` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\OperationAware` to `Phalcon\Acl\RoleAware` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\AdapterInterface::addOperation` to `Phalcon\Acl\AdapterInterface::addRole` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\AdapterInterface::isOperation` to `Phalcon\Acl\AdapterInterface::isRole` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\AdapterInterface::isSubject` to `Phalcon\Acl\AdapterInterface::isComponent` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\AdapterInterface::addSubject` to `Phalcon\Acl\AdapterInterface::addComponent` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\AdapterInterface::addSubjectAccess` to `Phalcon\Acl\AdapterInterface::addComponentAccess` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\AdapterInterface::dropSubjectAccess` to `Phalcon\Acl\AdapterInterface::dropComponentAccess` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\AdapterInterface::getActiveOperation` to `Phalcon\Acl\AdapterInterface::getActiveRole` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\AdapterInterface::getActiveSubject` to `Phalcon\Acl\AdapterInterface::getActiveComponent` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\AdapterInterface::getOperationss` to `Phalcon\Acl\AdapterInterface::getRoles` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\AdapterInterface::getSubjects` to `Phalcon\Acl\AdapterInterface::getComponents` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\Adapter::getActiveOperation` to `Phalcon\Acl\AdapterInterface::getActiveRole` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\Adapter::getActiveSubject` to `Phalcon\Acl\AdapterInterface::getActiveComponent` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\Adapter\Memory::addOperation` to `Phalcon\Acl\Adapter\Memory::addRole` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\Adapter\Memory::isOperation` to `Phalcon\Acl\Adapter\Memory::isRole` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\Adapter\Memory::isSubject` to `Phalcon\Acl\Adapter\Memory::isComponent` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\Adapter\Memory::addSubject` to `Phalcon\Acl\Adapter\Memory::addComponent` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\Adapter\Memory::addSubjectAccess` to `Phalcon\Acl\Adapter\Memory::addComponentAccess` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\Adapter\Memory::dropSubjectAccess` to `Phalcon\Acl\Adapter\Memory::dropComponentAccess` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\Adapter\Memory::getOperationss` to `Phalcon\Acl\Adapter\Memory::getRoles` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Acl\Adapter\Memory::getSubjects` to `Phalcon\Acl\Adapter\Memory::getComponents` [#13808](https://github.com/phalcon/cphalcon/issues/13808)
- Renamed `Phalcon\Mvc\Url` to `Phalcon\Url` [#13742](https://github.com/phalcon/cphalcon/issues/13742)
- Renamed `Phalcon\Mvc\UrlInterface` to `Phalcon\UrlInterface` [#13742](https://github.com/phalcon/cphalcon/issues/13742)
- Renamed `Phalcon\Mvc\Url\Exception` to `Phalcon\Url\Exception` [#13742](https://github.com/phalcon/cphalcon/issues/13742)

## Removed
- Removed the CSS/JS minifiers. This affects the Assets\Filter classes. For now the classes return the original content. [#13819](https://github.com/phalcon/cphalcon/issues/13819), [#10118](https://github.com/phalcon/cphalcon/issues/10118)
- Removed `Phalcon\Queue` namespace and tests. Beanstalkd is near being abandoned. A new Queue component/adapter will be implemented for queueing needs of the community. [#13364](https://github.com/phalcon/cphalcon/issues/13364)


# [4.0.0-alpha.2](https://github.com/phalcon/cphalcon/releases/tag/v4.0.0-alpha.2) (2019-02-02)
## Added
- Added `notFound()` method in `Phalcon\Translate\Adapter\NativeArray` which returns the key requested if not found. The method can be overridden when extending the class, returning what the developer needs [#13007](https://github.com/phalcon/cphalcon/pull/13007)
- Added `Phalcon\Service\Locator`, `Phalcon\Service\LocatorInterface` and `Phalcon\Service\LocatorFactoryInterface` to allow for the creation of service locators and factories throughout the application [#13771](https://github.com/phalcon/cphalcon/pull/13771)
- Added `Phalcon\Http\Request::setParameterFilters`. It allows you to preset filters for specific input (i.e. `id`, `name` etc.). You can then retrieve the automatically sanitized values using `Phalcon\Http\Request::getFilteredQuery`, `Phalcon\Http\Request::getFilteredPost` and `Phalcon\Http\Request::getFilteredPut` [#13488](https://github.com/phalcon/cphalcon/issue/13488)

## Fixed
- Fixed `Phalcon\Mvc\Micro::handle` to properly return a response object [#13712](https://github.com/phalcon/cphalcon/issues/13712)
- Fixed `Phalcon\Cache\Backend\Libmemcached` returning "empty" values being as `null` when they could be `0`, `false` or empty `string`. [#13497](https://github.com/phalcon/cphalcon/issues/13497)
- Fixed session adapters to properly implement [`SessionHandlerInterface::write`](http://php.net/manual/en/sessionhandlerinterface.write.php)
- Fixed `Phalcon\Session\Manager` to not interact with `$_SESSION` variable if the session has not been started [#13718](https://github.com/phalcon/cphalcon/issues/13718), [#13520](https://github.com/phalcon/cphalcon/issues/13520)
- Fixed `Phalcon\Cli\Console` class not found error if handling the same module twice [#13724](https://github.com/phalcon/cphalcon/issues/13724)
- Fixed `Phalcon\Cache\Backend\Libmemcached` returning "empty" values being as `null` when they could be `0`, `false` or empty `string`. [#13497](https://github.com/phalcon/cphalcon/issues/13497)
- Fixed `Phalcon\Mvc\View\Engine\Volt\Compiler::functionCall` building the incorrect code for the following tags; `select`, and `select_static` [#13459](https://github.com/phalcon/cphalcon/issues/13459)
- Fixed `Phalcon\Tag\Select` not rendering without any options.
-
## Changed
- Changed the `Phalcon\Tag::renderTitle()` parameters such as `Phalcon\Tag::getTitle()` [#13706](https://github.com/phalcon/cphalcon/pull/13706)
- Changed the `Phalcon\Html\Tag::renderTitle()` parameters such as `Phalcon\Html\Tag::getTitle()` [#13706](https://github.com/phalcon/cphalcon/pull/13706)
- Changed the `Phalcon\Version::get()` to follow [semantic versioning](https://semver.org/) [#13720](https://github.com/phalcon/cphalcon/pull/13720)
- Changed the `Phalcon\Translate\Adapter\NativeArray` to accept a new parameter in the constructor `triggerError`. This will trigger an error if the key is not found [#13007](https://github.com/phalcon/cphalcon/pull/13007)
- Changed the default action of `Phalcon\Acl\Memory`to be `Acl::DENY` instead of `Acl::ALLOW` [#13758](https://github.com/phalcon/cphalcon/pull/13758)
- Changed `Phalcon\Mvc\User\Plugin` to `Phalcon\Plugin` [#13749](https://github.com/phalcon/cphalcon/issues/13749)
- Changed `Phalcon\Exception` to implement `\Throwable` interface.[#13750](https://github.com/phalcon/cphalcon/issues/13758)
- Changed `Phalcon\Http\Cookie`. The `httpOnly` property is no longer initialised with a value [#13464](https://github.com/phalcon/cphalcon/issues/13464)
- Changed the default action for no arguments of `Phalcon\Acl\Memory`to be `Acl::DENY` instead of `Acl::ALLOW` [#13769](https://github.com/phalcon/cphalcon/issues/13769)
- Changed handling of `Phalcon\Config\Adapter\Grouped::_construct()` when receiving an configuration file as a string from the `arrayConfig` parameter
  to automatically attempt and the parameter `defaultAdapter` is set to an empty string, to determine the adapter from the file extension,
  producing the same behaviour as `Phalcon\Config\Factory::load()` [#13762](https://github.com/phalcon/cphalcon/pull/13762)

## Removed
- Removed `Phalcon\Mvc\User\Component`, `Phalcon\Mvc\User\Module` and `Phalcon\Mvc\User\Plugin` [#13749](https://github.com/phalcon/cphalcon/pull/13749)

# [4.0.0-alpha1](https://github.com/phalcon/cphalcon/releases/tag/v4.0.0-alpha1) (2018-12-25)
## Added
- Added [CODE_OF_CONDUCT](https://github.com/phalcon/cphalcon/blob/master/CODE_OF_CONDUCT.md) for the project
- Added `Phalcon\Db\Adapter\Pdo\Postgresql::describeReferences` to implement custom Postgresql rules [438](https://github.com/phalcon/phalcon-devtools/issues/438)
- Added `Phalcon\Mvc\Router\RouteInterface::convert` so that calling `Phalcon\Mvc\Router\Group::add` will return an instance that has `convert` method [#13380](https://github.com/phalcon/cphalcon/issues/13380)
- Added `Phalcon\Mvc\ModelInterface::getModelsMetaData` [#13070](https://github.com/phalcon/cphalcon/issues/13402)
- Added `Phalcon\Validation\Validator\Ip`, class used to validate ip address fields. It allows to validate a field selecting IPv4 or IPv6, allowing private or reserved ranges and empty values if necessary. [#13574](https://github.com/phalcon/cphalcon/pull/13574)
- Added `Phalcon\Messages\MessageInterface`, `Phalcon\Messages\Message`, `Phalcon\Messages\Exception` and `Phalcon\Messages\Messages` to handle all messages for the application (model/validation) [#13114](https://github.com/phalcon/cphalcon/issues/13114)
- Added `getHandlerSuffix()`, `setHandlerSuffix()` in Dispatcher, `getTaskSuffix()`, `setTaskSuffix()` in the CLI Dispatcher [#13468](https://github.com/phalcon/cphalcon/issues/13468)
- Added ability to set a custom template for the Flash Messenger. [#13445](https://github.com/phalcon/cphalcon/issues/13445)
- Added `forUpdate` in the Sqlite dialect to override the method from the base dialect. [#13539](https://github.com/phalcon/cphalcon/issues/13539)
- Added `TYPE_ENUM` in the Mysql adapter. [#11368](https://github.com/phalcon/cphalcon/issues/11368)
- Added more column types for the Mysql adapter. The adapter supports `TYPE_BIGINTEGER`, `TYPE_BIT`, `TYPE_BLOB`, `TYPE_BOOLEAN`, `TYPE_CHAR`, `TYPE_DATE`, `TYPE_DATETIME`, `TYPE_DECIMAL`, `TYPE_DOUBLE`, `TYPE_ENUM`, `TYPE_FLOAT`, `TYPE_INTEGER`, `TYPE_JSON`, `TYPE_JSONB`, `TYPE_LONGBLOB`, `TYPE_LONGTEXT`, `TYPE_MEDIUMBLOB`, `TYPE_MEDIUMINTEGER`, `TYPE_MEDIUMTEXT`, `TYPE_SMALLINTEGER`, `TYPE_TEXT`, `TYPE_TIME`, `TYPE_TIMESTAMP`, `TYPE_TINYBLOB`, `TYPE_TINYINTEGER`, `TYPE_TINYTEXT`, `TYPE_VARCHAR`  [#13151](https://github.com/phalcon/cphalcon/issues/13151), [#12223](https://github.com/phalcon/cphalcon/issues/12223), [#524](https://github.com/phalcon/cphalcon/issues/524), [#13225](https://github.com/phalcon/cphalcon/pull/13225) [@zGaron](https://github.com/zGaron), [#12523](https://github.com/phalcon/cphalcon/pull/12523) [@Studentsov](https://github.com/Studentsov), [#12471](https://github.com/phalcon/cphalcon/pull/12471) [@ruudboon](https://github.com/ruudboon)
- Added `Phalcon\Acl\Adapter\Memory::addRole` support multiple inherited [#13557](https://github.com/phalcon/cphalcon/pull/13557)
- Added `Phalcon\Tag::renderTitle()` that renders the title enclosed in `<title>` tags. [#13547](https://github.com/phalcon/cphalcon/issues/13547)
- Added `hasHeader()` method to `Phalcon\Http\Response` to provide the ability to check if a header exists. [#12189](https://github.com/phalcon/cphalcon/pull/12189)
- Added global setting `orm.case_insensitive_column_map` to attempt to find value in the column map case-insensitively. Can be also enabled by setting `caseInsensitiveColumnMap` key in `\Phalcon\Mvc\Model::setup()`. [#11802](https://github.com/phalcon/cphalcon/pull/11802)
- Added the ability to use FrontendInterface to serialize Model and ResultSet - Inject a `serializer` object which implements `FrontendInterface` in DI to use it. [#12808](https://github.com/phalcon/cphalcon/pull/12888)
- Added `Phalcon\Mvc\Model\Query\BuilderInterface::offset` [#13599](https://github.com/phalcon/cphalcon/pull/13599)
- Added `Phalcon\Http\Response\Cookies::getCookies` [#13591](https://github.com/phalcon/cphalcon/pull/13591)
- Added `Phalcon\Mvc\Model::isRelationshipLoaded` to check if relationship is loaded [#12772](https://github.com/phalcon/cphalcon/pull/12772)
- Added an easy way to work with Phalcon and run the tests locally, using [nanobox.io](https://nanobox.io) [#13578](https://github.com/phalcon/cphalcon/issues/13578)
- Added response handler to `Phalcon\Mvc\Micro`, `Phalcon\Mvc\Micro::setResponseHandler`, to allow use of a custom response handler. [#12452](https://github.com/phalcon/cphalcon/pull/12452)
- Added two new events `response::beforeSendHeaders` and `response::afterSendHeaders` to `Phalcon\Http\Response` [#10689](https://github.com/phalcon/cphalcon/issue/10689)
- Added a retainer for the current token to be used during the checkings, so when `Phalcon\Security::getToken` is called the token used for checkings don't change. [#12392](https://github.com/phalcon/cphalcon/issues/12392)
- Added `Phalcon\Html\Tag`, a component that creates HTML elements. It will replace `Phalcon\Tag` in a future version. This component does not use static method calls. [#12392](https://github.com/phalcon/cphalcon/issues/12392)
- Added `Phalcon\Paginator\RepositoryInterface` for repository the current state of `paginator` and also optional sets the aliases for properties repository [#10985](https://github.com/phalcon/cphalcon/pull/10985), [#10957](https://github.com/phalcon/cphalcon/issues/10957)
- Added bind support to `Phalcon\Mvc\Model\Query\Builder`. The Query Builder has the same methods as `Phalcon\Mvc\Model\Query`; `getBindParams`, `setBindParams`, `getBindTypes` and `setBindTypes`. [#13368](https://github.com/phalcon/cphalcon/issues/13368)
- Added `Phalcon\Html\Breadcrumbs`, a component that creates HTML code for breadcrumbs. [#13680](https://github.com/phalcon/cphalcon/issues/13680)
- Added more methods to interfaces.
    - `Phalcon\Cli\Router\RouteInterface` - `delimiter`, `getDelimiter`
    - `Phalcon\Cli\DispatcherInterface` - `setOptions`, `getOptions`
    - `Phalcon\Db\AdapterInterface` - `fetchColumn`, `insertAsDict`, `updateAsDict`
    - `Phalcon\Db\DialectInterface` - `registerCustomFunction`, `getCustomFunctions`, `getSqlExpression`
    - `Phalcon\Di\ServiceInterface` - `getParameter`, `isResolved`
    - `Phalcon\Events\ManagerInterface` - `hasListeners`
    - `Phalcon\Mvc\Model\Query\BuilderInterface` - `distinct`, `getDistinct`, `forUpdate`, `offset`, `getOffset`
    - `Phalcon\Mvc\Model\Transaction\ManagerInterface` - `setDbService`, `getDbService`, `setRollbackPendent`, `getRollbackPendent`
    - `Phalcon\Mvc\Model\CriteriaInterface` - `distinct`, `leftJoin`, `innerJoin`, `rightJoin`, `groupBy`, `having`, `cache`, `getColumns`, `getGroupBy`, `getHaving`,
    - `Phalcon\Mvc\Model\ManagerInterface` - `isVisibleModelProperty`, `keepSnapshots`, `isKeepingSnapshots`, `useDynamicUpdate`, `isUsingDynamicUpdate`, `addHasManyToMany`, `existsHasManyToMany`, `getRelationRecords`, `getHasManyToMany`, `registerNamespaceAlias`, `getNamespaceAlias`
    - `Phalcon\Mvc\Model\MessageInterface` - `setModel`, `getModel`, `setCode`, `getCode`
    - `Phalcon\Mvc\Model\QueryInterface` - `getSingleResult`, `setBindParams`, `getBindParams`, `setBindTypes`, `setSharedLock`, `getBindTypes`, `getSql`
    - `Phalcon\Mvc\Model\RelationInterface` - `getParams`
    - `Phalcon\Mvc\Model\ResultsetInterface` - `setHydrateMode`, `getHydrateMode`, `getMessages`, `update`, `delete`, `filter`
    - `Phalcon\Mvc\ModelInterface` - `getModelsMetaData`
    - `Phalcon\Session\AdapterInterface` - `setId`, `status`
    - `Phalcon\Validation\MessageInteraface` - `getCode`, `setCode`
    - `Phalcon\CryptInterface` - `setPadding`
    - `Phalcon\Mvc\RouterInterface` - `attach` [#12676](https://github.com/phalcon/cphalcon/issues/12676)
- Added `Phalcon\Container`, a proxy container class to the `Phalcon\DI` implementing PSR-11 [#12295](https://github.com/phalcon/cphalcon/issues/12295)
- Added `Phalcon\Acl\Adapter\Memory::getActiveKey`, `Phalcon\Acl\Adapter\Memory::activeFunctionCustomArgumentsCount` and `Phalcon\Acl\Adapter\Memory::getActiveFunction` to get latest key, number of custom arguments, and function used to acquire access [#12547](https://github.com/phalcon/cphalcon/pull/12547)

## Changed
- Now Phalcon requires the [PSR PHP extension](https://github.com/jbboehr/php-psr) to be installed and enabled
- By configuring `prefix` and `statsKey` the `Phalcon\Cache\Backend\Redis::queryKeys` no longer returns prefixed keys, now it returns original keys without prefix. [#13656](https://github.com/phalcon/cphalcon/pull/13656)
- The `Phalcon\Mvc\Application`, `Phalcon\Mvc\Micro` and `Phalcon\Mvc\Router` now must have a URI to process [#12380](https://github.com/phalcon/cphalcon/pull/12380)
- Response headers and cookies are no longer prematurely sent [#12378](https://github.com/phalcon/cphalcon/pull/12378)
- You can no longer assign data to models whilst saving them [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- The `Phalcon\Mvc\Model\Manager::load` no longer reuses already initialized models [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- Changed `Phalcon\Db\Dialect\Postgresql::describeReferences` to generate correct SQL, added "on update" and "on delete" constraints [438](https://github.com/phalcon/phalcon-devtools/issues/438)
- Changed catch `Exception` to `Throwable` [#12288](https://github.com/phalcon/cphalcon/issues/12288)
- Changed `Phalcon\Mvc\Model\Query\Builder::addFrom` to remove third parameter `$with` [#13109](https://github.com/phalcon/cphalcon/pull/13109)
- `Phalcon\Forms\Form::clear` will no longer call `Phalcon\Forms\Element::clear`, instead it will clear/set default value itself, and `Phalcon\Forms\Element::clear` will now call `Phalcon\Forms\Form::clear` if it's assigned to the form, otherwise it will just clear itself. [#13500](https://github.com/phalcon/cphalcon/pull/13500)
- `Phalcon\Forms\Form::getValue` will now also try to get the value by calling `Tag::getValue` or element's `getDefault` method before returning `null`, and `Phalcon\Forms\Element::getValue` calls `Tag::getDefault` only if it's not added to the form. [#13500](https://github.com/phalcon/cphalcon/pull/13500)
- Changed `Phalcon\Mvc\Model` to use the `Phalcon\Messages\Message` object for its messages [#13114](https://github.com/phalcon/cphalcon/issues/13114)
- Changed `Phalcon\Validation\*` to use the `Phalcon\Messages\Message` object for its messages [#13114](https://github.com/phalcon/cphalcon/issues/13114)
- Collections now use the Validation component [#12376](https://github.com/phalcon/cphalcon/pull/12376)
- Made the `specialKey` (`_PHCR`) optional for the `Phalcon\Cache\Backend\Redis` adapter [#10905](https://github.com/phalcon/cphalcon/issues/10905), [#11608](https://github.com/phalcon/cphalcon/pull/11608)
- Refactored `Phalcon\Db\Adapter\Pdo::query` to use PDO's prepare and execute. `Phalcon\Db\Adapter::fetchAll` to use PDO's fetchAll [#13515](https://github.com/phalcon/cphalcon/pull/13515)
- Fixed  `\Phalcon\Http\Response::setFileToSend` filename last much _ [#13496](https://github.com/phalcon/cphalcon/pull/13496)
- Changed `Phalcon\Tag::getTitle`. It returns only the text. It accepts `prepend`, `append` booleans to prepend or append the relevant text to the title. [#13547](https://github.com/phalcon/cphalcon/issues/13547)
- Changed `Phalcon\Di\Service` constructor to no longer takes the name of the service. [#13590](https://github.com/phalcon/cphalcon/pull/13590)
- Changed `Phalon\Tag::textArea` to use `htmlspecialchars` to prevent XSS injection. [#12428](https://github.com/phalcon/cphalcon/issues/12428)
- Changed `Phalon\Cache\Backend\*::get` to use only positive numbers for `lifetime` [11759](https://github.com/phalcon/cphalcon/issues/11759)
- Changed `Phalcon\Logger` to comply with PSR-3. The component has been rewritten to use adapters that alllow logging to different areas. The [#13438](https://github.com/phalcon/cphalcon/issues/13438)
- Renamed `Phalcon\Assets\Resource` namespace to `Phalcon\Assets\Asset` [#12082](https://github.com/phalcon/cphalcon/issues/12082)
- Renamed `Phalcon\Assets\Resource` to `Phalcon\Assets\Asset` [#12082](https://github.com/phalcon/cphalcon/issues/12082)
- Renamed `Phalcon\Assets\ResourceInterface` to `Phalcon\Assets\AssetInterface` [#12082](https://github.com/phalcon/cphalcon/issues/12082)
- Renamed `Phalcon\Assets\Manager::addResource` to `Phalcon\Assets\Manager::addAsset` [#12082](https://github.com/phalcon/cphalcon/issues/12082)
- Renamed `Phalcon\Assets\Manager::addResourceByType` to `Phalcon\Assets\Manager::addAssetByType` [#12082](https://github.com/phalcon/cphalcon/issues/12082)
- Renamed `Phalcon\Assets\Manager::collectionResourcesByType` to `Phalcon\Assets\Manager::collectionAssetsByType` [#12082](https://github.com/phalcon/cphalcon/issues/12082)
- Changed `paginate` in the place of `getPaginate`. Added `previous` in the place of `before`. [#13492](https://github.com/phalcon/cphalcon/issues/13492)
- Scope SQL Column Aliases (on nesting level), in `Phalcon\Mvc\Model\Query`, to prevent overwrite _root_ query's `_sqlColumnAliases` by sub-queries. [#13006](https://github.com/phalcon/cphalcon/issues/13006), [#12548](https://github.com/phalcon/cphalcon/issues/12548) and [#1731](https://github.com/phalcon/cphalcon/issues/1731)
- CLI parameters now work like MVC parameters [#12375](https://github.com/phalcon/cphalcon/pull/12375)
- Changed `Phalcon\Db\Dialect\Postgresql::addPrimaryKey` to make primary key constraints names unique by prefixing them with the table name. [#12629](https://github.com/phalcon/cphalcon/pull/12629)
- Fixed `Phalcon\Mvc\Model\Query::_prepareSelect` overwriting columns with the same alias [#13552](https://github.com/phalcon/cphalcon/issues/13552)
- Changed `Phalcon\Http\RequestInterface` to align with `Phalcon\Http\Request` [#13061](https://github.com/phalcon/cphalcon/pull/13061)
- Renamed `Phalcon\Acl\Resource` to `Phalcon\Acl\Subject` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\ResourceInterface` to `Phalcon\Acl\SubjectInterface` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\ResourceAware` to `Phalcon\Acl\SubjectAware` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\Role` to `Phalcon\Acl\Operation` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\RoleInterface` to `Phalcon\Acl\OperationInterface` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\RoleAware` to `Phalcon\Acl\OperationAware` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\AdapterInterface::addRole` to `Phalcon\Acl\AdapterInterface::addOperation` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\AdapterInterface::isRole` to `Phalcon\Acl\AdapterInterface::isOperation` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\AdapterInterface::isResource` to `Phalcon\Acl\AdapterInterface::isSubject` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\AdapterInterface::addResource` to `Phalcon\Acl\AdapterInterface::addSubject` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\AdapterInterface::addResourceAccess` to `Phalcon\Acl\AdapterInterface::addSubjectAccess` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\AdapterInterface::dropResourceAccess` to `Phalcon\Acl\AdapterInterface::dropSubjectAccess` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\AdapterInterface::getActiveRole` to `Phalcon\Acl\AdapterInterface::getActiveOperation` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\AdapterInterface::getActiveResource` to `Phalcon\Acl\AdapterInterface::getActiveSubject` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\AdapterInterface::getRoless` to `Phalcon\Acl\AdapterInterface::getOperations` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\AdapterInterface::getResources` to `Phalcon\Acl\AdapterInterface::getSubjects` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\Adapter::getActiveRole` to `Phalcon\Acl\AdapterInterface::getActiveOperation` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\Adapter::getActiveResource` to `Phalcon\Acl\AdapterInterface::getActiveSubject` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\Adapter\Memory::addRole` to `Phalcon\Acl\Adapter\Memory::addOperation` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\Adapter\Memory::isRole` to `Phalcon\Acl\Adapter\Memory::isOperation` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\Adapter\Memory::isResource` to `Phalcon\Acl\Adapter\Memory::isSubject` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\Adapter\Memory::addResource` to `Phalcon\Acl\Adapter\Memory::addSubject` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\Adapter\Memory::addResourceAccess` to `Phalcon\Acl\Adapter\Memory::addSubjectAccess` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\Adapter\Memory::dropResourceAccess` to `Phalcon\Acl\Adapter\Memory::dropSubjectAccess` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\Adapter\Memory::getRoless` to `Phalcon\Acl\Adapter\Memory::getOperations` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Renamed `Phalcon\Acl\Adapter\Memory::getResources` to `Phalcon\Acl\Adapter\Memory::getSubjects` [#13639](https://github.com/phalcon/cphalcon/issues/13639)
- Changed `Phalcon\Http\Response::setHeaders` now merges the headers with any pre-existing ones in the internal collection [#12836](https://github.com/phalcon/cphalcon/issues/12836)
- Changed `Phalcon\DI\FactoryDefault` to not load by default
    - the `Phalcon\Session\Adapter\Files` using the name `session`
    - the `Phalcon\Session\Bag` using the name `sessionBag` [#12921](https://github.com/phalcon/cphalcon/issues/12921)
  [#12921](https://github.com/phalcon/cphalcon/issues/12921)
- Changed the `Phalcon\Session` namespace by refactoring the component. `Phalcon\Session\Manager` is now the single component offering session manipulation by using adapters. Each adapter implements PHP's `SessionHandlerInterface`. Available adapters are `Phalcon\Session\Adapter\Files`, `Phalcon\Session\Adapter\Libmemcached`, `Phalcon\Session\Adapter\Noop` and `Phalcon\Session\Adapter\Redis`.  [#12833](https://github.com/phalcon/cphalcon/issues/12833), [#11341](https://github.com/phalcon/cphalcon/issues/11341), [#13535](https://github.com/phalcon/cphalcon/issues/13535)
- Fixed `Phalcon\Mvc\Models` magic method (setter) is fixed for arrays  [#13661](https://github.com/phalcon/cphalcon/issues/13661)
- Fixed `Phalcon\Mvc\Model::skipAttributes` and `Phalcon\Mvc\Model::allowEmptyColumns` allowEmptyStrings & skipAttributes repsect the column mapping. [#12975](https://github.com/phalcon/cphalcon/issues/12975), [#13477](https://github.com/phalcon/cphalcon/issues/13477)
## Removed
- PHP < 7.2 no longer supported
- Removed `xcache` support from adapters [#13628](https://github.com/phalcon/cphalcon/pull/13628)
- Removed `apc` support from adapters (use `apcu`) [#13628](https://github.com/phalcon/cphalcon/pull/13628)
- Removed `memcache` support from adapters (use `libmemcached`) [#13628](https://github.com/phalcon/cphalcon/pull/13628)
- Removed deprecated `Phalcon\Annotations\Adapter\Apc`
- Removed deprecated `Phalcon\Annotations\Adapter\Xcache`
- Removed deprecated `Phalcon\Cache\Backend\Apc`
- Removed deprecated `Phalcon\Cache\Backend\Memcache`
- Removed deprecated `Phalcon\Cache\Backend\Xcache`
- Removed deprecated `Phalcon\Cli\Console::addModules`
- Removed deprecated `Phalcon\Debug::getMajorVersion`
- Removed deprecated `Phalcon\Mvc\Model\Criteria::addWhere`
- Removed deprecated `Phalcon\Mvc\Model\Criteria::order`
- Removed deprecated `Phalcon\Mvc\Model\Metadata\Apc`
- Removed deprecated `Phalcon\Mvc\Model\Metadata\Memcache`
- Removed deprecated `Phalcon\Mvc\Model\Metadata\Xcache`
- Removed deprecated `Phalcon\Mvc\View::getParams`
- Removed deprecated `Phalcon\Mvc\ViewInterface::getParams`
- Removed deprecated `Phalcon\Paginator\Adapter\Model::getPaginate`
- Removed deprecated `Phalcon\Paginator\Adapter\Model - $before`
- Removed deprecated `Phalcon\Paginator\Adapter\Model - $total_pages`
- Removed deprecated `Phalcon\Paginator\Adapter\NativeArray::getPaginate`
- Removed deprecated `Phalcon\Paginator\Adapter\NativeArray - $before`
- Removed deprecated `Phalcon\Paginator\Adapter\NativeArray - $total_pages`
- Removed deprecated `Phalcon\Paginator\Adapter\QueryBuilder::getPaginate`
- Removed deprecated `Phalcon\Paginator\Adapter\QueryBuilder - $before`
- Removed deprecated `Phalcon\Paginator\Adapter\QueryBuilder - $total_pages`
- Removed deprecated `Phalcon\Security::hasLibreSsl`
- Removed deprecated `Phalcon\Security::getSslVersionNumber`
- Removed deprecated `Phalcon\Validation\Validator::isSetOption`
- Removed `Phalcon\Cli\Console::addModules` in favor of `Phalcon\Cli\Console::registerModules`
- Removed `Phalcon\Debug::getMajorVersion` due to the fact that we never use this method
- Removed `Phalcon\Dispatcher::setModelBinding` in favor of `Phalcon\Dispatcher::setModelBinder`
- Removed `Phalcon\Http\RequestInterface::isSecureRequest` in favor of `Phalcon\Http\RequestInterface::isSecure`
- Removed `Phalcon\Http\RequestInterface::isSoapRequested` in favor of `Phalcon\Http\Request::isSoap`
- Removed `Phalcon\Logger\Multiple`
- Removed `Phalcon\Mvc\Collection::validationHasFailed`
- Removed `Phalcon\Mvc\Model\Criteria::order` in favor of `Phalcon\Mvc\Model\Criteria::orderBy`
- Removed `Phalcon\Mvc\Model\Validator\*` in favor of `Phalcon\Validation\Validator\*`
- Removed `Phalcon\Mvc\Micro\Lazyloader::__call` in favor of `Phalcon\Mvc\Micro\Lazyloader::callMethod`
- Removed `Phalcon\Model::reset` [#12317](https://github.com/phalcon/cphalcon/issues/12317)
- Removed `Phalcon\Validation\Message` and `Phalcon\Mvc\Model\Message` in favor of `Phalcon\Messages\Message`
- Removed `Phalcon\Validation\MessageInterface` and `Phalcon\Mvc\Model\MessageInterface` in favor of `Phalcon\Messages\MessageInterface`
- Removed `Phalcon\Validation\Message` and `Phalcon\Mvc\Model\Message` in favor of `Phalcon\Messages\Message`
- Removed `Phalcon\Validation\Message\Group` in favor of `Phalcon\Messages\Messages`
- Removed calling `Phalcon\Mvc\Collection::validate` with object of type `Phalcon\Mvc\Model\ValidatorInterface`
