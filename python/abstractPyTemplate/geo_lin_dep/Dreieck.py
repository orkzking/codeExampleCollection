#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
import numpy as np
import geo_lin_dep.Quadrat as Quadrat_Module
# end imports


class Dreieck(Quadrat_Module.Quadrat):
    """Just a dummy geometric class to show depenencies

        A "Dreieck" implements a triangle and has got 3 points and 1 edgelength
    """
    def __init__(self, p1, p2, p3):
        """Default constructor"""
        ## This are the three point locations of the trigangle stored in a numpy matrix
        self.points = np.array([p1, p2, p3])
        ## This is the edge length of the class
        self.edgeLength = 3.0

    def printMyData(self):
        """Prints the data out to stdout"""
        print("I am a 'Triangle' and my edgeLength is " + str(self.edgeLength) + " and my points have the coords:\n")
        print("p1: " + str(self.points[0, :]) + "\n")
        print("p2: " + str(self.points[1, :]) + "\n")
        print("p3: " + str(self.points[2, :]) + "\n")
