#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPushButton;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    QPushButton* getBouton() const { return m_bouton; }

private:
    Ui::Widget *ui;
    QPushButton *m_bouton;
};

#endif // WIDGET_H
