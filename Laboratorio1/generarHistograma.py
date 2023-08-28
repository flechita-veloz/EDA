import matplotlib.pyplot as plt

# Cargar las distancias desde el archivo de texto
with open("distancias.txt", "r") as file:
    distancias = [float(line.strip()) for line in file]

# Configurar el título del histograma
dimension = "---"  # Reemplaza con la dimensión correspondiente
titulo = f"Histograma de las distancias entre los puntos con dimensión {dimension}"

# Crear el histograma
plt.hist(distancias, bins=20, edgecolor='k', alpha=0.75)

# Personalizar el gráfico
plt.title(titulo)
plt.xlabel("Distancia")
plt.ylabel("Frecuencia")

# Mostrar el histograma
plt.show()
