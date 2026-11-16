#include <iostream>

// PROBLEME
// - on constate qu'on a un accès valide alors que key = false
// - c'est dû au fait qu'on écrase avec TAB_LENGTH car on écrit un caractère 'A'
//
// SOLUTION
// - gérer les bornes !!

void unsafeFunction() {
    const int TAB_LENGTH = 2;
    bool key = true;// false;
    std::cout << "Adresse key = "<< &key << std::endl;
    char buffer[TAB_LENGTH];
    std::cout << "Adresse buffer = "<< &buffer << std::endl;

    // for (int i = 0; i <= TAB_LENGTH; ++i) {
    //     buffer[i] = 'A';
    // }
    std::string result = (key != false) ? "Access validated" : "Acess refused";

    std::cout << result << std::endl;
}

int main() {
    unsafeFunction();
    std::cout << "Function executed." << std::endl;
    return 0;
}
