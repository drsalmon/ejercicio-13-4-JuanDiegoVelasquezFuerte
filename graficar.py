import numpy as np
import matplotlib.pyplot as plt
import os

os.system ("g++ pendulo.cpp")
os.system ("./a.out")

a = np.loadtxt ("datos.dat")
ly = np.log(np.abs(a[:,1]-a[:,2]))

plt.figure()
plt.plot(a[:,0],ly)
plt.savefig("Lyupanov.png")            
            