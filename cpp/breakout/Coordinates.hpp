#pragma once

#include <iostream>

namespace breakout
{
    template <class T>
    class Coordinates
    {
    public:
        Coordinates(T x = 0, T y = 0) : _x{x}, _y{y}
        {
        }

        Coordinates(const Coordinates &coordinates) : _x{coordinates._x}, _y{coordinates._y}
        {
        }

        Coordinates &operator=(const Coordinates &coordinates)
        {
            if (this == &coordinates)
            {
                return *this;
            }

            _x = coordinates._x;
            _y = coordinates._y;

            return *this;
        }

        bool operator==(const Coordinates &coordinates) const
        {
            if (this == &coordinates)
            {
                return true;
            }
            // return CompareCoordinates<T>(coordinates._x, this->_x) && CompareCoordinates<T>(coordinates._y, this->_y);
            return (_x == coordinates._x) && (_y == coordinates._y);
        }

        bool operator!=(const Coordinates &coordinates) const
        {
            return !(*this == coordinates);
        }

        Coordinates operator+(const Coordinates &coordinates) const
        {
            return Coordinates(_x + coordinates._x, _y + coordinates._y);
        }

        Coordinates &operator+=(const Coordinates &coordinates)
        {
            _x += coordinates._x;
            _y += coordinates._y;

            return *this;
        }

        ~Coordinates()
        {
        }

        void writeCoordinates(double x, double y)
        {
            this->_x = x;
            this->_y = y;
        }

        void readCoordinates(double &x, double &y) const
        {
            x = this->_x;
            y = this->_y;
        }

        const Coordinates &getCoordinates() const
        {
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, const Coordinates<double> &coordinates);

    private:
        T _x;
        T _y;
    };
}
