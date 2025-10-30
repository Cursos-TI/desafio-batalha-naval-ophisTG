#include <stdio.h>

// Função para definir forma do octaedro:
int valor(int numero){
    if (numero < 0){
        return -numero;
    }
    return numero;
}

void constroi_octaedro(int matriz[5][5]){
    // centro da matriz:
    int centro = 2;

    // construir octaedro:
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (valor(i - centro) + valor(j - centro) <= centro){
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }

}

int main(){
    // Define tabuleiro, 0 é água...
    int tabuleiro[10][10] = {0};

    // Navio Vertical:
    int navio1[3] = {3, 3, 3};
    int n1_linha = 0, n1_coluna = 0;

    // Navio Horizontal:
    int navio2[3] = {3, 3, 3};
    int n2_linha = 0, n2_coluna = 7;

    // Navios diagonais:
    int navio_diagonal[3] = {3, 3, 3};
    int nd_linha = 7, nd_coluna = 7;
    int navio_diagonal2[3] = {3, 3, 3};
    int nd2_linha = 7, nd2_coluna = 2;

    // Habilidades:
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Cabeçalho:
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Constroi habilidades:
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            // Cone:
            if (j >= (2 - i) && j <= (2 +i)){
                cone[i][j] = 1;
            }

            // Cruz:
            if (i == 2 || j == 2){
                cruz[i][j] = 1;
            }
        }
    }
    
    constroi_octaedro(octaedro);

    // Adiciona habilidades no tabuleiro:
    int centro_habilidade = 2;

    // Cone:
    int cone_linha = 0;
    int cone_coluna = 3;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (cone[i][j] == 1){
                int tabuleiro_linha = cone_linha + i;
                int tabuleiro_coluna = cone_coluna + (j - centro_habilidade);

                // Verifica limite e disponibilidade do tabuleiro:
                if (tabuleiro_linha >= 0 && tabuleiro_linha < 10 && tabuleiro_coluna >= 0 && tabuleiro_coluna < 10){
                    if (tabuleiro[tabuleiro_linha][tabuleiro_coluna] == 0){
                        tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 5;
                    }
                }
            }
        }
    }

    // Cruz:
    int cruz_linha = 4;
    int cruz_coluna = 4;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (cruz[i][j] == 1){
                int tabuleiro_linha = cruz_linha + (i - centro_habilidade);
                int tabuleiro_coluna = cruz_coluna + (j - centro_habilidade);

                // Verifica limite e disponibilidade do tabuleiro:
                if (tabuleiro_linha >= 0 && tabuleiro_linha < 10 && tabuleiro_coluna >= 0 && tabuleiro_coluna < 10){
                    if (tabuleiro[tabuleiro_linha][tabuleiro_coluna] == 0){
                        tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 5;
                    }
                }
            }
        }
    }

    // Octaedro:
    int octaedro_linha = 4;
    int octaedro_coluna = 1;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (octaedro[i][j] == 1){
                int tabuleiro_linha = octaedro_linha + (i - centro_habilidade);
                int tabuleiro_coluna = octaedro_coluna + (j - centro_habilidade);

                // Verifica limite e disponibilidade do tabuleiro:
                if (tabuleiro_linha >= 0 && tabuleiro_linha < 10 && tabuleiro_coluna >= 0 && tabuleiro_coluna < 10){
                    if (tabuleiro[tabuleiro_linha][tabuleiro_coluna] == 0){
                        tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 5;
                    }
                }
            }
        }
    }



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

    // Verifica limite e disponibilidade de casas diagonais:
    casa_disponivel = 1;

    if (nd_linha + quantia_navios > 10 || nd_coluna + quantia_navios > 10){
        printf("Navio diagonal (1) excedeu o limite do tabuleiro.\n");
        casa_disponivel = 0;
    } else {
        for (int i = 0; i < quantia_navios; i++){
            if (tabuleiro[nd_linha + i][nd_coluna + i] != 0) {
                casa_disponivel = 0;
                break;
            }
        }
    }

    // Adiciona navio diagonal (1):
    if (casa_disponivel) {
        for (int i = 0; i < quantia_navios; i++){
            tabuleiro[nd_linha + i][nd_coluna + i] = 3;
        }
    } else {
        printf("Casa já ocupada.\n");
    }

    // Verifica limite e disponibilidade de casas diagonais:
    casa_disponivel = 1;
    if (nd2_linha + quantia_navios > 10 || (nd2_coluna - (quantia_navios - 1)) < 0){
        printf("Navio diagonal (2) excedeu o limite do tabuleiro.\n");
        casa_disponivel = 0;
    } else {
        for (int i = 0; i < quantia_navios; i++){
            if (tabuleiro[nd2_linha + i][nd2_coluna - i] != 0){
                casa_disponivel = 0;
                break;
            }
        }
    }

    // Adiciona navio diagonal (2):
    if (casa_disponivel) {
        for (int i = 0; i < quantia_navios; i++){
            tabuleiro[nd2_linha + i][nd2_coluna - i] = 3;
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
        // Altera a exibição de número para caractere
        switch (tabuleiro[vertical][horizontal]) {
            case 0:  // Água
                printf(" ~ |");
                break;
            case 3:  // Navio
                printf(" N |");
                break;
            case 5:  // Área de Habilidade
                printf(" X |");
                break;
            default: // Caso algo inesperado ocorra
                printf(" ? |");
                break;
        }
    }
    printf("\n");
}

    return 0;
}