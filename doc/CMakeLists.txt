# Copyright (c) 2024-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or https://opensource.org/license/mit/.

find_package(Doxygen COMPONENTS dot)

if(DOXYGEN_FOUND)
  set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
  configure_file(Doxyfile.in ${doxyfile} USE_SOURCE_PERMISSIONS)

  # In CMake 3.27, The FindDoxygen module's doxygen_add_docs()
  # command gained a CONFIG_FILE option to specify a custom doxygen
  # configuration file.
  # TODO: Consider using it.
  add_custom_target(docs
    COMMAND Doxygen::doxygen ${doxyfile}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Generating developer documentation"
    VERBATIM USES_TERMINAL
  )
else()
  add_custom_target(docs
    COMMAND ${CMAKE_COMMAND} -E echo "Error: Doxygen not found"
  )
endif()
PULL Tem-plate.md
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