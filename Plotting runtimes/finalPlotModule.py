# Siddharth Agarwal
# 1001577570
# 
# python finalPlotModule.py <input file name with extension> <output graph name without extension >
# for example
# python finalPlotModule.py runtime.txt testPlot2

import os
import sys
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


filenamePath = './'+sys.argv[1]
outputGraphName = sys.argv[2]+'.png'

churnData = pd.read_csv(filenamePath)

fig = churnData.plot()


fig = fig.get_figure()


fig.savefig(sys.argv[2])

