#ifndef PROBLEMA_H
#define PROBLEMA_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class Problema
{
    protected:
    private:
    public:
        Problema();
        virtual ~Problema();
        //LEE UN PROBLEMA DE UN ARCHIVO
        virtual void readProblema()=0;
        //TAMAÑO DEL GEN
        virtual int geneSize()=0;
        //CALCULO DEL FITNESS
        virtual double fitness()=0;
        //HILERA QUE INDICA EL NOMBRE DEL PROBLEMA
        virtual void name()=0;
};

/*c_str() retorna un puntero a un arreglo que que contiene una secuencia de caracteres
que representa el valor actual del objeto string*/

class VertexCover: public Problema
{
    public:
        //MODIFICARLO CON GETLINE getline(cin, str, '') pide el dato en consola(nombre del archivo), variable donde se guarda, delimitador
        void readProblema(){
            string line;
            string archivo;
            cout << " Introduzca el nombre del archivo .txt \n";
            cin >> archivo;
            ifstream enarchivo;
            enarchivo.open(archivo.c_str(),ios::in);

            //ERROR SI EL ARCHIVO NO ESTÁ CREADO
            if (enarchivo.fail()){
                cerr<<"el archivo no fue encontrado \n";
                exit(1);
            }
            if(enarchivo.is_open()){
                while(getline(enarchivo,line)){
                    cout << line << endl;
                }
                enarchivo.close();
            }else{
                cout<<"No se puede abrir el archivo"<<endl;
            }
        }
            /*string archivo;
            cout << "\n Introduzca el nombre del archivo .txt \n";
            cin >> archivo;
            ifstream enarchivo;
            enarchivo.open(archivo.c_str(),ios::in);
            int a,b,c,d;
            enarchivo >> a >> b >> c >> d; //lineas en el txt

            //ERROR SI EL ARCHIVO NO ESTÁ CREADO
            if (enarchivo.fail()){
                cerr<<"\n El archivo no fue encontrado \n";
                exit(1);
            }
            cout << a << " " << b << " " << c << " " << d; //lee cada linea del txt
        }*/
};

class MinimunCover: public Problema
{
    //MODIFICARLO CON GETLINE getline(cin, str, '') pide el dato en consola, variable donde se guarda, delimitador
        void readProblema(){
                        string line;
            string archivo;
            cout << " Introduzca el nombre del archivo .txt \n";
            cin >> archivo;
            ifstream enarchivo;
            enarchivo.open(archivo.c_str(),ios::in);

            //ERROR SI EL ARCHIVO NO ESTÁ CREADO
            if (enarchivo.fail()){
                cerr<<"el archivo no fue encontrado \n";
                exit(1);
            }
            if(enarchivo.is_open()){
                while(getline(enarchivo,line)){
                    cout << line << endl;
                }
                enarchivo.close();
            }else{
                cout<<"No se puede abrir el archivo"<<endl;
            }
        }
            /*string archivo;
            cout << "\n Introduzca el nombre del archivo .txt \n";
            cin >> archivo;
            ifstream enarchivo;
            enarchivo.open(archivo.c_str(),ios::in);
            int a,b,c,d;
            enarchivo >> a >> b >> c >> d;

            //ERROR SI EL ARCHIVO NO ESTÁ CREADO
            if (enarchivo.fail()){
                cerr<<"\n El archivo no fue encontrado \n";
                exit(1);
            }
            cout << a << " " << b << " " << c << " " << d; //lee cada linea del txt
        }*/
};

#endif // PROBLEMA_H
