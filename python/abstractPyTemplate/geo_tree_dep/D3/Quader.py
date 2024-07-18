#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
# import numpy as np
import geo_tree_dep.D3.Polyeder as Polyeder_Module
# end imports


class Quader(Polyeder_Module.Polyeder):
    """Just a dummy geometric class to show depenencies

        A "Quader" has got 8 points and 3 edgelengthes
    """

    def __init__(self, ppoints=[[0.0, 0.0, 0.0], [0.0, 1.0, 0.0], [2.0, 1.0, 0.0], [2.0, 0.0, 0.0], [0.0, 0.0, 3.0], [0.0, 1.0, 3.0], [2.0, 1.0, 3.0], [2.0, 0.0, 3.0]], pedgeLengths=[2.0, 1.0, 3.0]):
        """Default constructor"""
        super().__init__(ppoints)
        ## The length of all edges
        self.edgeLengths = pedgeLengths
        self.name = "Quader"

    def printMyData(self):
        print("I am a '" + self.name + "' and my edgeLengths are " + str(self.edgeLengths) + " and my points have the coords:\n")
        print("p1: " + str(self.points[0, :]) + "\n")
        print("p2: " + str(self.points[1, :]) + "\n")
        print("p3: " + str(self.points[2, :]) + "\n")
        print("p4: " + str(self.points[3, :]) + "\n")
        print("p5: " + str(self.points[4, :]) + "\n")
        print("p6: " + str(self.points[5, :]) + "\n")
        print("p7: " + str(self.points[6, :]) + "\n")
        print("p8: " + str(self.points[7, :]) + "\n")
