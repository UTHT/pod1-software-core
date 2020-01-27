from typing import List, Any

from PyQt5.QtWidgets import QVBoxLayout, QHBoxLayout

from components import LayoutOrientation


class Layout():
    def __init__(self, items: List[Any],
                 layout_type: LayoutOrientation) -> None:
        self.layout = None
        self.initGUI(items, layout_type)

    def initGUI(self, items: List[Any], layout_type: LayoutOrientation):
        if layout_type == LayoutOrientation.VERTICAL:
            self.layout = QVBoxLayout()

        elif layout_type == LayoutOrientation.HORIZONTAL:
            self.layout = QHBoxLayout()

        self.add_widgets(items)

    def add_widgets(self, items: List[Any]):
        for item in items:
            self.layout.addWidget(item)
