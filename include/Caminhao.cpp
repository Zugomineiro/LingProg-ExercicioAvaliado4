#include "Caminhao.h"

Caminhao::Caminhao(std::string placa,std::string marca,double capacidadeCarga):Veiculo(placa,marca),capacidadeCarga(capacidadeCarga){}

void Caminhao::mostrarInformacoes(std::ostream& out) const{
    out << "tipo: Caminhao" << std::endl;
    Veiculo::mostrarInformacoes();
    out << "Capacidade de Carga: " << capacidadeCarga << " toneladas" << std::endl;
}

double Caminhao::calcularCustoManutencao() const{
    return (capacidadeCarga/30+0.15)*getQuilometragem();
}

std::string Caminhao::getTipo(){return "Caminhao";}