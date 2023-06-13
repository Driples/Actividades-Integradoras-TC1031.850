#include "Grafo.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <utility>

using namespace std;

// Lectura del archivo de entrada y llenado del grafo y del heap
void Grafo::leerArchivo(string nombreArchivo){
    ifstream archivo(nombreArchivo);
    int n, m;
    string ip;

    if(archivo.is_open()){
        archivo >> n >> m;

        for(int i = 0; i < n; i++){
            archivo >> ip;
            GraphNode nodo;
            nodo.ip = ip;
            nodos[ip] = nodo;
        }

        string mes, dia, hora, ipOrigen, ipDestino, razon;
        int peso;
        for(int i = 0; i < m; i++){
            archivo >> mes >> dia >> hora >> ipOrigen >> ipDestino >> peso;
            getline(archivo, razon); // lectura del resto de la línea para la razón

            size_t pos = ipOrigen.find(':');
            ipOrigen = ipOrigen.substr(0, pos);
            pos = ipDestino.find(':');
            ipDestino = ipDestino.substr(0, pos);

            nodos[ipOrigen].adj[ipDestino] = peso;

            HeapNode nodoHeap;
            nodoHeap.ip = ipOrigen;
            nodoHeap.grado = nodos[ipOrigen].adj.size();

            heap.push(nodoHeap);
        }

        archivo.close();
    }
}

// Calcular y escribir el grado de salida de cada nodo
void Grafo::calcularGrados(string nombreArchivo){
    ofstream archivo(nombreArchivo);

    if(archivo.is_open()){
        for(auto& nodo : nodos){
            archivo << nodo.first << " " << nodo.second.adj.size() << "\n";
        }

        archivo.close();
    }
}

// Encontrar y escribir las 5 IPs con mayor grado de salida
void Grafo::encontrarMayoresGrados(string nombreArchivo){
    ofstream archivo(nombreArchivo);

    if(archivo.is_open()){
        for(int i = 0; i < 5; i++){
            if(!heap.empty()){
                HeapNode nodo = heap.top();
                archivo << nodo.ip << " " << nodo.grado << "\n";
                heap.pop();
            }
        }

        archivo.close();
    }
}

string Grafo::bootMaster() {
    if(!heap.empty()){
        return heap.top().ip;
    }
    return "";
}

// Implementar el algoritmo de Dijkstra y escribir los resultados
void Grafo::dijkstra(string bootmaster, string nombreArchivo){
    map<string, int> distancias; // IP, distancia
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq; // min heap

    for(auto& nodo : nodos){
        distancias[nodo.first] = numeric_limits<int>::max();
    }

    distancias[bootmaster] = 0;
    pq.push(make_pair(0, bootmaster));

    while(!pq.empty()){
        string u = pq.top().second;
        pq.pop();

        for(auto& vecino : nodos[u].adj){
            string v = vecino.first;
            int peso = vecino.second;

            if(distancias[u] + peso < distancias[v]){
                distancias[v] = distancias[u] + peso;
                pq.push(make_pair(distancias[v], v));
            }
        }
    }

    // Escribir las distancias en el archivo
    ofstream archivo(nombreArchivo);

    if(archivo.is_open()){
        for(auto& distancia : distancias){
            archivo << distancia.first << " " << distancia.second << "\n";
        }

        archivo.close();
    }
}
