import numpy as np 
import matplotlib.pyplot as plt

mapa = np.genfromtxt('map_data.txt')

plt.imshow(mapa, cmap="winter")
plt.savefig("Mapa.pdf")
