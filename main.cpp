#include <iostream>
#include "arreglo.h"
#include "computadora.h"

using namespace std;

int main()
{
    Arreglo<Computadora> computadora;

    Computadora pc1("Dafne", "Windows", 12, 256);
    Computadora pc2("Jaqueline", "Linux", 8, 128);
    Computadora pc3("Crespo", "iOs", 12, 128);
    computadora << pc1 << pc2 << pc3 << pc2 << pc2; 
    for(size_t i = 0; i < computadora.size(); i++)
    {
        cout << computadora[i];
    }
    Computadora pc4("Lupe", "iOs", 12, 128);

    Arreglo<Computadora*> punteros = computadora.buscarTodos(pc2);
    if(punteros.size() > 0){
        cout << endl <<"Encontrado por metodo Buscar Todos:" << endl;
        for(size_t i = 0; i < punteros.size(); i++){
            Computadora *c = punteros[i];
            cout << *c << endl;
            
        }
    }
    else{
        cout <<endl << "No existen coincidencias."<<endl<<endl;
    }

    /*
    Computadora *c = computadora.buscar(pc1);
    
    if(*c == computadora[1]){
        cout << endl <<"Encontrado por metodo buscar: "<<endl<< *c << "Espacio en memoria: " << c << endl << endl;
    }
    else{
        cout <<endl << "No existen coincidencias."<<endl<<endl;
    }*/
    


    /*
    Arreglo<string> arreglo;

    arreglo.insertarFinal("amor");
    arreglo.insertarFinal("salud");
    arreglo.insertarInicio("esperanza");
    arreglo.insertarInicio("fe");

    arreglo.mostrar();

    arreglo.insertar("carinio", 2);

    arreglo.mostrar();

    arreglo.eliminarInicio();
    arreglo.eliminarFinal();

    arreglo.eliminar(1);

    arreglo.mostrar();
*/
    return 0;
}
