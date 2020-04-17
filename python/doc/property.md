# Python `@property`

## Objectif

Encapulation des attributs

```bash
>>> class Celsius:
...     def __init__(self, temperature):
...             self._temperature = temperature
...
>>> c = Celsius(37)
>>> c.__dict__
{'_temperature': 37}
>>> c.__dict__['_temperature']
37
>>> c.__getattribute__('_temperature')
37
```

- `dir(<ref_instance>)` renvoie tous les attributs de l'objets
> ou bien encore `<ref_instance>.__dir__()` 

> `dir(c)` dans notre exemple ci-dessus

```python
>>> dir(c)
['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_temperature']
>>>
```

## Approche

- `property(fget=None, fset=None, fdel=None, doc=None)`

```python
#!/usr/bin/env python3

from random import randint


class Celsius:

    ZERO = -273.15

    def __init__(self, temperature=0):
        self.temperature = temperature

    def __str__(self):
        return f"{self.temperature}"

    def get_temperature(self):
        print("get_temperature called")
        return self._temperature

    def set_temperature(self, temperature):
        print("set_temperature called")
        if temperature >= Celsius.ZERO:
            self._temperature = temperature
        else:
            raise ValueError(f"{temperature} < {Celsius.ZERO}")

    # ATTENTION: il est important d'avoir deux variables
    # temperature et _temperature
    # En effet :
    # self.temperature = temp est vu comme set_temperature(temp)
    # self.temperature est vu comme un appel à get_temperature()
    # si nous avions _temperature = property(get_temperature, set_temperature)
    # alors nous aurions de appels RECURSIFS...
    temperature = property(get_temperature, set_temperature)


if __name__ == "__main__":
    l_alea = [randint(270, 280) for i in list(range(10))]
    for i in l_alea:
        p = -i if (i % 2 == 0) else i
        try:
            c = Celsius(p)
            print(c)
        except ValueError as err:
            print(err)
```

que l'on peut réécrire en 

```python
#!/usr/bin/env python3


class Celsius:

    ZERO = -273.15

    def __init__(self, temperature=0):
        self.temperature = temperature

    def __str__(self):
        return f"{self.temperature}"

    def get_temperature(self):
        print("get_temperature called")
        return self._temperature

    def set_temperature(self, temperature):
        print("set_temperature called")
        if temperature >= Celsius.ZERO:
            self._temperature = temperature
        else:
            raise ValueError(f"{temperature} < {Celsius.ZERO}")

    temperature = property()
    temperature = temperature.getter(get_temperature)
    temperature = temperature.setter(set_temperature)
```

pour aboutir à la forme ***à utiliser suivante***

```python
#!/usr/bin/env python3


class Celsius:

    ZERO = -273.15

    def __init__(self, temperature=0):
        self.temperature = temperature

    def __str__(self):
        return f"{self.temperature}"

    @property
    def temperature(self):
        print("get_temperature called")
        return self._temperature

    @temperature.setter
    def temperature(self, temperature):
        print("set_temperature called")
        if temperature >= Celsius.ZERO:
            self._temperature = temperature
        else:
            raise ValueError(f"{temperature} < {Celsius.ZERO}")


if __name__ == "__main__":
    c = Celsius(34)
    print(c)

    try:
        c = Celsius(-375)
    except ValueError as err:
        print(err)
    else:
        print(c)
```

## Biblio

- [programiz](https://www.programiz.com/python-programming/property)
