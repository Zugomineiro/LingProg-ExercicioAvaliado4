#include <iostream>
#include "Carro.h"
#include "Caminhao.h"
#include "Moto.h"
#include "Menu.h"
#include "No.h"


int main(){
    No<std::string> no1;
    No<std::string> no2;
    No<std::string> no3;
    No<std::string> no4;
    no1.pFilhoEsquerdo = &no2;
    no1.pFilhoDireito = &no3;
    no2.pFilhoEsquerdo = &no4;
    no1.conteudo = "oi";
    no2.conteudo = "eu";
    no3.conteudo = "sou";
    no4.conteudo = "Hugo";
    std::cout << no1.conteudo + no1.pFilhoEsquerdo->conteudo + no1.pFilhoDireito->conteudo + no1.pFilhoEsquerdo->pFilhoEsquerdo->conteudo << std::endl;
    return 0;
}
