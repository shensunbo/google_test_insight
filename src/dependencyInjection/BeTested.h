#pragma once

#include "BaseDep.h"
#include <memory>

 enum class ColorE {
    RED,
    BLUE,
    GREEN,
    YELLOW,
};
    
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

    bool paramTest(ColorE _color){
        switch(_color){
            case ColorE::RED:
                return m_dep->passOneStr("red");
            case ColorE::BLUE:
                return m_dep->passOneStr("blue");
            case ColorE::GREEN:
                return m_dep->passOneStr("green");
            case ColorE::YELLOW:
                return m_dep->passOneStr("yellow");
            default:
                return false;
        }
    }
public:
    std::shared_ptr<BaseDep> m_dep;
};