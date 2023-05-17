#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

static const unsigned int FMT_NUM{3};

struct A
{
    A(const unsigned int id = 0) : _id{id}
    {
        ++_total;
        std::cout << "passé par là" << std::endl;
    }

    virtual ~A()
    {
    }

    virtual void info()
    {
        std::cout << "A:[" << std::setw(FMT_NUM) << _id << "|" << _total << "]" << __func__ << std::endl;
    }

    unsigned int _id;
    static unsigned int _total;
};

unsigned int A::_total{0};

struct B : public A
{
    B(unsigned int id) : A{id}
    {
    }

    virtual ~B()
    {
    }

    void info() override
    {
        A::info();
        std::cout << "- B:[" << std::setw(FMT_NUM) << _id << "|" << _total << "]" << __func__ << std::endl;
    }
};

std::ostream &operator<<(std::ostream &os, A const &obj)
{
    return os;
}

int main(void)
{
    A a(0);

    std::vector<std::shared_ptr<A>> vB{
        std::make_shared<B>(0),
        std::make_shared<B>(1),
        std::make_shared<B>(2)};

    for (auto &element : vB)
    {
        element->info();
    }

    std::cout << A::_total << std::endl;

    return 0;
}