#!/usr/bin/env python3

import cgitb
cgitb.enable(format='text')

class Operation:

    def __init__(self, valA, valB):
        self._a = valA
        self._b = valB

    def __str__(self):
        return f"a:{str(self._a)}, b:{str(self._b)}"

    def add(self):
        print('Addition')
        return self._a + self._b

    def div(self):
        print('Division')
        return self._a / self._b

def main():
    op = Operation(4, 2) 
    print(op)
    res = op.add()
    print(res)
    res = op.div()
    print(res)

if __name__ == '__main__':
    main()
