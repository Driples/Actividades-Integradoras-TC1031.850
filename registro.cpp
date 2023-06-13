//Sergio Alfonso Casillas Santoyo - A01424863
//Eliuth Balderas Neri - A01703315
#include "registro.h"

Registro::Registro(std::string fecha, std::string ip, std::string falla) : fecha(fecha), ip(ip), falla(falla) {}

std::string Registro::getFecha() const {
    return fecha;
}

std::string Registro::getIP() const {
    return ip;
}

std::string Registro::getFalla() const {
    return falla;
}

bool Registro::operator<(const Registro &other) const {
    return fecha < other.fecha;
}

bool Registro::operator<=(const Registro &other) const {
    return fecha <= other.fecha;
}

bool Registro::operator==(const Registro &other) const {
    return fecha == other.fecha;
}

bool Registro::operator>=(const Registro &other) const {
    return fecha >= other.fecha;
}

bool Registro::operator>(const Registro &other) const {
    return fecha > other.fecha;
}

