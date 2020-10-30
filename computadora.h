#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Computadora{
private:
    string nombreEquipo;
    string sistemaOperativo;
    int memoriaRam;
    int capacidad;
public:
    Computadora();
    Computadora(const string &nombreEquipo, const string &sistemaOperativo, int memoriaRam, int capacidad);

    void setNombre(const string &n);
    void setSistema(const string &s);
    void setMemoria(int m);
    void setCapacidad(int c);

    string getNombre();
    string getSistema();
    int getMemoria();
    int getCapacidad();

    friend ostream& operator<<(ostream &out, const Computadora &c)
    {
        out << left;
        out << setw(17) << c.nombreEquipo;
        out << setw(20) << c.sistemaOperativo;
        out << setw(15) << c.memoriaRam;
        out << setw(8) << c.capacidad;
        out << endl;

        return out;
    }

    friend istream& operator>>(istream &in, Computadora &c)
    {
        cout << "Nombre Equipo: ";
        getline(cin, c.nombreEquipo);
        cout << "Sistema Operativo: ";
        getline(cin, c.sistemaOperativo);
        cout << "Memorio RAM: ";
        cin >> c.memoriaRam;
        cout << "Capacidad: ";
        cin >> c.capacidad;

        return in;

    }

    bool operator==(const Computadora& c)
    {
        return nombreEquipo == c.nombreEquipo;
    }
    bool operator==(const Computadora& c) const
    {
        return nombreEquipo == c.nombreEquipo;
    }


};

#endif