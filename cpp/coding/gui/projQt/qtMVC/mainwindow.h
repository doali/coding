#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

#include <QPushButton>
#include <iostream>

class Trace;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPushButton* button;
    Trace* trace;

private:
    Ui::MainWindow *ui;
    QStringListModel *_modele;    

private slots:
    void clickSelection();
};

#endif // MAINWINDOW_H
