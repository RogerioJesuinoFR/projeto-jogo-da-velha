#include<stdio.h>



char MAT[3][3];

void INICIALIZA_MATRIZ()
{
    int L, C;
    for(L=0;L<3;L++)
        for(C=0;C<3;C++)
            MAT[L][C]='-';
}

//-----------------------------------
void IMPRIMIR()
{
    int L, C;
    printf("\nJogo da Velha\n\n");
    for(L=0;L<3;L++)
    {
        for(C=0;C<3;C++)
            printf("%c\t",MAT[L][C]);
        printf("\n");
    }
}
//-----------------------------------

//-----------------------------------
void JOGADA(char JOGADOR)
{
    int LINHA, COLUNA;
    do
    {
        do
        {
            printf("Digite a linha que deseja\n");
            scanf("%d", &LINHA);
            if((LINHA < 0)||(LINHA>2))
                printf("Posicao invalida. Informe novamente\n");
        }while((LINHA < 0)||(LINHA>2));
        do
        {
            printf("Digite a coluna que deseja\n");
            scanf("%d", &COLUNA);
            if((COLUNA < 0)||(COLUNA>2))
                printf("Posicao invalida. Informe novamente\n");
        }while((COLUNA < 0)||(COLUNA>2));
        if(MAT[LINHA][COLUNA]!= '-')
            printf("Esta posicao esta ocupada. Digite novamente\n\n");
    }while(MAT[LINHA][COLUNA]!= '-');
    MAT[LINHA][COLUNA]= JOGADOR;
 }
 //-----------------------------------
 int VERIFICA_JOGADA(char JOGADOR)
 {
     int L, C, GANHOU;
     //printf("verifica ganhador na linha\n");
     for(L=0;L<3;L++)
     {
        GANHOU=0;
        for(C=0;C<3;C++)
        {
            if(MAT[L][C]==JOGADOR)
            {
                GANHOU++;
            }
        }
        if(GANHOU == 3)
            break;
    }
    if(GANHOU== 3)
    {
          return 1;//1 ganhou
    }
    //printf("verifica ganhador na coluna\n");
    for(C=0;C<3;C++)
     {
        GANHOU=0;
        for(L=0;L<3;L++)
        {
            if(MAT[L][C]==JOGADOR)
            {
                GANHOU++;
            }
        }
        if(GANHOU == 3)
            break;
    }
    if(GANHOU== 3)
    {
          return 1;//1 ganhou
    }
    //printf("verifica ganhador na diagonal principal\n");
    GANHOU=0;
    for(L=0;L<3;L++)
    {
        for(C=0;C<3;C++)
        {
            if((L == C )&&(MAT[L][C]==JOGADOR))
            {
                GANHOU++;
            }
        }
    }
    if(GANHOU== 3)
    {
          return 1;//1 ganhou
    }
    //printf("verifica ganhador na diagonal secundaria\n");
    GANHOU=0;
    for(L=0;L<3;L++)
    {
        for(C=0;C<3;C++)
        {
            if((L + C == 2 )&&(MAT[L][C]==JOGADOR))
            {
                GANHOU++;
            }
        }
    }
    if(GANHOU== 3)
    {
          return 1;//1 ganhou
    }
    return 0; //não ganhou em nenhuma situacao
 }
//-----------------------------------
int main()
{
    char JOGADOR;
    int CONT=0;
    INICIALIZA_MATRIZ();
    IMPRIMIR();
    while(CONT<9)
    {
        if(CONT % 2 == 0)
            JOGADOR = 'O';
        else
            JOGADOR = 'X';
        JOGADA(JOGADOR);
        IMPRIMIR();
        CONT++;
        if(CONT >4)
            if (VERIFICA_JOGADA(JOGADOR)==1)
            {
                printf("Jogador %c ganhou!\n",JOGADOR);
                CONT=9;//para encerrar o laço
            }
    }
    return 0;
}