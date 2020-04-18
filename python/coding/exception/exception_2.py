#!/usr/bin/env python3


class B(Exception):
    pass


class C(B):
    pass


class D(C):
    pass


def test_exception():
    for cls in [B, C, D]:
        try:
            raise cls()
        except D:
            print("D")
        except (B, C):
            print("B or C")


def main():
    test_exception()


if __name__ == "__main__":
    main()
