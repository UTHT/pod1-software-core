from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from typing import Dict

class Table(QWidget):
    def __init__(self):
        super().__init__()
        self.label = QLabel()
        self.table = QTableWidget()
        self.columns = {}
        self.rows = {}

    def set_title(self, title: str) -> bool:
        self.label.setText(title)
        return True
    
    def set_columns(self, num_columns: int) -> bool:
        if(num_columns < 1):
            return False
        else: 
            self.table.setColumnCount(num_columns)
            for x in range(0,num_columns):
                self.columns[x] = 100
            return True
    
    def set_rows(self, num_rows: int) -> bool:
        if(num_rows < 1):
            return False
        else:
            self.table.setRowCount(num_rows)
            for x in range(0,num_rows):
                self.rows[x] = 50
            return True

    def set_column_width(self, column_number: int, width: float) -> bool:
        if(column_number >= self.table.columnCount()):
            print("Column number passed out of bounds, no changes were made")
            return False
        elif((sum(self.columns.values()) + width) > self.width):
            print("Total column width exceeds width of window, no changes were made")
            return False
        else:
            self.columns[column_number] = width
            return True

    def set_row_width(self,row_number: int, height: float) -> bool:
        if(row_number >= self.table.rowCount()):
            print("Row number passed out of bounds, no changes were made")
            return False
        elif((sum(self.rows.values()) + height) > self.height):
            print("Total row height exceeds height of window, no changes were made")
            return False
        else:
            self.rows[row_number] = height
            return True

    def set_width(self, width: float) -> bool:
        self.width = width
        return True

    def set_height(self, height: float) -> bool:
        self.height = height
        return True

    def update_cell(self,row: int, col: int, value: str) -> bool:
        self.table.item(row, col).setText(value)
        return True
        
    def display(self) -> QWidget:
        for x, y in self.columns.items():
            self.table.setColumnWidth(x,y)
        for x, y in self.rows.items():
            self.table.setRowHeight(x,y)
        for i in range(self.table.rowCount()):
            for j in range(self.table.columnCount()):
                self.table.setItem(i,j, QTableWidgetItem("Cell (%s,%s)" % (i,j)))
                
        self.label.setAlignment(Qt.AlignCenter)
        self.table.horizontalHeader().hide()
        self.setGeometry(0, 0, self.width, self.height)
        self.layout = QVBoxLayout()
        self.layout.addWidget(self.label)
        self.layout.addWidget(self.table) 
        self.setLayout(self.layout) 
        self.show()