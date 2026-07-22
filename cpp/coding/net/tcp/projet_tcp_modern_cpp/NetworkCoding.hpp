#pragma once
#include "Protocol.hpp"
#include <memory>
#include <span>
#include <cstring>
#include <arpa/inet.h>
#include <iostream>

class NetworkCoding {
public:
    // ENCODAGE (Côté Client)
    // On transforme un Message en flux binaire prêt pour TCP
    static std::unique_ptr<std::vector<uint8_t>> serialize(const Net::Message& msg) {
        uint32_t bodyLen = Net::HEADER_SIZE + static_cast<uint32_t>(msg.payload.size());
        
        // Allocation du buffer : Taille(4) + Corps(Header + Payload)
        auto buffer = std::make_unique<std::vector<uint8_t>>(Net::PREFIX_SIZE + bodyLen);
        uint8_t* ptr = buffer->data();

        // 1. Longueur (Big Endian)
        uint32_t nBodyLen = htonl(bodyLen);
        std::memcpy(ptr, &nBodyLen, 4); ptr += 4;

        // 2. ID (Big Endian)
        uint32_t nId = htonl(msg.id);
        std::memcpy(ptr, &nId, 4); ptr += 4;

        // 3. Type (Big Endian)
        uint32_t nType = htonl(msg.type);
        std::memcpy(ptr, &nType, 4); ptr += 4;

        // 4. Payload (Octets bruts)
        if (!msg.payload.empty()) {
            std::memcpy(ptr, msg.payload.data(), msg.payload.size());
        }

        return buffer;
    }

    // DÉCODAGE (Côté Serveur)
    // On utilise std::span pour analyser sans copier
    static void deserialize(std::span<const uint8_t> rawData) {
        if (rawData.size() < Net::PREFIX_SIZE) {
            std::cout << "[Serveur] Données insuffisantes pour lire la taille." << std::endl;
            return;
        }

        // Lecture de la taille annoncée
        uint32_t nBodyLen;
        std::memcpy(&nBodyLen, rawData.data(), 4);
        uint32_t bodySize = ntohl(nBodyLen);

        // Vérification si le message est complet
        if (rawData.size() < Net::PREFIX_SIZE + bodySize) {
            std::cout << "[Serveur] Message incomplet (attendu: " << bodySize << " octets)." << std::endl;
            return;
        }

        // Extraction des composants via subspans
        auto body = rawData.subspan(Net::PREFIX_SIZE, bodySize);
        
        uint32_t nId, nType;
        std::memcpy(&nId, body.data(), 4);
        std::memcpy(&nType, body.data() + 4, 4);

        uint32_t id = ntohl(nId);
        uint32_t type = ntohl(nType);
        auto payload = body.subspan(Net::HEADER_SIZE);

        std::cout << "[Serveur] Message reçu !" << std::endl;
        std::cout << " -> ID: " << id << "\n -> Type: " << type << "\n -> Payload: " << payload.size() << " octets" << std::endl;
    }
};
