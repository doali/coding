#!/usr/bin/env python3


class Test:
    # static
    s_cpt = 0

    # instance
    def __init__(self):
        Test.s_cpt += 1

    # redefinition (instance)
    def __str__(self):
        return f"{Test.s_cpt}"

    # instance
    def inst_do(self, a):
        print(a, "instance method")

    # =====
    # comme si nous faisions
    # >>> t = Test()
    # >>> t.inst_do_bis = inst_do
    # =====
    # instance car inst_do (instance)
    inst_do_bis = inst_do

    # static
    def static_do(a):
        print(a, "static method")

    # =====
    # comme si nous faisions
    # >>> Test.static_do_bis = static_do
    # =====
    # static car inst_do (static)
    static_do_bis = static_do


def a_few_test():
    t = Test()
    print(Test.s_cpt)
    t.inst_do(1)
    t.inst_do_bis(2)

    # Test.inst_do(3) <= ERROR
    # Test.inst_do_bis(4) <= ERROR

    Test()
    Test()
    Test()
    Test()
    Test()

    print(Test.s_cpt)

    Test.static_do(10)
    Test.static_do_bis(20)
    # t.static_do(30) <= ERROR
    # t.static_do_bis(40) <= ERROR


if __name__ == "__main__":
    a_few_test()
