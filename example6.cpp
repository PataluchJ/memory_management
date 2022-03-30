#include <cstdio>
#include <memory>
#include <string>

using ShoppingList = std::shared_ptr<std::FILE>;

ShoppingList makeFile(const char* filename, const char* flags)
{
    ShoppingList list = ShoppingList(fopen(filename, "w"));
    return list;
}

class Partner
{
public:
    void addToFile(std::string element)
    {
       fwrite(element.c_str(), sizeof(element[0]), element.size(), shoppingList.get());
    }

    ShoppingList shoppingList;
};

int main()
{
    Partner boy{};
    boy.shoppingList = makeFile("ShoppingList", "wb");

    Partner girl{};
    girl.shoppingList = boy.shoppingList;
    girl.addToFile("Butter");
    girl.addToFile("Milk");
}
