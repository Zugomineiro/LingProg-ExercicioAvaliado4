#include "Menu.h"

void Menu::executaOpcao(){
    std::string opcaoEscolhida;
    while (true){
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            continue;
        }

        std::cout << "Escolha uma opcao: ";
        std::cin >> opcaoEscolhida;


        if (opcaoEscolhida == "1"){
            frota.inserirVeiculo();
            break;
        }
        else if(opcaoEscolhida == "2"){
            frota.imprimirVeiculos();
            break;
        }
        else if(opcaoEscolhida == "3"){
            frota.buscarVeiculo();
            break;
        }
        else if(opcaoEscolhida == "6"){
            usuarioSaiu = true;
            return;
        }
       
        else{
            std::cout << "Opcao invalida, tente novamente." << std::endl;
        }
    }

    std::cout << "Aperte enter para voltar..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}


void Menu::imprimirMenu(){
    std::cout << "________________ Escolha uma opcao ________________" << std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "1 - Inserir veiculo" << "|"<< std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "2 - Mostrar Veiculos" << "|"<< std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "3 - Buscar Veiculo" << "|"<< std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "6 - Sair" << "|"<< std::endl;
    std::cout << "---------------------------------------------------" << std::endl;

}

bool Menu::usuarioQuerSair(){
    return usuarioSaiu;
}
