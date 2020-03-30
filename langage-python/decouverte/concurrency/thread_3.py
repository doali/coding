#!/usr/bin/env python3

import sys
from threading import Thread, RLock

import cgitb


class Counter(Thread):
    lock_crt_sect = RLock() # variable static

    def __init__(self, world):
        Thread.__init__(self)
        self._world = world

    def run(self):
        i = 0

        Counter.lock_crt_sect.acquire() # acquisition du lock_crt_sect
        try:
            while (i < len(self._world)):
                sys.stdout.write(self._world[i])
                sys.stdout.flush()
                i += 1
        finally:
            Counter.lock_crt_sect.release() # relachement du lock_crt_sect
        sys.stdout.write("\n")


def main():
    th_a = Counter("PRATIQUE")
    th_b = Counter("theorie")

    th_a.start()
    th_b.start()

    th_a.run()
    th_b.run()

    th_a.join()
    th_b.join()


if __name__ == "__main__":
    main()
