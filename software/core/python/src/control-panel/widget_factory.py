from progress_bar import ProgressBar
from dial import Dial
from button import Button

def createProgressBar(title, dict):
        top = dict["TOP"]
        left = dict["LEFT"]
        width = dict["WIDTH"]
        height = dict["HEIGHT"]
        color = dict["COLOR"]
        min, max = dict["MINMAX"]
        progressbar = ProgressBar(title, min, max, top, left, width, height, color)
        return [dict["TAB"], progressbar]


def createDial(title, dict):
        top = dict["TOP"]
        left = dict["LEFT"]
        width = dict["WIDTH"]
        height = dict["HEIGHT"]
        min, max = dict["MINMAX"]
        dial = Dial(title, top, left, width, height, min, max)
        return [dict["TAB"], dial]

def createButton(title, dict):
    top = dict["TOP"]
    left = dict["LEFT"]
    width = dict["WIDTH"]
    height = dict["HEIGHT"]
    callback = None
    color = dict["COLOR"]
    tooltip = dict["TOOLTIP"]
    button = Button(title, top, left, width, height, callback, color, tooltip)
    return [dict["TAB"], button]