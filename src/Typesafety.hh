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

use HHPack\Getopt as cli;
use HHPack\Getopt\App\ApplicationSpec;
use HHPack\Typesafety\Reporter\ReporterNotFoundException;

final class Typesafety implements Application
{

    const string NAME = 'typesafety';
    const string VERSION = '0.7.5';

    private ApplicationSpec $spec;

    public function __construct()
    {
        $this->spec = cli\app(static::NAME)
            ->usage("  {app.name} [OPTIONS] [DIRECTORY]\n\n")
            ->version(static::VERSION)
            ->options([
                cli\bool_option('help', '-h|--help', false, 'display help message'),
                cli\bool_option('version', '-v|--version', false, 'display version'),
                cli\string_option('reporter', '-r|--reporter=?', 'text', 'specify the reporter to use')
            ]);
    }

    public async function run(Traversable<string> $argv) : Awaitable<ApplicationResult>
    {
        $args = ImmVector::fromItems($argv)->skip(1);
        $result = $this->spec->parse($args);

        $context = new TypeCheckContext(
            Arguments::fromItems($result->arguments()),
            ArgumentOptions::fromItems($result->options())
        );

        if ($context->isVersion()) {
            $this->spec->displayVersion();
            return ApplicationResult::Ok();
        }

        if ($context->isHelp()) {
            $this->spec->displayHelp();
            return ApplicationResult::Ok();
        }

        return await $this->check($context);
    }

    public async function check(ApplicationContext $context) : Awaitable<ApplicationResult>
    {
        try {
            await $context->execute();
        } catch (ReporterNotFoundException $exception) {
            return ApplicationResult::Error($exception);
        }

        return ApplicationResult::Ok();
    }

}
