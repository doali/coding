#ifndef _FORM_
#define _FORM_

#include <iostream>
#include <string.h>

class Form {

public:
  virtual ~Form();

  inline const int &getId() const { return this->_id; }
  inline void setId(const int id) { this->_id = id; }

  inline const std::string &getName() const { return this->_name; }
  inline void setName(const std::string name) { this->_name = name; }

  virtual float surface() const = 0;

  friend std::ostream &operator<<(const std::ostream &os, const Form &form);

protected:
  Form(int id, std::string name);

  int _id;
  std::string _name;
};

Form::~Form() {
  std::cout << "log:" << __func__ << "|" << this->getId() << "|"
            << this->getName() << std::endl;
}

Form::Form(int id, std::string name) : _id(id), _name(name) {
  std::cout << "log:" << __func__ << std::endl;
}

std::ostream &operator<<(const std::ostream &os, const Form &form) {
  std::cout << "ID:" << form.getId() << "|" << form.getName() << std::endl;
}

#endif
