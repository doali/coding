#include "Coordinates.hpp"
#include <iostream>

namespace breakout
{
    std::ostream &operator<<(std::ostream &os, const Coordinates<double> &coordinates)
    {
        return os << "[" << coordinates._x << ", " << coordinates._y << "]";
    }
}