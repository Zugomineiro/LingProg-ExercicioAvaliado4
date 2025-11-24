#ifndef ARVORE_H
#define ARVORE_H

#include "No.h"
#include <iostream>

template <class T>
class Arvore{
    public:
    ~Arvore(){

    }
    Arvore<T>& operator+(T& conteudo){ // Cria um nó copiando o conteúdo e adicona na árvore.
        No<T>* pNoNovo = new No<T>;
        pNoNovo->conteudo = &conteudo;
        if (quantidadeNos == 0){
            // Caso seja a primeira adição, inicializa o ponteiro de raiz com o nó adicionado, isso garante que pNoRaiz passou pelo construtor de No
            pNoRaiz = pNoNovo;
            quantidadeNos++;
        }
        else{
            adicionarNo(pNoNovo,pNoRaiz);
        }
        return *this;
    }

    void adicionarNo(No<T>* noNovo,No<T>* noRaizAtual){ // Percorre de forma recursiva a arvore e adiciona o No assim que encontrar a posição adequada
        if (*(noNovo->conteudo) > *(noRaizAtual->conteudo)){
            if (noRaizAtual->pFilhoEsquerdo != NULL){
                adicionarNo(noNovo,noRaizAtual->pFilhoEsquerdo);
            }
            else{
                noRaizAtual->pFilhoEsquerdo = noNovo;
                quantidadeNos++;
            }
        }
        else if(*(noNovo->conteudo) < *(noRaizAtual->conteudo)){
            if (noRaizAtual->pFilhoDireito != NULL){
                adicionarNo(noNovo,noRaizAtual->pFilhoDireito);
            }
            else{
                noRaizAtual->pFilhoDireito = noNovo;
                quantidadeNos++;
            }
        }
        else{
            // Se entrou aqui quer dizer que o conteudo do nó inserido é igual a de um nó existente na arvore, não modifica a arvore
            return;
        }
    }

    
    void printPercussoPrefixo(No<T>* pNoAtual){ // Faz o print de todos os elementos da arvore usando percurso prefixo (print -> filho esquerdo -> filho direito)
        std::cout << *(pNoAtual->conteudo) << std::endl;
        if (pNoAtual->pFilhoEsquerdo != NULL){
            printPercussoPrefixo(pNoAtual->pFilhoEsquerdo);
        }
        if (pNoAtual-> pFilhoDireito != NULL){
            printPercussoPrefixo(pNoAtual->pFilhoDireito);
        }

    }

    void mostrarInformacoes(){
        if (quantidadeNos == 0){
            std::cout << "Nao há itens para serem mostrados." << std::endl;
            return;
        }
        std::cout << "Mostrando " << quantidadeNos << " itens:" << std::endl << std::endl;
        printPercussoPrefixo(pNoRaiz);
    }

    private:
        No<T>* pNoRaiz;
        size_t quantidadeNos = 0;

};

template <class T>
std::ostream& operator<<(std::ostream& out, Arvore<T>& arvore){
    arvore.mostrarInformacoes();
    return std::cout;
};

#endif