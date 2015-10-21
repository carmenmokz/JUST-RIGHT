#ifndef ALIST_H_INCLUDED
#define ALIST_H_INCLUDED

#define DEFAULT_MAX_SIZE 1024
#include <stdexcept>
#include <iostream>

// Este código fue tomado de lo visto en clase sobre listas en forma de arreglos.

using namespace std;

template <typename E>
class ArrayList{
private:
    E *elements;
    int pos;
    int max;
    int size;

public:
    ArrayList(int pMax = DEFAULT_MAX_SIZE){
        elements = new E[pMax];
        max = pMax;
        size = 0;
        pos = 0;
    }

    ~ArrayList(){
        delete [] elements;
    }

    void insert(E pElement){
        if(size == max){
            throw runtime_error("Lista llena.");
        }
        for(int i = size; i>pos; i--){
            elements[i] = elements[i-1];
        }
        elements[pos] = pElement;
        size++;
    }

    void append(E pElement) throw(runtime_error){
        if(size == max){
            throw runtime_error("Lista llena.");
        }
        elements[size] = pElement;
        size++;
    }

    E remove() throw(runtime_error){
        if(size == 0){
            throw runtime_error("Lista vacía.");
        }
        if(pos == size){
            throw runtime_error("No hay elemento actual.");
        }
        E res = elements[pos];
        for(int i = pos; i < (size-1); i++){
            elements[i] = elements[i+1];
        }
        size--;
        return res;
    }

    void clear(){
        size = 0;
        pos = 0;
        delete [] elements;
        elements = new E[max];
    }

    E getElement() throw(runtime_error){
        if(pos == size){
            throw runtime_error("No hay elemento actual.");
        }
        return elements[pos];
    }

    void goToStart(){
        pos = 0;
    }

    void goToEnd(){
        pos = size;
    }

    void goToPos(int pPos) throw(runtime_error){
        if(pos < 0 || pos > size){
            throw runtime_error("Posición inválida.");
        }
        pos = pPos;
    }

    void previous(){
        if(pos > 0){
            pos--;
        }
    }

    void next(){
        if(pos < size){
            pos++;
        }
    }

    int getPos(){
        return pos;
    }

    int getSize(){
        return size;
    }

    void print(){
        int tempC = 0;
        while(tempC != size){
            if(tempC == pos){
                cout << " | ";
            }
            cout << elements[tempC];
            if(tempC + 1 != size){
                cout << " - ";
            }
            tempC += 1;
        }
        if(tempC == size && pos == size){
            cout << " |";
            }
        cout << endl;

        if(size == 0){
            cout << "La lista esta vacia." << endl;
        }
    }

    void reverse(){
        // Se crea una lista temporal en la que se irán guardando los elementos de la lista en reversa.
        ArrayList<E> tempList;
        int cont = size-1;
        int cont2 = 0;
        // Utilizando un contador, se va decrementando hasta que este sea menor a cero.
        // Cuando sea negativo, se han copiado todos los elementos a la lista temporal.
        while(cont >= 0){
            tempList.elements[cont2] = elements[cont];
            tempList.size++;
            cont--;
            cont2++;
        }
        // Este ciclo lo que hace es reemplazar los elementos de la lista original
        // con los de la temporal para que ahora esté en reversa.
        cont = 0;
        while(cont < size){
            elements[cont] = tempList.elements[cont];
            cont++;
        }
        // Se limpia la lista temporal.
        tempList.clear();
    }
};

#endif // ALIST_H_INCLUDED
