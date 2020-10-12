#include "headers/Civilizacao.hpp" 
#include <vector>
#include <iostream>

void Selecao(std::vector<Civilizacao>* civilizacoes, int n) {
    int i, j, Min;
    for (i = 0; i < n - 1; i++) {
        Min = i;
        for (j = i + 1 ; j < n; j++) {
            if (civilizacoes->at(j).GetDistancia() < civilizacoes->at(Min).GetDistancia() 
                || (civilizacoes->at(j).GetDistancia() == civilizacoes->at(Min).GetDistancia()
                    && (civilizacoes->at(j).GetPopulacao() > civilizacoes->at(Min).GetPopulacao()))) {
                Min = j;
            }
        }
        if(i != Min) {
            std::swap(civilizacoes->at(i), civilizacoes->at(Min));
        }
    }
}