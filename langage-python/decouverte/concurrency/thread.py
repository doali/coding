#!/usr/bin/env python3

import sys
from threading import Thread, RLock

import cgitb

class Counter(Thread):

    def __init__(self, world, _lock):
        Thread.__init__(self)
        self._world = world
        self._lock = _lock

    def run(self):
        i = 0

        self._lock.acquire()
        while (i < len(self._world)):
            sys.stdout.write(self._world[i])
            sys.stdout.flush()
            i += 1
        self._lock.release()
        sys.stdout.write("")

def main():
    lock = RLock()

    th_a = Counter("PRATIQUE", lock)
    th_b = Counter("theorie", lock)

    th_a.start()
    th_b.start()

    th_a.run()
    th_b.run()

    th_a.join()
    th_b.join()


if __name__ == "__main__":
    main()
