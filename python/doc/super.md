# Python `super`

- method overriding possible => polymorphism
- (!) method overloading is NOT possible

## Héritage simple

> repris de programiz

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

## Héritage multiple

> repris de programiz

```python3
class Base1:
    pass

class Base2:
    pass

class MultiDerived(Base1, Base2):
    pass
```

## Biblio

- [realpython](https://realpython.com/lessons/super-and-inheritance-hierarchy/)
- [python docs Enum](https://docs.python.org/3/library/enum.html)
- [programiz](https://www.programiz.com/python-programming/multiple-inheritance)
