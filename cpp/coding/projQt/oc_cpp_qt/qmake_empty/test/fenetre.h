#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLCDNumber>
#include <QLayout>

class Fenetre : public QWidget
{    
public:    
    Fenetre(unsigned int const largeur = 300, unsigned int const hauteur = 200);
    virtual ~Fenetre();
private:
    QPushButton* _bouton;
    QSlider* _slider;
    QLCDNumber* _lcd;
    QLayout* _layout;
};

#endif // FENETRE_H
