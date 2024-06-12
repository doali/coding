#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int main() {
    // Déclaration de variables cpp_int
    cpp_int a("23456789012345678901234567890");
    cpp_int b("987654321098765432109876543210");

    // Opérations arithmétiques
    cpp_int sum = a + b;
    cpp_int diff = b - a;
    cpp_int prod = a * b;
    cpp_int quot = b / a;
    cpp_int mod = b % a;

    // Affichage des résultats
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Product: " << prod << std::endl;
    std::cout << "Quotient: " << quot << std::endl;
    std::cout << "Modulus: " << mod << std::endl;

    // Comparaisons
    if (a < b) {
        std::cout << a << " is less than " << b << std::endl;
    }

    return 0;
}
