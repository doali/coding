#include <iostream>
#include <cstdlib>

#include <memory>

class MaClasse {
public:
    int x;
    MaClasse() : x(0) {
        std::cout << "Constructeur de MaClasse\n";
    }
    ~MaClasse() {
        std::cout << "Destructeur de MaClasse\n";
    }

    // Surcharge de l'opérateur new pour MaClasse
    void* operator new(std::size_t size) {
        std::cout << "MaClasse: Allocation de " << size << " octets\n";
        void* p = std::malloc(size);
        if (!p) {
            throw std::bad_alloc();
        }
        return p;
    }

    // Surcharge de l'opérateur delete pour MaClasse
    void operator delete(void* p) noexcept {
        std::cout << "MaClasse: Libération de mémoire\n";
        std::free(p);
    }
};

int main() {
    // std::cout << "Création d'un objet MaClasse\n";
    // MaClasse* obj = new MaClasse();
    // std::cout << "Suppression de l'objet MaClasse\n";
    // delete obj;


    // std::shared_ptr<MaClasse> s_ptr(new MaClasse());
    std::shared_ptr<MaClasse> s_ptr(std::make_shared<MaClasse>());

    return 0;
}
