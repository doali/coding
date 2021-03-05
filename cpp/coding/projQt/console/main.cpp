#include <QCoreApplication>

#include <iostream>
#include <sstream>

template <typename T>
static void affiche(const T &t)
{
    std::cout << t << std::endl;
}

static void sautDeLigne(const std::string &intro)
{
    std::cout << intro << std::endl;
}

static const std::string concat(const std::string &str, const int &entier)
{
    std::stringstream ss;
    ss << str << entier;

    const std::string res(ss.str());

    return res;
}

class A
{
private:
    std::string m_id;
    const int m_id_num;

public:
    static int m_total;

public:
    int get_m_id_num() const
    {
        return m_id_num;
    }

public:
    A():
        m_id_num(++m_total)
    {
        affiche(concat("A()", m_id_num));
    }

    A(const std::string & id):
        m_id_num(++m_total)
    {
        m_id = id;
        affiche(concat("A(" + id + ")", m_id_num));
    }

    ~A()
    {
        if (! (m_id.size() > 0))
        {
            m_id = "_";
        }
        std::stringstream ss;
        ss << m_total;

        m_id += ":" + ss.str();

        affiche(concat("~A()->" + m_id, m_id_num));
    }

    A(const A &fromA):
        m_id_num(fromA.m_id_num)
    {
        affiche(concat("A(const A &)", m_id_num));
    }

    A& operator=(const A& refA)
    {
        this->m_id = refA.m_id;

        affiche(concat("A& operator=(const A&)", m_id_num));
        return *this;
    }
};

std::ostream& operator<<(std::ostream &flux, const A &refA)
{
    return flux << "{" << refA.m_total<< ";" << refA.get_m_id_num() << "}";
}

static void declaration()
{
    A a("a");
    A b("b");
}

static void affectation()
{
    sautDeLigne("== declaration ==");
    A a("a");
    A b("b");

    sautDeLigne("== affectation ==");
    b = a;

    sautDeLigne("== declaration + affectation ==");
    A c = b;

    sautDeLigne("== declaration + constructeur ==");
    A d = A();
    A e;

    sautDeLigne("== declaration ==");
    A();

    sautDeLigne("== dynamique ==");
    A& refA = a;
}

static void tableau()
{
    A tabA[3];
    A tabB[] = { A("a"), A("b")};

    tabB[0] = A("c");

    A d("d");
    tabB[1] = d;
}

static void tableauReference()
{
//    A& tabRef[3]; // Impossible !!
//    A& tabRefEnumeration[] = {A(), A()}; // Impossible !!
}

static void tableauPointeur()
{
    A* tabPointeur[3];

    A adrA;
    A* tabPointeurEnumeration[] = {&adrA};
    affiche(*tabPointeurEnumeration[0]);
}

int A::m_total = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tableauPointeur();

    return a.exec();
}
