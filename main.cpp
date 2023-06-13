/**
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


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include "ip_counter.h"
#include "heap.h"

int main() {
    std::ifstream inputFile("bitacoraHeap.txt");
    std::string line;
    std::regex ipRegex(R"(\b\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\b)");
    std::smatch match;
    IPCounter ipCounter;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            if (std::regex_search(line, match, ipRegex)) {
                std::string ip = match.str();
                ipCounter.addIP(ip);
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Error al abrir el archivo bitacoraHeap.txt" << std::endl;
        return 1;
    }

    Heap<IPCounter::IPData> heap;
    for (const auto& ipData : ipCounter.getIPData()) {
        heap.insert(ipData);
    }

    std::vector<IPCounter::IPData> topIPs;
    for (int i = 0; i < 5 && !heap.isEmpty(); ++i) {
        topIPs.push_back(heap.extractMax());
    }

    std::ofstream outputFile("ips_con_mas_acceso.txt");
    outputFile << "Top 5 IP's mas usadas:" << std::endl;

    for (const auto& ipData : topIPs) {
        outputFile << "(" << ipData.ip << " - " << ipData.count << ")" << std::endl;
        std::cout << "(" << ipData.ip << " - " << ipData.count << ")" << std::endl;
    }

    outputFile.close();

    return 0;
}

