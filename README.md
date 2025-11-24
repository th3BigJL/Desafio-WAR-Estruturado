# Desafio WAR Estruturado

Este projeto é uma implementação do **Desafio WAR Estruturado** em C, inspirado no jogo de estratégia WAR.

## Níveis implementados

### Novato
- Cadastro de 5 territórios
- Entrada de nome, cor e tropas
- Exibição do mapa

### Aventureiro
- Uso de memória dinâmica com `calloc`
- Simulação de batalhas com números aleatórios
- Ataques entre territórios com lógica simples

### Mestre
- Modularização em funções
- Menu interativo
- Missões aleatórias para o jogador

## Como compilar
```bash
gcc main.c war.c -o war
