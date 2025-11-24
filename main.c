#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "war.h"

int main() {
    srand(time(NULL));

    // Alocação dinâmica dos territórios
    Territorio *territorios = (Territorio*) calloc(MAX_TERRITORIOS, sizeof(Territorio));

    // Nível Novato: cadastro
    printf("=== Nível Novato: Cadastro de Territórios ===\n");
    cadastroTerritorios(territorios, MAX_TERRITORIOS);
    exibirMapa(territorios, MAX_TERRITORIOS);

    // Nível Mestre: menu interativo
    const char *missao = "Destruir o exército Verde"; // exemplo de missão
    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        getchar(); // limpa buffer
        if (opcao == 1) {
            int a, d;
            exibirMapa(territorios, MAX_TERRITORIOS);
            printf("Escolha o atacante (1-%d): ", MAX_TERRITORIOS);
            scanf("%d", &a);
            printf("Escolha o defensor (1-%d): ", MAX_TERRITORIOS);
            scanf("%d", &d);
            getchar();
            batalhar(&territorios[a - 1], &territorios[d - 1]);
            exibirMapa(territorios, MAX_TERRITORIOS);
        } else if (opcao == 2) {
            if (verificarMissao(territorios, MAX_TERRITORIOS, missao))
                printf("\nMissão cumprida! 🎉\n");
            else
                printf("\nMissão não cumprida ainda.\n");
        }
    } while(opcao != 0);

    free(territorios);
    printf("Jogo encerrado.\n");
    return 0;
}
