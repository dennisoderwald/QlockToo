# -*- coding: utf-8 -*-
"""
Pattern App

Lets the user control each LED in the clock individually and create patterns
"""

from PySide.QtGui import *
from PySide.QtCore import *
from pattern_ui import Ui_pattern

class PatternApp(QDialog):
    def __init__(self, device):
        super(PatternApp, self).__init__()
        self.ui = Ui_pattern()
        self.ui.setupUi(self)
        self.exec_()


if __name__ == "__main__":
    # test environment in simulator
    import sys
    sys.path.append("..")
    from simulator import Simulator
    application = QApplication(sys.argv)
    device = Simulator()
    PatternApp(device)
    application.exec_()
