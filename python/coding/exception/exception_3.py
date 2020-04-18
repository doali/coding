#!/usr/bin/env python3

import sys


def test_exception(file_name):
    try:
        f = open(file_name, "r")
        s = f.readline()
        i = int(s.strip())
    except OSError as err:
        print(f"OS error: {err}")
    except ValueError as err:
        # err is bound to the ValueError instance
        print(type(err))
        # ValueError's arguments are store in args
        print(err.args)
        # __str__() is defined
        print(err)
        print("Could not convert data to an integer.")
    except:
        print("Unexpected error:", sys.exc_info()[0])
        raise


if __name__ == "__main__":
    test_exception(sys.argv[0])
