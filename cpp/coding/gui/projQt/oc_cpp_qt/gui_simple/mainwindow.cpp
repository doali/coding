#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Receiver *r(new Receiver());
    Sender *s(new Sender());
    QObject::connect(s, SIGNAL(welcome(QString)), r, SLOT(sayWelcome(QString)));

    s->send_sig("titi");

    delete s;
    delete r;
}

MainWindow::~MainWindow()
{
    delete ui;
}

