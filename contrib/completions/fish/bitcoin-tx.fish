# Disable files from being included in completions by default
complete --command bitcoin-tx --no-files

# Modified version of __fish_seen_subcommand_from
# Uses regex to detect cmd= syntax
function __fish_bitcoin_seen_cmd
    set -l cmd (commandline -oc)
    set -e cmd[1]
    for i in $cmd
        for j in $argv
            if string match --quiet --regex -- "^$j.*" $i
                return 0
            end
        end
    end
    return 1
end

# Extract options
function __fish_bitcoin_tx_get_options
    set --local cmd (commandline -oc)[1]
    if string match --quiet --regex -- '^-help$|-\?$' $cmd
        return
    end

    for option in ($cmd -help 2>&1 | string match -r '^  -.*' | string replace -r '  -' '-' | string replace -r '=.*' '=')
        echo $option
    end
end

# Extract commands
function __fish_bitcoin_tx_get_commands
    argparse 'commandsonly' -- $argv
    set --local cmd (commandline -oc)[1]
    set --local commands

    if set -q _flag_commandsonly
        set --append commands ($cmd -help | sed -e '1,/Commands:/d' -e 's/=/=\t/' -e 's/(=/=/' -e '/^  [a-z]/ p' -e d | string replace -r '\ \ ' '' | string replace -r '=.*' '')
    else
        set --append commands ($cmd -help | sed -e '1,/Commands:/d' -e 's/=/=\t/' -e 's/(=/=/' -e '/^  [a-z]/ p' -e d | string replace -r '\ \ ' '')
    end

    for command in $commands
        echo $command
    end
end

# Add options
complete \
    --command bitcoin-tx \
    --condition "not __fish_bitcoin_seen_cmd (__fish_bitcoin_tx_get_commands --commandsonly)" \
    --arguments "(__fish_bitcoin_tx_get_options)" \
    --no-files

# Add commands
complete \
    --command bitcoin-tx \
    --arguments "(__fish_bitcoin_tx_get_commands)" \
    --no-files

# Add file completions for load and set commands
complete \
    --command bitcoin-tx \
    --condition 'string match --regex -- "(load|set)=" (commandline -pt)' \
    --force-files
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
