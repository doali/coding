#!/usr/bin/env python3


class Person:
    def __init__(self, firstname, lastname):
        self._firstname = firstname
        self._lastname = lastname

    @staticmethod
    def cons_fullname(firstname, lastname):
        return f"{_firstname} {_lastname}"

    @classmethod
    def from_fullname(cls, fullname):
        return fullname.split(" ", 1)

    def __str__(self):
        return f"{self._firstname} {self._lastname}"


def main():
    p_1 = Person("Guido", "van Rossum")
    print(p_1)

    # Assignement enable since size list equals 2
    firstname, lastname = Person.from_fullname(str(p_1))

    print(f"Firstname:{firstname}, Lastname:{lastname}")


if __name__ == "__main__":
    main()
