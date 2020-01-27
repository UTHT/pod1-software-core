from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QApplication
from Button import Button
from components import Colour, LayoutOrientation
from Dial import Dial
from Graph import Graph
from Layout import Layout
from MainWindow import Window
from ProgressBar import ProgressBar
from Table import Table
from TextField import TextField


if __name__ == "__main__":
    app = QtWidgets.QApplication([])
    window = QtWidgets.QWidget()
    window.setGeometry(0, 0, 300, 300)

    Button(title='', width=50, height=50,
           left=0, top=100, callback=None,
           tool_tip='test',
           parent=window)
    Dial(title='', width=50, height=50,
         left=0, top=0, min_value=0,
         max_value=10,
         parent=window)
    ProgressBar(title='', width=50, height=50, left=100, top=0,
                min_value=0, max_value=10, parent=window)
    window.show()
    app.exec_()
