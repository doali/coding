# Python et les exceptions

## Gérer des exceptions

## Créer ses propres exceptions

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
            print(f"{self.temperature}{FourMalin.DEGRE}, cuisson en cours")
        except FourException as err:
            print(err)
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
