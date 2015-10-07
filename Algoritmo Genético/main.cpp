#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    ifstream enarchivo;
            enarchivo.open("cromosoma.txt");
            int a,b,c,d;
            enarchivo >> a >> b >> c >> d;

            //ERROR SI EL ARCHIVO NO ESTÁ CREADO
            if (enarchivo.fail()){
                cerr<<"el archivo no fue encontrado \n";
                exit(1);
            }
            cout << a << " " << b << " " << c << " " << d;
            return 0;
}
