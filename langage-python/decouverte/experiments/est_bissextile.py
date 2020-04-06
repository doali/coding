#!/usr/bin/env python3

import sys


def est_bissextile(annee):
    if (annee % 4) != 0:
        return False
    if (annee % 100) == 0:
        if (annee % 400) != 0:
            return False
        return True
    return True


def usage():
    print("Usage:\tbissextile <annee>")


def main():
    if len(sys.argv) == 2:
        try: 
            val = int(sys.argv[1])
            print(sys.argv[1], est_bissextile(val) == True)
        except:
            usage()
    else:
        usage()


if __name__ == "__main__":
    main()
