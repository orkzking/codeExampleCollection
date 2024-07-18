#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
from abc import ABC, abstractmethod
import numpy as np
# end imports

"""@package docstring
This Module implements the abstract class Polyeder.

There are no more details at the moment.
"""


class Polyeder(ABC):
    """Just a dummy geometric class to show depenencies

        An abstract polyeder having n Points and has an abstrcat method to print its data to std out
    """

    def __init__(self, ppoints=list()):
        """The default constructor"""
        ## This variable stores the n points of a polygon in a numpy matrix
        self.points = np.array(ppoints)
        ## This stores the name/type of the polygon as string
        self.name = "Polyeder"
        super().__init__()

    @abstractmethod
    def printMyData(self):
        """Prints the data out to stdout"""
        pass
