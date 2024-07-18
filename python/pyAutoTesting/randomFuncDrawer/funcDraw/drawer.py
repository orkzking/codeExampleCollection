#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
import numpy as np
import matplotlib.pyplot as plt
from funcCalc.triCalcer import TriCalcer as tc

class Drawer():
    """ This class draws the output of different Calcers and save them as files.

        Every drawer gets his own methods.
    """

    def __init__(self):
        """ The default constructor """
        self.triC = tc()

    def drawNoisySine2Window(self, x, seed=None):
        """ This draws a noisy sine calculated with triCalcer """
        nS = self.triC.calcNoisySine(x,seed)
        fig = plt.figure()
        plt.plot(x,nS)
        plt.tight_layout()
        plt.show()

