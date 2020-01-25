from typing import NamedTuple
from enum import Enum


class Colour(NamedTuple):
    red: float
    green: float
    blue: float


class Coordinate(NamedTuple):
    x: int
    y: int


class LayoutOrientation(Enum):
    HORIZONTAL = 0
    VERTICAL = 0

    def __str__(self) -> str:
        return self.name
