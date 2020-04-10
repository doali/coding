# Attributs : static et d'instance

## Dans une classe
- `NomClasse.nom_attribut` : utilisation
- `nom_instance._nom_attribut` : utilisation

```python
class Example:
    Variable = 2           # static variable

print Example.Variable     # prints 2   (static variable)

# Access through an instance
instance = Example()
print instance.Variable    # still 2  (ordinary variable)


# Change within an instance 
instance.Variable = 3      #(ordinary variable)
print instance.Variable    # 3   (ordinary variable)
print Example.Variable     # 2   (static variable)


# Change through Class 
Example.Variable = 5       #(static variable)
print instance.Variable    # 3  (ordinary variable)
print Example.Variable     # 5  (static variable)
```
- `Variable = 2` : est une variable static
> Toute variable définie au niveau d'une classe est static \
> (!) On peut définir malgré tout une variable d'instance de ***même*** nom !! \
> _(Ce qui peut porter à confusion)_

```python
class SomeClass:
    # this is a class attribute
    some_attr = 1

    def __init__(self):
        # this is an instance attribute
        self._new_attr = 2


def main():
    c1 = SomeClass()
    print(c1._new_attr)            # 2
    print(SomeClass.some_attr)     # 1
```
> Utilisation normale des attributs

## Dans une fonction
```python
#!/usr/bin/env python2

def some_fun():
    some_fun.i += 1
    print(some_fun.i)


def main():
    some_fun.i = 0;
    some_fun()         # 1
    some_fun()         # 2
    some_fun()         # 3


if __name__ == "__main__":
    main()
```
> La variable static est définie par le ***nom*** de la fonction `some_fun.variable_static` \
> A chaque appel de la fonction `some_fun()` on retrouve l'état actuel de la variable `some_fun.i`

## Biblio
- [exemple](https://stackoverflow.com/questions/27481116/how-to-declare-a-static-attribute-in-python)