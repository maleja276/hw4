import numpy as np 
import matplotlib.pyplot as plt

map = np.genfromtxt('map_data.txt')
datos=np.genfromtxt('datos.txt')

rad=datos[0]
py=datos[1]
px=datos[2]

fig, top=plt.subplots()
circulo=plt.Circle((px,py), rad, alpha=.2, color='black')
top.add_artist(circulo)
top.add_artist(plt.imshow(map, cmap='winter'))
top.set_title("PUNTO NEMO-MC")
plt.savefig('PuntoNemo.pdf')
plt.close()
