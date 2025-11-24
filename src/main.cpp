#include "Menu.h"

int main(){
    Menu menu;
    while (!menu.usuarioQuerSair()){
        menu.imprimirMenu();
        menu.executaOpcao();
    }
    return 0;
}
