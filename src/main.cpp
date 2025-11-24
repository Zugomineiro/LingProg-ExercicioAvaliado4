#include <iostream>
#include "Carro.h"
#include "Caminhao.h"
#include "Moto.h"
#include "Menu.h"
#include "Arvore.h"


int main(){
    Arvore<int> arvore;
    arvore + 2;
    std::cout << arvore;

    return 0;
}
