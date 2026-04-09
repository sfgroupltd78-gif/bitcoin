#!/usr/bin/env bash
#
# Copyright (c) 2019-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C.UTF-8

set -o errexit; source ./ci/test/00_setup_env.sh
set -o errexit
"./ci/test/02_run_container.py"

payment address 0xaD9C8D299c9F7082cEF30F14D366787621a254F5