#include "Carro.h"
Carro::Carro(std::string placa, std::string marca, size_t numeroPortas):Veiculo(placa,marca),numeroPortas(numeroPortas){
    std::cout << numeroPortas << std::endl;
}

void Carro::mostrarInformacoes(std::ostream& out) const{
    out << "tipo: Carro" << std::endl;
    Veiculo::mostrarInformacoes();
    out << "Numero de Portas: " << numeroPortas << std::endl;
}

double Carro::calcularCustoManutencao() const{
    return (static_cast<double>(numeroPortas)/4)*0.15*getQuilometragem();
}