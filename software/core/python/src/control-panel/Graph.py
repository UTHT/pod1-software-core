'''
Control Panel Graph Widget
'''
import numpy as np
import PyQt5 as pq
#from PyQt5.QtWidgets import QApplication, QLabel
import PyQt5.QtWidgets as pqtw
from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg
import logging

from typing import Any


class Graph:
    graph_title = ""
    window_title = ""
    x_axis_title = ""
    y_axis_title = ""
    width = 0
    height = 0
    x_units = ""
    y_units = ""
    x_data = 0
    y_data = 0

    def __init__(self):
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

    def __str__(self):
        logging.info('Graph initialized with title: '+ self.graph_title+ '\nIn the pod-system of: ' + self.window_title)

    def set_graph_title(self, name_of_graph):
        self.graph_title = name_of_graph

    def set_window_title(self, name_of_window):
        self.window_title = name_of_window

    def set_x_axis_title(self, x_axis, unit):
        self.x_axis_title = x_axis
        self.x_units = unit

    def set_y_axis_title(self, y_axis, unit):
        self.y_axis_title = y_axis
        self.y_units = unit

    def plot(self, max, data):  # "data" here represents the data read from the pod
        self.x_data = np.arange(0, max)
        self.y_data = data  # chanel_name.handle(data_structure)

    def set_width(self, window_width):
        self.width = window_width

    def set_height(self, window_height):
        self.height = window_height

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

if __name__ == '__main__':
    import sys
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        Graph1 = Graph()

        Graph1.set_height(1000);
        Graph1.set_width(1000)
        Graph1.set_graph_title("Un-initialized")
        Graph1.set_window_title("Un-initialized")
        Graph1.set_x_axis_title("Un-initialized", "Un-initialized")
        Graph1.set_y_axis_title("Un-initialized", "Un-initialized")
        Graph1.plot(50, np.random.normal(size=100))

        Graph1.display()





