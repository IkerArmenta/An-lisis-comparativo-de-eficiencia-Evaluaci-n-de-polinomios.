# Evaluación de Polinomios

Este proyecto en C++ compara dos métodos clásicos para evaluar polinomios:

- **Método Estándar:** Evalúa el polinomio calculando, para cada término, *coeficiente · (x<sup>i</sup>)* utilizando la función `std::pow`.
- **Método de Horner:** Emplea el algoritmo de Horner, que reduce las operaciones aritméticas, evaluando el polinomio de manera más eficiente.

El programa genera aleatoriamente polinomios de distintos grados (de 10 a 1000, con incrementos de 10) y un valor aleatorio para `x` (en el rango [-10, 10] excluyendo el cero). Para cada caso, se mide el tiempo promedio (en nanosegundos) de ejecución de ambos métodos, ejecutando cada evaluación 1000 veces. Los resultados se registran en un archivo CSV llamado `resultados.csv`.

## Características

- **Generación de Coeficientes:**  
  Se crean coeficientes aleatorios entre -10 y 10 para cada polinomio.
  
- **Generación de `x`:**  
  Se obtiene un valor aleatorio en el rango [-10, 10] (evitando el cero).
  
- **Medición del Rendimiento:**  
  La función `medirTiempo` utiliza `<chrono>` para obtener tiempos precisos, repitiendo la evaluación 1000 veces y sacando un promedio.
  
- **Registro de Resultados:**  
  Los tiempos de ejecución para cada grado se guardan en `resultados.csv` con la siguiente estructura:  
  `grado,tiempo_estandar_ns,tiempo_horner_ns`.

## Requisitos

- Compilador con soporte para C++17.
- Sistema operativo: Este código es multiplataforma (Linux, macOS o Windows).

## Compilación

Puedes compilar el proyecto utilizando un compilador como *g++*. Por ejemplo:

```bash
g++ -O2 -std=c++17 main.cpp -o polinomios_benchmark
