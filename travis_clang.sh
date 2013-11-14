#/bin/bash

# configure Travis CI build server for a C++11 build with Clang

sudo apt-get update
sudo apt-get --force-yes install clang-3.4 clang-3.4-doc libclang-common-3.4-dev libclang-3.4-dev libclang1-3.4 libclang1-3.4-dbg libllvm-3.4-ocaml-dev libllvm3.4 libllvm3.4-dbg lldb-3.4 llvm-3.4 llvm-3.4-dev llvm-3.4-doc llvm-3.4-examples llvm-3.4-runtime cpp11-migrate-3.4 clang-format-3.4
clang -v