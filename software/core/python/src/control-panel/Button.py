'''
Control Panel Button Widget
'''
from typing import Any
from PyQt5.QtWidgets import QPushButton
from PyQt5.QtCore import pyqtSlot

import logging


class Button(QPushButton):
    def __init__(self,
                 title: str,
                 top: int,
                 left: int,
                 width: int,
                 height: int,
                 callback: Any,
                 color: str = 'brown',
                 tool_tip: str = '',
                 parent: Any = None):
        super(Button, self).__init__(title, parent)
        self.setWindowTitle(title)
        self.setStyleSheet(f"background-color: {color}")
        self.setGeometry(left, top, width, height)
        self.setToolTip(tool_tip)
        self.callback = callback if callback is not None else self.on_click
        self.clicked.connect(self.callback)
        self.title = title
        self.show()

    def __str__(self) -> str:
        return self.title

    @pyqtSlot()
    def on_click(self):
        logging.info(f'Button: {str(self)}: Default callback.')
