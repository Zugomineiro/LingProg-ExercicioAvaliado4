#ifndef ARVORE_H
#define ARVORE_H

#include "No.h"
#include <iostream>

template <class T>
class Arvore{
    public:
    ~Arvore(){

    }
    Arvore<T>& operator+(T conteudo){
        No<T>* pNoNovo = new No<T>;
        pNoNovo->conteudo = conteudo;
        if (quantidadeNos == 0){
            // Caso seja a primeira adição, inicializa o ponteiro de raiz com o nó adicionado, isso garante que pNoRaiz passou pelo construtor de No
            pNoRaiz = pNoNovo;
        }
        else{
            adicionarNo(pNoNovo,pNoRaiz);
        }
        return *this;
    }

    void adicionarNo(No<T>* noNovo,No<T>* noRaizAtual){
        std::cout << noNovo->pFilhoDireito << " " << noNovo->pFilhoEsquerdo << std::endl;
        if (noNovo->conteudo > noRaizAtual->conteudo){
            std::cout << "maior";
            if (noRaizAtual->pFilhoEsquerdo != NULL){
                adicionarNo(noNovo,noRaizAtual->pFilhoEsquerdo);
            }
            else{
                noRaizAtual->pFilhoEsquerdo = noNovo;
                quantidadeNos++;
            }
        }
        else if(noNovo->conteudo < noRaizAtual->conteudo){
            std::cout << "menor";
            if (noRaizAtual->pFilhoDireito != NULL){
                adicionarNo(noNovo,noRaizAtual->pFilhoDireito);
            }
            else{
                std::cout << " adicionado" << std::endl;
                noRaizAtual->pFilhoDireito = noNovo;
                quantidadeNos++;
            }
        }
        else{
            std::cout << "igual";
            // Se entrou aqui quer dizer que o conteudo do nó inserido é igual a de um nó existente na arvore, não modifica a arvore
            return;
        }
    }

    void mostrarInformacoes(std::ostream& out = std::cout){
        out << pNoRaiz->conteudo <<std::endl;
    }

    private:
        No<T>* pNoRaiz;
        size_t quantidadeNos = 0;

};

template <class T>
std::ostream& operator<<(std::ostream& out, Arvore<T>& arvore){
    arvore.mostrarInformacoes(out);
    return out;
};

#endif