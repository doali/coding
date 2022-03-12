#!/usr/bin/env python3
# --------------------------------------------------------------------------------
# Same (almost) program in ruby
# https://github.com/doali/coding/tree/master/ruby/coding/experiments/class_inheritance_static.rb
# --------------------------------------------------------------------------------
class Coucou:
    def __init__(self, first="", last=""):
        self.first = first
        self.last = last

    def __str__(self):
        return f"Coucou {self.first} {self.last}"

    def doS(self):
        print(f"{self.first} does something")


class Titi(Coucou):
    a = "a"

    def decorate_me(f):
        def g(self, msg):
            print("==================")
            f(self, msg)
            print("==================")

        return g
       
    @decorate_me
    def coucou(self, msg):
        print(f"Ceci est le {msg}")

    def __init__(self, a="", b=""):
        Coucou.__init__(self, a, b)
        super().__init__(a, b)
        self.a = "b"

    def __str__(self):
        return f"Titi"

    def doS(self):
        print(f"I, {self.first} do not anything special")

    def titi(obj):
        print(f"titi {obj}")

    @staticmethod
    def titou(obj):
        print(f"titou {obj}")

class GenreDeFoncteur:
    def __init__(self, msg):
        self.msg = "comme un genre de foncteur"

    def __call__(self, *args, **kwargs):
        print("__call__ appelée")

if __name__ == "__main__":
    c = Coucou("first", "last")
    print(c)

    tt = Titi("r", "r")
    print(tt)
    print("=================")
    k = Titi("a", "a")
    Titi.titi("sans staticmethod")
    Titi.titou("avec staticmethod")
    # Titi().titi("sans staticmethod")
    Titi().titou("avec staticmethod")
    print(k)
    print("=================")

    t = Titi("titi", "kk")
    print(t)

    for e in [c, t]:
        e.doS()

    s = Titi()
    print(s.a)
    print(Titi.a)

    Titi().coucou("tata")

    g = GenreDeFoncteur("coucou")
    g()
