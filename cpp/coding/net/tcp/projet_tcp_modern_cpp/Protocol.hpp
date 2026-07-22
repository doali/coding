#pragma once
#include <cstdint>
#include <vector>

namespace Net {
    // Tailles fixes du protocole
    constexpr size_t PREFIX_SIZE = 4; // Champ Longueur
    constexpr size_t HEADER_SIZE = 8; // ID(4) + Type(4)

    // Structure de message logique
    struct Message {
        uint32_t id;
        uint32_t type;
        std::vector<uint8_t> payload;
    };
}
