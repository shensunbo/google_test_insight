# google_test_insight
google test(gtest) insight

# build 
```
mkdir build
cd build/
cmake ..
make
```

# run unit test
`../runTest.sh`
`../runTest.sh --color -VV`

# gcov
`lcov --capture --directory ./ --output-file coverage.info --exclude '*/include/*' --exclude 'include/*' --ignore-errors mismatch`

`genhtml coverage.info --output-directory coverage_report`

# gcov
`lcov --capture --directory ./ --output-file coverage.info --exclude '*/include/*' --exclude 'include/*' --ignore-errors mismatch`

`genhtml coverage.info --output-directory coverage_report`
