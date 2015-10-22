#ifndef PROBLEMA_H
#define PROBLEMA_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "graph.h"


using namespace std;

class Problema
{
    protected:
    private:
    public:
        Problema();
        //LEE UN PROBLEMA DE UN ARCHIVO
        virtual void readProblema()=0;
        //TAMAÑO DEL GEN
        virtual int geneSize()=0;
        //CALCULO DEL FITNESS
        virtual double fitness()=0;
        //HILERA QUE INDICA EL NOMBRE DEL PROBLEMA
        virtual void name()=0;
        virtual void createFile()=0;
};

/*c_str() retorna un puntero a un arreglo que que contiene una secuencia de caracteres
que representa el valor actual del objeto string*/

class VertexCover: public Problema
{
    private:
        string *paramsData= new string[5];
        string problemType;
        int N; //cantVertices
        int M; //cantAristas
        int K; //tamaño del recubrimiento deseado
        int num = 1;
        string archivo = "archivo";
        string txt = ".txt";
        string myFile;

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
        void readData(){
            string line;
            string archivo;
            cin >> archivo;
            ifstream enarchivo;
            enarchivo.open(archivo.c_str(),ios::in);
            //ERROR SI EL ARCHIVO NO ESTÁ CREADO
            if (enarchivo.fail()){
                cerr<<"el archivo no fue encontrado \n";
                exit(1);
            }else{
                if(enarchivo.is_open()){
                    int i=0;
                    while(getline(enarchivo,line)){
                        paramsData[i]=line;
                        i++;
                    }

                    enarchivo.close();

                }else{
                    cout<<"No se puede abrir el archivo"<<endl;
                }
            }

        }
        void assingData(){
            problemType= paramsData[0];
            for (int i=0; i!=paramsData[2]; i++){

            }
            N=atoi((paramsData[1]).c_str()); //cantVertices
            M=atoi((paramsData[2]).c_str()); //cantAristas
            K=atoi((paramsData[3]).c_str());
        //falta el 5to param!!
        }
        int geneSize(){}
        double fitness(){}
        void name(){}

        void createFile(){
            //CREAR ARCHIVO TXT
            FILE *pf;
            myFile += archivo;
            myFile += num + '0';
            myFile += txt;

            pf = fopen(myFile.c_str(),"w"); //w archivo solo para escritura / r solo para lectura

            if(pf != NULL){
                printf("el archivo se creo correctamente \n");
                 //ESCRIBIR EN ARCHIVO
                ofstream fout(myFile.c_str()); //VARIABLE TIPO OFSTREAM
                fout << "HOLA WORLD :V" << endl;
                num++;
                myFile = " ";
            }else{
                puts("no se pudo crear");
            }
        }

//        void createGraph(int u){
//            Grafo *graph = new Grafo(u);
//            int total;
//            total++;                                //aumento en mi respuesta la caida de un domino
//            bool visitado;
//            visitado[u] = true;                   //domino "u" cayo
//            for( int v = 0 ; v < graph[ u ].size(); ++v ){ //verifico los demas posibles domino que caeran si impulso "u"
//                    if( !visitado[ graph[ u ][ v ] ] ){         //si el domino adyacente no cayó entonces es el siguiente a evaluar
//                        createGraph( graph[ u ][ v ] );               //recursivamente veo que dominos caeran a partir del adyacente de "u"
//                        }
//            }
//        }


};

class MinimunCover: public Problema
{
    //MODIFICARLO CON GETLINE getline(cin, str, '') pide el dato en consola, variable donde se guarda, delimitador
    private:
        string *paramsData= new string[4];
        string paramsDataLists [1024][1024];
        string problemType;
        int N; //tamaño del conjunto S
        int M; //cantSubconjuntos de S que se encuentran en C
        int K; //tamaño del recubrimiento deseado

    public:
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
            else if(enarchivo.is_open()){
                    int i=0;
                    while(getline(enarchivo,line)){
                        if (i!=4){
                            paramsData[i]=line;
                            i++;
                        }else{


                        }
                    }
                    enarchivo.close();
                }else{
                    cout<<"No se puede abrir el archivo"<<endl;
                }
        }
        void assingData(){
            problemType= paramsData[0];
            N=atoi((paramsData[1].c_str())); //cantVertices
            M=atoi((paramsData[2].c_str())); //cantAristas
            K=atoi((paramsData[3].c_str()));
        //falta el 5to param!!
        }

        //TAMAÑO DEL GEN
        int geneSize(){}
        //CALCULO DEL FITNESS
        double fitness(){}
        //HILERA QUE INDICA EL NOMBRE DEL PROBLEMA
        void name(){}
        void createFile(){}
};

#endif // PROBLEMA_H
