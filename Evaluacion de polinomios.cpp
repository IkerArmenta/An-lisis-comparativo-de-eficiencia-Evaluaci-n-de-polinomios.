#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <functional>

double evalStandard(const std::vector<int>& coeffs, double x) {
    double result = 0.0;
    for (size_t i = 0; i < coeffs.size(); ++i) {
        result += coeffs[i] * std::pow(x, i);
    }
    return result;
}

double evalHorner(const std::vector<int>& coeffs, double x) {
    double result = coeffs.back();
    for (int i = coeffs.size() - 2; i >= 0; --i) {
        result = result * x + coeffs[i];
    }
    return result;
}

std::vector<int> generarCoeficientes(int grado) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-10, 10);
    std::vector<int> coef(grado + 1);
    for (int& c : coef) c = dis(gen);
    return coef;
}

double generarX() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10, 10);
    double x;
    do {
        x = dis(gen);
    } while (x == 0.0);
    return x;
}

long long medirTiempo(std::function<double(const std::vector<int>&, double)> metodo,
                      const std::vector<int>& coef, double x, int repeticiones) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < repeticiones; ++i) {
        metodo(coef, x);
    }
    auto end = high_resolution_clock::now();
    return duration_cast<nanoseconds>(end - start).count() / repeticiones;
}

int main() {
    std::ofstream archivo("resultados.csv");
    archivo << "grado,tiempo_estandar_ns,tiempo_horner_ns\n";
    
    const int repeticiones = 1000;

    for (int grado = 10; grado <= 1000; grado += 10) {
        auto coef = generarCoeficientes(grado);
        double x = generarX();

        auto tiempo_estandar = medirTiempo(evalStandard, coef, x, repeticiones);
        auto tiempo_horner = medirTiempo(evalHorner, coef, x, repeticiones);

        std::cout << "Grado: " << grado
                  << ", Est: " << tiempo_estandar << "ns"
                  << ", Horner: " << tiempo_horner << "ns" << std::endl;

        archivo << grado << "," << tiempo_estandar << "," << tiempo_horner << "\n";
    }

    archivo.close();
    return 0;
}
