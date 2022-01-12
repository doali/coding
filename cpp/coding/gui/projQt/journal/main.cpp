//#include "mainwindow.h"
//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
//}

#include "test/ConcreteObservable.h"
#include "test/ConcreteObserver.h"

#include "bdexception.h"

#include "BD.h"

#include "Nitp.h"

// TEST
void test();
void affiche(std::string flux) { std::cout << flux << std::endl; }
void lanceException(bool);

int main(void)
{
    test();
    return 0;
}

void test()
{
    ConcreteObserver lecteur("lecteur");
    affiche(lecteur.toString());

    ConcreteObserver orateur("orateur");
    affiche(orateur.toString());

    ConcreteObservable livre("livre");
    affiche(livre.toString());
    livre.add(lecteur);
    livre.add(orateur);
    livre.notifyAll();

    livre.remove(orateur);
    livre.notifyAll();

    ConcreteObservable film("film");
    affiche(film.toString());
    film.add(lecteur);
    film.notifyAll();

    try {
        lanceException(true);
    } catch (BDException ex) {
        affiche("catch lanceException");
        affiche(ex.what());
    }

    BD bd(1);
    std::cout << "BD is connected ? :" << bd.isConnected() << "\n";

    Nitp nip1("nip1");
    affiche(nip1.toString());

    bd.add(lecteur);

    nip1.add(lecteur);
    nip1.add(orateur);

    bd.notifyAll();
    nip1.notifyAll();
}

void lanceException(bool lancer)
{
    try
    {
        affiche("bloc try:deb");
        if (lancer)
        {
            affiche("lance exception");
            throw BDException("...aide explicative...");
        }
        affiche("bloc try:fin");
    }
    catch (BDException& ex1)
    {
        affiche("bloc catch:deb");
        affiche("BDException ex");
        affiche(ex1.getMessageExplicatif());
        affiche("bloc catch:fin");
        throw;
    }
    catch (std::exception& ex2)
    {
        affiche("bloc catch:deb");
        affiche("std::exception ex");
        affiche(ex2.what());
        affiche("bloc catch:fin");
        throw;
    }
}
