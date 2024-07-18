#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
import numpy as np
# end imports


class Quadrat(object):
    """Just a dummy geometric class to show depenencies

        A "Quadrat" implements a square and has got 4 points and 1 edgelength
    """

    def __init__(self, p1, p2, p3, p4):
        """Default constructor"""
        ## This are the four point locations of the square stored in a numpy matrix
        self.points = np.array([p1, p2, p3, p4])
        ## This is the edge length of the class
        self.edgeLength = 1.0

    def printMyData(self):
        """Prints the data out to stdout"""
        print("I am a 'Quadrat' and my edgeLength is " + str(self.edgeLength) + " and my points have the coords:\n")
        print("p1: " + str(self.points[0, :]) + "\n")
        print("p2: " + str(self.points[1, :]) + "\n")
        print("p3: " + str(self.points[2, :]) + "\n")
        print("p4: " + str(self.points[3, :]) + "\n")
