#include "computadora.h"

Computadora::Computadora(){

}

Computadora::Computadora(const string &nombreEquipo, const string &sistemaOperativo, int memoriaRam, int capacidad){
    this -> nombreEquipo = nombreEquipo;
    this -> sistemaOperativo = sistemaOperativo;
    this -> memoriaRam = memoriaRam;
    this -> capacidad = capacidad;
}
void Computadora::setNombre(const string &n){
    nombreEquipo = n;
}
void Computadora::setSistema(const string &s){
    sistemaOperativo = s;
}
void Computadora::setMemoria(int m){
    memoriaRam = m;
}
void Computadora::setCapacidad(int c){
    capacidad = c;
}


string Computadora::getNombre(){
    return nombreEquipo;
}
string Computadora::getSistema(){
    return sistemaOperativo;
}
int Computadora::getMemoria(){
    return memoriaRam;
}
int Computadora::getCapacidad(){
    return capacidad;
}