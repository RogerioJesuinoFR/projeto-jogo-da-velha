#include <stdio.h>
#include <windows.h>

#define MOLDURA "  \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"

char MAT[4][4];

void INICIALIZA_MATRIZ() {
    int L, C;
    for (L = 1; L < 4; L++)
        for (C = 1; C < 4; C++)
            MAT[L][C] = '-';
}

//-----------------------------------
void IMPRIMIR() {
    int L, C;
    system("cls");
    printf("         Jogo da Velha\n\n      1       2       3   \n");
    printf(MOLDURA);
    for (L = 1; L < 4; L++) {
        printf("%d \xBA   ", L);
        for (C = 1; C < 4; C++){
            printf("%c", MAT[L][C]);
            if(C < 3)
                printf("   \xBA   ");
        }
        if(L <3){
            printf("   \xBA\n  \xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9\n");
        }else
            printf("   \xBA\n");
        
    }
    printf("  \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
}
//-----------------------------------

//-----------------------------------
void JOGADA(char JOGADOR) {
    int LINHA, COLUNA;
    do {
        do {
            printf("\n\nVez do jogador  \xAF %c\n\nDigite a linha que deseja\n", JOGADOR);
            scanf("%d", &LINHA);
            if ((LINHA < 1) || (LINHA > 3))
                printf("Posicao invalida. Informe novamente\n");
        } while ((LINHA < 1) || (LINHA > 3));
        do {
            printf("Digite a coluna que deseja\n");
            scanf("%d", &COLUNA);
            if ((COLUNA < 1) || (COLUNA > 3))
                printf("Posicao invalida. Informe novamente\n");
        } while ((COLUNA < 1) || (COLUNA > 3));
        if (MAT[LINHA][COLUNA] != '-')
            printf("Esta posicao esta ocupada. Digite novamente\n\n");
    } while (MAT[LINHA][COLUNA] != '-');
    MAT[LINHA][COLUNA] = JOGADOR;
}
//-----------------------------------
int VERIFICA_JOGADA(char JOGADOR) {
    int L, C, GANHOU;

    // Verifica ganhador na linha
    for (L = 1; L < 4; L++) {
        GANHOU = 0;
        for (C = 1; C < 4; C++) {
            if (MAT[L][C] == JOGADOR) {
                GANHOU++;
            }
        }
        if (GANHOU == 3) {
            return 1; // 1 ganhou
        }
    }

    // Verifica ganhador na coluna
    for (C = 1; C < 4; C++) {
        GANHOU = 0;
        for (L = 1; L < 4; L++) {
            if (MAT[L][C] == JOGADOR) {
                GANHOU++;
            }
        }
        if (GANHOU == 3) {
            return 1; // 1 ganhou
        }
    }

    // Verifica ganhador na diagonal principal
    GANHOU = 0;
    for (L = 1; L < 4; L++) {
        for (C = 1; C < 4; C++) {
            if ((L == C) && (MAT[L][C] == JOGADOR)) {
                GANHOU++;
            }
        }
    }
    if (GANHOU == 3) {
        return 1; // 1 ganhou
    }

    // Verifica ganhador na diagonal secundaria
    GANHOU = 0;
    for (L = 1; L < 4; L++) {
        for (C = 1; C < 4; C++) {
            if ((L + C == 4) && (MAT[L][C] == JOGADOR)) {
                GANHOU++;
            }
        }
    }
    if (GANHOU == 3) {
        return 1; // 1 ganhou
    }

    return 0; // não ganhou em nenhuma situacao
}
//-----------------------------------
int main() {
    char JOGADOR;
    int CONT = 0;

    INICIALIZA_MATRIZ();
    IMPRIMIR();

    while (CONT < 9) {
        if (CONT % 2 == 0)
            JOGADOR = 'o';
        else
            JOGADOR = '\x9E';

        JOGADA(JOGADOR);
        IMPRIMIR();
        CONT++;
        if (CONT == 8){
            printf("\n\n...Deu velha...\n\n");
            break;
        }

        if (CONT > 4) {
            if (VERIFICA_JOGADA(JOGADOR) == 1) {
                printf("\n\nJogador %c ganhou!\n\n", JOGADOR);
                break; // Não é necessário CONT = 9; para encerrar o laço
            }
        }
    }

    return 0;
}
