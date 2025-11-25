#include "Menu.h"

int main(){
    Menu menu;
    while (!menu.usuarioQuerSair()){

        try{
            menu.imprimirMenu();
            menu.executaOpcao();
        }
        catch(std::exception& erro){
            std::cout << erro.what() << std::endl;

            std::cout << "Aperte enter para voltar..." << std::endl;
            std::cin.ignore();
            std::cin.get();
        }
    }
    
    return 0;
}
