import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QPushButton, QWidget, QAction, QTabWidget,QVBoxLayout, QHBoxLayout, QDockWidget, QLayout
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot
from Layout import *


app = QApplication(sys.argv)

class mainWindow(QMainWindow):

    def __init__(self):
        super().__init__()
        self.tabs = QTabWidget()
        self.setCentralWidget(self.tabs)
        self.title= 'Control Panel'
        self.setWindowTitle(self.title)
        self.setGeometry(0,0,300,200)
        self.setWindowTitle(self.title)
        self.show()


    def changeGeometry(self, left, top, width, height):
        self.setGeometry(left,top,width,height)
    
    def newTab(self, layout, tab_name):
        tab = QWidget()
        tab.setLayout(layout)
        self.tabs.addTab(tab, tab_name)
       
        

#I'm going to have a method that takes in a list of widgets, a string that either says 'vertical' or 'horizontal',
#I also need a method to create tabs and decide which widgets go in which tab.

widget1 = QPushButton("I'm a button")
widget2 = QPushButton ("I'm an inferior button")
list = [widget1, widget2]
x = Layout(list, "vertical")
layout = x.returnLayout()

push1 = QPushButton("niggers")
push2 = QPushButton("Lebron James")
list2 = [push1, push2]
y = Layout(list2, "vertical")
layout2 = y.returnLayout()

window = mainWindow()
window.newTab(layout, "moist")
window.newTab(layout2, "tingly")


app.exec_()