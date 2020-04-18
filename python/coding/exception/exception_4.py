#!/usr/bin/env python3

# raise an exception (must derived from Exception)
def test_exception():
    try:
        raise NameError("HiThere")
    except NameError as err:
        print(err)
        print("An exception flew by!")
        raise


if __name__ == "__main__":
    test_exception()
