#ifndef ARREGLO_H_INCLUDED
#define ARREGLO_H_INCLUDED
#include <iostream>

using namespace std;

template <class T>
class Arreglo{
private:
    T *arreglo;
    size_t tam;
    size_t cont;
    const static size_t MAX = 10;
    void expandir();
public:
    Arreglo();
    ~Arreglo();

    void insertar(const T& s, size_t p);
    void insertarInicio(const T& s);
    void insertarFinal(const T& s);

    void mostrar();

    void eliminar(size_t p);
    void eliminarFinal();
    void eliminarInicio();

    T* buscar(const T& s);//recibe string
    Arreglo<T*> buscarTodos(const T& s);

    size_t size();
    T operator[](size_t p){
        return arreglo[p];
    }

    friend Arreglo<T>& operator<<(Arreglo<T> &a, const T& s)
    {
        a.insertarFinal(s);
        return a;
    }
};


template <class T>
Arreglo<T>::Arreglo()
{
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}

template <class T>
Arreglo<T>::~Arreglo()
{
    delete[] arreglo;
}

template <class T>
void Arreglo<T>::insertar(const T& s, size_t p)
{
    if(p >= cont){
        cout << "Posicion invalida" << endl;
    }
    if(cont == tam){
        expandir();
    }
    for(size_t i = cont; i > p; i--){
        arreglo[i] = arreglo[i - 1];
    }
    arreglo[p] = s;
    cont++;

}

template <class T>
void Arreglo<T>::insertarInicio(const T& s)
{
    if(cont == tam){
        expandir();
    }
    for(size_t i = cont; i > 0; i--){
        arreglo[i] = arreglo[i - 1];
    }
    arreglo[0] = s;
    cont++;

}

template <class T>
void Arreglo<T>::insertarFinal(const T& s)
{
    if(cont == tam){
        expandir();
    }
    arreglo[cont] = s;
    cont++;
}

template <class T>
void Arreglo<T>::eliminar(size_t p){
    if(cont == 0){
        cout << "El arreglo esta vacio. " << endl;
    }
    for(size_t i = p; i < cont - 1; i++){
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}


template <class T>
void Arreglo<T>::eliminarInicio()
{
    if(cont == 0){
        cout << "El arreglo esta vacio. " << endl;
        return;
    }
    for(size_t i = 0; i < cont - 1; i++){
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}


template <class T>
void Arreglo<T>::eliminarFinal()
{
    if(cont == 0){
        cout << "El arreglo esta vacio. " << endl;
        return;
    }
    cont--;
}

template <class T>
void Arreglo<T>::mostrar()
{
    cout << endl;
    for(size_t i = 0; i < cont; i++){
        cout << arreglo[i] << ", ";
    }
}

template <class T>
T* Arreglo<T>::buscar(const T& s)
{
    for(size_t i = 0; i < cont; i++){
        if(s == arreglo[i]){
            return &arreglo[i];
        }
    }
    return nullptr;
}

template <class T>
Arreglo<T*> Arreglo<T>::buscarTodos(const T& s)
{
    Arreglo<T*> punteros;//arreglo de punteros
    for(size_t i = 0; i < cont; i++){
        if(s == arreglo[i]){
            punteros.insertarFinal(&arreglo[i]);
        }
    }
    return punteros;
}

template <class T>
size_t Arreglo<T>::size()
{
    return cont;
}

template <class T>
void Arreglo<T>::expandir()
{
    T *nuevo = new T[tam+MAX];
    for(size_t i = 0; i < cont; i++){
        nuevo[i] = arreglo[i + 1];
    }
    delete[] arreglo;
    arreglo = nuevo;
    tam = tam+MAX;

}

#endif