#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <thread>
#include <atomic>
#include <chrono>

#define LEN_NAME 50

typedef void (*p_f)(void *, const char *);

typedef struct
{
    char name[LEN_NAME];
    unsigned int id;
    p_f action;
} s_person;

void do_something(void *p, const char *msg)
{
    s_person titi = *(s_person *)(p);
    printf("%s [%u] is doing %s\n", titi.name, titi.id, msg);
}

struct Base
{
    Base()
    {
        std::cout << __func__ << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "Strange" << std::endl;
    }

    virtual void doSomething() = 0;
};

struct A final : public Base
{
    A() : Base()
    {
        std::cout << __func__ << std::endl;
    }

    ~A()
    {
        std::cout << __func__ << std::endl;
    }

    void doSomething() override
    {
        std::cout << "Hey, I'm the one doing something here !!" << std::endl;
    }
};

struct B final : public Base
{
    B() : Base()
    {
        std::cout << __func__ << std::endl;
    }

    ~B()
    {
        std::cout << __func__ << std::endl;
    }

    void doSomething() override
    {
        std::cout << "doing something" << std::endl;
    }
};

void star(unsigned int h)
{
    for (unsigned int k = 0; k < h; ++k)
    {
        for (unsigned int j = 0; j < k; ++j)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

struct Weapon
{
    Weapon(std::string weapon) : _weapon(weapon) {}
    std::string _weapon;
};

class Character
{
public:
    Character(unsigned int id, std::string pseudo, unsigned int life, std::shared_ptr<Weapon> weapon) : _id(id),
                                                                                                        _pseudo(pseudo),
                                                                                                        _life(life),
                                                                                                        _weapon(weapon)
    {
    }

    friend std::ostream &operator<<(std::ostream &os, Character const &character);

    unsigned int _id;
    std::string _pseudo;
    unsigned int _life;
    std::shared_ptr<Weapon> _weapon;
};

std::ostream &operator<<(std::ostream &os, Character const &character)
{
    return os << '[' << character._id << ']' << " " << character._pseudo << '|' << character._life << " -> " << character._weapon->_weapon;
}

class Warrior : public Character
{
public:
    Warrior(unsigned int id, std::string pseudo, unsigned int life, std::shared_ptr<Weapon> weapon) : Character(id, pseudo, life, weapon)
    {
    }
};

std::string reverse(std::string msg)
{
    std::string rMsg{};
    while (!msg.empty())
    {
        rMsg += msg.back();
        msg.pop_back();
    }

    return rMsg;
}

bool isPalindrome(std::string msg)
{
    return (reverse(msg).compare(msg) == 0);
}

unsigned int is_palindrome(const char *msg)
{
    unsigned int size = 0;
    const char *p_letter = msg;

    while (*p_letter != '\0')
    {
        ++size;
        ++p_letter;
    }

    for (unsigned int index = 0; index < (size / 2); ++index)
    {
        if (msg[index] != msg[size - index - 1])
        {
            return 0;
        }
    }

    return 1;
}

void cstr2ascii(const char *msg, size_t size)
{
    printf("C ----------\n");
    for (size_t index = 0; index < size; ++index)
    {
        printf("%c|%u\n", msg[index], msg[index]);
    }
}

int main()
{
    std::vector<std::shared_ptr<Base>> v{
        std::make_shared<A>(),
        std::make_shared<B>()};

    for (std::shared_ptr<Base> &e : v)
    {
        e->doSomething();
    }

    star(10);

    auto f = [](unsigned int h)
    {
        for (unsigned int r = 0; r < h; ++r)
        {
            std::cout << std::setw(h - r);
            for (unsigned int c = 0; c < 2 * r; ++c)
            {
                std::cout << "|";
            }
            std::cout << std::endl;
        }
    };

    s_person p = {
        "titi",
        42,
        &do_something};

    do_something(&p, "- something -");

    f(5);

    std::cout << std::endl;

    Warrior w(42, "quarante_deux", 100, std::make_shared<Weapon>("bazouka"));
    std::cout << w << std::endl;

    std::cout << std::endl;

    std::string msg{"titi et rominet"};
    std::cout << reverse(msg) << std::endl;

    std::vector<std::string> lstWord{
        "kayak",
        "ici",
        "palindrome",
        "",
        "a",
        "bb",
        ">>",
        "non",
        "oui",
        "rigolo"};

    for (std::string const &msg : lstWord)
    {
        std::cout << msg << " ? ";
        std::cout << ((isPalindrome(msg)) ? "OK" : "KO") << std::setw(20) << '|' << ((is_palindrome(msg.c_str()) == 1) ? "oui" : "non") << std::endl;
    }

    auto str2ascii = [](std::string const &msg)
    {
        std::cout << "C++ ----------" << std::endl;
        for (char const &letter : msg)
        {
            std::cout << letter << "|" << static_cast<int>(letter) << std::endl;
        }
    };

    for (std::string const &msg : lstWord)
    {
        str2ascii(msg);
        cstr2ascii(msg.c_str(), msg.length());
    }

    std::string s{"titi"};
    std::cout << s.back() << std::endl;
    std::cout << s.length() << std::endl;

    unsigned int index(0);
    for (char const &c : s)
    {
        std::cout << index++ << "|" << c << std::endl;
    }

    std::atomic<int> counter(0);    
    unsigned int glob_1(0);
    unsigned int glob_2(0);
    auto inc_titi_th = [&counter, &glob_1]()
    {
        while (glob_1 < 10000)
        {
            std::cout << ++counter << std::endl;
            ++glob_1;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }        
    };

    auto dec_titi_th = [&counter, &glob_2]()
    {
        while (glob_2 < 10000)
        {
            std::cout << --counter << std::endl;
            ++glob_2;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    };

    std::thread t_th_1(inc_titi_th);
    std::thread t_th_2(dec_titi_th);

    t_th_1.join();
    t_th_2.join();

    ([&glob_1, &glob_2]()
     {
        for (unsigned int const &g : {glob_1, glob_2})
            std::cout << "glob:" << g << std::endl; })();

    std::cout << "counter:" << counter << std::endl;

    return 0;
}