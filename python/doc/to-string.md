# Python _to string_

_Deux possibilités pour représenter un objet sous forme de chaines de caractères._

- `__repr__` : pour les développeurs, description interne de l'objet
- `__str__` : pour les utilisateurs, description _pretty print_ de l'objet

> (!) si `__str__` est manquant alors `__repr__` est invoquée

```python
class ReprVsStr:
    def __repr__(self):
        return "<{0}.{1} object at {2}>".format(
            self.__module__, type(self).__name__, hex(id(self))
        )

    def __str__(self):
        return (
            f"Nom de la classe {type(self).__name__} dans le module {self.__module__}"
        )


print(repr(ReprVsStr()))
print(str(ReprVsStr()))
```

## `__str__`

```text
if you print an object, or pass it to format, str.format, or str, then if a __str__ method is defined, that method will be called, otherwise, __repr__ will be used.
```


## `__repr__`

```text
The __repr__ method is called by the builtin function repr and is what is echoed on your python shell when it evaluates an expression that returns an object.

Since it provides a backup for __str__, if you can only write one, start with __repr__
```

## Biblio

- [stackoverflox](https://stackoverflow.com/questions/1436703/difference-between-str-and-repr)
