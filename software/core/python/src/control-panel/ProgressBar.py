'''
Control Panel Progress Bar Widget
'''
from typing import Any

from components import Colour


class ProgressBar():
    def __init__(self) -> None:
        ...

    def __str__(self) -> str:
        ...

    def set_current(self, current: Any) -> None:
        ...

    def set_min(self, min_value: Any) -> bool:
        ...

    def set_max(self, max_value: Any) -> bool:
        ...

    def set_colour(self, colour: Colour) -> bool:
        ...

    def set_width(self, width: float) -> bool:
        ...

    def set_height(self, height: float) -> bool:
        ...

    # TODO : This should actually return the actual PyQT (or whatever lib we
    #       use) widget, not None. Not sure if this is the best way
    def display(self) -> None:
        ...
