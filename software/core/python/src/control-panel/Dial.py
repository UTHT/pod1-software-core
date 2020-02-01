'''
Control Panel Dial Widget
'''
from typing import Any, Union
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5 import QtCore
from PyQt5.QtGui import QPainter, QBrush, QPen

from PyQt5.QtCore import Qt
import sys


# class WorkerThread(QtCore.QObject):
#     signalExample = QtCore.pyqtSignal(str, int)
#
#     def __init__(self):
#         super().__init__()
#
#     @QtCore.pyqtSlot()
#     def run(self):
#         while True:
#             self.signalExample.emit("leet", 1337)
#             time.sleep(5)

class Dial(QDial):
    def __init__(self,
                 title: str,
                 top: int,
                 left: int,
                 width: int,
                 height: int,
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
        self.setGeometry(left, top, width, height)
        self.setNotchesVisible(True)
        self.title = title
        self.height = height
        self.width = width
        self.setValue(min_value)
        self.show()

    def __str__(self) -> str:
        return self.title

    def set_current(self, current: Union[int, float]) -> bool:
        if not isinstance(current, int) and not isinstance(current, float):
            return False
        self.setValue(current)
        return True

    def paintEvent(self, event):
        painter = QPainter(self)
        # label = QLabel(self)
        pixmap = QPixmap("dialbackground.png")

        if (self.width >= self.height):
            pixmap = pixmap.scaledToHeight(self.height)
        else:
            pixmap = pixmap.scaledToWidth(self.height)

        painter.drawPixmap(self.rect(),pixmap)

        # if (self.width > self.height):
        #     painter.move(self.height / 2, 0)
        # if (self.height > self.width):
        #     painter.move(0, 0)
        # painter.setAlignment(Qt.AlignCenter)

        painter.setPen(QPen(Qt.white, 8))
        painter.drawLine(self.height/2,self.width/2,50,50)


app = QApplication(sys.argv)
d = Dial (title = "dial", top = 50, left = 50, width = 200, height = 200, min_value=10,max_value=50)
d.set_current(25)
sys.exit(app.exec_())
