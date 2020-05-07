#!/usr/bin/env python3


class Person:
    def __init__(self, nom, prenom):
        self._nom = nom
        self._prenom = prenom

    def __str__(self):
        return f"{self._nom} {self._prenom}"

    def decorate(fun):
        def dec(msg):
            return f"=>...{fun(msg)}...<="

        return dec

    def pretty_print(msg):
        return f"{msg}"

    pretty_print = decorate(decorate(pretty_print))


if __name__ == "__main__":
    p = Person("X", "Y")
    print(p)
    res = Person.pretty_print(p)
    print(res)
