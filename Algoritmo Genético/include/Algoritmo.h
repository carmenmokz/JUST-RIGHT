#ifndef ALGORITMO_H
#define ALGORITMO_H
#include <iostream>
#include <fstream>
#include <string>
#include <Problema.h>

using namespace std;

//Las variables suelen ser privadas
//Publico van las funciones
/*Virtual: la virtualizacion de funciones y clases nos permite
implementar una de las propiedades m�s potentes de POO: el Polimosfismo*/

class Algoritmo
{
    protected:
    private:
        bool politica; //Seleccion
        int numCruces; //cruce 1. 2 o m�s puntos
        double mutacion; //porcentaje de mutaci�n
        int tamPoblacion; //tama�o de la poblacion
    public:
        Algoritmo();
        virtual ~Algoritmo();
        void Problem(){}
        int resetPoblacion(){}
        string readPoblacion(){}
        string writePoblacion(){}
        void generacion(){}
        int getBest(){}
};

#endif // ALGORITMO_H
