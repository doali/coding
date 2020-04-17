# Python encapsulation

- on ne peut pas vraiment protéger l'accès à ses membres


## Cas pratique

### Attributs

```python
#!/usr/bin/env python3

class Base:
    def __init__(self):
        # public
        self.pub = "pub"

        # protected
        self._pro = "pro"

        # private
        self.__pri = "pri"

    def use(self):
        print(f"{Base.__name__}")
        print(self.pub)
        print(self._pro)
        print(self.__pri)


class Derived(Base):
    def __init__(self):
        super().__init__()

    def mine(self):
        print(f"{Derived.__name__}")
        print(self.pub)
        print(self._pro)
        print(self.__pri)

class Other:
    def __init__(self, base):
        self._base = base

def test():
    b = Base()
    o = Other(b)
    print(f"o._base.pub {o._base.pub}")
    print(f"o._base._pro {o._base._pro}")
    print(f"o._base.__pri {o._base.__pri}")

if __name__ == "__main__":
    test()
```

```bash
>>> from encapsulation import *
>>> b = Base()
>>> b.use()
Base
pub
pro
pri
>>> b.pub
'pub'
>>> b._pro
'pro'
>>> b.__pri
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'Base' object has no attribute '__pri'
>>> b.
b.pub   b.use(
>>> d = Derived()
>>> d.use()
Base
pub
pro
pri
>>> d.mine()
Derived
pub
pro
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
  File "/home/blackpc/git-github/coding/python/coding/type/class/encapsulation.py", line 29, in mine
    print(self.__pri)
AttributeError: 'Derived' object has no attribute '_Derived__pri'
>>> d.pub
'pub'
>>> d._pro
'pro'
>>> d.__pri
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'Derived' object has no attribute '__pri'
>>> test()
o._base.pub pub
o._base._pro pro
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
  File "/home/blackpc/git-github/coding/python/coding/type/class/encapsulation.py", line 40, in test
    print(f"o._base.__pri {o._base.__pri}")
AttributeError: 'Base' object has no attribute '__pri'
>>> ls
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'ls' is not defined
>>> d._
d._Base__pri  d._pro
>>> d._Base__pri
'pri'
>>>
```

### Important `name mangling`

```text
Python’s private and protect member can be accessed outside the class through python name mangling.
```

Comme ce que l'on a pu voir dans la trace précédente dans l'interpréteur python3

```bash
>>> d._Base__pri
'pri'
```

Cela s'appelle le `name mangling` et permet d'accéder à tous les membres quelle que soit la visibilité

### Méthodes

_Ce sont les mêmes notions que pour les membres_
- toujours l'idée du `name mangling`
- d'où une pseudo `encapsulation` 

```python
class Base:
    def pub(self):
        print("pub")

    def _pro(self):
        print("_pro")

    def __pri(self):
        print("__pri")

    def use(self):
        print(f"{Base.__name__}")
        self.pub()
        self._pro()
        self.__pri()


class Derived(Base):
    def mine(self):
        print(f"{Derived.__name__}")
        self.pub()
        self._pro()
        self.__pri()


class Other:
    def __init__(self, base):
        self._base = base

```
on ajoute aussi la fonction suivante


```python
def test():
    print("=== Base ===")
    b = Base()
    b.use()

    print("=== Derived ===")
    d = Derived()
    d.use()
    d.mine()

    #print("=== Other ===")
    #o = Other(b)
    #o._base.use()


if __name__ == "__main__":
    test()
```

qui produit le résultat suivant


```bash
=== Base ===
Base
pub
_pro
__pri
=== Derived ===
Base
pub
_pro
__pri
Derived
pub
_pro
Traceback (most recent call last):
  File "./encapsulation_meth.py", line 50, in <module>
    test()
  File "./encapsulation_meth.py", line 42, in test
    d.mine()
  File "./encapsulation_meth.py", line 26, in mine
    self.__pri()
AttributeError: 'Derived' object has no attribute '_Derived__pri'
```

on conserve toujours notre code mais on remplace la méthodes tests par celle-cl

```python
idef test():
    print("=== Base ===")
    b = Base()
    b.use()

    print("=== Derived ===")
    d = Derived()
    d.use()
    #d.mine()

    print("=== Other ===")
    o = Other(b)
    o._base.use()
```

qui produit le résultat

```bash
=== Base ===
Base
pub
_pro
__pri
=== Derived ===
Base
pub
_pro
__pri
=== Other ===
Base
pub
_pro
__pri
```

## Biblio

- [geeksforgeeks](https://www.geeksforgeeks.org/encapsulation-in-python/) (attention j'ai lu des erreurs dans le code)
- [geeksforgeeks _](https://www.geeksforgeeks.org/underscore-_-python/)
