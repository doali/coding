#include "widget.h"
#include <QApplication>

#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QVBoxLayout vbLayout(&w);
    QPushButton button("tres long");
    QPushButton button2("tres long 2");
    QPushButton* button3 = new QPushButton("bouton 3");
    vbLayout.addWidget(&button);
    vbLayout.addWidget(&button2);
    vbLayout.addWidget(button3);
    vbLayout.addWidget(w.getBouton());
    w.setLayout(&vbLayout);


    w.show();    

    return a.exec();
}

