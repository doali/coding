# YAML

```
YAML Ain't Markup Language is a human-readable data-serialization language
```

## Syntax

- indentation to indicate nesting
- scalars: 
  - strings `""` or `''` or `!!str`
  - integers `1`
  - floats `123.0` or `!!float 123.0`
- lists:
  - `- item1`
  - `[item1, ..., itemN]`
- `key: value` associative arrays (maps, hashes, dictionaries) (!) space after `:` (!)
- `---` document separator (imagine we have one stream) (at the begining)
- `...` end a document
- `#` for comments
- `|` or `>` for block scalars to preserve new lines
- `&` definition
- `*` reference a definition
- `<<` extend objects
- `<<: *`<anchor> inject anchor into and then extend

## Examples

```yaml
---
receipt:     Oz-Ware Purchase Invoice
date:        2012-08-06
customer:
    first_name:   Dorothy
    family_name:  Gale

items:
    - part_no:   A4786
      descrip:   Water Bucket (Filled)
      price:     1.47
      quantity:  4

    - part_no:   E1628
      descrip:   High Heeled "Ruby" Slippers
      size:      8
      price:     133.7
      quantity:  1

bill-to:  &id001
    street: |
            123 Tornado Alley
            Suite 16
    city:   East Centerville
    state:  KS

ship-to:  *id001

specialDelivery:  >
    Follow the Yellow Brick
    Road to the Emerald City.
    Pay no attention to the
    man behind the curtain.
...
```

```yaml
---
foo: &anchor
  K1: "One"
  K2: "Two"

bar:
  <<: *anchor
  K2: "I Changed"
  K3: "Three"

{
    "foo": {
        "K1": "One",
        "K2": "Two"
    },
    "bar": {
        "K1": "One",
        "K2": "I Changed",
        "K3": "Three"
    }
}
...
```

```yaml
---
foo:
 <<: &anchor
   K1: "One"
 K2: "Two"

bar:
 <<: *anchor
 K3: "Three"

{
    "foo": {
        "K1": "One",
        "K2": "Two"
    },
    "bar": {
        "K1": "One",
        "K3": "Three"
    }
}
...
```

### Conversion YAML -> JSON

#### `fichier.yaml`

```yaml
A: 'a'
B: 'b'

D:

liste:
  - a
  - 1
  - 2.0

autre: [1, 2, 3]

personne: &str
  nom: 'coucou'
  prenom:

jean:
  <<: *str
  prenom: 'jean'
  age: 20
```

```bash
alias yaml2js="python3 -c 'import sys, yaml, json; json.dump(yaml.load(sys.stdin), sys.stdout, indent=4)'"
```

```bash
yaml2js < fichier.yaml  > fichier.json
```

#### `fichier.json`

```json
{
    "A": "a",
    "B": "b",
    "D": null,
    "liste": [
        "a",
        1,
        2.0
    ],
    "autre": [
        1,
        2,
        3
    ],
    "personne": {
        "nom": "coucou",
        "prenom": null
    },
    "jean": {
        "nom": "coucou",
        "prenom": "jean",
        "age": 20
    }
}
```

## Biblio

- [w in y](https://learnxinyminutes.com/docs/yaml/)
- [daemonl](https://blog.daemonl.com/2016/02/yaml.html)
- [wikipedia](https://en.wikipedia.org/wiki/YAML)
