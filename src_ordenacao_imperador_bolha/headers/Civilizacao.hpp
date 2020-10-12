#ifndef CIVILIZACAO_HPP
#define CIVILIZACAO_HPP
#include <cstddef>
#include <string>

class Civilizacao {
    public:
        Civilizacao();
        Civilizacao(char n[15], int d, int p);
        int GetDistancia();
        int GetPopulacao();
        void Imprime();
    private:
        int distancia;
        int populacao;
        char nome[15];
};
#endif