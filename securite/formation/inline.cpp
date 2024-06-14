#include <iostream>
 
// Macro pour calculer le carré d'un nombre
#define SQUARE(x) ((x) * (x))

// Utiliser inline a la place des macros
// - car typage

inline int square(int a){
    return a*a;
}
 
int main() {
    int a = 2;
    int b = 3;
    int result = square(a++);
    std::cout << "Square: " << result << std::endl;
    std::cout << "a " << a << std::endl;
    return 0;
}
