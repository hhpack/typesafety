<?hh //strict

/**
 * This file is part of hhpack\typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\typesafety;

use Exception;

final class ApplicationResult
{

    public function __construct(
        private ResultType $result = ResultType::Ok,
        private ?Exception $exception = null
    )
    {
    }

    public function isOk() : bool
    {
        return ResultType::Ok === $this->result;
    }

    public function isError() : bool
    {
        return ResultType::Error === $this->result;
    }

    public function displayError(Output $output) : void
    {
        if ($this->exception === null) {
            return;
        }
        $output->error($this->exception->getMessage());
        $output->error($this->exception->getTraceAsString());
    }

    public static function Ok() : this
    {
        return new static();
    }

    public static function Error(Exception $exception) : this
    {
        return new static(ResultType::Error, $exception);
    }

}
