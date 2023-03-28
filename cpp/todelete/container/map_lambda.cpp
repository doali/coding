#include <iostream>
#include <map>
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
    }
}

int main(void)
{
    test::test_map();

    return EXIT_SUCCESS;
}