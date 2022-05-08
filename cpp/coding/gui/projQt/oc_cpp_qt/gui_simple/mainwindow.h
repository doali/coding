#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Sender : public QObject
{
    Q_OBJECT
public:
        Sender(QWidget *parent = nullptr) : QObject(parent)
        {

        }

        void send_sig(QString const msg)
        {
            emit welcome(msg);
        }
signals:
    void welcome(QString msg);
 };

class Receiver : public QObject
{
    Q_OBJECT
public:
    Receiver(QWidget *parent = nullptr) : QObject(parent)
    {

    }
public slots:
    void sayWelcome(QString msg)
    {
        QObject *s{sender()};
        qDebug() << "from :" << s << "|" << msg;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
