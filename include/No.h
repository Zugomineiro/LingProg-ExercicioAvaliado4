#ifndef NO_H
#define NO_H

// Define NULL como 0 caso ainda não tenha sido definido
#ifndef NULL
#define NULL 0
#endif

/**
 * 
 * @brief Struct com template que serve pra representar um nó binário de árvore.
 * 
 */
template <class T>
struct No{
    T conteudo;
    No<T>* pFilhoEsquerdo = NULL;
    No<T>* pFilhoDireito = NULL;
};


#endif