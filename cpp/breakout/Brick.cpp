#include "Brick.hpp"

#include <iostream>

namespace breakout
{
    BrickDamage Brick::collision()
    {
        // std::cout << *this << " => collision " << "BrickDamage::FULL\n";

        return BrickDamage::FULL;
    }

    std::ostream &operator<<(std::ostream &os, const Brick &brick)
    {
        // return os << static_cast<const Element>(brick) << ":Brick"; // NO !! Copy constructor is called !! That is not what we expect !!
        return os << *static_cast<const Element *>(&brick) << ":Brick"; // YES
    }
}