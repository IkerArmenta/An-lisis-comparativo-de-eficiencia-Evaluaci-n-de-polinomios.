# Evaluación de Polinomios - Comparación de Métodos

Me llamo **IKER GERARDO SANCHEZ ARMENTA**

## Nombre del Proyecto y Resumen

**Evaluación de Polinomios - Comparación de Métodos** es un proyecto en C++ diseñado para comparar dos algoritmos clásicos de evaluación de polinomios:

- **Método Estándar:** Calcula el polinomio sumando cada término, es decir, cada coeficiente multiplicado por x elevado a la potencia correspondiente.
- **Método de Horner:** Reestructura el polinomio en forma anidada, reduciendo significativamente la cantidad de operaciones aritméticas, lo que optimiza la evaluación del polinomio.

El programa genera polinomios con coeficientes aleatorios y evalúa cada uno en un valor aleatorio de x. Para cada polinomio se mide el tiempo de ejecución promedio de los dos métodos (realizando 1000 repeticiones) y se registran los resultados en un archivo CSV (`resultados.csv`).

## Autor

**IKER GERARDO SANCHEZ ARMENTA**

## Requisitos del Sistema

- **Sistema Operativo:** Multiplataforma (Windows, Linux, macOS).
- **Compilador C++:** Se recomienda utilizar *g++* versión 7.0 o superior, ya que se requiere soporte para C++17.
- **Bibliotecas Externas:** Solo se usan las bibliotecas estándar de C++ (`<iostream>`, `<vector>`, `<chrono>`, `<random>`, `<fstream>`).

## Instrucciones de Compilación y Ejecución

### Compilación

Utiliza el siguiente comando en la terminal para compilar el código:

```bash
g++ -O2 -std=c++17 main.cpp -o polinomios
