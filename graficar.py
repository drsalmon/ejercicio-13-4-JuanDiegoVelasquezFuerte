import numpy as np
import matplotlib.pyplot as plt
import os

os.system ("g++ pendulo.cpp")
os.system ("./a.out")

a = np.loadtxt ("datos.dat")
t = np.linspace(0.0,12.0,a.shape[0])

plt.figure()
plt.plot(t,np.log(np.abs(a[:,0] - a[:,1])))
plt.savefig("Lyupanov.png")            
            