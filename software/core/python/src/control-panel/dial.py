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
        self.setValue(min_value)
        self.show()

    def __str__(self) -> str:
        return self.title

    def set_current(self, current: Union[int, float]) -> bool:
        if not isinstance(current, int) and not isinstance(current, float):
            return False
        self.setValue(current)
        return True
