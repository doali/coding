#pragma once

#include <cmath>

namespace breakout
{
    namespace tools
    {
        constexpr double PI{acos(-1)};

        namespace compare_real
        {
            static constexpr double EPSILON{0.0001f};

            template <typename T>
            static bool CompareReal(T x, T y, double epsilon)
            {
                return (std::fabs(x - y) < epsilon);
            }

            template <typename T>
            static bool CompareCoordinates(T x, T y)
            {
                return CompareReal<T>(x, y, EPSILON);
            }
        }
    }
}