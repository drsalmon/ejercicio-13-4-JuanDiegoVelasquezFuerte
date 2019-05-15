import numpy as np
import matplotlib.pyplot as plt
import os

os.system ("g++ penduloregcaotico.cpp")
os.system ("./a.out")

datos = np.loadtxt ("angulos.dat")
tiempo = np.linspace(0.0,100.0,datos.shape(datos)[0])

plt.figure()
plt.plot(tiempo,np.log(np.abs(datos[:,0] - datos[:,1])), label = "Simulation")
plt.xlabel("Time")
plt.ylabel("Angle Difference |θ1-θ2|") 
plt.legend(loc = 0)
plt.savefig("Lyapunov_caotic.png")            
            