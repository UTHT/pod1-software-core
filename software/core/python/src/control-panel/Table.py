'''
Control Panel Table Widget
'''


class Table():
    def __init__(self) -> None:
        ...

    def __str__(self) -> str:
        ...

    def set_title(self, title: str) -> bool:
        ...

    def set_columns(self, num_columns: int) -> bool:
        ...

    def set_rows(self, num_rows: int) -> bool:
        ...

    # NOTE : these two should have checking to make sure it fits in width for
    #        example
    def set_column_width(self, column_number: int, width: float) -> bool:
        ...

    def set_row_height(self, column_number: int, width: float) -> bool:
        ...

    def set_width(self, width: float) -> bool:
        ...

    def set_height(self, height: float) -> bool:
        ...

    # TODO : This should actually return the actual PyQT (or whatever lib we
    #       use) widget, not None. Not sure if this is the best way
    def display(self) -> None:
        ...
