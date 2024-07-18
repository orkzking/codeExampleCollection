#!/user/bin/env python
#-*- coding: utf-8 -*-

# this section is for all necessary imports
# import numpy as np
import sys
import numpy as np
import funcCalc.triCalcer as tC
from funcDraw.drawer import Drawer

sys.path.append("../")

if __name__ == "__main__":
    # lTriCalcer = tC.TriCalcer()
    ldrawer = Drawer()
    lX = np.arange(0.0, np.pi*6.0, 0.1)
    ldrawer.drawNoisySine2Window(x=lX)

