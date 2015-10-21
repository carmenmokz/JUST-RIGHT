#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define INF 999
#define INT_MAX 12832920

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "AList.h"

using namespace std;

// Aquí se incluyen todas clases necesarias para el funcionamiento del grafo.

// La clase vértice maneja solamente un entero como identificador y un puntero al vértice siguiente.
class Vertice{
public:
    int dest;
    Vertice* next;
};

// La clase arista maneja solamente un identificador del nodo fuente y un identificador del nodo destino.
class Arista{
public:
    int fuente;
    int destino;

    // Constructor para inicializar datos deseados.
    Arista(int fuente, int destino){
        this->fuente = fuente;
        this->destino = destino;
    }

    // Constructor con datos que nunca serán reales, por lo que son válidos para comparar.
    Arista(){
        fuente = -1;
        destino = -1;
    }

    // Método de prueba para verificar el contenido de una arista.
    void print(){
        cout << "FUENTE: " << fuente << endl;
        cout << "DESTINO: " << destino << endl;
        cout << endl;
    }
};

// La clase para lista de adyacencia. Maneja solamente la cabeza o inicio de la lista.
class ListaAdyacencia{
public:
    Vertice *head;
};

// La clase que maneja propiamente los grafos y todas sus funcionalidades. Maneja la cantidad de nodos y la lista de adyacencia general.
class Grafo{
private:
    int size;
    ListaAdyacencia* listaAdyacencia;

public:

    // Constructor que crea un grafo con la cantidad de nodos deseada.
    Grafo(int size){
        this->size = size;
        listaAdyacencia = new ListaAdyacencia[size];
        for(int i = 0; i < size; i++){
            listaAdyacencia[i].head = NULL;
        }
    }

    // Método para crear un nuevo nodo o vértice con el identificador del nodo conectado a él.
    Vertice* crearNodo(int dest){
        Vertice* nuevoNodo = new Vertice();
        nuevoNodo->dest = dest;
        nuevoNodo->next = NULL;
        return nuevoNodo;
    }

    // Método para agregar aristas nuevas al grafo. Es decir, recibe el ID del nodo fuente y el destino & los conecta.
    void agregarArista(int fuente, int destino){
        Vertice* nuevoNodo = crearNodo(destino);
        nuevoNodo->next = listaAdyacencia[fuente].head;
        listaAdyacencia[fuente].head = nuevoNodo;

        nuevoNodo = crearNodo(fuente);
        nuevoNodo->next = listaAdyacencia[destino].head;
        listaAdyacencia[destino].head = nuevoNodo;
    }

    // Método que verifica que exista una arista. Recibe la fuente y destino y retorna un booleano como resultado.
    // Recorre la lista de adyacencia del nodo fuente en búsqueda del nodo destino.
    bool existeArista(int fuente, int destino){
        Vertice* temp = listaAdyacencia[fuente].head;
        while(temp){
            if((temp->dest) == destino){
                return true;
            }
            temp = temp -> next;
        }
        return false;
    }

    // Establece un grafo "sin paredes", es decir, cada nood conectado con el de arriba, abajo, derecha e izquierda.
    void sinParedes(){
        for(int i = 0; i < size; i++){
            listaAdyacencia[i].head = NULL;
        }
        int n = sqrt(size);
        int esquinas[4] = {0, n-1, n*(n-1), n*(n-1)+(n-1)};

        for(int i = 0; i < size; i++){
            if(i == esquinas[3]){
                break;
            }
            else if(((esquinas[2]) <= i) && (i < esquinas[3])){
                agregarArista(i,i+1);
            }
            else if((i+1) % n == 0){
                agregarArista(i, i+n);
            }
            else{
                agregarArista(i,i+1);
                agregarArista(i,i+n);
            }
        }
    }
        void createGraph(int u){
            Grafo *graph = new Grafo(u);
            int total;
            total++;                                //aumento en mi respuesta la caida de un domino
            bool visitado;
            visitado[u] = true;                   //domino "u" cayo
            for( int v = 0 ; v < graph[ u ].size(); ++v ){ //verifico los demas posibles domino que caeran si impulso "u"
                    if( !visitado[ graph[ u ][ v ] ] ){         //si el domino adyacente no cayó entonces es el siguiente a evaluar
                        createGraph( graph[ u ][ v ] );               //recursivamente veo que dominos caeran a partir del adyacente de "u"
                        }
            }
        }

