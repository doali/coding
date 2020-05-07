#ifndef _TRIANGLE_
#define _TRIANGLE_

#include "Form.cpp"

class Triangle : public Form {

public:
  virtual ~Triangle() { std::cout << "log:" << __func__ << std::endl; }
  Triangle(int id, std::string name, int base, int heigth)
      : Form(id, name), _base(base), _heigth(heigth) {
    std::cout << "log:" << __func__ << std::endl;
  }

  inline const int &getBase() const { return this->_base; }
  inline void setBase(const int base) { this->_base = base; }

  inline const int &getHeigth() const { return this->_heigth; }
  inline void setHeigth(const int heigth) { this->_heigth = heigth; }

  virtual float surface() const {
    return this->getBase() * this->getHeigth() / 2;
  }

private:
  int _base;
  int _heigth;
};

#endif // _TRIANGLE_
