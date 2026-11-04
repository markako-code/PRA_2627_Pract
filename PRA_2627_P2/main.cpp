#include <iostream>
#include <vector>
#include <chrono>
#include "DyV.h"

int main()
{
    
    std::vector<int> enteros = {8, 3, 1, 7, 0, 10, 2};
    std::cout << "Original: ";
    for (int x : enteros)
        std::cout << x << ' ';
        
    
    auto start_int = std::chrono::system_clock::now();
    if (!enteros.empty())
        quicksort(enteros, 0, static_cast<int>(enteros.size()) - 1);
    auto end_int = std::chrono::system_clock::now(); // Tiempo justo al terminar
    

    std::chrono::duration<float, std::milli> duration_int = end_int - start_int;

    std::cout << "\nOrdenado: ";
    for (int x : enteros)
        std::cout << x << ' ';
    std::cout << "\nTiempo QuickSort (int): " << duration_int.count() << " ms";
    
    int indiceInt = busquedaBinaria(7, enteros, 0, static_cast<int>(enteros.size()) - 1);
    std::cout << "\nBusqueda de 7: " << indiceInt << "\n\n";


   
    std::vector<float> reales = {3.5f, 1.2f, 8.7f, 2.4f, 5.1f};
    std::cout << "Original: ";
    for (float x : reales)
        std::cout << x << ' ';
        
    auto start_float = std::chrono::system_clock::now();
    if (!reales.empty())
        quicksort(reales, 0, static_cast<int>(reales.size()) - 1);
    auto end_float = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration_float = end_float - start_float;

    std::cout << "\nOrdenado: ";
    for (float x : reales)
        std::cout << x << ' ';
    std::cout << "\nTiempo QuickSort (float): " << duration_float.count() << " ms";
        
    int indiceFloat = busquedaBinaria(2.4f, reales, 0, static_cast<int>(reales.size()) - 1);
    std::cout << "\nBusqueda de 2.4: " << indiceFloat << "\n\n";


    
    std::vector<char> caracteres = {'d', 'a', 'z', 'c', 'b'};
    std::cout << "Original: ";
    for (char x : caracteres)
        std::cout << x << ' ';
        
    auto start_char = std::chrono::system_clock::now();
    if (!caracteres.empty())
        quicksort(caracteres, 0, static_cast<int>(caracteres.size()) - 1);
    auto end_char = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration_char = end_char - start_char;

    std::cout << "\nOrdenado: ";
    for (char x : caracteres)
        std::cout << x << ' ';
    std::cout << "\nTiempo QuickSort (char): " << duration_char.count() << " ms";
        
    int indiceChar = busquedaBinaria('c', caracteres, 0, static_cast<int>(caracteres.size()) - 1);
    std::cout << "\nBusqueda de 'c': " << indiceChar << '\n';

    return 0;
}
