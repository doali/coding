#include <cstdio>
#include <iostream>
#include <iomanip>

// Ce code montre qu'on peut écraser toute la mémoire
// - et donc l'adresse de retour !!!
// - ce qui entrainera un crash

// SOLUTION
// - gérer la taille => std::setw

void printMessage(const char *user_input) {
  char buffer[256];
  // sprintf(buffer, user_input); // Vulnerable to format string attack
  snprintf(buffer, sizeof(buffer), "%p", user_input); // SOLUTION gérer la taille n et le type "%s"
  std::cout << buffer << std::endl;

  std::cout << "Adresse du user_input : "
            << static_cast<const void *>(user_input) << std::endl;
  std::cout << "Adresse du tableau buffer : "
            << static_cast<void *>(static_cast<void *>(&buffer)) << std::endl;
}

int main() {
  char user_input[256];
  std::cout << "Enter a message: ";
  std::cin >> std::setw(256) >> user_input; // SOLUTION gérer la taille
  printMessage(user_input);
  return 0;
}
