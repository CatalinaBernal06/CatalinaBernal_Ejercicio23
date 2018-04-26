import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt('datos.txt')
plt.figure()
plt.plot(datos[:,0], datos[:,1], label ='valor inicial de u (A = 1.0)')
plt.plot(datos[:,0], datos[:,2], label ='u (A = 0.5)')
plt.plot(datos[:,0], datos[:,3], label ='u (A = -0.5)')
plt.plot(datos[:,0], datos[:,4], label ='u (A = -1.0)')
plt.xlabel('X : desplazamiento')
plt.ylabel('Valor de U')
plt.title('Ecuacion de Onda')
plt.legend()
plt.savefig('onda.pdf')
