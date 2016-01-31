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

final class ArgumentOptions
{

    private ImmMap<string, mixed> $options;

    public function __construct(
        KeyedTraversable<string, mixed> $options
    )
    {
        $this->options = new ImmMap($options);
    }

    public static function fromItems(KeyedTraversable<string, mixed> $options) : this
    {
        return new static($options);
    }

}
