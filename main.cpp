//actvidad Act-Integradora-2 Estructuras de Datos Lineales
//Hecho por:
//Sergio Alfonso Casillas Santoyo - A01424863
//Eliuth Balderas Neri - A01703315
//Fecha: 18/04/2023
//compilacion para debug:
//g++ -std=c++17 -g -o main *.cpp
//ejecucion con valgrind (en caso de errores):
//nix-env -iA nixpkgs.valgrind
//valgrind --leak-check=full ./main
//compilacion para ejecucion:
//g++ -std=c++17 -O3 -o main *.cpp
//ejecucion:
//./main


#include <iostream>
#include "doubly_linked_list.h"

int main() {
    DoublyLinkedList dll;
    dll.loadFromFile("bitacora.txt");
    dll.sort();

    std::string start, end;
    std::cout << "Introduzca la fecha de inicio en formato MMM dd hh:mm:ss: ";
    std::getline(std::cin, start);
    std::cout << "Introduzca la fecha de fin en formato MMM dd hh:mm:ss: ";
    std::getline(std::cin, end);

    dll.searchAndSave(start, end, "resultado_busqueda.txt");
    dll.saveToFile("bitacora_ordenada.txt");

    return 0;
}
