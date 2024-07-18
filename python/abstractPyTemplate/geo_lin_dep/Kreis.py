#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
import numpy as np
import geo_lin_dep.Quadrat as Quadrat_Module
# end imports


class Kreis(Quadrat_Module.Quadrat):
    """Just a dummy geometric class to show depenencies

        A "Kreis" implements a circle and has got 1 center point and 1 radius
    """
    def __init__(self, p1=[0.0, 0.0], pradius=1.0):
        self.points = np.array(p1)
        self.edgeLength = pradius
        self.radius = pradius

    def printMyData(self):
        """Prints the data out to stdout"""
        print("I am a 'Kreis' and my radius is " + str(self.edgeLength) + " and my center point has the coords:\n")
        print("p1: " + str(self.points[:]) + "\n")
