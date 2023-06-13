//Sergio Alfonso Casillas Santoyo - A01424863
//Eliuth Balderas Neri - A01703315

#include "Registro.h"
#include <string>
#include <iostream>

Registro::Registro() {
  mes = "";
  dia = "";
  hora = "";
  minuto = "";
  segundo = "";
  ip1 = "";
  ip2 = "";
  ip3 = "";
  ip4 = "";
  puerto = "";
  mensaje = "";
  ipfinal = 0;
}

Registro::Registro(std::string mes, std::string dia, std::string hora, std::string min, std::string seg, std::string ip1, std::string ip2, std::string ip3, std::string ip4, std::string puerto, std::string msg, long ipfinal) {
  this->mes = mes;
  this->dia = dia;
  this->hora = hora;
  this->minuto = min;
  this->segundo = seg;
  this->ip1 = ip1;
  this->ip2 = ip2;
  this->ip3 = ip3;
  this->ip4 = ip4;
  this->puerto = puerto;
  this->mensaje = msg;
  this->ipfinal = ipfinal;
  
  crearFechas(seg, min, hora, dia, mes);

}

std::string Registro::info(){
    std::string info = mes + " " + dia + " " + hora + ":" + minuto + ":" + segundo + " " + ip1 + "." + ip2 + "." + ip3 + "." + ip4 + ":" + puerto + " " + mensaje;
    return info;
}

long Registro::getFechas(){ return stoi(std::to_string(date));}

long Registro::ayudaFechas(std::string f) {
    std::string texto = "", mes, dia, hora, minuto, semana;
bool mes1 = false, dia1 = false, hora1 = false, minuto1 = false, semana1 = false;
for (int i = 0; i <= f.length(); i++) {
if (f[i] == ' ' || f[i] == ':') {
if (!mes1) {
mes = texto;
texto = "";
mes1 = true;
} else if (!dia1) {
dia = texto;
texto = "";
dia1 = true;
} else if (!hora1) {
hora = texto;
texto = "";
hora1 = true;
} else if (!minuto1) {
minuto = texto;
texto = "";
minuto1 = true;
} else if (!semana1) {
semana = texto;
texto = "";
semana1 = true;
}
} else {
texto = texto + f[i];
}
}
return crearFechas(semana, minuto, hora, dia, mes);
}

long Registro::crearFechas(std::string semana, std::string minuto, std::string hora, std::string dia, std::string mes) {
dateStruct.tm_sec = stoi(semana);
dateStruct.tm_min = stoi(minuto);
dateStruct.tm_hour = stoi(hora);
dateStruct.tm_mday = stoi(dia);
dateStruct.tm_isdst = 0;

for (int i = 0; i < (int)meses.size(); i++) {
if (meses[i] == mes) {
dateStruct.tm_mon = i;
}
}
dateStruct.tm_year = 2025 - 1900;

return date = mktime(&dateStruct);
}




