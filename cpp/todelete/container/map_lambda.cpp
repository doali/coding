#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <cassert>

enum class DIRECTION // better than old plain enum
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

static void action_right(void) { std::cout << "RIGHT" << std::endl; } // visibility only in this file

namespace test
{
    static void test_map()
    {
        // Modern way !!
        std::function<void(void)> action_up = []()
        { std::cout << "UP" << std::endl; };

        // Old way...
        void (*pf_action_right)(void);
        pf_action_right = action_right;

        // Mix...
        void (*action_down)(void) = []()
        { std::cout << "DOWN" << std::endl; };

        // Enum -> function
        std::map<DIRECTION, std::function<void(void)>> l_action{
            {DIRECTION::UP, action_up},
            {DIRECTION::RIGHT, pf_action_right},
            {DIRECTION::DOWN, action_down},
            {DIRECTION::LEFT, []()
             { std::cout << "LEFT" << std::endl; }}};

        l_action[DIRECTION::UP]();
        l_action[DIRECTION::RIGHT]();
        l_action[DIRECTION::DOWN]();
        l_action[DIRECTION::LEFT]();

        auto test_iterator = [&]() -> void
        {
            std::cout << "test_iterator" << std::endl;
            auto it = l_action.begin();
            while (it != l_action.end())
            {
                l_action[(it++)->first]();
            }
        };

        auto test_range = [&]() -> void
        {
            std::cout << "test_range" << std::endl;
            for (auto &element : l_action)
            {
                l_action[element.first](); // OK : element.first corresponds to the key
                // (element.second)();        // OK :element.second corresponds to the value
            }
        };

        test_range();
        test_iterator();
    }

    static void test_vector()
    {
        std::cout << "test_vector" << std::endl;
        std::vector<int> v{1, 2, 3, 6, 7};
        std::vector<int>::iterator it = v.begin(); // auto it = v.begin();

        // A new iterator is returned... !!
        it = v.insert(it, 0);
        std::cout << *it << std::endl;
        std::cout << *++it << std::endl;

        // Insertion of an old array (or raw array like in C)
        int o_arr[] = {4, 5};
        auto it_start = v.begin();
        v.insert(it_start + 4, o_arr, o_arr + 2);

        auto print_v = [](const auto v) -> void
        {
            for (auto &e : v)
                std::cout << e << " ";
            std::cout << std::endl;
        };
        print_v(v);
    }
}

int main(void)
{
    test::test_map();
    test::test_vector();

    return EXIT_SUCCESS;
}