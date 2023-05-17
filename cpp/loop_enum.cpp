#include <iostream>
#include <map>
#include <functional>
#include <chrono>
#include <thread>
#include <type_traits>
#include <cstdlib>
#include <vector>

namespace game
{
    enum class ACTION
    {
        IDLE,
        WALK,
        JUMP,
        RUN
    };

    static std::string enumActionToString(const ACTION &action)
    {
        switch (action)
        {
        case ACTION::IDLE:
            return "IDLE";
        case ACTION::WALK:
            return "WALK";
        case ACTION::JUMP:
            return "JUMP";
        case ACTION::RUN:
            return "RUN";
        default:
            break;
        }

        return "";
    }

    template <typename T>
    struct BaseAction
    {
        BaseAction(ACTION action = ACTION::IDLE) : _action{action}
        {
            initMapAction();
        }

        static void infoAction(const game::ACTION action)
        {
            std::cout << enumActionToString(action) << std::endl;
        }

        void initMapAction()
        {
            _mapAction[ACTION::IDLE] = BaseAction::infoAction;
            _mapAction[ACTION::WALK] = BaseAction::infoAction;
            _mapAction[ACTION::JUMP] = BaseAction::infoAction;
            _mapAction[ACTION::RUN] = BaseAction::infoAction;
        };

        ACTION _action;
        std::map<ACTION, std::function<void(T)>> _mapAction;
    };
}

std::ostream &operator<<(std::ostream &os, const game::ACTION &action)
{
    os << static_cast<std::underlying_type<game::ACTION>::type>(action); // type_traits
    return os;
}

bool condition()
{
    static unsigned int counter{10};
    return (counter-- > 0);
}

void loop(std::function<bool()> fCond, game::BaseAction<game::ACTION> &action)
{
    auto aleaAction = []() -> game::ACTION {
        static std::vector<game::ACTION> tabAction = {
            game::ACTION::IDLE,
            game::ACTION::WALK,
            game::ACTION::JUMP,
            game::ACTION::RUN
        };

        auto randUpToMax = [](const unsigned int max) -> unsigned int {
            return std::rand() % max;
        };

        return tabAction[randUpToMax(tabAction.size() - 1)];
    };
    
    while (fCond())
    {
        action._mapAction[game::ACTION::IDLE](aleaAction());
        // action._mapAction[game::ACTION::IDLE](game::ACTION::IDLE);
        // game::BaseAction<game::ACTION>::infoAction(game::ACTION::IDLE);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "fin" << std::endl;
}

int main()
{
    try
    {
        game::BaseAction<game::ACTION> bAction;

        loop(condition, bAction);
    }

    catch (std::exception &e)

    {
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}