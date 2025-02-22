
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator\File\Size;

use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\Validator\File\Size\Min;
use Phalcon\Validation\Validator\File\AbstractFile;

/**
 * Checks if a value has a correct file
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File\Size;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Min(
 *         [
 *             "size"     => "2M",
 *             "included" => true,
 *             "message"  => ":field exceeds the min filesize (:size)",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Min(
 *         [
 *             "size" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "included" => [
 *                 "file"        => false,
 *                 "anotherFile" => true,
 *             ],
 *             "message" => [
 *                 "file"        => "file exceeds the min filesize 2M",
 *                 "anotherFile" => "anotherFile exceeds the min filesize 4M",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class Min extends AbstractFile
{
    protected template = "File :field can not have the minimum size of :size";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var bytes, fileSize, included = false, replacePairs, result, size, value;

        // Check file upload
        if this->checkUpload(validation, field) === false {
            return false;
        }

        let value = validation->getValue(field),
            size = this->getOption("size");

        if typeof size == "array" {
            let size = size[field];
        }

        let bytes = round(this->getFileSizeInBytes(size), 6),
            fileSize = round(floatval(value["size"]), 6);

        let included = this->getOption("included");

        if typeof included == "array" {
            let included = (bool) included[field];
        } else {
            let included = (bool) included;
        }

        if included {
            let result = fileSize >= bytes;
        } else {
            let result = fileSize > bytes;
        }

        if result {
            let replacePairs = [
                ":size"  : size
            ];

            validation->appendMessage(
                this->messageFactory(validation, field, replacePairs)
            );

            return false;
        }

        return true;
    }
}
