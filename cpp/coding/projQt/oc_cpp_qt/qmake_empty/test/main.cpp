#include "fenetre.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Fenetre fenetre{100, 50};
    fenetre.show();

    return app.exec();
}
