#include "mainwindow.h"
#include <QApplication>
#include <iostream>

class Form
{
public:
    Form(const std::string& idName):
        m_idName(idName),
        m_type("Form")
    {

    }

    virtual ~Form() = 0;

    const std::string& getIdName() const
    {
        return this->m_idName;
    }

    const std::string& getType() const
    {
        return this->m_type;
    }

    void setIdName(const std::string& idName)
    {
        this->m_idName = idName;
    }

    virtual void info() const
    {
        std::cout << "{m_type:" << this->getType() << "}";
        std::cout << "{m_idName:" << this->getIdName() << "}";
    }

    virtual float surface() = 0;

protected:
    std::string m_idName;
    std::string m_type;
};

Form::~Form()
{

}

class Square: public Form
{
public:
    Square(const std::string& idName) :
        Form(idName)
    {
        this->m_type = "Square";
    }

    Square(const std::string& idName, const float length):
        Form(idName)
    {
        this->m_length = length;
    }

    virtual ~Square() {}

    virtual void info() const
    {
        Form::info();
    }

    virtual float surface()
    {
        return this->m_length * this->m_length;
    }

private:
    float m_length;
};

class Triangle: public Form
{
public:
    Triangle(const std::string& idName) :
        Form(idName)
    {
        this->setIdName(idName);
        this->m_type = "Triangle";
    }

    Trianqle(const std::string& idName, const float length, const float height):
        Form(idName),
        m_len
    {

    }

    virtual ~Triangle() {}

    virtual void info() const
    {
        Form::info();
    }

    virtual float surface()
    {
        return this->m_height * this->m_length / 2;
    }

private:
    float m_length;
    float m_height;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Square square("square_0");
    square.info();

    std::cout << std::endl;

    Triangle triangle("triangle_0");
    triangle.info();


    return a.exec();
}
