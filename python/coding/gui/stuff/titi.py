
class Personne:
    def __init__(self, nom, prenom):
        self.nom = nom
        self.prenom = prenom

    def __str__(self):
        return f"{self.prenom} {self.nom}"

class Ecurie:
    def __init__(self, nom):
        self.nom = nom

    def __str__(self):
        return f"{self.nom}"

class Pilote(Personne):
    def __init__(self, nom, prenom, ecurie):
        super().__init__(nom, prenom)
        self.ecurie = ecurie

    def __str__(self):
        return f"{self.prenom} {self.nom} court chez {self.ecurie}"

    def update(self, ecurie):
        self.ecurie = ecurie

if __name__ == '__main__':
    p = Personne("titi", "rominet")
    print(p)

    f = Ecurie("Ferrari")
    print(f)

    p = Pilote("ayrton", "senna", f)
    print(p)

    m = Ecurie("McLaren")
    p.update(m)
    print(p)
