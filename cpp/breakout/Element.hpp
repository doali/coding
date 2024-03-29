#pragma once

#include "Coordinates.hpp"

#include <iostream>

namespace breakout
{
    class Element
    {
    public:
        Element() : _id{++ELEMENT_TOTAL}
        {
            // std::cout << *this << std::endl;
        }

        Element(const Coordinates<double> &position) : _position{position}, _id{++ELEMENT_TOTAL}
        {
            // std::cout << *this << std::endl;
        }

        Element(const Element &element) : _position(element._position), _id{++ELEMENT_TOTAL}
        {
            // std::cout << "copy" << *this << std::endl;
        }

        virtual ~Element() = default;

        Element &operator=(const Element &element)
        {
            if (this == &element)
            {
                return *this;
            }

            Coordinates<double> position;
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

        void writePosition(const Coordinates<double> &position)
        {
            _position = position;
        }

        void readPosition(Coordinates<double> &position) const
        {
            position = _position;
        }

        const Coordinates<double> &getPosition() const
        {
            return _position;
        }

        unsigned int getId() const
        {
            return _id;
        }

        static unsigned int total()
        {
            return ELEMENT_TOTAL;
        }

        static void reinitTotal()
        {
            ELEMENT_TOTAL = 0;
        }

        friend std::ostream &operator<<(std::ostream &os, const Element &element);

    protected:
        static unsigned int ELEMENT_TOTAL;

        Coordinates<double> _position{};
        unsigned int _id{0};
    };
}