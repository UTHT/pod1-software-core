'''
Control Panel Button Widget
'''
from PyQt5.QtWidgets import QWidget, QPushButton
from PyQt5.QtCore import pyqtSlot

from components import Coordinate


class Button(QWidget):
    def __init__(self,
                 title: str,
                 coordinates: Coordinate,
                 width: int,
                 height: int):
        super().__init__()
        self.setWindowTitle(self.title)
        self.setGeometry(coordinates.x, coordinates.y, width, height)

    def __str__(self) -> str:
        return 'Button'

    def initUI(self):
        # TODO what?
        self.setStyleSheet("background-color: brown")
        button = QPushButton('PyQt5 button', self)

        button.setToolTip('This is an example button')
        button.move(100, 70)
        button.clicked.connect(self.on_click)

        self.show()

    @pyqtSlot()
    def on_click(self):
        print('PyQt5 button click')

    def action(self) -> None:
        ...


"""
if __name__ == '__main__':
    app = QApplication(sys.argv)
    button = Button()
    sys.exit(app.exec_())"""
