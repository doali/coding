#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_temoin(new WidgetTemoin())
{
    ui->setWidgetTemoin(m_temoin);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_temoin;
}
