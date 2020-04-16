#!/usr/bin/env python3


class Celsius:

    ZERO = -273.15

    def __init__(self, temperature=0):
        self.temperature = temperature

    def __str__(self):
        return f"{self.temperature}"

    def get_temperature(self):
        return self._temperature

    def set_temperature(self, temperature):
        if temperature >= Celsius.ZERO:
            self._temperature = temperature
        else:
            raise ValueError(f"{temperature} <= {Celsius.ZERO}")

    temperature = property(get_temperature, set_temperature)
