#ifndef ALGORITMO_H
#define ALGORITMO_H
#include <iostream>

using namespace std;

//Las variables suelen ser privadas
//Publico van las funciones
/*Virtual: la virtualizacion de funciones y clases nos permite
implementar una de las propiedades más potentes de POO: el Polimosfismo*/

class Algoritmo
{
    protected:
    private:
        bool politica;
        int numCruces;
        double mutacion;
        int tamPoblacion;
    public:
        Algoritmo();
        virtual ~Algoritmo();
};

#endif // ALGORITMO_H
