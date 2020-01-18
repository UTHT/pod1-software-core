'''
Control Panel Text Field Widget
'''
from typing import Any

from components import Colour

import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

class TextField(QWidget):
    def __init__(self, inputType: int, originX: int, originY: int) -> None:
        # initialize text box
        super().__init__()

        # default width and height
        self.textBox_width = 200
        self.textBox_height = 27
        
        # at position (originX,originY)
        self.x = originX
        self.y = originY
        
        # expected type
        # >>>>>>>>>>>> note: 0 - float | 1 - string <<<<<<<<<<<<<<<<
        self.expectedType = inputType

        # calling initUI
        self.initUI()


    def __str__(self) -> str:
        ...

    def initUI(self):
        # create textbox
        self.textbox = QLineEdit(self)
        self.textbox.move(self.x, self.y)
        self.textbox.resize(self.textBox_width, self.textBox_height)

        # Create button
        self.button = QPushButton('OK', self)
        self.button.move(self.x + self.textBox_width + 5, self.y)
        self.button.resize(50, self.textBox_height)
        self.button.clicked.connect(self.on_click)
        self.show()


    # Handle key presses
    # def keyPressEvent(self, qKeyEvent):
    #     if qKeyEvent.key() == 16777220: #enter key
    #         self.on_click()

    @pyqtSlot()
    def on_click(self):
        # print ("PARSING INPUTS NOW")
        self.typeCheck(self.textbox.text())


    def get_input(self) -> Any:
        # print()
        # print("get_input = ", self.textbox.text())
        # print()
        return self.textbox.text()

    def set_width(self, width: float) -> bool:
        self.textBox_width = width
        self.textbox.resize(self.textBox_width, self.textBox_height)

    def set_height(self, height: float) -> bool:
        self.textBox_height = height
        self.textbox.resize(self.textBox_width, self.textBox_height)

    # TODO: Note sure if best idea to use RGB or if use Hex for colour
    def set_colour(self, colour: Colour) -> bool:
        ...

    # TODO : This should actually return the actual PyQT (or whatever lib we
    #       use) widget, not None. Not sure if this is the best way
    def display(self) -> None:
        ...

    # Helper Functions
    def typeCheck(self, input) -> bool:
        # if float...
        if self.isFloat(input):
            if self.expectedType==0:
                # print("Input is accepted")
                return True
            else:
                # print("Input is NOT accepted")
                return False

        # if string...
        if not self.isFloat(input):
            if self.expectedType==1:
                # print("Input is accepted")
                return True
            else:
                # print("Input is NOT accepted")
                return False

    def isFloat(self, input):
        try:
            float(input)
            return True
        except ValueError:
            return False


# Uncomment to test
# if __name__ == '__main__':
#     app = QApplication(sys.argv)
#     boxA = TextField(0,20,20)
#     sys.exit(app.exec_())