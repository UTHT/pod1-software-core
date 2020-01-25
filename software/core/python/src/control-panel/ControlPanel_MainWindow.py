from PyQt5.QtWidgets import QWidget, QTabWidget, QMainWindow
from Layout import Layout


class MainWindow(QMainWindow):
    def __init__(self, left: int, top: int,
                 width: int, height: int) -> None:
        super().__init__()
        self.tabs = QTabWidget()
        self.setCentralWidget(self.tabs)
        self.title = 'Control Panel'
        self.setWindowTitle(self.title)
        self.setGeometry(left, top, width, height)
        self.setWindowTitle(self.title)
        self.show()

    def new_tab(self, layout: Layout, tab_name: str) -> None:
        tab = QWidget()
        tab.setLayout(layout)
        self.tabs.addTab(tab, tab_name)
