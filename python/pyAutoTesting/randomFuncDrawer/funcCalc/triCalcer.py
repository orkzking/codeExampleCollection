#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
import numpy as np
# import random

class TriCalcer():
	"""This class calculates randomized trigonometric functions
	
	   Especially noised sine and cosine.
	"""

	def __init__(self):
		""" The default constructor """
		print("Atm not needed maybe later in the implementation")


	def calcNoisySine(self, x, seed=None):
		""" This calculates a noisy sine with random magnitude and frequence. """
		if seed != None:
			np.random.seed(seed)
		return np.random.random() * np.sin(2 * np.pi * np.random.random() * x) + np.random.random() * np.sin( 2 * np.pi * np.random.random() * x)

	def calcNoisyCosine(self, x, seed=None):
		""" This calculates a noisy cosine with random magnitude and frequence """
		if seed != None:
			np.random.seed(seed)
		return np.random.random() * np.cos(2 * np.pi * np.random.random() * x) + np.random.random() * np.cos( 2 * np.pi * np.random.random() * x)
