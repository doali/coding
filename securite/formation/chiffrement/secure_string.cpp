#include <iostream>
#include <openssl/crypto.h>
#include <cstring>

class SecureString {
private:
    char* data;
    size_t length;

public:
    SecureString() : data(nullptr), length(0) {}

    explicit SecureString(const char* str) : length(std::strlen(str)) {
        data = static_cast<char*>(OPENSSL_secure_malloc(length + 1));
        std::strcpy(data, str);
    }

    SecureString(const SecureString& other) : length(other.length) {
        data = static_cast<char*>(OPENSSL_secure_malloc(length + 1));
        std::strcpy(data, other.data);
    }

    SecureString& operator=(const SecureString& other) {
        if (this != &other) {
            /*
                TODO
                    utilisez OPENSSL_secure_free pour libérer la mémoire
                    mettre à jour la donnée et sa taille
                        utilisez OPENSSL_secure_malloc
            */
            
        }
        return *this;
    }

    ~SecureString() {
        /*
            TODO
            utilisez OPENSSL_secure_free pour libérer la mémoire
        */
    }

    const char* c_str() const {
        return data;
    }

    size_t size() const {
        return length;
    }
};

int main() {
    SecureString password("my_secure_password");

    // Example usage
    std::cout << "Password length: " << password.size() << std::endl;
    std::cout << "Password: " << password.c_str() << std::endl;

    // Password data will be securely cleared when going out of scope

    return 0;
}
