#!/usr/bin/env python3

import sys


def info():
    return f"""
        The name of a file is also the name of the module
        file_name <==> module_name
        ex: file_is_module.py ({sys.argv[0]})
        >>> import file_is_module
        """


if __name__ == "__main__":
    print(info())
