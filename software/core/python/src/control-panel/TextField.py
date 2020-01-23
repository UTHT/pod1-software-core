'''
Control Panel Text Field Widget
'''
from typing import Any


from PyQt5.QtWidgets import QWidget, QLineEdit, QPushButton
from PyQt5.QtCore import pyqtSlot

from components import Coordinate  # Colour


class TextField(QWidget):
    def __init__(self,
                 input_type: Any,
                 width: int,
                 height: int,
                 coordinates: Coordinate,) -> None:
        super().__init__()
        self.width = width
        self.height = height
        self.coordinates = coordinates
        self.input_type = input_type
        self.widget = QLineEdit(self)
        self.button = QPushButton('OK', self)

    def __str__(self) -> str:
        return 'TextField'

    # Handle key presses
    # def keyPressEvent(self, qKeyEvent):
    #     if qKeyEvent.key() == 16777220: #enter key
    #         self.on_click()
    @pyqtSlot()
    def on_click(self) -> bool:
        content = self.textbox.text()
        return isinstance(content, type(self.input_type))

    def get_input(self) -> Any:
        return self.widget.text()

    def initUI(self) -> None:
        self.widget.move(self.coordinates.x, self.coordinates.y)
        self.widget.resize(self.width, self.height)

        # Create button
        self.button.move(self.x + self.textBox_width + 5, self.y)
        self.button.resize(50, self.textBox_height)
        self.button.clicked.connect(self.on_click)
        self.show()


# Uncomment to test
# if __name__ == '__main__':
#     app = QApplication(sys.argv)
#     boxA = TextField(0,20,20)
#     sys.exit(app.exec_())
