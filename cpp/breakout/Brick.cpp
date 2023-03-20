#include "Brick.hpp"

#include <iostream>

namespace breakout
{
    std::ostream &operator<<(std::ostream &os, const Brick &brick)
    {
        // return os << static_cast<const Element>(brick) << ":Brick"; // NO !! Error, that is not what we expect !!
        return os << *static_cast<const Element*>(&brick) << ":Brick"; // YES
    }
}