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
        print(c)
        c = -375
        print(c)
    except ValueError as err:
        print(err)

