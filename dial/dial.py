# import sys
# import PyQt5
# from PyQt5 import QtGui,QtCore, QtWidgets
# from PyQt5.QtGui import QIcon
# from PyQt5.QtWidgets import QApplication, QMainWindow, QDialog, QDial, QHBoxLayout, QSpinBox
#
# class Window(QDialog):
#     def __init__(self):
#         super().__init__(dialvalue,Max,Min)
#
#         self.setWindowTitle("Temperature Dial")
#         self.setGeometry(40,400,450,300)
#         self.setWindowIcon(QIcon("dial.py"))
#         self.InitUI(Max,Min)
#
#
#     def InitUI(self,Max,Min):
#         dial = QDial()
#         dial.setNotchesVisible(True)
#         dial.setMinimum(Min)
#         dial.setMaximum(Max)
#         spin = QSpinBox()
#         hbox = QHBoxLayout()
#         hbox.addWidget(dial)
#         hbox.addWidget(spin)
#         self.setLayout(hbox)
#         dial.valueChanged.connect(spin.setValue)
#         spin.valueChanged.connect(dial.setValue)
#
# app = QApplication(sys.argv)
# window = Window()
# window.show()
# app.exec()


from PyQt5.QtWidgets import *
import sys

class Window(QWidget):
    def __init__(self,Max,Min,Val):
        QWidget.__init__(self)
        layout = QGridLayout()
        self.setLayout(layout)
        self.dial = QDial()
        self.dial.setNotchesVisible(True)
        self.dial.setMinimum(Min)
        self.dial.setMaximum(Max)
        self.dial.setValue(Val)
        layout.addWidget(self.dial)

    def updateValue(self,new):
        self.dial.valueChanged.connect(new)

app = QApplication(sys.argv)
screen = Window(100,0,20)
screen.show()
# for i in range(5):
#     new = input("New Value? = ")
#     screen.updateValue(int(new))
sys.exit(app.exec_())

