from PyQt5.QtWidgets import QWidget
from PyQt5.QtCore import pyqtSignal
from typing import Any, List


'''worker class used for emitting the signal. It contains a pyqtSignal object
that takes in an integer as an argument. This class also has the emit
function defined which takes in an integer and emits the signal with
that integer'''

class worker(QWidget):
    my_signal = pyqtSignal(float,int,list)
    def emit(self,val: Any):
        self.my_signal.emit(val)