<?hh //strict

/**
 * This file is part of hhpack\typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\typesafety\reporter;

use hhpack\package as package;
use hhpack\package\selector as selector;
use hhpack\package\Package;
use hhpack\typesafety\Reporter;
use RuntimeException;

final class ReporterLoader
{

    private Package $package;

    public function __construct()
    {
        $this->package = package\package(shape(
            'namespace' => 'hhpack\\typesafety\\reporter\\',
            'packageDirectory' => realpath(__DIR__)
        ));
    }

    public function load(string $name, Traversable<mixed> $args = []) : Reporter
    {
        $reporterName = ucfirst($name) . 'Reporter';

        $reporter = $this->package->classes(selector\implementsInterface(Reporter::class))
            ->select(selector\endsWith($reporterName))
            ->toImmVector()
            ->firstValue();

        if ($reporter === null) {
            throw new RuntimeException('invalid reporter');
        }

        $parameters = ImmVector::fromItems($args)->toValuesArray();
        return $reporter->instantiate($parameters);
    }

}
