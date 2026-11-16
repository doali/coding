#include <iostream>

// Cet exercice montre la cohérence des types
// La sortie est t-elle cohérente avec le type et ses capacités

unsigned int test(unsigned int i_number)
{
    return i_number * 2;
}
int main() {
    unsigned int l_number = 260;
    std::cout << "Nombre = " << l_number << std::endl;
    unsigned int l_result = test(l_number);
    std::cout << "Resultat = " << l_result << std::endl;
    return 0;
}
