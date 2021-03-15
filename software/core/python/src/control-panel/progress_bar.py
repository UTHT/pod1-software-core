'''
Control Panel Progress Bar Widget
'''
from typing import Union, Any
from PyQt5.QtWidgets import QProgressBar, QWidget, QVBoxLayout, QLabel


class ProgressBar(QWidget):
    def __init__(self,
                 title: str,
                 min_value: Union[int, float],
                 max_value: Union[int, float],
                 top: int,
                 left: int,
                 width: int,
                 height: int,
                 color: str = 'brown',
                 parent: Any = None) -> None:
        super(ProgressBar, self).__init__(parent)
        if not isinstance(min_value, int) and \
                not isinstance(min_value, float) \
                or not isinstance(max_value, int) and \
                not isinstance(max_value, float):
            raise Exception
        self.progressbar = QProgressBar()
        self.progressbar.setMinimum(min_value)
        self.progressbar.setMaximum(max_value)
        self.progressbar.setStyleSheet(
            "QProgressBar::chunk {background: %s}" % color)
        self.progressbar.setGeometry(left, top, width, height)
        self.progressbar.title = title
        self.progressbar.setValue(min_value)
        self.min_max_label = QLabel(
            "min: {}, max: {}". format(
                self.progressbar.minimum(), self.progressbar.maximum())
        )
        self.layout = QVBoxLayout()
        self.layout.addWidget(self.progressbar)
        self.layout.addWidget(self.min_max_label)
        self.setLayout(self.layout)
        self.show()

    def __str__(self) -> str:
        return self.progressbar.title

    def set_current(self, current: Union[int, float]) -> bool:
        if not isinstance(current, int) and not isinstance(current, float):
            return False
        self.progressbar.setValue(current)
        return True
