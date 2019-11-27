'''
Control Panel Dial Widget
'''
from typing import Any, Tuple

from components import Colour


class Dial():
    def __init__(self) -> None:
        ...

    def __str__(self) -> str:
        ...

    def set_current(self, current: Any) -> bool:
        ...

    def set_min(self, min_value: Any) -> bool:
        ...

    def set_max(self, min_value: Any) -> bool:
        ...

    def set_width(self, width: float) -> bool:
        ...

    def set_height(self, height: float) -> bool:
        ...

    def set_colour(self, colour: Colour) -> bool:
        ...

    # TODO : This should actually return the actual PyQT (or whatever lib we
    #       use) widget, not None. Not sure if this is the best way
    def display(self) -> None:
        ...
