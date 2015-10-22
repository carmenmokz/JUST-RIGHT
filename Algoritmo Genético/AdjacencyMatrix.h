#include <iostream>
#include <fstream>
#include <cstdlib
using namespace std;
#define MAX 20
/*
 * Adjacency Matrix Class
 */
class AdjacencyMatrix
{
    private:
        int n;
        int **adj;
        bool *visited;
    public:
        AdjacencyMatrix(int n)
        {
            this->n = n;
            visited = new bool [n];
            adj = new int* [n];
            for (int i = 0; i < n; i++)
            {
                adj[i] = new int [n];
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = 0;
                }
            }
        }
        /*
         * Adding Edge to Graph
         */
        void add_edge(int origin, int destin)
        {
            if( origin > n || destin > n || origin < 0 || destin < 0)
            {
                cout<<"Invalid edge!\n";
            }
            else
            {
                adj[origin - 1][destin - 1] = 1;
            }
        }
        /*
         * Print the graph
         */
        void display()
        {
            FILE *pf;
            pf = fopen("prueba.txt","w"); //w archivo solo para escritura / r solo para lectura

            int i,j;
            ofstream fout("prueba.txt");
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                    fout<<adj[i][j]<<" ";
                fout<<"\n";
            }
        }
};
