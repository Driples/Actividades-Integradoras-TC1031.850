
//Sergio Alfonso Casillas Santoyo - A01424863
//Eliuth Balderas Neri - A01703315
#include "Bitacora.h"

#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

Bitacora::Bitacora(){
  // Constructor
  row.resize(0);
}

Bitacora::~Bitacora(){
  // Destructor
  row.clear();
}

// Función encargada de poder desplegar y pedirle al usuario el rango de fechas los cuales se quieren encontrar

void Bitacora::lectura(const std::string &fileName) {
    std::string month, day, hour, minute, second,ip1,ip2,ip3,ip4, port, message;
    
    unsigned long long ipfin;

    std::ifstream inputFile(fileName);

    while (!inputFile.eof()) {
        getline(inputFile, month, ' ');
        getline(inputFile, day, ' ');
        getline(inputFile, hour, ':');
        getline(inputFile, minute, ':');
        getline(inputFile, second, ' ');
        getline(inputFile, ip1, '.');
        getline(inputFile, ip2, '.');
        getline(inputFile, ip3, '.');
        getline(inputFile, ip4, ':');
        getline(inputFile, port, ' ');
        getline(inputFile, message);
        ipfin = (stol(ip1))*1000000000L + (stoi(ip2))*1000000 + (stoi(ip3))*1000 + (stoi(ip4));
        Registro tmpReg(month, day, hour, minute, second,ip1,ip2,ip3, ip4, port, message, ipfin);
        row.push_back(tmpReg);
    }
    inputFile.close();
}

// Función encargada de poder desplegar y pedirle al usuario el rango de fechas los cuales se quieren encontrar

void Bitacora::merge(std::vector<Registro> &lista, long izquierda, long m, long derecha, long &compara){
  long i, j, k;
  long n1 = m - izquierda + 1;
  long n2 = derecha - m;
  std::vector<Registro> L(n1);
  std::vector<Registro> R(n2);

 
  for (i = 0; i < n1; i++)
    L[i] = lista[izquierda + i];
  for (j = 0; j < n2; j++)
    R[j] = lista[m + 1 + j];
  i = j = 0;
  k = izquierda;
  while (i < n1 && j < n2) {
     compara++;
    if (L[i].getFechas() < R[j].getFechas()) {
      lista[k] = L[i];
      i++;
    } else {
      lista[k] = R[j];
      j++;
    }
    k++;
  }
  // Se encargan de los elementos sobrantes
  while (i < n1) {
    lista[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    lista[k] = R[j];
    j++;
    k++;
  }
}



void Bitacora::mergeSort(std::vector<Registro> &lista, long izquierda, long derecha, long &compara){
  if (izquierda < derecha){
    long m = izquierda + (derecha - izquierda) / 2;
    mergeSort(lista, izquierda, m, compara);
    mergeSort(lista, m + 1, derecha, compara);
    merge(lista, izquierda, m, derecha, compara);
  }
}

void Bitacora::quickSort(std::vector<Registro> &A, long low, long high, long &compara, int &swap) {
  if (low < high) {
    long p = partition(A, low, high, compara, swap);
    quickSort(A, low, p - 1, compara, swap);
    quickSort(A, p + 1, high, compara, swap);
  }
}

long Bitacora::partition(std::vector<Registro> &A, long low, long high, long &compara, int &swap) {
  long pivot = A[high].getFechas();
  long i = low - 1;
  for (long j = low; j < high; j++) {
    compara++;
    if (A[j].getFechas() < pivot) {
      i++;
      std::swap(A[i], A[j]);
      swap++;
    }
  }
  std::swap(A[i + 1], A[high]);
  return i + 1;
}

// Función encargada de poder desplegar y pedirle al usuario el rango de fechas los cuales se quieren encontrar
void Bitacora::print(int s) {
    long comparaciones, l, r;
    comparaciones = 0;
    l = 0; 
    r = row.size()-1;
    int intercambios = 0;
    long indexI2 = 0, indexF2 = 0;

    if(s==0){ 
    mergeSort(row, l, r, comparaciones);
  }else{
    quickSort(row, l, r, comparaciones, intercambios);
  }
  

std::cout << "Hola bienvenido a la bitacora del tec" << std::endl << "Favor de poner que rango desea" <<  std::endl <<"con el siguiente formato (Jun 01 00:22:36):"<< std::endl << "Ingrese el inicio del rango de busqueda"<< std::endl;

    do{
    getline(std::cin, indexI);
    indexI2 = row[0].ayudaFechas(indexI+" ");
    indiceI = busquedaBinaria(row, indexI2);
    if (indiceI > -1){
      std::cout << "El dato esta en el indice: " << indiceI+1 << " ***" << std::endl;
      std::cout << "Favor de insertar la fecha final:"<< std::endl;
      std::getline(std::cin, indexF);
      indexF2 = row[10].ayudaFechas(indexF+" ");
      indiceF = busquedaBinaria(row, indexF2);
      if(indiceI < indiceF){
        std::cout << "El dato esta en el indice: " << indiceF+1 << " ***" << std::endl;
        std::cout << "El rango de busqueda es: " << std::endl;
        for(long i = indiceI; i <= indiceF; i++){
            std::cout << row[i].info() << std::endl;
        }
        std::cout << "El numero de comparaciones es: " << comparaciones << std::endl;
        
      }else{
        std::cout << "La fecha final es menor a la inicial, favor de insertar una fecha valida" << std::endl;
      }
    }else{
        std::cout << "!!! No esta registrado, intente otro!!!" << std::endl;
    }
} while(indiceI > indiceF || indiceI == indiceF);
}

void Bitacora::imprimiVector(std::vector<Registro> vec){
  for(int i=0; i<vec.size(); i++){
    std::cout << vec[i].info() << std::endl;
  }
}

long Bitacora::busquedaBinaria(std::vector<Registro> &lista, long dato){
  long inicio = 0;
  long fin = lista.size() - 1;
  long mitad = 0;
  while(inicio <= fin){
    mitad = (inicio + fin) / 2;
    if(lista[mitad].getFechas() == dato){
      return mitad;
    }else if(lista[mitad].getFechas() < dato){
      inicio = mitad + 1;
    }else{
      fin = mitad - 1;
    }
  }
  return -1;
}

void Bitacora::creaciondocumentoArreglado(std::string name){
  std::ofstream fhandle(name, std::ofstream::out);

  if(fhandle.is_open()){
    for(int i=0; i <= (int)row.size()-1; i++){
		  fhandle << row[i].info() << std::endl;
	  }
    fhandle.close();

  }

}


  








