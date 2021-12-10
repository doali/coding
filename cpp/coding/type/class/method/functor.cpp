#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
static void display(std::vector<T> const &v)
{
    for (T const &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

struct Foncteur
{
    std::string _pattern;

    Foncteur(std::string const &pattern) : _pattern(pattern) {}

    void operator()(std::string &s)
    {
        s += _pattern;
    }
};

int main()
{
    Foncteur foncteur{"-ok-"};

    std::vector<std::string> v{"0", "1", "2", "3", "4", "5"};
    display(v);

    foncteur = std::for_each(v.begin(), v.end(), foncteur);
    display(v);

    return 0;
}