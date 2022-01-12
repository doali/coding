#include "mainwindow.h"
#include <QApplication>

#include <iostream>

#define SAFE_DELETE(X) if (X) { delete X; X = NULL; }

template <typename T>
static void affiche(const T &refT)
{
    std::cout << refT << std::endl;
}

struct A
{
    A()
    {
        affiche("A()");
    }

   ~A()
    {
        affiche("~A()");
    }
};

std::ostream& operator<<(std::ostream &flux, const A &refA)
{
    return flux << "{" << refA << "}";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    a.exec();

    A* l_a(new A());
    SAFE_DELETE(l_a);

    return EXIT_SUCCESS;
}
