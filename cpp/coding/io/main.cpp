#include <iostream>
#include <vector>

static std::vector<std::string> ref{
	"https://learntutorials.net/fr/cplusplus/topic/7660/flux-c-plusplus",
	"https://fr.wikibooks.org/wiki/Programmation_C%2B%2B/Les_entr%C3%A9es-sorties",
	"http://sdz.tdct.org/sdz/c-les-manipulateurs-de-flux.html",
	"https://cpp.developpez.com/faq/cpp/?page=Entrees-sorties-avec-les-flux",
	"http://www.iro.umontreal.ca/~dift1169/cours/ift1169/communs/Cours/2P/1_03/C06_1169_2P.pdf"
};

int main()
{
	for (auto &e : ref) std::cout << e << std::endl;

	return 0;
}
