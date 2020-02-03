from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QApplication
from components import Colour, LayoutOrientation
from button import Button
from dial import Dial
from graph import Graph
from layout import Layout
from window import Window
from progress_bar import ProgressBar
from table import Table
from text_field import TextField


if __name__ == "__main__":
    app = QtWidgets.QApplication([])
    window = QtWidgets.QWidget()
    window.setGeometry(0, 0, 300, 300)

    # Button(title='', width=50, height=50,
    #        left=0, top=100, callback=None,
    #        tool_tip='test',
    #        parent=window)
    # Dial(title='', width=50, height=50,
    #      left=0, top=0, min_value=0,
    #      max_value=10,
    #      parent=window)
    # ProgressBar(title='', width=50, height=50, left=100, top=0,
    #             min_value=0, max_value=10, parent=window)
    Table(title='test', columns=5, rows=3, left=0,
          top=0, height=5, width=10, parent=window,
          col_headers=['test', 't', 't', 't', 't'],
          row_headers=['test', 'f', ])
    # TextField(title='test', width=100, height=50, left=0,
    #           top=0, callback=None, parent=window)
    window.show()
    app.exec_()
