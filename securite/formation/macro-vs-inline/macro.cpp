#include <iostream>

// Macro pour calculer le carré d'un nombre
#define SQUARE(x) ((x) * (x))

int main() {
    int a = 2;
    int result = SQUARE(5);
    std::cout << "Square: " << result << std::endl;
    return 0;
}
