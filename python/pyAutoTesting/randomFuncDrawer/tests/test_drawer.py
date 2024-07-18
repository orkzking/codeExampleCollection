#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
import unittest
import numpy as np
from randomFuncDrawer.funcDraw.drawer import Drawer as dw


class DrawerFunctionally(unittest.TestCase):
    """ Just test all functions of the class Drawer. """
    
    def setUp(self):
        self.testInteger = np.arange(20)
        self.testDoubles = np.arange(20,0.1)
        self.tDrawer = dw()
        
    def test_drawNoisySine2Window(self):
        # np.random.seed(42)
        dw.drawNoisySine2Window(x=self.testInteger,seed=42)
        dw.drawNoisySine2Window(x=self.testDoubles,seed=42)
        
    def tearDown(self):
        self.testInteger = None
        self.testDoubles = None
        self.tDrawer = None
