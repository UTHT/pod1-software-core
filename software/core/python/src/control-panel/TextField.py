'''
Control Panel Text Field Widget
'''
from typing import Any

from components import Colour


class TextField():
    def __init__(self) -> None:
        ...

    def __str__(self) -> str:
        ...

    def get_input(self) -> Any:
        ...

    def set_width(self, width: float) -> bool:
        ...

    def set_height(self, height: float) -> bool:
        ...

    # TODO: Note sure if best idea to use RGB or if use Hex for colour
    def set_colour(self, colour: Colour) -> bool:
        ...

    # TODO : This should actually return the actual PyQT (or whatever lib we
    #       use) widget, not None. Not sure if this is the best way
    def display(self) -> None:
        ...
