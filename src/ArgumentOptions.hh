<?hh //strict

/**
 * This file is part of hhack/typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Typesafety;

final class ArgumentOptions
{

    private ImmMap<string, mixed> $options;

    public function __construct(
        KeyedTraversable<string, mixed> $options = []
    )
    {
        $this->options = new ImmMap($options);
    }

    public function containsKey(string $name) : bool
    {
        return $this->options->containsKey($name);
    }

    public function contains(string $name) : bool
    {
        return $this->options->contains($name);
    }

    public function at(string $name) : mixed
    {
        return $this->options->at($name);
    }

    public static function fromItems(KeyedTraversable<string, mixed> $options) : this
    {
        return new static($options);
    }

}
