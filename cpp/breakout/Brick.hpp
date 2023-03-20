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

    class Brick : public Element
    {
    public:
        Brick(Coordinates coordinates) : Element(coordinates)
        {
            std::cout << *this << std::endl;
        }

        Brick(Coordinates coordinates, BrickColor color) : Brick(coordinates)
        {
            _color = color;
        }

        BrickColor color() const
        {
            return _color;
        }

        friend std::ostream &operator<<(std::ostream &os, const Brick &brick);

    private:
        BrickColor _color{BrickColor::BLUE};
    };
}