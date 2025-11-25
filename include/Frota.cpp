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

void Frota::buscarVeiculo(){
    std::string placaProcurada;
    std::cout << "Digite a placa do veiculo desejado: ";
    std::cin >> placaProcurada;
    std::cout << std::endl;
    Veiculo& veiculo = *(arvore(placaProcurada));
    std::cout << "Veiculo encontrado:" << std::endl << std::endl<< veiculo;
}

void Frota::imprimirVeiculos(){
    std::cout << arvore << std::endl;
}

void Frota::atualizarQuilometragem(){
    std::string placaProcurada;
    double quilometragemDesejada;
    std::cout << "Digite a placa do veiculo desejado: ";
    std::cin >> placaProcurada;
    std::cout << std::endl;

    std::cout << "Digite a quilometragem desejada: ";
    std::cin >> quilometragemDesejada;
    std::cout << std::endl;

    Veiculo* pVeiculo = arvore(placaProcurada,quilometragemDesejada);
    if (pVeiculo == NULL){
        throw VeiculoNaoEncontrado();
    }
    std::cout << "Veiculo encontrado:" << std::endl << std::endl<< *pVeiculo;
}

void Frota::calculaCustoManutencao(){
    custoMedioCaminhao = 0;
    custoMedioCarro = 0;
    custoMedioMoto = 0;

    quantidadeCaminhao = 0;
    quantidadeCarro = 0;
    quantidadeMoto = 0;

    No<Veiculo>& noRaiz = arvore.getNoRaiz();
    percussoPrefixoCustoManutencao(noRaiz);

    if (quantidadeCaminhao == 0){
        quantidadeCaminhao = 1; // Para fazer a divisao
    }
    if (quantidadeCarro == 0){
    quantidadeCarro = 1; // Para fazer a divisao
    }
    if (quantidadeMoto == 0){
    quantidadeMoto = 1; // Para fazer a divisao
    }

    std::cout << "--- Custos de manutencao ---" << std::endl;
    std::cout << "Carro: " << custoMedioCarro/quantidadeCarro << " R$" << std::endl;
    std::cout << "Caminhao: " << custoMedioCaminhao/quantidadeCaminhao << " R$"<< std::endl;
    std::cout << "Moto: " << custoMedioMoto/quantidadeMoto << " R$"<< std::endl;
    std::cout << "----------------------------" << std::endl;

}

void Frota::percussoPrefixoCustoManutencao(No<Veiculo>& noAtual){
    // Realiza ação (acumula custo manutenção na variável do tipo respectivo)
    if(noAtual.conteudo->getTipo() == "Carro"){
        custoMedioCarro += noAtual.conteudo->getCustoManutencao();
        quantidadeCarro++;
    }
    else if(noAtual.conteudo->getTipo() == "Moto"){
        custoMedioMoto += noAtual.conteudo->getCustoManutencao();
        quantidadeMoto++;
    }
    else if(noAtual.conteudo->getTipo() == "Caminhao"){
        custoMedioCaminhao += noAtual.conteudo->getCustoManutencao();
        quantidadeCaminhao++;
    }

    // Realiza percursso
    if (noAtual.pFilhoEsquerdo != NULL){
        percussoPrefixoCustoManutencao(*(noAtual.pFilhoEsquerdo));
    }
    if (noAtual.pFilhoDireito != NULL){
        percussoPrefixoCustoManutencao(*(noAtual.pFilhoDireito));
    }
}

void Frota::ativarDebug(){
    Veiculo* pVeiculo = new Carro("g","Fiat",4);
    arvore = arvore + *pVeiculo;
    (*pVeiculo)(100); // Coloca quilometragem do veiculo em 100km, calcula e atualiza o custo de manutenção.

    pVeiculo = new Caminhao("m","Mercedes-Benz",15);
    arvore = arvore + *pVeiculo;
    (*pVeiculo)(100);

    pVeiculo = new Moto("c","Toyota",500);
    arvore = arvore + *pVeiculo;
    (*pVeiculo)(100);
    
    pVeiculo = new Carro("i","Audi",6);
    arvore = arvore + *pVeiculo;
    (*pVeiculo)(100);

    pVeiculo = new Caminhao("n","Chevrolet",5);
    arvore = arvore + *pVeiculo;
    (*pVeiculo)(100);

    pVeiculo = new Moto("d","Honda",100);
    arvore = arvore + *pVeiculo;
    (*pVeiculo)(100);

    std::cout << "Dados de depuracao criados!" << std::endl;
}