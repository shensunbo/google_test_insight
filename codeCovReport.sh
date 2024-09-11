#!/bin/bash

previous_dir=$(pwd)
script_path=$(dirname $(realpath $0))

cd $script_path/build/src

ctest "$@" --output-on-failure

# NOTE:
# sudo apt-get install lcov
# sudo apt-get install xdg-utils
lcov --capture --directory . --exclude '**/include/**' --output-file coverage.info
genhtml coverage.info --output-directory coverage_report
xdg-open coverage_report/index.html

cd $previous_dir