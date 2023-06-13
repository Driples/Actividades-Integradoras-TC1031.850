//Sergio Alfonso Casillas Santoyo - A01424863
//Eliuth Balderas Neri - A01703315
#ifndef BITACORA_H
#define BITACORA_H

#include "Registro.h"

#include <iostream>
#include <vector>
#include <string>

class Bitacora {
private:
    // vector de objetos Registro (cada celda es un renglon de bitacora.txt)
    std::vector<Registro> row;
    int indiceI{}, indiceF{};
    std::string indexI,indexF;
    long partition(std::vector<Registro> &values, long low, long high, long &compara, int &swap);

public:
    Bitacora();
    ~Bitacora();
    void lectura(const std::string& fileName);

    // ordenamiento y búsqueda
    void merge(std::vector<Registro> &lista, long l, long m, long r, long &compara);
    void mergeSort(std::vector<Registro> &lista, long l, long r, long &compara);
    long busquedaBinaria(std::vector<Registro> &lista, long ipb);
    void quickSort(std::vector<Registro> &values, long low, long high, long &compara, int &swap);
    void print(int s);
    void imprimiVector(std::vector<Registro> vec);
    void creaciondocumentoArreglado(std::string name);


};

#endif //BITACORA_H

/*
class Bitacora {
private:
    std::vector<Registro> row;
    int indiceI{}, indiceF{};
    std::string indexI,indexF;
    long partition(std::vector<Registro> &values, long low, long high, long &compara, int &swap);
    std::string fecha;
    std::string getFecha() const { return fecha; };
    void setFecha(std::string fecha) { this->fecha = fecha; };
    unsigned long long ip;
    std::vector<Registro> regisros;

public:
    Bitacora();
    Bitacora();
    void lectura(const std::string& fileName);
    void merge(std::vector<Registro> &lista, long l, long m, long r, long &compara);
    void mergeSort(std::vector<Registro> &lista, long l, long r, long &compara);
    long busquedaBinaria(std::vector<Registro> &lista, long ipb);
    void quickSort(std::vector<Registro> &values, long low, long high, long &compara, int &swap);
    void print(int s);
    void imprimiVector(std::vector<Registro> vec );
    void creaciondocumentoArreglado(std::string name);
    void Ordenar();
    void Busqueda(const std::string &fecha1, const std::string &fecha2);
    void escritura(const std::string& fileName);
    std::string fecha;
    std::string getFecha() const { return fecha; };
    void setFecha(std::string fecha) { this->fecha = fecha; };
    unsigned long long ip;
    unsigned long long getIp() const { return ip; };
    void setIp(unsigned long long ip) { this->ip = ip; };
    void leerArchivo(std::string nombreArchivo);
    void escribirArchivo(std::string nombreArchivo);
    void ordenarIneficiente();
    void ordenarEficiente();
    std::vector<Registro> buscarPorFechas(std::string fechaInicio, std::string fechaFin);



};

*/