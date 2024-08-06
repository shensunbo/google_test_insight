#pragma once

#include "BaseDep.h"
#include <memory>

class BeTested {
public:
    BeTested() = delete;
    BeTested(std::shared_ptr<BaseDep> _dep) : m_dep(std::move(_dep)) {}

    bool funcWithDep(int _foo) { 
        return m_dep->doSomething(_foo); 
    }

    bool setCar(Car _car){
        return m_dep->funcNeedMatcher(_car);
    }
public:
    std::shared_ptr<BaseDep> m_dep;
};