#include "headers/Civilizacao.hpp" 
#include <vector>
#include <iostream>

void Particao(int Esq, int Dir, int *i, int *j, std::vector<Civilizacao>* civilizacoes) {
    Civilizacao x, w;
    *i = Esq; *j = Dir;

    x = civilizacoes->at((*i + *j)/2); 
    do
    {
        while (x.GetDistancia() > civilizacoes->at(*i).GetDistancia() 
            || (x.GetDistancia() == civilizacoes->at(*i).GetDistancia() 
                && (x.GetPopulacao() < civilizacoes->at(*i).GetPopulacao()))) {
            (*i)++;
        }
        while (x.GetDistancia() < civilizacoes->at(*j).GetDistancia()
            || (x.GetDistancia() == civilizacoes->at(*j).GetDistancia() 
                    && x.GetPopulacao() > civilizacoes->at(*j).GetPopulacao())) {
            (*j)--;
        }
        if (*i <= *j) {
            w = civilizacoes->at(*i); 
            civilizacoes->at(*i) = civilizacoes->at(*j); 
            civilizacoes->at(*j) = w;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, std::vector<Civilizacao>* civilizacoes) { 
    int i, j;
    Particao(Esq, Dir, &i, &j, civilizacoes);
    if (Esq < j) Ordena(Esq, j, civilizacoes);
    if (i < Dir) Ordena(i, Dir, civilizacoes);
}
void QuickSort(std::vector<Civilizacao>* civilizacoes, int n) {
    Ordena(0, n-1, civilizacoes);
}

