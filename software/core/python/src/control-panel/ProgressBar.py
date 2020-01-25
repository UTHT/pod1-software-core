'''
Control Panel Progress Bar Widget
'''
from typing import Union

from PyQt5.QtWidgets import (QApplication, QProgressBar)


app = QApplication([])


class ProgressBar(QProgressBar):
    def __init__(self,
                 min_value: Union[int, float],
                 max_value: Union[int, float],
                 colour: str,
                 top: int,
                 left: int,
                 width: int,
                 height: int) -> None:
        super().__init__()
        if not isinstance(min_value, int) or not isinstance(min_value, float) \
                or not isinstance(max_value, int) or \
                not isinstance(max_value, float):
            raise
        self.setMinimum(min_value)
        self.setMaximum(max_value)
        self.setStyleSheet("QProgressBar::chunk {background: %s}" % colour)
        self.setGeometry(left, top, width, height)

    def __str__(self) -> str:
        return 'ProgressBar'

    def set_current(self, current: Union[int, float]) -> bool:
        if not isinstance(current, int) or not isinstance(current, float):
            return False
        self.setValue(current)
        return True

    # TODO : This should actually return the actual PyQT (or whatever lib we
    #       use) widget, not None. Not sure if this is the best way
    def display(self):
        return self
