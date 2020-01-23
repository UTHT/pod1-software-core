import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QPushButton, QWidget, QAction, QTabWidget,QVBoxLayout, QHBoxLayout, QDockWidget, QLayout
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot
from Layout import *

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
       