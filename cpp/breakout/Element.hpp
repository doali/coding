#pragma once

#include "Coordinates.hpp"

#include <iostream>

namespace breakout
{
    class Element
    {
    public:
        Element(const Coordinates position = Coordinates{}) : _position{position}, _id{++ELEMENT_TOTAL}
        {
            // std::cout << *this << std::endl;
        }

        Element(const Element &element) : _position(element._position), _id{++ELEMENT_TOTAL}
        {
            // std::cout << "copy" << *this << std::endl;
        }

        Element &operator=(const Element &element)
        {
            if (this == &element)
            {
                return *this;
            }

            Coordinates position;
            element.readPosition(position);
            writePosition(position);

            return *this;
        }

        bool operator==(const Element &element)
        {
            if (this == &element)
            {
                return true;
            }

            return (_position == element._position);
        }

        bool operator!=(const Element &element)
        {
            return !(*this == element);
        }

        void writePosition(const Coordinates &position)
        {
            _position = position;
        }

        void readPosition(Coordinates &position) const
        {
            position = _position;
        }

        unsigned int getId() const
        {
            return _id;
        }

        static unsigned int total()
        {
            return ELEMENT_TOTAL;
        }

        friend std::ostream &operator<<(std::ostream &os, const Element &element);

    private:
        static unsigned int ELEMENT_TOTAL;

        Coordinates _position{};
        unsigned int _id{0};
    };
}