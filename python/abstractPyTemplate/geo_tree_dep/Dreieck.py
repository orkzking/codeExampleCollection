#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
# import numpy as np
import geo_tree_dep.Polygon as Polygon_Module
# end imports


class Dreieck(Polygon_Module.Polygon):
    """Just a dummy geometric class to show depenencies

        A "Dreieck" implements a triangle and has got 3 points and 1 edgelength
    """
    def __init__(self, ppoints=[[0.0, 0.0], [0.0, 3.0], [1.5, 2.5981]], pedgeLength=3.0):
        """Default constructor"""
        super().__init__(ppoints)
        ## The length of all edges
        self.edgeLength = pedgeLength
        self.name = "Dreieck"

    def printMyData(self):
        """Prints the data out to stdout"""
        print("I am a '" + self.name + "' and my edgeLength is " + str(self.edgeLength) + " and my points have the coords:\n")
        print("p1: " + str(self.points[0, :]) + "\n")
        print("p2: " + str(self.points[1, :]) + "\n")
        print("p3: " + str(self.points[2, :]) + "\n")
