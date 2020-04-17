# Python `@property`

## Approche

- `property(fget=None, fset=None, fdel=None, doc=None)`

```python
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
            raise ValueError(f"{temperature} <= {Celsius.ZERO}")

    # ATTENTION: il est important d'avoir deux variables
    # temperature et _temperature
    # En effet :
    # self.temperature = temp est vu comme set_temperature(temp)
    # self.temperature est vu comme un appel à get_temperature()
    # si nous avions _temperature = property(get_temperature, set_temperature)
    # alors nous aurions de appels RECURSIFS...
    temperature = property(get_temperature, set_temperature)
```

que l'on peut réécrire en 

```python
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
            raise ValueError(f"{temperature} <= {Celsius.ZERO}")

    temperature = property()
    temperature.getter(get_temperature)
    temperature.setter(set_temperature)
```



```python


## Biblio

- [programiz](https://www.programiz.com/python-programming/property)
