#!/usr/bin/env bash
set -o nounset
set -o errexit
set -o pipefail

python3 ./bootstrap.py
mkdir -p build/
cd build/
cmake ..
make clean
make
make test