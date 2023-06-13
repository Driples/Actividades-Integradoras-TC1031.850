#ifndef GRAFO_H
#define GRAFO_H

#include <map>
#include <queue>
#include "GraphNode.h"
#include "HeapNode.h"

class Grafo {
private:
    std::map<std::string, GraphNode> nodos;
    std::priority_queue<HeapNode> heap;
public:
    void leerArchivo(std::string nombreArchivo);
    void calcularGrados(std::string nombreArchivo);
    void encontrarMayoresGrados(std::string nombreArchivo);
    void dijkstra(std::string bootmaster, std::string nombreArchivo);
    std::string bootMaster();
};

#endif
