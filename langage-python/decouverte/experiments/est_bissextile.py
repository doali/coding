#!/usr/bin/env python

import sys


def est_bissextile(annee):
    if annee % 4 != 0:
        return False
    if annee % 100 == 0:
        if annee % 400 == 0:
            return True
        else:
            return False
        return True


def usage():
    print("Usage:\tbissextile <annee>")


def main():
    if len(sys.argv) == 2:
        print(sys.argv[1], est_bissextile(int(sys.argv[1])) == True)
    else:
        usage()


if __name__ == "__main__":
    main()
