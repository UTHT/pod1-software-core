'''
Control Panel Dial Widget
'''
from typing import Any, Tuple

from components import Colour


class Dial():
    def __init__(self) -> None:
        QWidget.__init__(self)
        self.layout = QGridLayout()
        self.dial = QDial()

    def __str__(self) -> str:
        ...

    def set_current(self, current: Any) -> bool:
        self.dial.setValue(current)

    def set_min(self, min_value: Any) -> bool:
        self.dial.setMinimum(min_value)

    def set_max(self, max_value: Any) -> bool:
        self.dial.setMaximum(max_value)

    def set_width(self, width: float) -> bool:
        ...

    def set_height(self, height: float) -> bool:
        ...

    def set_colour(self, colour: Colour) -> bool:
        ...

    # TODO : This should actually return the actual PyQT (or whatever lib we
    #       use) widget, not None. Not sure if this is the best way
    def display(self) -> None:
        self.setLayout(self.layout)
        self.dial.setNotchesVisible(True)
        self.layout.addWidget(self.dial)
        app = QApplication(sys.argv)
        d = dial(100,0,50)
        d.show()
        sys.exit(app.exec_())
        
