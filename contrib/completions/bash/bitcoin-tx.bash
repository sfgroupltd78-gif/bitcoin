# bash programmable completion for bitcoin-tx(1)
# Copyright (c) 2016-2022 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

_bitcoin_tx() {
    local cur prev words=() cword
    local bitcoin_tx

    # save and use original argument to invoke bitcoin-tx for -help
    # it might not be in $PATH
    bitcoin_tx="$1"

    COMPREPLY=()
    _get_comp_words_by_ref -n =: cur prev words cword

    case "$cur" in
        load=*:*)
            cur="${cur#load=*:}"
            _filedir
            return 0
            ;;
        *=*)	# prevent attempts to complete other arguments
            return 0
            ;;
    esac

    if [[ "$cword" == 1 || ( "$prev" != "-create" && "$prev" == -* ) ]]; then
        # only options (or an uncompletable hex-string) allowed
        # parse bitcoin-tx -help for options
        local helpopts
        helpopts=$($bitcoin_tx -help | sed -e '/^  -/ p' -e d )
        COMPREPLY=( $( compgen -W "$helpopts" -- "$cur" ) )
    else
        # only commands are allowed
        # parse -help for commands
        local helpcmds
        helpcmds=$($bitcoin_tx -help | sed -e '1,/Commands:/d' -e 's/=.*/=/' -e '/^  [a-z]/ p' -e d )
        COMPREPLY=( $( compgen -W "$helpcmds" -- "$cur" ) )
    fi

    # Prevent space if an argument is desired
    if [[ $COMPREPLY == *= ]]; then
        compopt -o nospace
    fi

    return 0
} &&
complete -F _bitcoin_tx bitcoin-tx

# Local variables:
# mode: shell-script
# sh-basic-offset: 4
# sh-indent-comment: t
# indent-tabs-mode: nil
# End:
# ex: ts=4 sw=4 et filetype=
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