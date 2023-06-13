//actvidad Act-Integradora-1 Conceptos básicos y algoritmos fundamentales
//Hecho por:
//Sergio Alfonso Casillas Santoyo - A01424863
//Eliuth Balderas Neri - A01703315
//Fecha: 28/03/2023
//Con la ayuda del codigo del profesor Eduardo Arturo Rodríguez Tello y el apoyo de nuesto compañero de semestre mas adelenates Cesar que nos explico 
//compilacion para debug:
//g++ -std=c++17 -g -o main *.cpp
//ejecucion con valgrind (en caso de errores):
//nix-env -iA nixpkgs.valgrind
//valgrind --leak-check=full ./main
//compilacion para ejecucion:
//g++ -std=c++17 -O3 -o main *.cpp
//ejecucion:
//./main
// Probar en replit tambien



#include "Bitacora.h"

int main() {
  std::string fileName = "bitacora.txt";
  Bitacora bitacora;
  bitacora.lectura(fileName);
  bitacora.print(0);
  bitacora.creaciondocumentoArreglado("datos_ordenados.txt");

  return 0;
}
