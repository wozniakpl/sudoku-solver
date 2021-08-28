#!/bin/bash

set -euo pipefail

app=$1
which $app > /dev/null # will not exit if app exists

board=$($app -s 42 -g 5)
echo $board
./build/bin/susolver -i $board
