//Sergio Alfonso Casillas Santoyo - A01424863
//Eliuth Balderas Neri - A01703315
#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>

class Registro {
public:
    Registro(std::string fecha, std::string ip, std::string falla);
    std::string getFecha() const;
    std::string getIP() const;
    std::string getFalla() const;
    bool operator<(const Registro &other) const;
    bool operator<=(const Registro &other) const;
    bool operator==(const Registro &other) const;
    bool operator>=(const Registro &other) const;
    bool operator>(const Registro &other) const;

private:
    std::string fecha;
    std::string ip;
    std::string falla;
};

#endif // REGISTRO_H
