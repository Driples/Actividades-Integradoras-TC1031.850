//Sergio Alfonso Casillas Santoyo - A01424863
//Eliuth Balderas Neri - A01703315
#ifndef _REGISTRO_H_
#define _REGISTRO_H_


// transformar una fecha a numero decimal

#include <bits/stdc++.h>

class Registro
{
    private:
        std::string mes;
        std::string dia;
        std::string hora;
        std::string minuto;
        std::string segundo;
        std::string ip1;
        std::string ip2;
        std::string ip3;
        std::string ip4;
        std::string mensaje;
        std::string puerto;

       
       std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    public:
    struct tm dateStruct;
    time_t date;
    long ipfinal;
    std::string info();
    Registro();
    Registro(std::string mes, std::string dia, std::string hora, std::string minuto, std::string segundo, std::string ip1, std::string ip2, std::string ip3, std::string ip4, std::string mensaje, std::string puerto, long ipfinal);
    Registro(std::string m, std::string d, std::string h, std::string min, std::string s, unsigned long long i, std::string p, std::string men);
    long getFechas();
    long ayudaFechas(std::string F);
    long crearFechas(std::string mes, std::string dia, std::string hora, std::string minuto, std::string segundo);
    

    // Sobrecarga de operadores
    bool operator<(const Registro& r) const;
    bool operator>(const Registro& r) const;
    bool operator==(const Registro& r) const;
    bool operator!=(const Registro& r) const;
    bool operator<=(const Registro& r) const;
    bool operator>=(const Registro& r) const;
    friend std::ostream& operator<<(std::ostream& os, const Registro& r);
};

#endif



     