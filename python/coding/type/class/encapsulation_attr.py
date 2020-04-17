#!/usr/bin/env python3


class Base:
    def __init__(self):
        # public
        self.pub = "pub"

        # protected
        self._pro = "pro"

        # private
        self.__pri = "pri"

    def use(self):
        print(f"{Base.__name__}")
        print(self.pub)
        print(self._pro)
        print(self.__pri)


class Derived(Base):
    def __init__(self):
        super().__init__()

    def mine(self):
        print(f"{Derived.__name__}")
        print(self.pub)
        print(self._pro)
        print(self.__pri)


class Other:
    def __init__(self, base):
        self._base = base


def test():
    b = Base()
    o = Other(b)
    print(f"o._base.pub {o._base.pub}")
    print(f"o._base._pro {o._base._pro}")
    print(f"o._base.__pri {o._base.__pri}")


if __name__ == "__main__":
    test()
