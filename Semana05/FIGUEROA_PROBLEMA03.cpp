//Raul Martin Figueroa Teran

#include <iostream>
#include <cmath>

double sumaDeTresElevadoAN(int m) {
    double suma = 0.0;
    for (int n = 0; n <= m; ++n) {
        suma += std::pow(3, n);
    }
    return suma;
}

int mainFigueroa1() {
    int m;
    std::cout << "Introduzca un valor entero no negativo para m: ";
    std::cin >> m;
    std::cout << "La sumatoria de 3^n desde n=0 hasta n=" << m
              << " es " << sumaDeTresElevadoAN(m) << std::endl;
    return 0;
}
