'''
Control Panel Graph Widget
'''
from PyQt5 import QtWidgets, QtCore, uic
from pyqtgraph.Qt import QtGui
from pyqtgraph import PlotWidget, plot
import pyqtgraph as pg
from PyQt5.QtWidgets import QProgressBar, QWidget, QVBoxLayout, QApplication, QLabel


from typing import Any, List, Union


class Graph(QWidget):
    def __init__(self,
                 x: List[Union[float, int]],
                 y: List[Union[float, int]],
                 width: int,
                 height: int,
                 x_units: str,
                 y_units: str,
                 title: str = '',
                 x_axis_title: str = '',
                 y_axis_title: str = '',
                 parent: Any = None) -> None:
        super(Graph, self).__init__(parent=parent)
        self.title = title

        # win = pg.GraphicsWindow(title=title)
        # self.resize(width, height)
        # self.setWindowTitle(title)

        # DATA from system that is to be displayed goes here
        self.graphWidget = pg.PlotWidget()
        self.graphWidget.setTitle(title)
        self.graphWidget.setLabel('bottom', x_axis_title + ' (' + x_units + ')')
        self.graphWidget.setLabel('left', y_axis_title + ' (' + y_units + ')')
        self.resize(300,300)
        self.x = x
        self.y = y
        self.graphWidget.setBackground('w')

        pen = pg.mkPen(color=(255, 0, 0))

        self.data_line = self.graphWidget.plot(self.x, self.y, pen=pen)

        self.new_x = [4,5,6,7,8]
        self.new_y = [11,17,20,45,60]
        self.count = 0

        # QtGui.QApplication.instance().exec_()
        self.layout = QVBoxLayout()
        self.layout.addWidget(self.graphWidget)
        self.setLayout(self.layout)
        self.show()


    def update_plot_data(self):
        self.x.append(self.new_x[self.count])
        self.y.append(self.new_y[self.count])
        self.data_line.setData(self.x, self.y)

    def __str__(self) -> str:
        return self.title
