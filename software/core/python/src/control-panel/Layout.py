import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QPushButton, QWidget, QAction, QTabWidget,QVBoxLayout, QHBoxLayout, QDockWidget, QBoxLayout
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot

class Layout():
    def __init__(self, list, layout_type):
        self.layout = None
        self.initGUI(list, layout_type)
    
    def initGUI(self, list, layout_type):
        self.layout = QVBoxLayout()

        if layout_type == "vertical":
            self.layout = QVBoxLayout()
            self.addWidgets(list)

        elif layout_type == "horizontal":
            self.layout = QHBoxLayout()
            self.addWidgets(list)
        
    def addWidgets(self,list):
        length = len(list)
        i = 0
        for i in range(length):
            self.layout.addWidget(list[i])
    
    def returnLayout(self):
        return self.layout

