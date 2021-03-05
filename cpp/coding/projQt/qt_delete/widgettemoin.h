#ifndef WIDGETTEMOIN_H
#define WIDGETTEMOIN_H

#include <QWidget>
#include <iostream>

class WidgetTemoin : public QWidget
{
    Q_OBJECT

public:
    ~WidgetTemoin()
    {
        std::cout << "~WidgetTemoin()" << std::endl;
    }
};

#endif // WIDGETTEMOIN_H
