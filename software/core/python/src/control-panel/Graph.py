'''
Control Panel Graph Widget
'''

import numpy as np
from PyQt5.QtWidgets import QApplication
from pyqtgraph.Qt import QtGui
import pyqtgraph as pg

import logging

from typing import Any, Union


class Graph(QApplication):

    def __init__(self,
                 graph_title: str,
                 window_title: str,
                 x_axis_title: str,
                 y_axis_title: str,
                 width: Union[int, float],
                 height: Union[int, float],
                 x_units: str,
                 y_units: str,
                 x_data: Union[float, list],
                 y_data: Union[float, list],
                 parent: Any = None):
        if graph_title is None \
                and window_title is None \
                and x_axis_title is None \
                and y_axis_title is None \
                and width is None \
                and height is None \
                and x_units is None \
                and y_units is None \
                and x_data is None \
                and y_data is None:
            self.height = 100
            self.width = 100
            self.graph_title = "Un-initialized"
            self.window_title = "Un-initialized"
            self.x_axis_title = "Un-initialized"
            self.x_units = "Un-initialized"
            self.y_axis_title = "Un-initialized"
            self.y_units = "Un-initialized"
            self.x_data = 50
            self.y_data = np.random.normal(size=100)
        else:
            super(Graph, self).__init__(parent)
            self.graph_title = graph_title
            self.window_title = window_title
            self.x_axis_title = x_axis_title
            self.y_axis_title = y_axis_title
            self.width = width
            self.height = height
            self.x_units = x_units
            self.y_units = y_units
            self.x_data = x_data
            self.y_data = y_data

    def __str__(self):
        logging.info('Graph initialized with title: '+ self.graph_title+ '\nIn the pod-system of: ' + self.window_title)

    def set_graph_title(self, name_of_graph) -> bool:
        if not isinstance(name_of_graph, str):
            return False
        self.graph_title = name_of_graph
        return True

    def set_window_title(self, name_of_window) -> bool:
        if not isinstance(name_of_window, str):
            return False
        self.window_title = name_of_window
        return True

    def set_x_axis_title(self, x_axis, unit) -> bool:
        if not isinstance(x_axis, str) and not isinstance(unit, str):
            return False
        self.x_axis_title = x_axis
        self.x_units = unit
        return True

    def set_y_axis_title(self, y_axis, unit) -> bool:
        if not isinstance(y_axis, str) and not isinstance(unit, str):
            return False

        self.y_axis_title = y_axis
        self.y_units = unit
        return True

    def plot(self, max, data):  # "data" here represents the data read from the pod
        self.x_data = np.arange(0, max)
        self.y_data = data  # chanel_name.handle(data_structure)

    def set_width(self, window_width):
        if not isinstance(window_width, int):
            return False
        self.width = window_width
        return True

    def set_height(self, window_height):
        if not isinstance(window_height, int):
            return False
        self.height = window_height
        return True

    def display(self):
        app = QtGui.QApplication([])

        win = pg.GraphicsWindow(title="Title")
        win.resize(self.width, self.height)
        win.setWindowTitle(self.window_title)

        plot = win.addPlot(title=self.graph_title, y = self.y_data) #DATA from system that is to be displayed goes here
        plot.setLabel('left', self.y_axis_title, units = self.x_units)
        plot.setLabel('bottom', self.x_axis_title, units = self.y_units)

        QtGui.QApplication.instance().exec_()

        return win




