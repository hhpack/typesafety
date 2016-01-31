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

use hhpack\typechecker\TypeCheckerClient;
use hhpack\getopt as cli;
use hhpack\getopt\app\ApplicationSpec;

final class Application
{

    const NAME = 'typesafety';
    const VERSION = '0.5.0';

    private ApplicationSpec $spec;

    public function __construct()
    {
        $this->spec = cli\app(static::NAME)
            ->version(static::VERSION)
            ->options([
                cli\bool_option('help', '-h|--help', false, 'display help message'),
                cli\bool_option('version', '-v|--version', false, 'display version')
            ]);
    }

    public async function run(Traversable<string> $argv) : Awaitable<void>
    {
        $args = ImmVector::fromItems($argv)->skip(1);
        $result = $this->spec->parse($args);

        $context = new ApplicationContext(
            Arguments::fromItems($result->arguments()),
            ArgumentOptions::fromItems($result->options())
        );

        if ($context->isVersion()) {
            return $this->spec->displayVersion();
        }

        if ($context->isHelp()) {
            return $this->spec->displayHelp();
        }

        await $this->check($context);
    }

    public async function check(Context $context) : Awaitable<void>
    {
        $context->started();

        $client = new TypeCheckerClient( $context->rootDirectory() );

        await $client->restart();
        $result = await $client->check();

        $context->finish();

        await $context->report($result);
        $context->terminated($result);
    }

}
