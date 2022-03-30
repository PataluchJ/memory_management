#include <iostream>
#include <stdexcept>
#include <memory>

class CustomError : public std::logic_error{
public:
    explicit CustomError(const std::string& message)
	: std::logic_error(message) {}
    explicit CustomError(const char* message)
	: std::logic_error(message) {}

    virtual ~CustomError() noexcept {}

private:

};

void validateArguments(int argc)
{
    if(argc != 2)
    {
        std::cerr << "You need to pass 1 argument" << std::endl;
        exit(-1);
    }
}

class Resource
{
public:
    void use(const char* arg)
    {
        std::cout << "Using resource. Passed " << *arg << std::endl;
        if (*arg == 'd')
        {
            throw CustomError("Passed d. d is prohibited.");
        }
    }
};

int main(int argc, char* argv[])
{
    validateArguments(argc);

    const char* argument = argv[1];
    Resource* rsc = nullptr;

    try
    {
        rsc = new Resource();
        rsc->use(argument);
    }
    catch (CustomError& e)
    {
        std::cout << e.what() << std::endl;
    }
    if(rsc != nullptr)
	delete rsc;
    return 0;
}

