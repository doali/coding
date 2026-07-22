#include "NetworkCoding.hpp"
#include <vector>
#include <string>


 // g++ -std=c++20 -ggdb -o tcp_example main.cpp

int main() {
    // 1. Préparation d'un message côté Client
    Net::Message msg;
    msg.id = 1234;
    msg.type = 1;
    std::string content = "Bonjour, ceci est un message sécurisé !";
    msg.payload.assign(content.begin(), content.end());

    std::cout << "[Client] Encodage du message..." << std::endl;
    auto packet = NetworkCoding::serialize(msg);

    // 2. Simulation de la transmission réseau
    // Ici packet est un std::unique_ptr<std::vector<uint8_t>>
    
    // 3. Réception côté Serveur
    std::cout << "[Serveur] Réception et décodage..." << std::endl;
    NetworkCoding::deserialize(*packet);

    return 0;
}
