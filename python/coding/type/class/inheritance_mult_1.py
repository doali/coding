#!/usr/bin/env python3

# Code from : https://www.programiz.com/python-programming/polymorphism

from math import pi
from enum import Enum


class EColor(Enum):
    RED = 1
    GREEN = 2
    BLUE = 3


class Color:
    def __init__(self, ecolor):
        self._ecolor = ecolor

    def __str__(self):
        return f"I'm {self._ecolor} !!"


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


class Circle(Shape, Color):
    def __init__(self, radius, ecolor):
        Shape.__init__(self, "Circle")
        Color.__init__(self, ecolor)
        self.radius = radius

    def area(self):
        return pi * self.radius ** 2

    def __str__(self):
        return f"Forme: {self.name}, Color: {self._ecolor}"



a = Square(4)
print(a)
b = Circle(7, Color(EColor.BLUE))
print(b)
print(b.fact())
print(a.fact())
print(b.area())
