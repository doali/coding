#!/usr/bin/env python3


class Titi:
    def __init__(self, id, name):
        self.id = id
        self.name = name

    def do_something(self):
        print("I'm doing something")

    def __str__(self):
        f"id:{self.id} name:{self.name}"

    @staticmethod
    def do_static_thing():
        print("static thing is about to happen")

    def function():
        print("Plain old function")


if __name__ == "__main__":
    msg = "Everything works fine"
    print(msg)

    titi = Titi(1, "titi")

    titi.do_something()
    
    titi.do_static_thing()
    Titi.do_static_thing()

    Titi.function()
    #titi.function()
