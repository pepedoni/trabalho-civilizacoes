#include "headers/Civilizacao.hpp" 
#include <vector>
#include <iostream>

void Bolha(std::vector<Civilizacao>* civilizacoes, int n) {
    int i, j;

    for(i = 0; i < n-1; i++) {
        for(j = 1; j < n-i; j++) {
            if (civilizacoes->at(j).GetDistancia() < civilizacoes->at(j - 1).GetDistancia() 
                || (civilizacoes->at(j).GetDistancia() == civilizacoes->at(j - 1).GetDistancia()
                    && (civilizacoes->at(j).GetPopulacao() > civilizacoes->at(j - 1).GetPopulacao()))) {
                std::swap(civilizacoes->at(j), civilizacoes->at(j-1));
            } 
        }
    }
}