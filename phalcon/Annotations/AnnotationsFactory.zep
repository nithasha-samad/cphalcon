
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use Phalcon\Annotations\Adapter\AbstractAdapter;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Helper\Arr;

/**
 * Factory to create annotations components
 */
class AnnotationsFactory extends AbstractFactory
{
    /**
     * AdapterFactory constructor.
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * Factory to create an instace from a Config object
     */
    public function load(var config) -> var
    {
        var name, options;

        let config = this->checkConfig(config),
            name   = config["adapter"];

        unset config["adapter"];

        let options = Arr::get(config, "options", []);

        return this->newInstance(name, options);
    }

    /**
     * Create a new instance of the adapter
     */
    public function newInstance(string! name, array! options = []) -> <AbstractAdapter>
    {
        var definition;

        this->checkService(name);

        if !isset this->services[name] {
            let definition           = this->mapper[name],
                this->services[name] = new {definition}(options);
        }

        return this->services[name];
    }

    /**
     * The available adapters
     */
    protected function getAdapters() -> array
    {
        return [
            "apcu"   : "\\Phalcon\\Annotations\\Adapter\\Apcu",
            "memory" : "\\Phalcon\\Annotations\\Adapter\\Memory",
            "stream" : "\\Phalcon\\Annotations\\Adapter\\Stream"
        ];
    }
}
