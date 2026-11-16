/*
 * PRINCIPE RAII ET GESTION DES EXCEPTIONS DANS UN CONSTRUCTEUR :
 *
 * 1. Le principe RAII (Resource Acquisition Is Initialization) :
 *    L'acquisition de la ressource est liée à l'initialisation d'un objet (ici,
 *    la classe 'Ressource'), et sa libération est automatiquement assurée par
 *    son destructeur dès que l'objet sort de sa portée.
 *
 * 2. Objets locaux et temporaires entièrement construits :
 *    Grâce au RAII et au déroulement de la pile (stack unwinding), tous les
 *    objets locaux (comme 'v') et temporaires créés avant le 'throw' sont
 *    automatiquement nettoyés dans l'ordre inverse de leur création,
 * garantissant l'absence de fuite.
 *
 * 3. L'objet en cours de construction ('c') :
 *    L'exception étant levée avant la fin de son constructeur, l'objet externe
 *    n'est pas entièrement construit : son propre destructeur (~LanceException)
 *    n'est donc pas appelé. En revanche, toutes les sous-ressources qu'il avait
 *    déjà entièrement initialisées (comme 'v' ou 'Ressource(30)') ont bien été
 *    libérées grâce au RAII.
 */

#include <iostream>
#include <source_location>

#define TRACE(X, M) std::cout << X << ":" << M << std::endl

template <typename T>
void trace(const T &message,
           std::source_location loc = std::source_location::current()) {
  std::cout << loc.function_name() << ":" << message << std::endl;
}

struct Ressource {
  Ressource(unsigned int id) : _id{id} { TRACE(__func__, _id); }

  ~Ressource() { trace<unsigned int>(_id); }
  unsigned int _id;
};

struct LanceException {
  LanceException(int id) : _id(id) {
    std::cout << __func__ << ":DEB" << std::endl;
    Ressource(10);
    Ressource v(id);
    if (id > 10) {
      Ressource(30);
      Ressource v(40);
      throw id;
      std::cout << __func__ << ":Jamais appele" << std::endl;
    } else {
      std::cout << __func__ << ":Comportement normal" << std::endl;
      // ...
    }

    std::cout << __func__ << ":FIN" << std::endl;
  }

  ~LanceException() { std::cout << __func__ << "(" << _id << ")" << std::endl; }

  int _id;
};

int main(int argc, char **argv) {
  std::cout << __func__ << ":DEB" << std::endl;
  try {
    LanceException a(0);
    LanceException(1);
    LanceException b(2);
    {
      std::cout << "Lancement problématique à venir" << std::endl;
      LanceException c(11);
    }
    std::cout << "Jamais atteint du fait du lancement de l'exception"
              << std::endl;
  } catch (int &ref) {
    std::cout << __func__ << ":Attrapee" << ":" << ref << std::endl;
  }
  std::cout << __func__ << ":FIN" << std::endl;

  std::cout << std::endl;

  std::cout << "En conclusion : les destructeurs sont appelés lors du "
               "déroulement de la pile,\n"
               "y compris pour les sous-objets de l'objet en échec, sauf pour "
               "l'objet\n"
               "en cours de construction lui-même."
            << std::endl;
}
