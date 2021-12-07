#include "fenetre.h"
#include <QApplication>

Fenetre::Fenetre(unsigned int const largeur /* = 300 */, unsigned int const hauteur /* = 200 */) :
    _bouton(new QPushButton("OK", this)),
    _slider(new QSlider(Qt::Horizontal, this)),
    _bar(new QProgressBar(this)),
    _layout(new QHBoxLayout(this))
{
    setLayout(_layout);
    _layout->addWidget(_slider);
    _layout->addWidget(_bar);
    _layout->addWidget(_bouton);
    _bouton->setFont(QFont("Comic Sans MS", 14));
    _bar->setRange(0, 100);
    QObject::connect(_bouton, SIGNAL(clicked()), this, SLOT(resetSlider()));
    QObject::connect(_bouton, SIGNAL(clicked()), _bar, SLOT(reset()));
    QObject::connect(_slider, SIGNAL(valueChanged(int)), _bar, SLOT(setValue(int)));
}

Fenetre::~Fenetre()
{
    // Tous les composants ont pour parent Fenetre
    // - Qt libère la mémoire pour les fils de Fenetre
    // => aucun delete à réaliser dans ce cas
}

void Fenetre::resetSlider()
{
    _slider->setValue(0);
}