    // Calcula el árbol de expansión utilizando el algoritmo de Prim aleatorio.
    // Retorna un grafo nuevo, por lo que se usa para reemplazar al anterior.
    Grafo calcularPrim(){
        srand (time(NULL));

        Grafo g(size);
        bool vertices[size];
        ArrayList<Arista> aristas;

        // Marcar todos los vértices como no visitados
        for(int i = 0; i < size; i++){
            vertices[i] = false;
        }

        vertices[0] = true;

        Vertice* temp = listaAdyacencia[0].head;
        int c = 0;
        while (temp){
            aristas.append(Arista(0, temp->dest));
            temp = temp -> next;
            c++;
        }

        while(aristas.getSize() > 0){
            int x = 0;
            if(aristas.getSize() != 1){
                x = rand() % (aristas.getSize() - 1);
            }
            aristas.goToPos(x);
            Arista a = aristas.getElement();
            int y = a.destino;
            if(!vertices[y]){
                aristas.remove();
                vertices[y] = true;
                g.agregarArista(a.fuente,a.destino);

                temp = listaAdyacencia[y].head;
                c = 0;
                while (temp){
                    aristas.append(Arista(y, temp->dest));
                    temp = temp -> next;
                    c++;
                }
            }
            else{
                aristas.remove();
            }
        }
        return g;
    }

    // Generador de aristas aleatorias, para agregarle arcos extra al laberinto.
    // Primero verifica que la arista sea válida y que no exista para poder crearla.
    void aristasAleatorias(){
        int cantidadNodos = (size / 100) * 5;
        int contador = 0;
        int n = sqrt(size);
        int esquinas[4] = {0, n-1, n*(n-1), n*(n-1)+(n-1)};

        while(contador < cantidadNodos){
            int num = rand() % (size - 1);
            int y = rand() % 4;

            // Arista hacia arriba
            if(y == 0){
                if(num <= esquinas[1]){
                    continue;
                }
                else{
                    if(existeArista(num, num-n)){
                        continue;
                    }
                    else{
                        agregarArista(num,num-n);
                        contador++;
                    }
                }
            }

            // Arista para la derecha
            else if(y == 1){
                if((num + 1) % n == 0){
                    continue;
                }
                else{
                    if(existeArista(num, num+1)){
                        continue;
                    }
                    else{
                        agregarArista(num,num+1);
                        contador++;
                    }
                }
            }

            // Arista para abajo
            else if(y == 2){
                if(num >= esquinas[2]){
                    continue;
                }
                else{
                    if(existeArista(num, num+n)){
                        continue;
                    }
                    else{
                        agregarArista(num,num+n);
                        contador++;
                    }
                }
            }
            // Arista para la izquierda
            else if(y == 3){
                if(num % n == 0){
                    continue;
                }
                else{
                    if(existeArista(num, num-1)){
                        continue;
                    }
                    else{
                        agregarArista(num,num-1);
                        contador++;
                    }
                }
            }
        }
    }

    // Generador de la ruta más corta utilizando el algoritmo de Dijkstra.
    // Recibe el nodo origen y calcula las rutas hacia todos los nodos, pero a la hora de ser usado, se interpreta
    // para solo considerar el camino a la salida. Retorna sus resultados en un arreglo de enteros o IDs de nodos.
    int* rutaMasCorta(int origen){
        int nodoActual = origen;

        int distancias[size];
        for(int i = 0; i < size; i++){
            if(i != origen){
                distancias[i] = 9999;
            }
            else{
                distancias[i] = 0;
            }
        }

        int *nodoOrigen = new int[size];
        nodoOrigen[origen] = origen;

        bool distanciasDef[size];
        for(int i = 0; i < size; i++){
            if(i != origen){
                distanciasDef[i] = false;
            }
            else{
                distanciasDef[i] = true;
            }
        }


        int contDef = 0;

        while(contDef < size){
            Vertice* temp = listaAdyacencia[nodoActual].head;
            while (temp){
                int nodo = temp->dest;
                if(!distanciasDef[nodo]){
                    int dist = distancias[nodoActual] + 1;
                    if(dist < distancias[nodo]){
                        distancias[nodo] = dist;
                        nodoOrigen[nodo] = nodoActual;
                    }
                }
                temp = temp->next;
            }

            int menor = INT_MAX;
            int posMenor = INT_MAX;
            for(int i = 0; i < size; i++){
                if(distanciasDef[i] == false){
                    if(distancias[i] < menor){
                        menor = distancias[i];
                        posMenor = i;
                    }
                }
            }

            if(menor == INT_MAX){
                break;
            }

            distancias[posMenor] = menor;
            distanciasDef[posMenor] = true;
            nodoActual = posMenor;

            contDef++;

        }

        int x = (size - 1);
        while(true){
            x = nodoOrigen[x];
            if(x == origen){
                break;
            }
        }

        return nodoOrigen;
    }

    int getSize(){
        return size;
    }
};

#endif // GRAPH_H_INCLUDED
