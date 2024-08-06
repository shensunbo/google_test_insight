#include "RealDep.h"

#include <iostream>

bool RealDep::doSomething(int _foo) {
    std::cout << "RealDep::doSomething(" << _foo << ")" << std::endl;
    return true;
}

bool RealDep::funcNeedMatcher(Car _car){
    std::cout<<_car.cool<<"  "<<_car.price<<std::endl;
    return true;
}