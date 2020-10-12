#include "./headers/Civilizacao.hpp"
#include <iostream>
#include <string.h>

Civilizacao::Civilizacao() {}

Civilizacao::Civilizacao(char n[15], int d, int p) {
    strcpy(this->nome, n);
    this->populacao = p;
    this->distancia = d;
}

int Civilizacao::GetPopulacao() {
    return this->populacao;
}

int Civilizacao::GetDistancia() {
    return this->distancia;
}

void Civilizacao::Imprime() {
    std::cout << this->nome << " " << this->distancia << " " << this->populacao << "\n"; 
}