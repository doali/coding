// Compiler : x86-64 gcc 10.3
// Execute arguments ( =>]) (execution stdin) pour entrez votre cin
#include <cstdio>
#include <cstring>
#include <iostream>

const char *PASSWORD_FILE = "rictro";

int main() {
  char password[8]; // En pile
  // char input[8];    // En pile
  std::string input; // SOLUTION : prendre std::string pour être dans la HEAP

  std::sscanf(PASSWORD_FILE, "%s", password);

  std::cout << "Enter password: ";
  std::cin >> input;

  if (input.size() > 8) {
    std::cout << "_Access denied_" << std::endl;
    return 0;
  }

  // Verification du mot de passe entré par l'utilisateur
  if (std::strncmp(password, input.c_str(), 8) == 0) { // SOLUTIN : modifier ici également
    std::cout << "Access granted" << std::endl;
  } else {
    std::cout << "Access denied" << std::endl;
  }

  return 0;
}


//L'option ASan permet d'ajouter des marqueurs, des canary pour être sûr qu'on efface pas un autre espace mémoire

//  (  edf in coding/cpp/formation-securite on  master!? )
//  ❯ g++ exo_1.cpp -o exo_1

//  (  edf in coding/cpp/formation-securite on  master!? )
//  ❯ ./exo_1
// Enter password: 1111111111111111
// Access denied

//  (  edf in coding/cpp/formation-securite on  master!? )
//  ❯
