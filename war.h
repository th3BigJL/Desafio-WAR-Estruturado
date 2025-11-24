#ifndef WAR_H
#define WAR_H

#define MAX_TERRITORIOS 5
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    char cor[MAX_NOME];
    int tropas;
} Territorio;

// Funções Nível Novato
void cadastroTerritorios(Territorio *territorios, int n);
void exibirMapa(Territorio *territorios, int n);

// Funções Nível Aventureiro
int batalhar(Territorio *atacante, Territorio *defensor);

// Funções Nível Mestre
void menu();
int verificarMissao(Territorio *territorios, int n, const char *missao);

#endif
