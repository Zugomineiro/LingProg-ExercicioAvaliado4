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
            break;
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
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "1 - Adicionar Biblioteca" << "|"<< std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "2 - Registrar novo livro" << "|"<< std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "3 - Inserir livro no acervo" << "|"<< std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "4 - Mostrar Biblioteca" << "|"<< std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "5 - Remover livro no acervo" << "|"<< std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "6 - Pesquisar livros por autor" << "|"<< std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "7 - Atualizar avaliacao de um livro" << "|"<< std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "8 - Comparar bibliotecas" << "|"<< std::endl;
    std::cout << "|" << std::left << std::setw(larguraMenu - 2) << "9 - Sair" << "|"<< std::endl;
    std::cout << "---------------------------------------------------" << std::endl;

}

bool Menu::usuarioQuerSair(){
    return usuarioSaiu;
}
