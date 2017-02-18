<?hh //strict

/**
 * This file is part of hhack/typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Typesafety\Reporter;

use HHPack\Package as package;
use HHPack\Package\VendorPackage;
use HHPack\Typesafety\TypeCheckReporter;

final class ReporterLoader
{

    private VendorPackage $package;

    public function __construct()
    {
        $this->package = VendorPackage::fromItems([
            Pair { 'hhpack\\typesafety\\reporter\\', realpath(__DIR__) }
        ]);
    }

    public function load(string $name, Traversable<mixed> $args = []) : TypeCheckReporter
    {
        $reporterName = ucfirst($name) . 'Reporter';

        $reporter = $this->package->classes(package\implementsInterface(TypeCheckReporter::class))
            ->filter(package\endsWith($reporterName))
            ->firstValue();

        if ($reporter === null) {
            throw new ReporterNotFoundException("Reporter {$reporterName} was not found");
        }

        $parameters = ImmVector::fromItems($args)->toValuesArray();
        return $reporter->instantiate($parameters);
    }

}
