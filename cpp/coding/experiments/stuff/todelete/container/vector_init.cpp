#include <iostream>
#include <vector>
#include <cassert>

namespace test
{
    static void test_front_back()
    {
        std::vector<int> v;
        v.push_back(1);
        v.insert(v.begin(), 0);

        assert(v[0] == 0);
        assert(v[1] == 1);

        int tmp{v[0]};
        v.front() = v.back();
        v.back() = tmp;

        assert(v[0] == 1);
        assert(v[1] == 0);
    }

    static void test_init()
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
    }
}

int main(void)
{
    test::test_front_back();
    test::test_init();

    return EXIT_SUCCESS;
}