#pragma once

#include "Brick.hpp"

namespace breakout
{
    class BrickUnbreakable : public Brick
    {
    public:
        BrickUnbreakable(const Coordinates &coordinates) : Brick(coordinates, BrickColor::RED)
        {
        }

        BrickDamage collision() override;

        friend std::ostream &operator<<(std::ostream &os, const BrickUnbreakable &brickUnbreakable);
    };
}