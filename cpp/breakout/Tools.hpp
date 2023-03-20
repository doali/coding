#pragma once

#include <cmath>

namespace tools
{
    namespace compare_real
    {
        static constexpr double EPSILON{0.0001f};

        static bool CompareReal(double x, double y, double epsilon)
        {
            return (std::fabs(x - y) < epsilon);
        }

        static bool CompareCoordinates(double x, double y)
        {
            return CompareReal(x, y, EPSILON);
        }
    }
}