#include "BeTested.h"
#include "RealDep.h"
#include <memory>

int main() {
    BeTested tested(std::make_shared<RealDep>());
    tested.funcWithDep(8);
    return 0;
}