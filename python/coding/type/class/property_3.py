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
    def temperature(self, temp):
        print("set_temperature called")
        if temp >= Celsius.ZERO:
            self._temperature = temp
        else:
            raise ValueError(f"{temp} < {Celsius.ZERO}")


if __name__ == "__main__":
    c = Celsius(34)
    print(c)

    try:
        c = Celsius(-375)
    except ValueError as err:
        print(err)
    else:
        print(c)

