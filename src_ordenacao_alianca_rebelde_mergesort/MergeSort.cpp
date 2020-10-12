#include "headers/Civilizacao.hpp" 
#include <vector>
#include <iostream>

void Merge(std::vector<Civilizacao>* civilizacoesLeft, std::vector<Civilizacao>* civilizacoesRight, int nl, int nr, std::vector<Civilizacao>* civilizacoes) {
    
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < nl && j < nr) {
        if(civilizacoesLeft->at(i).GetDistancia() < civilizacoesRight->at(j).GetDistancia() 
            || (civilizacoesLeft->at(i).GetDistancia() == civilizacoesRight->at(j).GetDistancia()
                && (civilizacoesLeft->at(i).GetPopulacao() > civilizacoesRight->at(j).GetPopulacao()))) {
            civilizacoes->at(k) = civilizacoesLeft->at(i);
            i++;
        }else {
            civilizacoes->at(k) = civilizacoesRight->at(j);
            j++;
        }
        k++;
    }
    // Complemeta com os elementos que faltaram na esquerda
    while (i < nl) {
        civilizacoes->at(k) = civilizacoesLeft->at(i);
        i++; k++;
    }
    // Complemeta com os elementos que faltaram na direita
    while (j < nr) {
        civilizacoes->at(k) = civilizacoesRight->at(j);
        j++; k++;
    }
}

void MergeSort(std::vector<Civilizacao>* civilizacoes) {
    if (civilizacoes->size() <= 1) return;
    int mid = civilizacoes->size() / 2;
    
    std::vector<Civilizacao>* civilizacoesLeft = new std::vector<Civilizacao>;
    std::vector<Civilizacao>* civilizacoesRight = new std::vector<Civilizacao>;

    for (int i = 0; i < mid; i++) {
        civilizacoesLeft->push_back(civilizacoes->at(i));
    }
    for (size_t j = 0; j < civilizacoes->size() - mid; j++) {
       civilizacoesRight->push_back(civilizacoes->at(mid + j));
    }

    MergeSort(civilizacoesLeft);
    MergeSort(civilizacoesRight);
    Merge(civilizacoesLeft, civilizacoesRight, civilizacoesLeft->size(), civilizacoesRight->size(), civilizacoes);
}