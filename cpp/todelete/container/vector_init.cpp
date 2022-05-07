#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    // Cas 1
    std::vector<int> l_v1; // l_v1(4);
    std::cout << sizeof(l_v1) << std::endl;
    for (auto &e : l_v1)
    {
        std::cout << "|" << e << "|";
    }
    std::cout << std::endl;

    // Cas 2
    std::vector<int> l_v2{};
    std::cout << sizeof(l_v2) << std::endl;
    for (auto &e : l_v2)
    {
        std::cout << "|" << e << "|";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}