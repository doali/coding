#!/usr/bin/env python3

import time
import threading
import sys

UP='A'
DOWN='B'
LEFT='D'
RIGHT='C'

class Progress:
    def __init__(self, alive):
        self.alive=False

    def progress(self):
        print('start')
        print('\033[{}{}'.format(1, UP), end='')
        print('\033[{}{}'.format(10, RIGHT), end='')
        list_cursor = ['|','/','-','\\']
        while self.alive:
            for cursor_position in list_cursor:
                print(cursor_position)
                print('\033[{}{}'.format(10, RIGHT), end='')
                print('\033[{}{}'.format(1, UP), end='')
                time.sleep(0.08)
        print('\033[{}{}'.format(10, LEFT), end='')
        print()
        print('stop')

    def progress_stop(self):
        self.alive=False

    def progress_start(self):
        self.alive=True
        self.progress()

def main(timer=3):
    progress = Progress(timer)
    th_timer = threading.Timer(timer, progress.progress_stop)
    th_timer.start()
    progress.progress_start()

def usage():
    print('Usage : progress_cursors.py <number_time_value>')

if __name__ == '__main__':
    if len(sys.argv) == 2:
        try:
            main(float(sys.argv[1]))
        except:
            usage()
    else:
        usage()
