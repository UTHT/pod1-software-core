from typing import NamedTuple
from enum import Enum


class Colour(NamedTuple):
    red: float
    green: float
    blue: float


class LayoutOrientation(Enum):
    HORIZONTAL = 0
    VERTICAL = 0

    def __str__(self) -> str:
        return self.name


class TableLocation(NamedTuple):
    row: int
    col: int


class CellLocation(Enum):
    TABLE: 0
    ROW: 1
    COL: 1

    def __str__(self) -> str:
        return self.name
