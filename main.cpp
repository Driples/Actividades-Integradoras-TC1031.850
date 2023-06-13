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

#include "log_parser.h"
#include <algorithm>
#include <iostream>

int main() {
  LogParser parser("bitacoraGrafos.txt");

  auto events = parser.parse();
  auto table = parser.createHashTable(events);

  std::cout << "Total de colisiones: " << table.getTotalCollisions()
            << std::endl;

  std::string ip;
  std::cout << "Introduzca una IP (Ejemplo de ip: 33.213.148.82) : ";
  std::getline(std::cin, ip);

  const auto &summary = table.get(ip);

  std::cout << "Total accedido: " << summary.total_accessed << std::endl;
  std::cout << "Total accedido desde: " << summary.total_accessed_from
            << std::endl;

  auto accessed_ips = summary.accessed_ips;
  std::sort(accessed_ips.begin(), accessed_ips.end(),
            std::greater<std::string>());

  for (const auto &accessed_ip : accessed_ips) {
    std::cout << "Accedido: " << accessed_ip << std::endl;
  }

  return 0;
}
