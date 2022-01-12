#include "mainwindow.h"
#include <QApplication>

#include "base.h"
#include "derivee.h"
#include <iostream>

#define SAFE_DELETE_PTR(P) if (P) { delete P; P = NULL; }

void affiche(const std::string& ref)
{
    std::cout << ref << std::flush;
}

int main(int argc, char *argv[])
{
    //    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();

    Base base;
    Derivee derivee;

    Base &ref = derivee;

    ref.faire();

    std::cout << "fin reference" << std::endl;

    Base vectBase[] = {
        Derivee()
    };

    for (auto &ref: vectBase)
    {
        ref.faire();
    }

    vectBase[0].faire();

    std::vector<Base*> vect;
    vect.push_back(new Base());
    vect.push_back(new Derivee());

    std::vector<Base*>::iterator it = vect.begin();
    while (it != vect.end())
    {
        (*it)->faire();
        SAFE_DELETE_PTR(&(*it));
        ++it;
    }



    //    return a.exec();
    return 1;
}
