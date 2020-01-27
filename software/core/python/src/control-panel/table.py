from typing import List, Union, Any

import logging

from PyQt5.QtWidgets import QWidget, QLabel, QTableWidget, \
    QTableWidgetItem, QVBoxLayout
from PyQt5.QtCore import Qt


class Table(QWidget):
    def __init__(self,
                 title: str,
                 columns: int,
                 rows: int,
                 left: int,
                 top: int,
                 width: Union[int, List[int]],
                 height: int,
                 parent: Any = None,
                 width_of_table: bool = False) -> None:
        '''
        @param width: either int or List[int]. If int, all columsn equi-width
                      if List[int], len() must be equal to @param columns
        @param width_of_table: bool. Defines if width is width of column of
                      width of table
        '''
        super(Table, self).__init__(parent)
        self.label = QLabel(self)
        self.table = QTableWidget(self)
        self.label.setText(title)
        self.title = title
        if columns <= 0:
            logging.warning(
                'Table: columns passed in <= 0. Creating 0 column table')
            columns = 0
        if rows <= 0:
            logging.warning(
                'Table: rows passed in <= 0. Creating 0 row table')
            rows = 0
        self.table.setColumnCount(columns)
        self.column_widths = dict()
        total_width = 0
        if isinstance(width, List):
            if len(width) != columns:
                logging.warning(
                    "Table: @param width is a list and doesn't have " +
                    f"length = {columns}. Either define a uni-width or " +
                    "define a width for each column. Defaulting width = " +
                    f"{width}")
                raise Exception
            else:
                for i, w in enumerate(width):
                    self.column_widths[i] = w
                    total_width += w * 5
        else:
            width = width / columns if width_of_table else width
            for i in range(0, columns):
                self.column_widths[i] = width
                total_width += width * 5
        total_height = 0
        self.row_heights = dict()
        self.table.setRowCount(rows)
        for i in range(0, rows):
            self.row_heights[i] = height
            total_height += height * 10

        for x, y in self.column_widths.items():
            self.table.setColumnWidth(x, y)
        for x, y in self.row_heights.items():
            self.table.setRowHeight(x, y)
#         for i in range(self.rowCount()):
#             for j in range(self.columnCount()):
#                 self.setItem(
#                     i, j, QTableWidgetItem("Cell (%s, %s)" % (i, j)))
        self.label.setAlignment(Qt.AlignCenter)
        # self.horizontalHeader().hide()
        self.setGeometry(left, top, total_width, total_height)
        self.layout = QVBoxLayout()
        self.layout.addWidget(self.label)
        self.layout.addWidget(self.table)
        self.setLayout(self.layout)
        self.show()

    def __str__(self) -> str:
        return self.title

    def update_cell(self, row: int, col: int, value: str) -> None:
        self.item(row, col).setText(value)
