from PyQt5.QtWidgets import *
import sys

class dial(QWidget):
    def __init__(self,Max,Min,Val):
        QWidget.__init__(self)
        layout = QGridLayout()
        self.spin = QSpinBox()
        self.setLayout(layout)
        self.dial = QDial()
        self.dial.setNotchesVisible(True)
        self.dial.setMinimum(Min)
        self.dial.setMaximum(Max)
        self.dial.setValue(Val)
        self.spin.setValue(Val)
        layout.addWidget(self.dial)
        layout.addWidget(self.spin)
        self.dial.valueChanged.connect(self.spin.setValue)
        self.spin.valueChanged.connect(self.dial.setValue)

    def update(self,newval):
        self.dial.valueChanged(newval)

app = QApplication(sys.argv)
d = dial(100,0,50)
d.show()
# d.update(50)
sys.exit(app.exec_())

