#ifndef NO_H
#define NO_H

template <class T>
class No{
    public:
        T conteudo;
        No<T>* pFilhoEsquerdo;
        No<T>* pFilhoDireito;
        
};
#endif