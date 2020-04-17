#!/usr/bin/env python3


class Base:
    def pub(self):
        print("pub")

    def _pro(self):
        print("_pro")

    def __pri(self):
        print("__pri")

    def use(self):
        print(f"{Base.__name__}")
        self.pub()
        self._pro()
        self.__pri()


class Derived(Base):
    def mine(self):
        print(f"{Derived.__name__}")
        self.pub()
        self._pro()
        self.__pri()


class Other:
    def __init__(self, base):
        self._base = base


def test():
    print("=== Base ===")
    b = Base()
    b.use()

    print("=== Derived ===")
    d = Derived()
    d.use()
    #d.mine()

    print("=== Other ===")
    o = Other(b)
    o._base.use()


if __name__ == "__main__":
    test()
