#!/usr/bin/env hhvm
<?hh //partial

namespace hhpack\typesafety;

$autoloadFiles = [
    __DIR__ . '/../../../autoload.php',
    __DIR__ . '/../vendor/autoload.php',
    __DIR__ . '/vendor/autoload.php',
    __DIR__ . '/../autoload.php'
];

$composerInstall = false;
foreach ($autoloadFiles as $autoloadFile) {
    if (file_exists($autoloadFile) === false) {
        continue;
    }
    require $autoloadFile;
    $composerInstall = true;
    break;
}

if (!$composerInstall) {
    echo 'You must set up the dependencies, run the following commands:'. PHP_EOL .
        'curl -s http://getcomposer.org/installer | php' . PHP_EOL .
        'php composer.phar install' . PHP_EOL;
    exit(1);
}

unset($composerInstall, $autoloadFiles, $autoloadFile);

main($argv);
