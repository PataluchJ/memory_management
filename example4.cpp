#include <iostream>
#include <stdexcept>
#include <memory>

void foo()
{
    throw std::runtime_error("Error");
}

class MyPointer
{
public:
    MyPointer(): pointer(std::make_unique<int>(15))
    {
	foo();
    }

    ~MyPointer() {}
    std::unique_ptr<int> pointer;
};

int main()
{
    try
    {
        MyPointer pointerTest;
        std::cout <<&(*pointerTest.pointer) << std::endl;
    }
    catch(std::runtime_error const& p_err)
    {
        std::cout << "Ups: " << p_err.what() << std::endl;
    }
}
