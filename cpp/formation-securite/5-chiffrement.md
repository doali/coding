# Chiffrement

## Asymétrique RSA

### Principe

Chiffrement asymétrique

> N = p * q

> N est publié mais p et q sont privés pour le créateur
> le couple (e, N) constitue la clef publique
> Grace à la clef publique on peut calculer la clef privée
> Le couple (d, N) constitue la clef privée

### Rôle

| Clef publique | uniquement pour chiffrer (ne permet pas de déchiffrer) |
| Clef privée   | uniquement pour chiffrer et signer                     |


| Chiffrement | émetteur chiffre avec la clef publique et destinataire déchiffre avec sa clef privée.                      |
| Signature   | émetteur signe avec sa clef privée et le destinataire utilise la clef publique pour vérifier la signature. |

> On créé un hache qui garantit l'intégrité du document et ont le chiffre avec sa clef privée pour garantir l'authenticité.
> Le destinataire déchiffre le hash avec la clef publique qui garantit donc l'authenticité et la comparaison des hash l'intégrité.

## Symétrique

- Rapide, et clef plus longue.
- Permet également de chiffrer de grande taille de données.

## Mixer les deux techniques de chiffrement

L'objectif est d'utiliser un chiffrement symétrique pour les données avec une clef commune (connue de l'émetteur et du destinataire).
Pour transférer la clef commune, on utilise le chiffrement asymétrique.

1. Envoie de la clef symétrique via la clef asymétrique
2. Chiffrement des données via la clef symétrique
3. Envoie des données chiffrées
4. Réception des données chiffrées
5. Déchiffrement des données chiffrées via la clef symétrique

## Echange Diffie-Hellman

(clef publique Commune, clef privée A) => 3ième clef_A
(clef publique Commune, clef privée B) => 3ième clef_B

A envoie clef_A à B
B envoie clef_B à A

A utilise sa clef privée et clef_B => la clef symétrique commune
A utilise sa clef privée et clef_B => la clef symétrique commune

> L'idée à retenir est d'être en capacité de créer la clef symétrique sans avoir besoin de l'échanger !!
