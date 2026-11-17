#include <iostream>
#include <fstream>
#include <string>

// PROBLEME
// - on peut corrompre les données => problème d'intégrité

// SOLUTION
// - générer une empreinte

class MyClass {
public:
    MyClass() : value(0) {}
    MyClass(int val) : value(val) {}

    void serialize(std::ofstream& out) const {
        out.write(reinterpret_cast<const char*>(&value), sizeof(value));
    }

    void deserialize(std::ifstream& in) {
        in.read(reinterpret_cast<char*>(&value), sizeof(value));
    }

    int getValue() const {
        return value;
    }

private:
    int value;
};

/* Deserialisation d'un fichier et lecture de la valeur du fichier */
void unsafeDeserialization(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open()) {
        MyClass obj;
        obj.deserialize(inFile);
        int result = obj.getValue();
        std::cout << "Value: " << result << std::endl;
        inFile.close();
    } else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}

int main() {
    std::string filename = "untrusted_data.bin";

    /********* APPLICATION n°1 **********************************/
    // Ecriture d'un fichier avec une valeur
    {
        MyClass obj(42);
        std::ofstream outFile(filename, std::ios::binary);
        if (outFile.is_open()) {
            obj.serialize(outFile);
            outFile.close();
        } else {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return 1;
        }
    }

    /********* APPLICATION n°2 **********************************/
    // Deserialize untrusted data
    unsafeDeserialization(filename);

    return 0;
}
