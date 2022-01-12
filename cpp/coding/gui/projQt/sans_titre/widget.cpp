#include "widget.h"
#include "ui_widget.h"

#include <iostream>
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_bouton(new QPushButton("bouton"))
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
