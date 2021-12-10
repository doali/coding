#include <iostream>
#include <vector>
#include <algorithm>

struct Foncteur
{
    static int const AFFINE = 2;
    int _coeff;
    std::vector<int> vres;

    void clear() { vres.clear(); }

    Foncteur(int const &coeff)
    {
        _coeff = coeff;
    }

    int operator()(const int &a)
    {
        int res;
        res = _coeff * a + Foncteur::AFFINE;

        vres.push_back(res);

        return res;
        // return a;
    }

    int operator()(std::string &s)
    {
        s += "-ok-";
    }
};

static void display(std::vector<int> const &v)
{
    std::vector<int>::const_iterator it;
    for (it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Foncteur foncteur(2);
    
    std::cout << foncteur(3) << std::endl;    

    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    display(v);
    
    foncteur.clear();

    foncteur = std::for_each(v.begin(), v.end(), foncteur);
    display(v);
    display(foncteur.vres);

    return 0;
}