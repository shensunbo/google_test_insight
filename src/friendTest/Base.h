#include <string>

class Base{
public:
    Base(int a, std::string str): num_(a), name_(str) {

    }
    ~Base() = default;

    void setNum(int num) {num_ = num;}
    void setName(std::string name) {name_ = name;}

    // for unit test only
    friend class BaseTest;
    friend void memberStateTest(const Base& base, int a, std::string str);
private:
    int num_;
    std::string name_;
};