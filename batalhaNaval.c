#include <stdio.h>

int main(){
    // Define tabuleiro, 0 é água...
    int tabuleiro[10][10] = {0};
    // Navio Vertical:
    int navio1[3] = {3, 3, 3};
    int n1_linha = 4, n1_coluna = 5;
    // Navio Horizontal:
    int navio2[3] = {3, 3, 3};
    int n2_linha = 7, n2_coluna = 2;
    // Cabeçalho:
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    

    // Verifica limite e disponibilidade de casas verticais:
    int quantia_navios = 3;
    int casa_disponivel = 1;

    if (n1_linha + quantia_navios > 10){
        printf("Tamanho vertical do tabuleiro excedido.\n");
        casa_disponivel = 0;
    } else {
        for (int i = 0; i < quantia_navios; i++){
            if (tabuleiro[n1_linha + i][n1_coluna] != 0){
                casa_disponivel = 0;
                break;
            }
        }
    }

    // Adiciona navio vertical: ==> Valor 1 - True, Valor 0 - False.
    if (casa_disponivel){
        for (int i = 0; i < quantia_navios; i++){
            tabuleiro[n1_linha + i][n1_coluna] = navio1[i];
        };
    } else {
        printf("Casa já ocupada.\n");
    }
    
    // Verifica limite e disponibilidade de casas horizontais:
    casa_disponivel = 1;

    if (n2_coluna + quantia_navios > 10){
        printf("Tamanho horizontal do tabuleiro excedido.\n");
        casa_disponivel = 0;
    } else {
        for (int i = 0; i < quantia_navios; i++){
            if (tabuleiro[n2_linha][n2_coluna + i] != 0){
                casa_disponivel = 0;
                break;
            }
        }
    }

    // Adiciona navios horizontais: ==> Valor 1 - True, Valor 0 - False.
    if (casa_disponivel){
        for (int i = 0; i < quantia_navios; i++){
            tabuleiro[n2_linha][n2_coluna + i] = navio2[i];
        }
    } else {
        printf("Casa já ocupada.\n");
    }

    // Imprime cabecalho:
    printf(" ===============BATALHA NAVAL===============\n");
    printf("   |");
    for (int i = 0; i < 10; i++){
        printf(" %c |", linha[i]);
    }
    printf("\n");

    

    // Imprime numerais das casas:
    for (int vertical = 0; vertical < 10; vertical++){
        printf("%2d |", vertical + 1);
        // Imprime tabuleiro:
        for (int horizontal = 0; horizontal < 10; horizontal++){
            printf(" %d |", tabuleiro[vertical][horizontal]);
        }
        printf("\n");
    }

    return 0;
}