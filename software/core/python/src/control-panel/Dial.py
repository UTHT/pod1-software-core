'''
Control Panel Dial Widget
'''
from typing import Any, Union
from PyQt5.QtWidgets import QDial


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
        self.setMinimum(min_value)
        self.setMaximum(max_value)
        self.setGeometry(left, top, width, height)
        self.setNotchesVisible(True)
        self.title = title
        self.show()

    def __str__(self) -> str:
        return self.title

    def set_current(self, current: Any) -> bool:
        self.setValue(current)
