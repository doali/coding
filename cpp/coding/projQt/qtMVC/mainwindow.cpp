#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringListModel>
#include <QMessageBox>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _modele(new QStringListModel())
{
    ui->setupUi(this);

    QStringList listePays;
    listePays << "France" << "Espagne" << "Italie" << "Portugal" << "Suisse";
    this->_modele->setStringList(listePays);

    ui->listView->setModel(this->_modele);
    connect(this->ui->pushButton, SIGNAL(clicked()), this, SLOT(clickSelection()));    
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _modele;
}

void MainWindow::clickSelection()
{
    QItemSelectionModel* itemSelection = this->ui->listView->selectionModel();
    QModelIndex index = itemSelection->currentIndex();
    QVariant element = this->_modele->data(index, Qt::DisplayRole);
    QMessageBox::information(this, "Elément sélectionné", element.toString());
}
