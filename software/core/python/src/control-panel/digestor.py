#importing all necessary modules
import json
import os
import sys
from ProgressBar import ProgressBar
from Dial import Dial
from Table import Table
from typing import List
from components import TableLocation,TableEnum

def Digestor(progress_bar: List[ProgressBar], dial: List[Dial], table: Table):

    #initializing TableLocation objects for specifying which cells in table to modify, to be used in widget_dict
    temp1Cell = TableLocation(row=0,col=0)
    temp2Cell = TableLocation(row=0,col=1)
    temp3Cell = TableLocation(row=0,col=2)
    batteryCell = TableLocation(row=1,col=0)
    speedCell = TableLocation(row=2,col=0)

    #initializing dict for mapping data to widgets
    widget_dict = {
        "TEMP1": [dial[0],(table,temp1Cell.row,temp1Cell.col)],
        "TEMP2": [dial[1],(table,temp2Cell.row,temp2Cell.col)],
        "TEMP3": [dial[2],(table,temp3Cell.row,temp3Cell.col)],
        "BATTERY": [progress_bar,(table,batteryCell.row,batteryCell.col)],
        "SPEED": [progress_bar,(table,speedCell.row,speedCell.col)]
    }

    #loading data.json file that is stored in same directory
    with open(os.path.join(sys.path[0], "data.json"), "r") as jsonfile: 
        data = json.load(jsonfile)

    #cycling through parsed json and updating widgets 
    for cluster in data:
        for key in cluster:
            for widget in widget_dict[key]:
                if (isinstance(widget,table)):
                    widget[TableEnum.TABLE].update(cluster[key],widget[TableEnum.ROW],widget[TableEnum.COL])
                else:
                    widget.update(cluster[key])
