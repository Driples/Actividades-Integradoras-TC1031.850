/**
 * Ejemplo que implementa un stack usando listas ligadas
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -Wall -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -Wall -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 **/
// Sergio Alfonso Casillas Santoyo - A01424863
// Eliuth Balderas Neri - A01703315

#include "Grafo.h"
#include <iostream>

int main() {
  Grafo grafo;
  grafo.leerArchivo("bitacoraGrafos.txt");
  grafo.calcularGrados("grados_ips.txt");
  grafo.encontrarMayoresGrados("mayores_grados_ips.txt");

  std::string bootmaster = grafo.bootMaster();
  std::cout << "El boot master se encuentra en la IP: " << bootmaster << "\n";

  grafo.dijkstra(bootmaster, "distancia_bootmaster.txt");

  return 0;
}
