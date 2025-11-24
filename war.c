#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "war.h"

// ===================== NÍVEL NOVATO =====================
void cadastroTerritorios(Territorio *territorios, int n) {
    for (int i = 0; i < n; i++) {
        printf("=== Territorio %d ===\n", i + 1);
        printf("Nome: ");
        fgets(territorios[i].nome, MAX_NOME, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0;

        printf("Cor do exército: ");
        fgets(territorios[i].cor, MAX_NOME, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0;

        printf("Número de tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // limpa buffer
    }
}

void exibirMapa(Territorio *territorios, int n) {
    printf("\n=== Mapa Atual ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s | Exército: %s | Tropas: %d\n",
               i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }
}

// ===================== NÍVEL AVENTUREIRO =====================
int batalhar(Territorio *atacante, Territorio *defensor) {
    int dadoAtaque = rand() % 6 + 1;
    int dadoDefesa = rand() % 6 + 1;

    printf("\nBatalha: %s (Atacante) vs %s (Defensor)\n", atacante->nome, defensor->nome);
    printf("Dado do atacante: %d\n", dadoAtaque);
    printf("Dado do defensor: %d\n", dadoDefesa);

    if (dadoAtaque >= dadoDefesa) {
        defensor->tropas -= 1;
        printf("%s perde 1 tropa!\n", defensor->nome);
        if (defensor->tropas <= 0) {
            printf("%s foi conquistado por %s!\n", defensor->nome, atacante->nome);
            strcpy(defensor->cor, atacante->cor);
            defensor->tropas = 1; // conquista com 1 tropa
            return 1; // conquistado
        }
    } else {
        printf("Defensor se mantém!\n");
    }
    return 0; // não conquistado
}

// ===================== NÍVEL MESTRE =====================
void menu() {
    printf("\n=== Menu ===\n");
    printf("1 - Atacar\n");
    printf("2 - Verificar Missão\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

int verificarMissao(Territorio *territorios, int n, const char *missao) {
    if (strcmp(missao, "Destruir o exército Verde") == 0) {
        for (int i = 0; i < n; i++) {
            if (strcmp(territorios[i].cor, "Verde") == 0)
                return 0;
        }
        return 1;
    } else if (strcmp(missao, "Conquistar 3 territorios") == 0) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(territorios[i].cor, "Azul") == 0)
                count++;
        }
        return count >= 3;
    }
    return 0;
}
