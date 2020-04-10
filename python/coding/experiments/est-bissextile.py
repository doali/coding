#!/usr/bin/env python3

import sys

def est_bissextile(annee):
    return (((annee % 4 ==0) and (annee % 100 != 0)) or (annee % 400 == 0))

def usage():
    print("Usage:\tbissextile <annee>")


def main():
    if len(sys.argv) == 2:
        try: 
            val = int(sys.argv[1])
            print(val, est_bissextile(val) == True)
        except:
            usage()
    else:
        usage()


if __name__ == "__main__":
    main()
