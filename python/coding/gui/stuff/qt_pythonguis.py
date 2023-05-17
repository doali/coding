import sys
from math import *
from PyQt5 import QtCore, QtGui, QtWidgets, uic
from PyQt5.QtCore import Qt


class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()

        self.label = QtWidgets.QLabel()
        canvas = QtGui.QPixmap(400, 300)
        canvas.fill(Qt.white)
        self.label.setPixmap(canvas)
        self.setCentralWidget(self.label)
        self.draw_line()
        self.draw_point()
        self.draw_cirlce()

    def draw_line(self):
        painter = QtGui.QPainter(self.label.pixmap())
        painter.drawLine(10, 10, 300, 200)
        painter.end()

    def draw_point(self):
        painter = QtGui.QPainter(self.label.pixmap())
        painter.drawPoint(50, 50)
        painter.drawPoint(floor(50 + 4 * cos(pi / 4)), floor(50 + 4 * cos(pi / 4)))
        painter.end()

    def draw_cirlce(self):
        painter = QtGui.QPainter(self.label.pixmap())
        step = 100
        l_val = [x * (2 * pi / step) for x in range(step)]

        for angle in l_val:
            painter.drawPoint(
                floor(150 + 50 * cos(angle)), floor(150 + 50 * sin(angle))
            )
        painter.end()


app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec_()
