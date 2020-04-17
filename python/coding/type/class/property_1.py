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
            raise ValueError(f"{temperature} <= {Celsius.ZERO}")

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
