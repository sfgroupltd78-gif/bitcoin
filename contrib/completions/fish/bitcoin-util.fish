# Disable files from being included in completions by default
complete --command bitcoin-util --no-files

# Extract options
function __fish_bitcoin_util_get_options
    set --local cmd (commandline -opc)[1]
    set --local options

    set --append options ($cmd -help 2>&1 | string match -r '^  -.*' | string replace -r '  -' '-' | string replace -r '=.*' '=')

    for option in $options
        echo $option
    end
end

# Extract commands
function __fish_bitcoin_util_get_commands
    set --local cmd (commandline -opc)[1]
    set --local commands

    set --append commands ($cmd -help | sed -e '1,/Commands:/d' -e 's/=/=\t/' -e 's/(=/=/' -e '/^  [a-z]/ p' -e d | string replace -r '\ \ ' '')
    for command in $commands
        echo $command
    end
end

# Add options
complete \
    --command bitcoin-util \
    --condition "not __fish_seen_subcommand_from (__fish_bitcoin_util_get_commands)" \
    --arguments "(__fish_bitcoin_util_get_options)"

# Add commands
complete \
    --command bitcoin-util \
    --condition "not __fish_seen_subcommand_from (__fish_bitcoin_util_get_commands)" \
    --arguments "(__fish_bitcoin_util_get_commands)"
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