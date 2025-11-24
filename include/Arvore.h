#ifndef ARVORE_H
#define ARVORE_H

#include "No.h"
#include <iostream>

template <class T>
class Arvore{
    public:
    ~Arvore();
    Arvore<T>& operator+(T);
    void mostrarInformacoes(std::ostream& out = std::cout);

    private:
        No<T> noRaiz;
        size_t quantidadeNos = 0;

};

template <class T>
std::ostream& operator<<(std::ostream& out, Arvore<T>& arvore){
    arvore.mostrarInformacoes(out);
};

#endif