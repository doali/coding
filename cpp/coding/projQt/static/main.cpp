#include <QCoreApplication>

#include <iostream>

class A
{
public:
    static int m_total;
private:
    const int m_id;
    const std::string m_str;
public:
    A(const std::string &str):
        m_id(m_total++),
        m_str(str)
    {

    }

    A(const A &refA):
        m_id(refA.m_id),
        m_str(refA.m_str)
    {
        std::cout << "A(const A&)" << std::endl;
    }

    const int& getId() const { return m_id; }

    friend std::ostream& operator<<(std::ostream& flux, const A& refConsole)
    {
        return flux << "[" << refConsole.m_id << "|" << refConsole.m_str << "]";
    }
};

int A::m_total(0);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << A("a");
    std::cout << A("b");
    std::cout << A("c");

    return a.exec();
}
