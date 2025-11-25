#include "Veiculo.h"

Veiculo::Veiculo(std::string placa,std::string marca):placa(placa),marca(marca){}
void Veiculo::mostrarInformacoes(std::ostream& out) const{
    out << "Placa: " << placa << std::endl;
    out << "Marca: " << marca << std::endl;
    out << "Quilometragem: " << quilometragem << " Km" <<  std::endl;
    out << "Custo de Manutencao: " << custoManutencao << " R$" << std::endl; 
}

Veiculo::Veiculo(){}

double Veiculo::calcularCustoManutencao() const{
    return 0.25*quilometragem;
}

void Veiculo::setCustoManutencao(double custoManutencao){
    if (custoManutencao < 0){
        throw ExcecaoNumeroNegativo();
    }
    this-> custoManutencao = custoManutencao;
}

void Veiculo::setQuilometragem(double quilometragem){
    if (quilometragem < 0){
        throw ExcecaoNumeroNegativo();
    }
    this-> quilometragem = quilometragem;
}

double Veiculo::getQuilometragem() const {return quilometragem;}
double Veiculo::getCustoManutencao() const {return custoManutencao;}
std::string Veiculo::getMarca() const {return marca;}
std::string Veiculo::getPlaca() const {return placa;}

std::ostream& operator<<(std::ostream& out, Veiculo& veiculo){
    veiculo.mostrarInformacoes(out);
    return out;
}

bool Veiculo::operator>(Veiculo& veiculo){
    if (placa > veiculo.getPlaca()){
        return true;
    }
    return false;
}

bool Veiculo::operator<(Veiculo& veiculo){
    if (placa < veiculo.getPlaca()){
        return true;
    }
    return false;
}

bool Veiculo::operator==(Veiculo& veiculo){
    if (placa == veiculo.getPlaca()){
        return true;
    }
    return false;
}

bool Veiculo::operator>(std::string placa){
    if (this->placa > placa){
        return true;
    }
    return false;
}

bool Veiculo::operator<(std::string placa){
    if (this->placa < placa){
        return true;
    }
    return false;
}

bool Veiculo::operator==(std::string placa){
    if (this->placa == placa){
        return true;
    }
    return false;
}