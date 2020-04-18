# Python et les exceptions

## Gérer des exceptions

- clause `try`, `except`, `else`, `finally`
- attraper les exception selon leurs positions dans la hiérarchie des classes
- `raise` pour relancer une exception
- `raise <Exception>` pour lancer `<Exception>`

```python
#!/usr/bin/env python3


class B(Exception):
    pass


class C(B):
    pass


class D(C):
    pass


def test_exception():
    for cls in [B, C, D]:
        try:
            raise cls()
        except D:
            print("D")
        except (B, C):
            print("B or C")


def main():
    test_exception()


if __name__ == "__main__":
    main()
```

## Créer ses propres exceptions

- dériver de la classe `Exception`

```python
#!/usr/bin/env python3


class Error(Exception):
    """Base class for exceptions in this module."""

    pass


class InputError(Error):
    """Exception raised for errors in the input.

    Attributes:
        expression -- input expression in which the error occurred
        message -- explanation of the error
    """

    def __init__(self, expression, message):
        self.expression = expression
        self.message = message


class TransitionError(Error):
    """Raised when an operation attempts a state transition that's not
    allowed.

    Attributes:
        previous -- state at beginning of transition
        next -- attempted new state
        message -- explanation of why the specific transition is not allowed
    """

    def __init__(self, previous, next, message):
        self.previous = previous
        self.next = next
        self.message = message


# Implementation sous forme de class
# avec des methodes statiques
class Test:
    @staticmethod
    def wanna_raise_input():
        raise InputError("expression", "message")

    @staticmethod
    def something_will_happen():
        try:
            print("Ready ?")
            Test.wanna_raise_input()
        except InputError as err:
            print(err)
        finally:
            print("I told you")


# Implementation differente
# utilisation de fonctions
def test_exception():
    def wanna_raise_input():
        raise InputError("expression", "message")

    def something_will_happen():
        try:
            print("Ready ?")
            Test.wanna_raise_input()
        except InputError as err:
            print(err)
        finally:
            print("I told you")

    something_will_happen()


if __name__ == "__main__":
    Test.something_will_happen()
    test_exception()
```

## Exemple

```python
#!/usr/bin/env python3


class FourException(Exception):
    """FourException : gestion des exceptions liées au four"""

    def __init_(self, message):
        self._message = message
        super().__init__()


class FourMalin:
    """FourMalin : four avec sécurite d'extinction au dela d'une certaine température"""

    DEGRE = "°C"
    """Unité de mesure"""

    MAX_TEMPERATURE = 250
    """Temperature maximale autorisée"""

    @property
    def temperature(self):
        """Attribut d'instance : temperature du four"""
        return self._temperature

    @temperature.setter
    def temperature(self, temperature):
        self._temperature = temperature

    def allumer(self, val_temperature):
        """Action d'allumer le four"""
        if val_temperature < FourMalin.MAX_TEMPERATURE:
            self.temperature = val_temperature
            print("Allumage du four")
        else:
            raise FourException(
                f"Attention !! {FourMalin.MAX_TEMPERATURE}{FourMalin.DEGRE} !!"
            )

    def eteindre(self):
        """Action d'éteindre le four"""
        self.temperature = 0
        print(f"Extinction du four temperature {self.temperature}{FourMalin.DEGRE}")

    def cuire(self, temperature):
        """Action de cuisson"""
        print(f"Essai de cuisson")
        try:
            self.allumer(temperature)
        except FourException as err:
            print(err)
        else:
            # Mieux de mettre ici que dans la clause try
            print(f"{self.temperature}{FourMalin.DEGRE}, cuisson en cours")
        finally:
            self.eteindre()


def main():
    """Scénario"""
    four = FourMalin()
    four.cuire(100)
    four.cuire(300)


if __name__ == "__main__":
    main()
```

## Bibliographie

- [pierre giraud](https://www.pierre-giraud.com/python-apprendre-programmer-cours/gestion-exception-try-except-else/)
- [docs python](https://docs.python.org/3/library/re.html)
- [docs python](https://docs.python.org/3/tutorial/errors.html)
