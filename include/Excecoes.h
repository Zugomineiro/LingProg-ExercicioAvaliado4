#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>

class ExcecaoNumeroNegativo : public std::runtime_error{
    public:
        ExcecaoNumeroNegativo();
};

#endif