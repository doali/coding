#include <iostream>
#include <vector>
#include <algorithm>

struct Foncteur {
    static int const AFFINE = 2;
    int _coeff;

    Foncteur(int const &coeff) {
        _coeff = coeff;
    }

    int operator() (int &a) {
        a = _coeff * a + Foncteur::AFFINE;
    }
};

template <typename T>
static void display(std::vector<T> const &v) {
    for (T const &e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main() {
    Foncteur foncteur{2};  

    std::vector<int> v{0, 1, 2, 3, 4, 5};
    display(v);

    std::for_each(v.begin(), v.end(), foncteur);
    display(v);

    return 0;
}