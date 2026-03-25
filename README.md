# Algoritmos Concurrentes y Paralelos 💻

Este repositorio contiene las resoluciones de los trabajos prácticos de la materia **Algoritmos Concurrentes y Paralelos** (Licenciatura en Informática, Universidad Siglo 21).

## 📂 Estructura del Proyecto

```ascii
.
├── .gitignore
└── TP1/
    ├── Algoritmo1.cpp   # Creación manual de hilos individuales
    ├── Algoritmo2.cpp   # Uso de vectores de threads
    └── Consigna2.cpp    # Implementación de 15 hilos aleatorios con try-catch
```

## 🛠️ Requisitos e Instalación

Para ejecutar estos programas necesitás un compilador de C++ que soporte el estándar **C++11** o superior.

### Compilación y Ejecución

Es fundamental incluir la bandera `-pthread` al compilar para que la librería de hilos funcione correctamente.

**Ejemplo para el TP1:**

```bash
# Compilar el programa de la Consigna 2
g++ TP1/Consigna2.cpp -o TP1_Consigna2 -std=c++11 -pthread

# Ejecutar el binario generado
./TP1_Consigna2
```

## 📝 Notas de Implementación

- **Escalabilidad**: Se prioriza el uso de `std::vector<std::thread>` para gestionar múltiples procesos de forma eficiente.
- **Robustez**: Los desarrollos incluyen bloques `try-catch` para el tratamiento de errores críticos del sistema.
- **Aleatoriedad**: Se utiliza la librería `<random>` para simular comportamientos no deterministas mediante pausas y repeticiones variables.
