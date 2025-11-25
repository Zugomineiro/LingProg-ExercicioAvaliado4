#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <exception>

class ExcecaoNumeroNegativo : public std::runtime_error{
    public:
        ExcecaoNumeroNegativo();
};

class VeiculoNaoEncontrado : public std::exception{
    public:
        virtual const char* what() const throw();
};

#endif