#include "fenetre.h"
#include <QApplication>

Fenetre::Fenetre(unsigned int const largeur /* = 300 */, unsigned int const hauteur /* = 200 */) :
    _bouton(new QPushButton("OK", this)),
    _slider(new QSlider(Qt::Horizontal, this)),
    _lcd(new QLCDNumber(this)),
    _layout(new QHBoxLayout(this))
{
    setLayout(_layout);
    _layout->addWidget(_slider);
    _layout->addWidget(_lcd);
    _layout->addWidget(_bouton);
    _bouton->setFont(QFont("Comic Sans MS", 14));
    _lcd->setSegmentStyle(QLCDNumber::Flat);
    QObject::connect(_bouton, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(_slider, SIGNAL(valueChanged(int)), _lcd, SLOT(display(int)));
}

Fenetre::~Fenetre()
{
    // Tous les composants ont pour parent Fenetre
    // - Qt libère la mémoire pour les fils de Fenetre
    // => aucun delete à réaliser dans ce cas
}
