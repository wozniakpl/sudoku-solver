#!/bin/bash

set -euo pipefail

app=$(realpath $1)

board=$($app -s 42 -g 5)
echo $board
./build/bin/susolver -i $board
