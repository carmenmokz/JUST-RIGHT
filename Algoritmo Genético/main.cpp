#include <iostream>
#include <fstream>
#include <string>
#include <Problema.h>

using namespace std;

int main()
{
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
