#ifndef _SQUARE_
#define _SQUARE_

#include "Form.cpp"

class Square : public Form {

public:
  ~Square() override { std::cout << "log:" << __func__ << std::endl; }
  Square(int id, std::string name, int length)
      : Form(id, name), _length(length) {
    std::cout << "log:" << __func__ << std::endl;
  }

  inline const int &getLength() const { return this->_length; }
  inline void setLength(const int length) { this->_length = length; }

  float surface() const override { return this->_length * this->_length; }

private:
  int _length;
};

#endif // _SQUARE_
