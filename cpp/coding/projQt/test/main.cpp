#include <QCoreApplication>

#include <iostream>

class B
{
public:
    B()
    {
        std::cout << "B()" << std::endl;
    }

    ~B()
    {
        std::cout << "~B()" << std::endl;
    }

    B& operator=(const B&)
    {
        std::cout << "B& operator=(const B&)" << std::endl;
        return *this;
    }
};

class A: public B
{
public:
    A():
        B()
    {
        std::cout << "A()" << std::endl;
    }

    ~A()
    {
        std::cout << "~A()" << std::endl;
    }

    A& operator=(const A&)
    {
        std::cout << "A& operator=(const A&)" << std::endl;
        return *this;
    }
};

class Englobante
{
public:
    Englobante():
        a(new A())
    {
        std::cout << "Englobante" << std::endl;
    }

    ~Englobante()
    {
        delete a;
        std::cout << "~Englobante" << std::endl;
    }

private:
    A *a;
};

std::ostream& operator<<(std::ostream &flux, const B &b)
{
    return flux << "{" << &b << "}" << std::endl;
}

std::ostream& operator<<(std::ostream &flux, const Englobante &e)
{
    return flux << "{" << "Englobante:" << &e << "}" << std::endl;
}

static void constructeur()
{
    const B &b = A();
    std::cout << b;

    const int &i = 1;

    Englobante e;
    std::cout << e << std::flush;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    constructeur();

    return a.exec();
}
