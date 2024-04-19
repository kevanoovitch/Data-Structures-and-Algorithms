#include <vector>
#include <iostream>

int main()
{

    std::vector<int> Test = {1, 2, 8};

    std::cout << Test.size() - 1 << std::endl;
    std::cout << Test.back() << std::endl;

    for (int i = 0; i < Test.back(); i++)
    {
        std::cout << Test[i] << std::endl;
    }

    return 0;
}