#ifndef PROBLEMA_H
#define PROBLEMA_H
#include <iostream>

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

#endif // PROBLEMA_H
