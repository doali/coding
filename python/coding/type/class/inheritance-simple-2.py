#!/usr/bin/env python3

class MaSuperClasse:
    def __init__(self):
        print(f"Super classe : {self.__module__} {self.__class__}")

class MaClasseFille(MaSuperClasse):
    def __init__(self):
        super().__init__()
        print(f"Classe fille : {self.__module__} {self.__class__}")


print("Instanciation de MaSuperClasse")
msp = MaSuperClasse()

print()

print("Instanciation de MaClasseFille")
mcf = MaClasseFille()
