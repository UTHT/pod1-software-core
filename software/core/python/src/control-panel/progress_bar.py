'''
Control Panel Progress Bar Widget
'''
from typing import Union, Any

import threading
import time
import logging

from PyQt5.QtWidgets import QProgressBar,QApplication,QWidget
from PyQt5.QtCore import pyqtSignal, QThread,pyqtSlot


class ProgressBar(QProgressBar):
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
        self.setMinimum(min_value)
        self.setMaximum(max_value)
        self.setStyleSheet("QProgressBar::chunk {background: %s}" % color)
        self.setGeometry(left, top, width, height)
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

    @pyqtSlot(int)
    def on_sld_valueChanged(self, value):
        self.setValue(value)
        print(self.value)
        self.update()
    

class worker(QWidget):
    my_signal = pyqtSignal(int)

    def emit(self,val: int):
        self.my_signal.emit(val)


def thread_function(work: worker) -> None:
    a = 0
    while(True):
        w.emit(a)
        a = a + 1
        time.sleep(4)
        print(a)



app = QApplication([])

ex = ProgressBar("progress",0,20,0,0,600,600)
 
w = worker()

w.my_signal.connect(ex.on_sld_valueChanged)

x = threading.Thread(target=thread_function,args=(w,),daemon=True)

x.start()

app.exec()

print("thread ending") 