from random import randint

liste_messages_ko = [
    "Essaie encore",
    "C'est mal",
    "Les cerveaux sont en promo",
    "Je sais que vous etes meilleurs !!!",
    "Gabin, Orane, Lison un petit probleme ?",
    "Alors on seche ?",
    "Circuits grilles !!"
]


liste_messages_ok = [
    "C'est bien",
    "On est sur la bonne route",
    "Ca progresse",
    "Entre genies on se comprend",
    "Je reconnais bien la la patte du maitre",
    "Quel esprit vif !!"
]

liste_potter = [
	"acromentule",
	"auror",
	"arithmancie",
	"ashwinder",
	"augurey",
	"antipodean opaleye",
	"basilic",
	"botruc",
	"billywig",
	"boullu",
	"boursoufle",
	"bandaymon",
	"boutefeu chinois",
	"centaure",
	"chaporouge",
	"chimere",
	"ciseburine",
	"clabbert",
	"cheval aile",
	"crabe de feu",
	"cracmol",
	"croup",
	"cognard",
	"demiguise",
	"diablotin",
	"dirico",
	"doxy ou fee mordeuse",
	"dragon",
	"erkling",
	"eruptif",
	"etres de eau",
	"fangieux",
	"farfadet",
	"fee",
	"focifere",
	"grinchebourdon",
	"gnome",
	"goule",
	"grapcorne",
	"griffon",
	"galion",
	"horcruxe",
	"licorne",
	"loup-garou",
	"moldu",
	"magyar a pointe",
	"noir des hebrides",
	"norvegien a crete",
	"peruvian vipertooth",
	"pensedefer",
	"cornelongue romain",
	"sortilege",
	"transplaner",
	"vert gallois commun",
]

liste_mots = [
    "craies",
    "dakota",
    "dictionnaire",
    "dindons",
    "ecole",
    "eglise",
    "fouet",
    "papier",
    "agenda",
    "clavier",
    "souris",
    "voiture",
    "maison",
    "television",
    "ordinateur",
    "paris",
    "cigarette",
    "briquet",
    "coiffeur",
    "medecin",
    "rasoir",
    "miroir",
    "concubain",
    "whisky",
    "professionnelle",
    "message",
    "calculatrice",
    "kayak",
    "quille",
    "yahourt",
    "principe",
    "confort",
    "tendre",
    "chaussettes"
]


def choisir_msg(liste_msg):
    return liste_msg[randint(0, len(liste_msg)-1)]


def choisir_mot_alea():
    index=randint(0,len(liste_potter)-1)
    return liste_potter[index]



def affiche_mot(mot, liste_lettre):
    list_mot = list(mot)
    mot_trouve = True
    for lettre_courante in list_mot:
        trouve = False 
        for lettre in liste_lettre:
            if  lettre.lower() == lettre_courante.lower():
                print(f"{lettre} ", end="")                
                trouve = True
        if not trouve:
            print("_ ", end="")
            mot_trouve = False
    
    return mot_trouve


print("Bienvenue au jeu du pendu")
print("- special Harry Potter a Vulcano - (presque)")

mot_a_deviner = choisir_mot_alea()

print(f"Le mot comporte {len(mot_a_deviner)} lettres")

liste_lettre = []

max_essais=3
i = 0

while (i < max_essais):
    print()
    print(f"Il reste {max_essais - i} essais")
    lettre = input("Saisir une lettre:")
    liste_lettre.append(lettre)

    gagne = affiche_mot(mot_a_deviner, liste_lettre)

    if gagne:
        print("Gagné !!")
        break
        
    if lettre in mot_a_deviner:
        print(choisir_msg(liste_messages_ok))        
    else:
        print(choisir_msg(liste_messages_ko))
        i = i + 1
  #  if (input("voulez-vous quitter ? [o/O]").lower() == "o"):
       # break
print ("Il fallait trouver:",mot_a_deviner)

