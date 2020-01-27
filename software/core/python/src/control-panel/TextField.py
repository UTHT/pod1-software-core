'''
Control Panel Text Field Widget
'''
from typing import Any, Union

import logging

from PyQt5.QtWidgets import QWidget, QLineEdit, QPushButton
from PyQt5.QtCore import pyqtSlot


class TextField(QWidget):
    def __init__(self,
                 title: str,
                 width: int,
                 height: int,
                 left: int,
                 top: int,
                 callback: Any = None,
                 parent: Any = None) -> None:
        super(TextField, self).__init__(parent)
        # TODO LAYOUT
        self.widget = QLineEdit(self)
        self.button = QPushButton('OK', self)
        self.callback = callback if callback is not None else self.on_click
        self.title = title
        self.setGeometry(left, top, width, height)
        self.widget.resize(width, height)

        # self.button.move(self.coordinates.x + self.width, self.coordinates.y)
        # self.button.resize(50, self.textBox_height)
        self.button.clicked.connect(self.callback)
        self.show()

    def __str__(self) -> str:
        return self.title

    @pyqtSlot()
    def on_click(self) -> bool:
        logging.info(f'TextField: {str(self)}: Default on click.')

    def get_input(self) -> Any:
        return self.widget.text()
