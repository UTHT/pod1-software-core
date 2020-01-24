from typing import NamedTuple
from enum import Enum

class Colour(NamedTuple):
    red: float
    green: float
    blue: float


class TableLocation(NamedTuple):
    row: int
    col: int

class TableEnum(Enum):
    TABLE: 0
    ROW: 1
    COL: 1
