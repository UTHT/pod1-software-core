from typing import List, Union

import logging

from PyQt5.QtWidgets import QWidget, QLabel, QTableWidget, QTableWidgetItem, \
    QVBoxLayout
from PyQt5.QtCore import Qt


class Table(QWidget):
    def __init__(self,
                 title: str,
                 columns: int,
                 rows: int,
                 width: Union[int, List[int]],
                 height: int,
                 width_of_table: bool = False) -> None:
        '''
        @param width: either int or List[int]. If int, all columsn equi-width
                      if List[int], len() must be equal to @param columns
        @param width_of_table: bool. Defines if width is width of column of
                      width of table
        '''
        super().__init__()
        self.label = QLabel()
        self.widget = QTableWidget()

        self.set_title(title)
        if columns <= 0:
            logging.warning(
                'Table: columns passed in <= 0. Creating 0 column table')
            columns = 0
        if rows <= 0:
            logging.warning(
                'Table: rows passed in <= 0. Creating 0 row table')
            rows = 0
        self.widget.setColumnCount(columns)
        self.columns = dict()
        if isinstance(width, List):
            if len(width) != columns:
                width = 500
                logging.critical(
                    "Table: @param width is a list and doesn't have " +
                    f"length = {columns}. Either define a uni-width or " +
                    "define a width for each column. Defaulting width = " +
                    f"{width}")
            for i, w in enumerate(width):
                self.columns[i] = w
        else:
            width = width / columns if width_of_table else width
            for i in range(0, columns):
                self.columns[i] = width
        self.rows = dict()
        self.table.setRowCount(rows)
        for i in range(0, rows):
            self.rows[i] = height

    def __str__(self) -> str:
        return 'Table'

    def update_cell(self, row: int, col: int, value: str) -> None:
        self.table.item(row, col).setText(value)

    def display(self) -> QWidget:
        for x, y in self.columns.items():
            self.table.setColumnWidth(x, y)
        for x, y in self.rows.items():
            self.table.setRowHeight(x, y)
        for i in range(self.table.rowCount()):
            for j in range(self.table.columnCount()):
                self.table.setItem(
                    i, j, QTableWidgetItem("Cell (%s, %s)" % (i, j)))

        self.label.setAlignment(Qt.AlignCenter)
        self.table.horizontalHeader().hide()
        self.setGeometry(0, 0, self.width, self.height)
        self.layout = QVBoxLayout()
        self.layout.addWidget(self.label)
        self.layout.addWidget(self.table)
        self.setLayout(self.layout)
        self.show()
