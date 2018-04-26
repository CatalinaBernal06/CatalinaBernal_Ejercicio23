import numpy as np
import matplotlib.pyplot as plt

dat = np.loadtxt('datos.txt')
plt.figure()
plt.plot(dat[:,0] , dat[:,1])
plt.show()
