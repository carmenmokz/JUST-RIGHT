#ifndef PROBLEMA_H
#define PROBLEMA_H
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Problema
{
    protected:
    private:
    public:
        Problema();
        virtual ~Problema();
        virtual void readProblema()=0;
        virtual int geneSize()=0;
        virtual double fitness()=0;
        virtual void name()=0;
};

class VertexCover: public Problema
{
    public:
        //MODIFICARLO CON GETLINE getline(cin, str, '') pide el dato en consola, variable donde se guarda, delimitador
        void readProblema(){
            ifstream enarchivo;
            enarchivo.open("cromosoma.txt");
            int a,b,c,d;
            enarchivo >> a >> b >> c >> d;

            //ERROR SI EL ARCHIVO NO ESTÁ CREADO
            if (enarchivo.fail()){
                cerr<<"el archivo no fue encontrado \n";
                exit(1);
            }
            cout << a << " " << b << " " << c << " " << d; //lee cada linea del txt
            return 0;
        }
};

#endif // PROBLEMA_H
