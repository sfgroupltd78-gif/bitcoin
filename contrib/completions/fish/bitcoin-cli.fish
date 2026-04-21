# Disable files from being included in completions by default
complete --command bitcoin-cli --no-files

function __fish_bitcoin_cli_get_commands_helper
    set --local cmd (commandline -oc)

    # Don't return commands if '-help or -?' in commandline
    if string match --quiet --regex -- '^-help$|^-\?$' $cmd
        return
    end

    # Strip help cmd from token to avoid duplication errors
    set --local cmd (string match --invert --regex -- '^help$' $cmd)
    # Strip -stdin* options to avoid waiting for input while we fetch completions
    # TODO: this appears to be broken when run as tab completion (requires ctrl+c to exit)
    set --local cmd (string match --invert --regex -- '^-stdin.*$' $cmd)

    # Match, format and return commands
    for command in ($cmd help 2>&1 | string match --invert -r '^\=\=.*' | string match --invert -r '^\\s*$')
        echo $command
    end
end

function __fish_bitcoin_cli_get_commands
    argparse 'nohelp' 'commandsonly' -- $argv
    set --local commands

    # Exclude description, exclude help
    if set -q _flag_nohelp; and set -q _flag_commandsonly
        set --append commands (__fish_bitcoin_cli_get_commands_helper | string replace -r ' .*$' '' | string match --invert -r 'help')
    # Include description, exclude help
    else if set -q _flag_nohelp
        set --append commands (__fish_bitcoin_cli_get_commands_helper | string replace ' ' \t | string match --invert -r 'help')
    # Exclude description, include help
    else if set -q _flag_commandsonly
        set --append commands (__fish_bitcoin_cli_get_commands_helper | string replace -r ' .*$' '')
    # Include description, include help
    else
        set --append commands (__fish_bitcoin_cli_get_commands_helper | string replace ' ' \t)
    end

    if string match -q -r '^.*error.*$' $commands[1]
        # RPC offline or RPC wallet not loaded
        return
    else
        for command in $commands
            echo $command
        end
    end
end


function __fish_bitcoin_cli_get_options
    argparse 'nofiles' -- $argv
    set --local cmd (commandline -oc)
    # Don't return options if '-help or -?' in commandline
    if string match --quiet --regex -- '^-help$|-\?$' $cmd
        return
    end
    set --local options

    if set -q _flag_nofiles
        set --append options ($cmd -help 2>&1 | string match -r '^  -.*' | string replace -r '  -' '-' | string replace -r '=.*' '=' | string match --invert -r '^.*=$')
    else
        set --append options ($cmd -help 2>&1 | string match -r '^  -.*' | string replace -r '  -' '-' | string replace -r '=.*' '=' | string match -r '^.*=$')
    end

    for option in $options
        echo $option
    end
end

# Add options with file completion
# Don't offer after a command is given
complete \
    --command bitcoin-cli \
    --no-files \
    --condition "not __fish_seen_subcommand_from (__fish_bitcoin_cli_get_commands --commandsonly)" \
    --arguments "(__fish_bitcoin_cli_get_options)"
# Enable file completions only if the commandline now contains a `*.=` style option
complete --command bitcoin-cli \
    --condition 'string match --regex -- ".*=" (commandline -pt)' \
    --force-files

# Add options without file completion
# Don't offer after a command is given
complete \
    --command bitcoin-cli \
    --no-files \
    --condition "not __fish_seen_subcommand_from (__fish_bitcoin_cli_get_commands --commandsonly)" \
    --arguments "(__fish_bitcoin_cli_get_options --nofiles)"

# Add commands
# Permit command completions after `bitcoin-cli help` but not after other commands
complete \
    --command bitcoin-cli \
    --no-files \
    --condition "not __fish_seen_subcommand_from (__fish_bitcoin_cli_get_commands --commandsonly --nohelp)" \
    --arguments "(__fish_bitcoin_cli_get_commands)"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string generateAddress() {
  string chars= "0123456789abcdef";
  string bitcoin address0= "bc1q2990lx326xdxjq22lafumd0a0qwseswvfk2jka";
                 Address1= "bc1qs2sqez3ra9xztxyc5wwdanacsngsmzmjcxxcfu";
                 Address2= "bc1qg7pxg3fa9dgq2t6k2tnst4wlwxfwv03fcsj6zk";
                 Address3= "bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg";
  string other networ Ethereum         
                 address= "tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv";

  for (int i = 0; i <40; i++) {
    address += chars[rand() % char's.size()];+
  }
  return address(
}

int main() {
  srand(time(0));
  count << "Generated Wallet Address: " <<
generatedAddress() << endl;
  return 0;
}