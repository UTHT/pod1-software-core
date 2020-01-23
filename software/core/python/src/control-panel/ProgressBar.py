'''
Control Panel Progress Bar Widget
'''
from typing import Any

from PyQt5.QtWidgets import (QApplication, QProgressBar)


app = QApplication([])


class ProgressBar(QProgressBar):
    def __init__(self):
        super().__init__()

    def __str__(self) -> str:
        ...

    def set_current(self, current: Any) -> None:
        self.setValue(current)

    def set_min(self, min_value: Any) -> bool:
        if(min_value >= 0 and (isinstance(min_value, int) or isinstance(min_value, float))):
            self.setMinimum(min_value)
            return True
        else:
            return False

    def set_max(self, max_value: Any) -> bool:
        if(max_value >= 0 and (isinstance(max_value, int) or isinstance(max_value, float))):
            self.setMaximum(max_value)
            return True
        else:
            return False

    def set_colour(self, colour: str) -> bool:
        if(isinstance(colour, str)):
            self.setStyleSheet("QProgressBar::chunk {background: %s}" % colour)
            return True
        else:
            return False

    def set_geometry(self, width: float, height: float) -> bool:
        if(width >= 0 and (isinstance(width, int) or isinstance(width, float)) and height >= 0 and (isinstance(height, int) or isinstance(height, float))):
            self.setGeometry(0, 0, width, height)
            return True
        else:
            return False

    # TODO : This should actually return the actual PyQT (or whatever lib we
    #       use) widget, not None. Not sure if this is the best way
    def display(self):
        return self
