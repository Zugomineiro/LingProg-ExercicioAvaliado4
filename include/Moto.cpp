#include "Moto.h"

Moto::Moto(std::string placa, std::string marca, double cilindradas):Veiculo(placa,marca),cilindradas(cilindradas){}

void Moto::mostrarInformacoes(std::ostream& out) const{
    out << "tipo: Moto" << std::endl;
    Veiculo::mostrarInformacoes();
    out << "Cilindradas: " << cilindradas << " cc(centimetro cubico)" << std::endl;
}

double Moto::calcularCustoManutencao() const{
    return (0.000125*cilindradas + 0.03)*getQuilometragem();
}