#!/usr/bin/env python3


class MyClass:
    ##
    # Nb of instance
    # static !!
    count = 0

    def __init__(self, id):
        self._id = str(id)
        MyClass.count += 1

    def __str__(self):
        return f"[{self._id}]"

    @staticmethod
    def total():
        return MyClass.count


if __name__ == "__main__":
    for cpt in list(range(3)):
        print(f"Tour {cpt}; ID {MyClass(cpt)}; Total = {MyClass.total()}")
