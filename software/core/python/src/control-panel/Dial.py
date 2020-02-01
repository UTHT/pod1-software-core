'''
Control Panel Dial Widget
'''
from typing import Any, Union
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5 import QtCore
from PyQt5.QtGui import QPainter, QBrush, QPen, QFont
import math
from PyQt5.QtCore import Qt, QPoint
import sys


class Dial(QDial):
    def __init__(self,
                 title: str,
                 top: int,
                 left: int,
                 diameter: int,
                 min_value: Union[int, float],
                 max_value: Union[int, float],
                 parent: Any = None) -> None:
        super(Dial, self).__init__(parent)
        if not isinstance(min_value, int) and \
                not isinstance(min_value, float) \
                or not isinstance(max_value, int) and \
                not isinstance(max_value, float):
            raise Exception

        self.setMinimum(min_value)
        self.setMaximum(max_value)
        self.setGeometry(left, top, diameter, diameter)
        self.setNotchesVisible(True)
        self.setValue(min_value)

        
        self.minval = min_value
        self.maxval = max_value
        self.current = min_value
        self.title = title
        self.diameter = diameter
        
        self.show()

    def __str__(self) -> str:
        return self.title

    def set_current(self, current: Union[int, float]) -> bool:
        if not isinstance(current, int) and not isinstance(current, float):
            return False
        self.setValue(current)
        self.current = current
        return True

    def paintEvent(self, event):
        painter = QPainter(self)
        pixmap = QPixmap("dialbackground.png")


        painter.drawPixmap(self.rect(),pixmap)

        painter.setFont(QFont('Open Sans', self.diameter/40, weight=QFont.Bold))
        painter.setPen(QPen(Qt.white, 8))

        minpos = QPoint(self.diameter * 0.22, self.diameter * 0.85)
        painter.drawText(minpos, str(self.minval))
        maxpos = QPoint(self.diameter * 0.70, self.diameter * 0.85)
        painter.drawText(maxpos, str(self.maxval))
        midpoint = QPoint(self.diameter / 2, self.diameter/10*6)
        painter.drawText(midpoint, str(self.current))

        needlelength = math.sqrt((self.diameter/2-self.diameter*0.25)**2+(self.diameter/2-self.diameter*0.75)**2)
        diff = self.maxval-self.minval
        degpertick = 270/diff
        numtickstomove = self.current - self.minval
        degtorotate = degpertick * numtickstomove

        newdegrees = 225 - degtorotate
        x = needlelength * math.cos(newdegrees*math.pi/180)
        y = needlelength * math.sin(newdegrees*math.pi/180)

        painter.drawLine(self.diameter / 2, self.diameter / 2, (self.diameter/2)+x, (self.diameter/2)-y)


app = QApplication(sys.argv)
d = Dial (title = "dial", top = 50, left = 50, diameter = 400, min_value=10,max_value=50)
d.set_current(40)
sys.exit(app.exec_())