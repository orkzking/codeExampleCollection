#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
# import numpy as np
import geo_tree_dep.Polygon as Polygon_Module
# end imports


class Quadrat(Polygon_Module.Polygon):
    """Just a dummy geometric class to show depenencies

        A "Quadrat" implements a square and has got 4 points and 1 edgelength
    """

    def __init__(self, ppoints=[[0.0, 0.0], [0.0, 1.0], [1.0, 1.0], [0.0, 1.0]], pedgeLength=1.0):
        """Default constructor"""
        super().__init__(ppoints)
        ## The length of all edges
        self.edgeLength = pedgeLength
        self.name = "Quadrat"

    def printMyData(self):
        print("I am a '" + self.name + "' and my edgeLength is " + str(self.edgeLength) + " and my points have the coords:\n")
        print("p1: " + str(self.points[0, :]) + "\n")
        print("p2: " + str(self.points[1, :]) + "\n")
        print("p3: " + str(self.points[2, :]) + "\n")
        print("p4: " + str(self.points[3, :]) + "\n")
