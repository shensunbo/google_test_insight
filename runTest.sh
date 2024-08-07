#!/bin/bash

previous_dir=$(pwd)
script_path=$(dirname $(realpath $0))

cd $script_path/build/src

if [ "$1" = "--color" ]; then
    GTEST_COLOR=1 ctest "$@" --output-on-failure
else
    ctest "$@" --output-on-failure
fi


cd $previous_dir