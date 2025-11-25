#include "Excecoes.h"

ExcecaoNumeroNegativo::ExcecaoNumeroNegativo():
runtime_error("Tentativa de utilizar numero negativo em uma variavel que nao assume numeros negativos."){}

const char* VeiculoNaoEncontrado::what() const throw(){
    return "Erro: veiculo nao encontrado no sistema.";
}