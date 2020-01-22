'''
Control Panel Button Widget
'''

import sys
from PyQt5.QtWidgets import (QApplication, QWidget, QPushButton)
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot



class Button(QWidget):
    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 button '
        self.left = 10
        self.top = 10
        self.width = 320
        self.height = 200
        self.initUI()
    
    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        self.setStyleSheet("background-color: brown")
        button = QPushButton('PyQt5 button', self)
    
        button.setToolTip('This is an example button')
        button.move(100,70)
        button.clicked.connect(self.on_click)
        
        self.show()

    @pyqtSlot()
    def on_click(self):
        print('PyQt5 button click')
        

    def __str__(self) -> str:
        ...

    def action(self) -> None:
        ...

    def set_text(self, text: str) -> bool:
        self.setWindowTitle(self.title)

    def set_width(self, width: float) -> bool:
        if(width >= 0 and (isinstance(width, int) or isinstance(width, float))):
            self.setGeometry(0,0,width)
            return True
        else:
            return False

    def set_height(self, height: float) -> bool:
        if(height >= 0 and (isinstance(height, int) or isinstance(height, float))):
            self.setGeometry(0,0,height)
            return True
        else:
            return False

    # TODO: Note sure if best idea to use RGB or if use Hex for colour
        if(isinstance(colour, str)):
            self.setStyleSheet("QButton::chunk {background: %s}" % colour)
            return True
        else:
            return False

    # TODO : This should actually return the actual PyQT (or whatever lib we
    #       use) widget, not None. Not sure if this is the best way
    def display(self):
        return self

        #uncomment below to test
"""
if __name__ == '__main__':
    app = QApplication(sys.argv)
    button = Button()
    sys.exit(app.exec_())"""
    