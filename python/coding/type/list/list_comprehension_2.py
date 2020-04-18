#!/usr/bin/env python3

import random as r

#print(chr(97))
#print(chr(97 + 25))

alphabet = [chr(lettre) for lettre in list(range(97, 97 + 25))]
#print(alphabet)

# Lambda fonction sans paramètre
gen_mot = lambda: ''.join([alphabet[r.randint(0, 100) % 25] for lettre in list(range(r.randint(3, 20)))])
#print(gen_mot())

# Lambda fonction avec un paramètre
gen_phrase = lambda nb_mot: ' '.join([gen_mot() for _ in list(range(nb_mot))])
print(gen_phrase(10))
