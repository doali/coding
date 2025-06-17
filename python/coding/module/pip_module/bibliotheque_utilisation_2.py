import sys
import pprint

pprint.pprint(sys.path)  # Affiche les chemins où Python cherche les modules

try:
    from ma_bibliotheque.calculs import addition, multiplication
    res = addition(4, 3)
    print(res)
    print("Import réussi !")
except ModuleNotFoundError as e:
    print(f"Erreur d'import : {e}")
