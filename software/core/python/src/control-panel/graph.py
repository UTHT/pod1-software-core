'''
Control Panel Graph Widget
'''

from pyqtgraph.Qt import QtGui
import pyqtgraph as pg


from typing import Any, List, Union


class Graph(pg.GraphicsWindow):
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
        super(Graph, self).__init__(title=title,
                                    size=(height, width),
                                    parent=parent)
        self.title = title

        # win = pg.GraphicsWindow(title=title)
        # self.resize(width, height)
        # self.setWindowTitle(title)

        # DATA from system that is to be displayed goes here
        plot = self.addPlot(title=title, x=x, y=y)
        plot.setLabel('left', y_axis_title, units=y_units)
        plot.setLabel('bottom', x_axis_title, units=x_units)

        # QtGui.QApplication.instance().exec_()
        self.show()

    def __str__(self) -> str:
        return self.title
