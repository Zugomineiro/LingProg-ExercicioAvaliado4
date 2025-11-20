#include <iostream>
#include "Carro.h"
#include "Caminhao.h"
#include "Moto.h"
#include "Menu.h"


int main(){
    Moto veiculoTeste("ABCD12345","Fiat",600);
    std::cout << veiculoTeste << std::endl;
    double quilometragemEscolhida;
    while(true){
        try{
            std::cout << "Escolha a quilometragem: ";
            std::cin >> quilometragemEscolhida;
            std::cout << std::endl;
            veiculoTeste.setQuilometragem(quilometragemEscolhida);
            veiculoTeste.setCustoManutencao(veiculoTeste.calcularCustoManutencao());
            break;
        }
        catch(std::exception& e){
            std::cout << "Excecao ocorreu: " << e.what() << std::endl;
        }
    }
    std::cout << veiculoTeste << std::endl;
    return 0;
}
