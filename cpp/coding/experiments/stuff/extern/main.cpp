#include <iostream>
 
// déclaration d'une variable
// définie en dehors de ce fichier
extern int a;

// obligation d'ajouter à nouveau le namespace
// - ainsi que le mot clef extern (pour référencer dans util.c)
namespace titi {
	extern int a_titi;
};

int main() {
	std::cout << a << std::endl;
	std::cout << titi::a_titi << std::endl;

	return 0;
}
