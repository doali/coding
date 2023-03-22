#pragma once

#include <iostream>

namespace breakout
{
    template <typename T=int>
    class Coordinates
    {
    public:
        Coordinates() = default;

        Coordinates(T x, T y) : _x{x}, _y{y}
        {
        }

        Coordinates(const Coordinates<T> &coordinates) : _x{coordinates._x}, _y{coordinates._y}
        {
        }

        Coordinates<T> &operator=(const Coordinates<T> &coordinates)
        {
            if (this == &coordinates)
            {
                return *this;
            }

            _x = coordinates._x;
            _y = coordinates._y;

            return *this;
        }

        bool operator==(const Coordinates<T> &coordinates) const
        {
            if (this == &coordinates)
            {
                return true;
            }
            // return CompareCoordinates<T>(coordinates._x, this->_x) && CompareCoordinates<T>(coordinates._y, this->_y);
            return (_x == coordinates._x) && (_y == coordinates._y);
        }

        bool operator!=(const Coordinates<T> &coordinates) const
        {
            return !(*this == coordinates);
        }

        Coordinates<T> operator+(const Coordinates<T> &coordinates) const
        {
            return Coordinates<T>(_x + coordinates._x, _y + coordinates._y);
        }

        Coordinates<T> operator-(const Coordinates<T> &coordinates) const
        {
            return Coordinates<T>(_x - coordinates._x, _y - coordinates._y);
        }

        Coordinates<T> &operator+=(const Coordinates<T> &coordinates)
        {
            _x += coordinates._x;
            _y += coordinates._y;

            return *this;
        }

        Coordinates<T> &operator-=(const Coordinates<T> &coordinates)
        {
            _x -= coordinates._x;
            _y -= coordinates._y;

            return *this;
        }

        ~Coordinates() = default;

        void writeCoordinates(T x, T y)
        {
            this->_x = x;
            this->_y = y;
        }

        void readCoordinates(T &x, T &y) const
        {
            x = this->_x;
            y = this->_y;
        }

        const Coordinates<T> &getCoordinates() const
        {
            return *this;
        }

        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const Coordinates<U> &coordinates);

    private:
        T _x{0};
        T _y{0};
    };

    template <typename U>
    std::ostream &operator<<(std::ostream &os, const Coordinates<U> &coordinates)
    {
        return os << "[" << coordinates._x << ", " << coordinates._y << "]";
    }
}
