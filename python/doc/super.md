# Python `super`

- method overriding possible => polymorphism
- (!) method overloading is NOT possible

## Principe

```text
super() alone returns a temporary object of the superclass that then allows you to call that superclass’s methods.
```

```text
super() returns a delegate object to a parent class, so you call the method you want directly on it: super().area().
```

> _Citation de realpython_

## Héritage

- `object` est la super classe primitive de toute classe...

***sauf*** les classes d'exception

```python
>>> class MyError:
...     pass
...
>>> raise MyError()
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: exceptions must derive from BaseException
>>>
```

en rectifiant, on obtient comme ceci

```python
>>> class MyError(BaseException):
...     pass
...
>>> raise MyError()
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
__main__.MyError
>>>
```

> (!) il est recommandé de dériver ses exceptions depuis `Exception` (et non `BaseException` directement)
> `Exception` : on est ainsi au niveau des exceptions différentes des exceptions systèmes

pour le reste, on dérive de la classe `object` (au moins par transitivité)

```python
>>> dir()
['__annotations__', '__builtins__', '__doc__', '__loader__', '__name__', '__package__', '__spec__']
>>> o = object()
>>> dir(o)
['__class__', '__delattr__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__']
>>> class MyClass:
...     pass
...
>>> mc = MyClass()
>>> dir(mc)
['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__']
>>>
```

### Héritage simple

Description de la syntaxe

```python
class MaSuperClasse:
    pass

class MaClasseFille(MaSuperClasse):
    pass
```

> Methodes utiles

```python3
>>> from inheritance_simple_3 import *
>>> msc = Ma
MaClasseFille(  MaSuperClasse(
>>> msc = MaSuperClasse()
>>> mcf = MaClasseFille()
>>> msc is mcf
False
>>> msc == mcf
False
>>> issubclass(MaClasseFille, MaSuperClasse)
True
>>> issubclass(MaSuperClasse, MaClasseFille)
False
>>> isinstance(a, MaClasseFille)
False
>>> isinstance(a, MaSuperClasse)
True
>>> isinstance(b, MaClasseFille)
True
>>> isinstance(b, MaSuperClasse)
True
>>> b = a
>>> b is a
True
>>> a == a
True
>>>
```

#### `super().<methode>`

```python
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
```

qui renvoie

```bash
Instanciation de MaSuperClasse
Super classe : __main__ <class '__main__.MaSuperClasse'>

Instanciation de MaClasseFille
Super classe : __main__ <class '__main__.MaClasseFille'>
Classe fille : __main__ <class '__main__.MaClasseFille'>
```

```python
class Shape:
    def __init__(self, name):
        self.name = name

    def area(self):
        pass

    def fact(self):
        return "I am a two-dimensional shape."

    def __str__(self):
        return self.name


class Square(Shape):
    def __init__(self, length):
        super().__init__("Square")
        self.length = length

    def area(self):
        return self.length ** 2

    def fact(self):
        return "Squares have each angle equal to 90 degrees."
```

> repris de programiz

#### `super(<sous_classe>, <instance_sous_classe>).<methode>`

La méthode <methode> recherchée commencera à partir de la classe parente de `<sous_classe>`

```python
class Rectangle:
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width

    def perimeter(self):
        return 2 * self.length + 2 * self.width

class Square(Rectangle):
    def __init__(self, length):
        super(Square, self).__init__(length, length)
        # Identique en python3 à
        #super(Square, self).__init__(length, length)

class Cube(Square):
    def surface_area(self):
        # ATTENTION : ici, on passe Square et non Cube
        # => .area() sera cherchée dans la classe parente de Square (soit Rectangle)
        # cela ne change rien dans cette situation par rapport à l'appel
        # super().area() <= qui aurait directement cherché dans la classe parente de Cube (soit Square)
        # car en effet, Square ne redéfinit pas la méthode .area()
        face_area = super(Square, self).area()
        return face_area * 6

    def volume(self):
        face_area = super(Square, self).area()
        return face_area * self.length

if __name__ == '__main__':
    sq = Square(2)
    print(f"{sq.area()}")
    cb = Cube(2)
    print(f"{cb.volume()}")
```

### Héritage multiple

```python
class Base1:
    pass

class Base2:
    pass

class MultiDerived(Base1, Base2):
    pass
```
> repris de programiz

## Biblio

- [realpython](https://realpython.com/lessons/super-and-inheritance-hierarchy/)
- [python docs Enum](https://docs.python.org/3/library/enum.html)
- [programiz](https://www.programiz.com/python-programming/multiple-inheritance)
- [inheritance](https://realpython.com/inheritance-composition-python/#whats-composition)
