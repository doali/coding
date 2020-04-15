#!/usr/bin/env python3


class Student(object):
    def __init__(self, first_name, last_name):
        self._first_name = first_name
        self._last_name = last_name

    @classmethod
    def from_string_class(cls, name_str):
        first_name, last_name = map(str, name_str.split(" "))
        student = cls(first_name, last_name)
        return student

    @staticmethod
    def from_string_static(name_str):
        first_name, last_name = map(str, name_str.split(" "))
        student = Student(first_name, last_name)
        return student

    def __str__(self):
        return f"{self._first_name} {self._last_name}"


class Person:
    def __init__(self, firstname, lastname):
        self._firstname = firstname
        self._lastname = lastname

    @staticmethod
    def cons_fullname(firstname, lastname):
        return f"{self._firstname} {self._lastname}"

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

    s_1 = Student("John", "Mac")
    print(s_1)
    s_class = Student.from_string_class("John Martin")
    print(s_class)
    s_static = Student.from_string_static("Jenny Martin")
    print(s_static)


if __name__ == "__main__":
    main()
