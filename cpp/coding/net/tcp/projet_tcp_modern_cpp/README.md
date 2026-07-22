# Exemple TCP Modern C++

Ce projet illustre l'encodage et le décodage de messages TCP avec :
- **std::unique_ptr** pour la gestion mémoire des buffers d'envoi.
- **std::span** (C++20) pour l'analyse sans copie (zéro-copy) à la réception.
- **Endianness** (htonl/ntohl) pour la compatibilité réseau.

## Compilation
```bash
make
```

## Exécution
```bash
./tcp_example
```
