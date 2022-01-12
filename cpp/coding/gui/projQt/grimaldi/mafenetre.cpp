#include "mafenetre.h"

#include <QPushButton>
#include <QGridLayout>

#include <iostream>

MaFenetre::MaFenetre(QWidget *parent) :
    QWidget(parent),
    _bouton(new QPushButton(nullptr)),
    _layout(new QGridLayout(nullptr))
{
    this->_bouton->setText("ok");    
    this->_layout->addWidget(this->_bouton);
    this->setLayout(_layout);
}

MaFenetre::MaFenetre(QString nom, QWidget *parent) :
    QWidget(parent),
    _nom(nom),
    _bouton(new QPushButton(nullptr)),
    _layout(new QGridLayout(nullptr))
{
    this->_bouton->setText("ok");
    this->_layout->addWidget(this->_bouton);
    this->setLayout(_layout);
}

MaFenetre::~MaFenetre()
{
    if (!_bouton)
    {
        std::cout << "_bouton already deleted" << std::endl;        
        std::cout << "    " << this->_nom.toStdString() << std::endl;
    }
    else
    {
        std::cout << "delete processing for _bouton" << std::endl;
        std::cout << "    " << this->_nom.toStdString() << std::endl;
        delete _bouton;
        _bouton = nullptr;
    }

    if (!_layout)
    {
        std::cout << "_layout already deleted" << std::endl;
        std::cout << "    " << this->_nom.toStdString() << std::endl;
    }
    else
    {
        std::cout << "delete processing for _layout" << std::endl;
        std::cout << "    " << this->_nom.toStdString() << std::endl;
        delete _layout;
        _layout = nullptr;
    }
}
