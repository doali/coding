#include <iostream>

/* Explanations by microsoft
 * https://docs.microsoft.com/fr-fr/cpp/cpp/lambda-expressions-in-cpp?view=msvc-160
 */

int main(void) {
    auto y = [] (int first, int second)
    {
        return first + second;
    };

    int res = y(1, 10);

    std::cout << res << std::endl;

    int ret = ([] (int first, int second)
    {
        return first + second;
    })(10, 10);

    std::cout << ret << std::endl;

return 0;
}