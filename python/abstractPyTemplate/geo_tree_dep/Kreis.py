#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
# import numpy as np
import geo_tree_dep.Polygon as Polygon_Module
# end imports


class Kreis(Polygon_Module.Polygon):
    """Just a dummy geometric class to show depenencies

        A "Kreis" implements a circle and has got 1 center point and 1 radius
    """
    def __init__(self, pcenter=[0.0, 0.0], pradius=1.0):
        """Default constructor"""
        super().__init__(pcenter)
        self.name = "Kreis"
        self.radius = pradius

    def printMyData(self):
        """Prints the data out to stdout"""
        print("I am a '" + self.name + "' and my radius is " + str(self.radius) + " and my center point has the coords:\n")
        print("p1: " + str(self.points[:]) + "\n")
