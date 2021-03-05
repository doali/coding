#include "mafenetre.h"
#include <QApplication>

#include <QPushButton>
#include <QBoxLayout>

#include <iostream>

#define FUNC_SAFE_DELETE_POINTER(X) if(X) { delete X; X = NULL; }

class Fenetre {
public:
    Fenetre():
        widget(new QWidget())
    {
        widget->setMinimumSize(300, 400);
    }
    ~Fenetre()
    {
        std::cout << "~Fenetre" << std::endl;
        delete widget;
    }
    QWidget* widget;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Fenetre window;
    QVBoxLayout layout;
    window.widget->setLayout(&layout);
    MaFenetre* fenetreUn = new MaFenetre("un");
    layout.addWidget(fenetreUn);
    MaFenetre* fenetreDeux = new MaFenetre("deux");
    layout.addWidget(fenetreDeux);
    layout.addWidget(new MaFenetre("trois"));

//    fenetreUn->hide();
//    delete fenetreUn;
    delete fenetreDeux;

    layout.removeWidget(fenetreDeux);
    window.widget->show();

//    MaFenetre maWindow;
//    maWindow.show();

    return a.exec();
}
