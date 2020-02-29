from typing import Any
from PyQt5.QtWidgets import QWidget, QTabWidget, QMainWindow
from layout import Layout


class Window(QMainWindow):
    def __init__(self,
                 title: str,
                 left: int,
                 top: int,
                 width: int,
                 height: int,
                 parent: Any = None) -> None:
        super().__init__(parent)
        self.tabs = QTabWidget()
        self.setCentralWidget(self.tabs)
        self.title = title
        self.setWindowTitle(self.title)
        self.setGeometry(left, top, width, height)
        self.show()

    def new_tab(self, layout: Layout, tab_name: str) -> None:
        tab = QWidget()
        tab.setLayout(layout.layout)
        self.tabs.addTab(tab, tab_name)
