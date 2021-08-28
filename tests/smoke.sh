#!/bin/bash

set -euo pipefail

build_dir=$(realpath $1)
app=$build_dir/bin/susolver

board=$($app -s 42 -g 5)
echo $board
./build/bin/susolver -i $board
