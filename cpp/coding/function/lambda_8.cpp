#include <iostream>
#include <vector>
#include <algorithm>

auto display_vector(std::vector<int> const v) {
    for (int const &e: v) { std::cout << e << " "; }
    std::cout << std::endl;
}

int sum(std::vector<int> const &v) {
    int res = 0;
    for (int const &e: v) { res += e; }
    return res;
}

int main(int, char**) {
    std::vector<int> v{1, 2, 3, 4, 5};
    display_vector(v);

    int res = (v.size() * (v.size() + 1) / 2);
    std::cout << res << std::endl;

    int res_lambda = 0;
    std::for_each(v.begin(), v.end(), ([&res_lambda](const int &e) -> int {
        res_lambda += e;
        return res_lambda;
    }));
    std::cout << res_lambda << std::endl;

    int res_fonction = sum(v);
    std::cout << res_fonction << std::endl;

    display_vector(v);
}
