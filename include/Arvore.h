#ifndef ARVORE_H
#define ARVORE_H

#include "No.h"
#include "Excecoes.h"
#include <iostream>

/**
 * 
 * @brief Classe template de arvore binária que permite diversas operações
 * 
 */
template <class T>
class Arvore{
    public:
    ~Arvore(){
        deletePercussoPosfixo(pNoRaiz);
        delete pNoRaiz;; // Desaloca memoria do nó raíz
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
    void deletePercussoPosfixo(No<T>* pNoAtual){
        if (pNoAtual->pFilhoEsquerdo != NULL){
            deletePercussoPosfixo(pNoAtual->pFilhoEsquerdo);
        }
        if (pNoAtual->pFilhoDireito != NULL){
            deletePercussoPosfixo(pNoAtual->pFilhoDireito);
        }
        // Deleta ponteiros dos filhos do nó atual para desalocar memória alocada dinamicamente
        delete pNoAtual->pFilhoEsquerdo;
        delete pNoAtual->pFilhoDireito;
        // Deleta conteúdo porque assume que o conteúdo foi alocado dinamicamente de forma externa a esse código
        delete pNoAtual->conteudo;
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

    T* buscaBinaria(std::string& atributo,No<T>* noRaizAtual){
        if (*(noRaizAtual->conteudo) < atributo){
            if (noRaizAtual->pFilhoEsquerdo != NULL){
                return buscaBinaria(atributo,noRaizAtual->pFilhoEsquerdo );
            }
            else{
                // Se entrou aqui, quer dizer que não há próximo nó para percorrer e o veiculo não foi encontrado
                throw VeiculoNaoEncontrado(); //OBS: para uma classe mais geral a exceção "VeiculoNaoEncontrado" não é genérica, mas foi escolhida pois é exigida no exercício.
            }
        }
        else if(*(noRaizAtual->conteudo) > atributo){
            if (noRaizAtual->pFilhoDireito != NULL){
                return buscaBinaria(atributo,noRaizAtual->pFilhoDireito);
            }
            else{
                // Se entrou aqui, quer dizer que não há próximo nó para percorrer e o veiculo não foi encontrado
                throw VeiculoNaoEncontrado();
            }
        }
        else{
            // Se entrou aqui quer dizer que o atributo foi encontrado em algum nó, retorna o ponteiro para o conteúdo do nó
            return noRaizAtual->conteudo;
        }
    }
    
    T* operator()(std::string& atributo){
        return buscaBinaria(atributo,pNoRaiz);
    }

    T* operator()(std::string& atributoBusca,double atributoAtualizacao){
        T* ponteiroConteudo;
        try{
            ponteiroConteudo = operator()(atributoBusca);
            (*ponteiroConteudo)(atributoAtualizacao); // Chama o metodo de operator() com o argumento double atributoAtualizacao, a implementação fica a cargo de quem for implementar a função template 
        }
        catch(VeiculoNaoEncontrado& erro){
            ponteiroConteudo = NULL;
        }
        return ponteiroConteudo;
    }

    No<T>& getNoRaiz(){return *pNoRaiz;}


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