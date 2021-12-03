#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QTextBlock>
#include <iostream>

class MyProgressBar: public QProgressBar
{
public slots:
    void reset() {
        std::cout << "my reset" << std::endl;
        this->QProgressBar::reset();
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget parent;
    QHBoxLayout layout;
    MyProgressBar *bar = new MyProgressBar();
    QPushButton *button = new QPushButton("&Reset");
    QObject::connect(button, SIGNAL(clicked()), bar, SLOT(reset()));
    bar->setRange(0, 100);
    bar->setValue(42);

    layout.addWidget(button);
    layout.addWidget(bar);

    for (quint8 indexItem = 0; indexItem < layout.count(); indexItem++)
    {
        layout.itemAt(indexItem)->widget()->show();
    }

    parent.setLayout(&layout);
    parent.show();

    return app.exec();
}
