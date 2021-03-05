#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>

class QPushButton;
class QLayout;

class MaFenetre : public QWidget
{
    Q_OBJECT

public:
    explicit MaFenetre(QWidget *parent = nullptr);
    explicit MaFenetre(QString nom, QWidget *parent = nullptr);
    ~MaFenetre();

public:
    QString _nom;
    QPushButton* _bouton;
    QLayout* _layout;    
};

#endif // MAFENETRE_H
