#include <iostream>
#include "Carro.h"
#include "Caminhao.h"
#include "Moto.h"
#include "Menu.h"
#include "Arvore.h"


int main(){
    Arvore<char> arvore;
    arvore + 'g';
    arvore + 'm';
    arvore + 'c';
    arvore + 'i';
    std::cout << arvore;

    return 0;
}
