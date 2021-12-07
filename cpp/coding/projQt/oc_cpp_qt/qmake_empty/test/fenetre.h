#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QProgressBar>
#include <QLayout>

class Fenetre : public QWidget
{    
    Q_OBJECT
public:    
    Fenetre(unsigned int const largeur = 300, unsigned int const hauteur = 200);
    virtual ~Fenetre();
public slots:
    void resetSlider();
private:
    QPushButton* _bouton;
    QSlider* _slider;
    QProgressBar* _bar;
    QLayout* _layout;
};

#endif // FENETRE_H
