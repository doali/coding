#include <iostream>
#include <vector>
#include <iterator>
#include <functional>

template <typename T>
static std::vector<T> filter(std::vector<T> &p_rVector, const std::function<bool(const T &p_rElement)> &p_rFunction)
{
    std::vector<T> l_Ret{};

    for (const T &l_rElement : p_rVector)
    {
        if (p_rFunction(l_rElement))
        {
            l_Ret.push_back(l_rElement);
        }
    }

    return l_Ret;
}

template <typename T>
static std::ostream &operator<<(std::ostream &os, const std::vector<T> &p_rVect)
{
    typename std::vector<T>::const_iterator l_It = p_rVect.begin();

    os << "[";

    if (l_It != p_rVect.end())
    {
        os << *l_It;

        while (l_It + 1 != p_rVect.end())
        {
            l_It++;
            os << " " << *l_It;
        }
    }
    os << "]";

    return os;
}

template <typename T>
static void print_list(const std::vector<T> &p_rVect)
{
    std::cout << p_rVect << std::endl;
}

static bool heaven(int p_Element)
{
    return p_Element % 2 == 0;
}

int main(int argc, char **argv)
{
    std::vector<int> l_Vect{0, 1, 2, 3, 4, 5, 6, 7};
    print_list(l_Vect);

    print_list<int>(
        filter<int>(l_Vect, heaven));

    return 0;
}