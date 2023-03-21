#include "BrickUnbreakable.hpp"

namespace breakout
{
    BrickDamage BrickUnbreakable::collision()
    {
        std::cout << *this << " => collision " << "BrickDamage::NONE\n";

        return BrickDamage::NONE;
    }

    std::ostream &operator<<(std::ostream &os, const BrickUnbreakable &brickUnbreakable)
    {
        return os << *static_cast<const Brick *>(&brickUnbreakable) << ":BrickUnbreakable";
    }
}