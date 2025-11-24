#include "Frota.h"

void Frota::inserirVeiculo(){
    // Pergunta a marca e placa do veiculo novo
    std::string placa;
    std::string marca;
    std::cout << "Digite a placa do veiculo: ";
    std::cin >> placa;
    std::cout << std::endl << "Digite a marca do veiculo: ";
    std::cin >> marca;
    std::cout << std::endl;

    while (true){
        
        // Pergunta ao usuario qual tipo de veiculo ele quer adicionar
        std::string opcaoEscolhida;

        std::cout << "Escolha o tipo de veiculo desejado: " << std::endl;
        std::cout << "1 - Carro" << std::endl;
        std::cout << "2 - Caminhao" << std::endl;
        std::cout << "3 - Moto" << std::endl;
        
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcaoEscolhida;
        if (opcaoEscolhida == "1"){
            // Pergunta o numero de portas para o usuário
            size_t numeroPortas;
            std::cout << std::endl << "Digite o numero de portas do carro: ";
            std::cin >> numeroPortas;
            std::cout << std::endl;
            
            // Adiciona veiculo na arvore
            Carro& carro = *(new Carro(placa,marca,numeroPortas)); // Delete é feito na classe Arvore
            arvore = arvore + carro;
            break;
        }
        else if(opcaoEscolhida == "2"){
            // Pergunta a capacidade para o usuário
            double capacidadeCarga;
            std::cout << std::endl << "Digite a capacidade de carga(toneladas) do caminhao: ";
            std::cin >> capacidadeCarga;
            std::cout << std::endl;
            
            // Adiciona veiculo na arvore
            Caminhao& caminhao = *(new Caminhao(placa,marca,capacidadeCarga)); // Delete é feito na classe Arvore
            arvore = arvore + caminhao;
            break;

        }
        else if(opcaoEscolhida == "3"){
            // Pergunta a quantidade de cilindradas para o usuário
            double cilindradas;
            std::cout << std::endl << "Digite a quantidade de cilindradas(cm^3) da moto: ";
            std::cin >> cilindradas;
            std::cout << std::endl;
            
            // Adiciona veiculo na arvore
            Moto& moto = *(new Moto(placa,marca,cilindradas)); // Delete é feito na classe Arvore
            arvore = arvore + moto;
            break;

        }
        else{
            std::cout << "Opcao invalida, tente novamente." << std::endl << std::endl;
        }


    }
}

void Frota::imprimirVeiculos(){
    std::cout << arvore << std::endl;
}