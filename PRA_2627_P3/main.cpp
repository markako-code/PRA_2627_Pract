#include <iostream>
#include <vector>
#include "PD.h"

int main() {
    std::cout << "=== PRACTICA 3: PROGRAMACION DINAMICA ===\n\n";

    // --- 1. PRUEBA CAMBIO DE MONEDAS ---
    std::vector<int> V = {1, 4, 6}; 
    int M_monedas = 8;              
    std::vector<int> solucion_monedas; 

    std::cout << "--- 1. Problema del Cambio de Monedas ---\n";
    std::cout << "Monedas disponibles: ";
    for (int m : V) std::cout << m << " ";
    std::cout << "\nCantidad a devolver: " << M_monedas << "\n";

    monedas(V, M_monedas, solucion_monedas);

    std::cout << "Solucion (cantidad de cada moneda):\n";
    for (size_t i = 0; i < V.size(); ++i) {
        std::cout << "- Monedas de " << V[i] << " u.v.: " << solucion_monedas[i] << "\n";
    }

    std::cout << "\n";

    // --- 2. PRUEBA PROBLEMA DE LA MOCHILA ---
    std::vector<int> p = {9, 6, 5};      
    std::vector<int> b = {38, 40, 24};   
    int M_mochila = 15;                  
    std::vector<int> solucion_mochila; 

    std::cout << "--- 2. Problema de la Mochila ---\n";
    std::cout << "Pesos: ";
    for (int peso : p) std::cout << peso << " ";
    std::cout << "\nBeneficios: ";
    for (int ben : b) std::cout << ben << " ";
    std::cout << "\nCapacidad maxima: " << M_mochila << "\n";


    int beneficio_maximo = mochila(p, b, M_mochila, solucion_mochila);

    std::cout << "Beneficio maximo obtenido: " << beneficio_maximo << "\n";
    std::cout << "Elementos elegidos (1 = si, 0 = no):\n";
    for (size_t i = 0; i < p.size(); ++i) {
        std::cout << "- Elemento " << i << " (Peso: " << p[i] << ", Beneficio: " << b[i] << "): " << solucion_mochila[i] << "\n";
    }

    return 0;
}
