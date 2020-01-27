'''
Control Panel Graph Widget
'''
from typing import Any


class Graph():
    def __init__(self) -> None:
        ...

    def __str__(self) -> str:
        ...

    def set_title(self, title: str) -> bool:
        ...

    def set_x_axis_title(self, title: str) -> bool:
        ...

    def set_y_axis_title(self, title: str) -> bool:
        ...

    def set_plot_type(self, plot_type: Any) -> bool:
        ...

    def plot(self, x: Any, y: Any) -> bool:
        ...

    def set_width(self, width: float) -> bool:
        ...

    def set_height(self, height: float) -> bool:
        ...

    # TODO : This should actually return the actual PyQT (or whatever lib we
    #       use) widget, not None. Not sure if this is the best way
    def display(self) -> None:
        ...
