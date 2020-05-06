#!/usr/bin/env python3

from random import randint


class Celsius:

    ZERO = -273.15

    def __init__(self, temperature=0):
        self.init_temp = temperature

    def __str__(self):
        return f"{self.init_temp}"

    def get_temperature(self):
        print("get_temperature called")
        return self._temperature

    def set_temperature(self, temperature):
        print("set_temperature called")
        if temperature >= Celsius.ZERO:
            self._temperature = temperature
        else:
            raise ValueError(f"{temperature} < {Celsius.ZERO}")

    init_temp = property()
    init_temp = init_temp.getter(get_temperature)
    init_temp = init_temp.setter(set_temperature)


if __name__ == "__main__":
    l_alea = [randint(270, 280) for i in list(range(10))]
    for i in l_alea:
        p = -i if (i % 2 == 0) else i
        try:
            c = Celsius(p)
            print(c)
        except ValueError as err:
            print(err)
