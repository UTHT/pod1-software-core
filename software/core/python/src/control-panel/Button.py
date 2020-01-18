'''
Control Panel Button Widget
'''
from components import Colour


class Button():
    def __init__(self) -> None:
        ...

    def __str__(self) -> str:
        ...

    def action(self) -> None:
        ...

    def set_text(self, text: str) -> bool:
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
