#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
import unittest
import numpy as np
# import randomFuncDrawer.funcCalc.triCalcer.TriCalcer as tc
from randomFuncDrawer.funcCalc.triCalcer import TriCalcer as tc


class TriCalcerFuntionally(unittest.TestCase):
	""" Just test all functions of the class TriCalcer. """

	def setUp(self):
		self.testInteger = np.arange(20)
		self.testDoubles = np.arange(20,0.1)
		self.tTriCalc = None

	def test_calcNoisySine(self):
		self.tTriCalc = tc()
		tIResult = self.tTriCalc.calcNoisySine(self.testInteger,42)
		np.random.seed(42)
		cIResult = np.random.random() * np.sin(2 * np.pi * np.random.random() * self.testInteger) + np.random.random() * np.sin(2 * np.pi * np.random.random() * self.testInteger)
		for i in range(len(cIResult)):
			self.assertEqual(tIResult[i], cIResult[i])
		tDResult = self.tTriCalc.calcNoisySine(self.testDoubles)
		cDResult = np.random.random() * np.sin(2 * np.pi * np.random.random() * self.testDoubles) + np.random.random() * np.sin(2 * np.pi * np.random.random() * self.testDoubles)
		for i in range(len(cDResult)):
			self.assertEqual(tDResult[i],cDResult[i])


	def test_calcNoisyCosine(self):
		self.tTriCalc = tc()
		tIResult = self.tTriCalc.calcNoisyCosine(self.testInteger,1337)
		np.random.seed(1337)
		cIResult = np.random.random() * np.cos(2 * np.pi * np.random.random() * self.testInteger) + np.random.random() * np.cos(2 * np.pi * np.random.random() * self.testInteger)
		for i in range(len(cIResult)):
			self.assertEqual(tIResult[i],cIResult[i])
		tDResult = self.tTriCalc.calcNoisyCosine(self.testDoubles)
		cDResult = np.random.random() * np.cos(2 * np.pi * np.random.random() * self.testDoubles) + np.random.random() * np.cos(2 * np.pi * np.random.random() * self.testDoubles)
		for i in range(len(cDResult)):
			self.assertEqual(tDResult[i],cDResult[i])

	def tearDown(self):
		self.testInteger = None
		self.testdoubles = None
		self.tTriCalc = None

if __name__ == '__main__':
	unittest.main()
