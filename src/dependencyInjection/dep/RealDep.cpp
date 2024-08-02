#include "RealDep.h"

#include <iostream>

bool RealDep::doSomething(int _foo) {
    std::cout << "RealDep::doSomething(" << _foo << ")" << std::endl;
    return true;
}