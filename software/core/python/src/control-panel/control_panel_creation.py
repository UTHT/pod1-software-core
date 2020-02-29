import json
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import Qt
from window import Window
from progress_bar import ProgressBar
from dial import Dial
from layout import Layout
from PyQt5.QtWidgets import QMainWindow
from components import LayoutOrientation
import widget_factory as factory

app = QtWidgets.QApplication(sys.argv)
    
json_file = open("control_panel_config_full", "r")
control_panel_config = json.load(json_file)
json_file.close()

print(control_panel_config)



tabs = {}


for widget_name in control_panel_config:
    #I'm going to create a dictionary. The keys will be the tab names and the values will be a list of widgets. 
    #I will iterate through this dictionary, and create a layout from the widgets, and then a tab from the tab name and Layout.
    

    widget_info = control_panel_config[widget_name]
    key = widget_name
    value = None

    if(widget_info["TYPE"] == "GRAPH"):
        continue

    if(widget_info["TYPE"] == "PROGRESSBAR"):
        value = factory.createProgressBar(widget_name, widget_info)



    if(widget_info["TYPE"] == "DIAL"):
        value = factory.createDial(widget_name, widget_info)

    if(widget_info["TYPE"] == "BUTTON"):
        value = factory.createButton(widget_name, widget_info)
    
    tab_name = value[0]
    #value is evaluating to None
    widget = value[1]

    if tab_name in tabs:
        tabs[tab_name].append(widget)
    else:
        tabs[tab_name] = [widget]


for tab in tabs:
    print(tab, "  ", len(tabs[tab]))

mainWindow = Window("Main", 0, 100, 200, 300)

for tab_name, widgets in tabs.items():
    newLayout = Layout(widgets, LayoutOrientation.VERTICAL)
    mainWindow.new_tab(newLayout, tab_name)



# for widget in widgets.values:
#     widget_tab = widget[0]
#     if not layouts.__contains__(widget_tab):
#         newLayout = Layout("Vertical")
#         layoutWidget = 
    





sys.exit(app.exec_())

