#include "Element.hpp"

namespace breakout
{
    unsigned int Element::ELEMENT_TOTAL{0};

    std::ostream& operator<<(std::ostream &os, const Element& element)
    {
        return os << "{Element: _id:" << element._id << " of " << Element::ELEMENT_TOTAL << "; _position:" << element._position << "}";
    }
}