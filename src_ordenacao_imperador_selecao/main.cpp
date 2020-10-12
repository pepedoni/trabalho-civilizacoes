#include <cstdio> // em C substituir por #include <stdio.h>
#include <iostream>
#include <vector>
#include "headers/Civilizacao.hpp" 
#include "Selecao.cpp"
using namespace std;

int main() {
    int num_civilizacoes;
    scanf("%d",&num_civilizacoes);
    int i, j;

    vector<Civilizacao>* civilizacoes = new vector<Civilizacao>;
    
    for(i=0; i < num_civilizacoes; i++){
        char nome[15] = {};
        int distancia, populacao;
        scanf("%s %d %d", &nome[0], &distancia, &populacao);
        civilizacoes->push_back(Civilizacao(nome, distancia, populacao));
    }

    Selecao(civilizacoes, num_civilizacoes);

    for(j=0; j < num_civilizacoes; j++){
        civilizacoes->at(j).Imprime();
    }

    return 0;
}
