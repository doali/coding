#pragma once

#include "Element.hpp"

#include <iostream>

namespace breakout
{
    enum class BrickColor
    {
        RED,
        GREEN,
        BLUE
    };

    enum class BrickDamage
    {
        NONE,
        PARTIAL,
        FULL
    };

    class Brick : public Element
    {
    public:
        Brick(const Coordinates<double> &coordinates) : Element(coordinates)
        {
            std::cout << *this << std::endl;
        }

        Brick(const Coordinates<double> &coordinates, const BrickColor &color) : Brick(coordinates)
        {
            _color = color;
        }

        virtual ~Brick() = default;

        BrickColor color() const
        {
            return _color;
        }

        virtual BrickDamage collision();

        friend std::ostream &operator<<(std::ostream &os, const Brick &brick);

    protected:
        BrickColor _color{BrickColor::BLUE};
    };
}