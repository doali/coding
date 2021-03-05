#ifndef BDEXCEPTION_H
#define BDEXCEPTION_H

#include <stdexcept>

class BDException: public std::exception
{
public:
    BDException():
        _errorMessage("BD"),
        _messageExplicatif("")
    {

    }

    BDException(std::string messageExplicatif):
        _errorMessage("BD"),
        _messageExplicatif(messageExplicatif)
    {

    }

    virtual ~BDException() noexcept // throw()
    {

    }

    virtual const char* what() const noexcept //throw()
    {
        return this->_errorMessage.c_str();
    }

    const std::string& getMessageExplicatif() const noexcept
    {
        return this->_messageExplicatif;
    }

protected:
    std::string _errorMessage;
    std::string _messageExplicatif;
};

#endif // BDEXCEPTION_H
