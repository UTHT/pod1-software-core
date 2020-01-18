from PyQt5.QtWidgets import *
import sys

class Window(QWidget):
    def __init__(self,Max,Min,signallist):
        QWidget.__init__(self)
        layout = QGridLayout()
        self.spin = QSpinBox()
        self.setLayout(layout)
        self.dial = QDial()
        self.dial.setNotchesVisible(True)
        self.dial.setMinimum(Min)
        self.dial.setMaximum(Max)
        self.dial.setValue(signallist[len(signallist)-1])
        self.spin.setValue(signallist[len(signallist)-1])
        layout.addWidget(self.dial)
        layout.addWidget(self.spin)
        self.dial.valueChanged.connect(self.spin.setValue)
        self.spin.valueChanged.connect(self.dial.setValue)


app = QApplication(sys.argv)
screen = Window(100,0,[20,30,40])
screen.show()
sys.exit(app.exec_())

