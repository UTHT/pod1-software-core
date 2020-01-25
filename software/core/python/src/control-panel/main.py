from PyQt5.QtWidgets import QApplication
from Button import Button
from components import Colour, Coordinate, LayoutOrientation
from Dial import Dial
from Graph import Graph
from Layout import Layout
from MainWindow import MainWindow
from ProgressBar import ProgressBar
from Table import Table
from TextField import TextField

import sys


if __name__ == "__main__":
    app = QApplication(sys.argv)
    boxA = TextField('', width=50, height=50, left=0, top=0)
    sys.exit(app.exec_())
