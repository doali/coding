#!/usr/bin/env python3


class Student(object):
    def __init__(self, first_name, last_name):
        self._first_name = first_name
        self._last_name = last_name

    def __str__(self):
        return f"{self._first_name} {self._last_name}"


scott = Student("Scott", "Robinson")
print(scott)
