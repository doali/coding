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

    inline bool dejaVu() const { return _dejaVu; }
    void setDejaVu(const bool& dejaVu) { _dejaVu = dejaVu; }

    static const unsigned int SEUIL{75};
public slots:
    void resetSlider(); // implique la déclaration de la macro Q_OBJECT
    void checkSeuil(int);
    void handleAvertissement(unsigned int);
signals:
    void avertissementSeuil(unsigned int); // toujours void en type de retour !!
private:
    QPushButton* _bouton;
    QSlider* _slider;
    QProgressBar* _bar;
    QLayout* _layout;
    bool _dejaVu;
};

#endif // FENETRE_H
