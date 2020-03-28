#!/usr/bin/env python

import re
import sys

def check_addr_mail(addr_mail):
    reg_ex = re.compile(r"(\w+)@(\w+\.[a-zA-Z]{2,3})")
    tuple_groupe = reg_ex.search(addr_mail)
    addr = False
    if (tuple_groupe <> None):
        print tuple_groupe.group(0)
        print tuple_groupe.group(1)
        print tuple_groupe.group(2)
        if len(tuple_groupe.group(0)) == len(addr_mail):
            addr = True

    if not addr:
        print addr_mail,'is not valid'
    else:
        print addr_mail,'is valid'

    return tuple_groupe


def main():
    if len(sys.argv) == 2:
        check_addr_mail(sys.argv[1])
    else:
        print 'Usage : %s <user>@<domain>' % (sys.argv[0])

if __name__ == '__main__':
    main()
