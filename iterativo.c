#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "2048.c"

int zerMatriz(int grelha[MAX_SIZE][MAX_SIZE],int sz)
{
    for (int lin = 0; lin < sz; lin++) {
        for (int col = 0; col < sz; col++) {
            if (grelha[lin][col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

void numerosAleatorios(int grelha[MAX_SIZE][MAX_SIZE], int sz){
    if (zerMatriz(grelha,sz) == 0) return;
    int x, y;
    srand(time(NULL));

    do {
        x = rand() % sz;
        y = rand() % sz;
    } while (grelha[x][y] != 0);

    int s = rand() % 20;
    if (s > 17) grelha[x][y] = 2;
    else grelha[x][y] = 4;
}




void numerosIniciais(int grelha[MAX_SIZE][MAX_SIZE], int sz) {
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            grelha[i][j]=0;
        }
    }
    grelha[rand() % sz][rand() % sz] = (rand() > RAND_MAX/2) ? 2 : 4;
    grelha[rand() % sz][rand() % sz] = (rand() > RAND_MAX/2) ? 2 : 4;
}

void copiarGrelha(int grelha[MAX_SIZE][MAX_SIZE],int grelha2[MAX_SIZE][MAX_SIZE],int sz){
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            grelha2[i][j]=grelha[i][j];
        }
    }
}

int compararGrelha(int grelha[MAX_SIZE][MAX_SIZE],int grelha2[MAX_SIZE][MAX_SIZE],int sz){
    for (int lin = 0; lin < sz; lin++) {
        for (int col = 0; col < sz; col++) {
            if (grelha2[lin][col] != grelha[lin][col]) return 1;
        }
    }
    return 0;
}

int jogDisponiveis(int grelha[MAX_SIZE][MAX_SIZE],int sz)
{
    if (zerMatriz(grelha,sz) == 0) {
        for (int lin = 0; lin < sz ; lin++) {
            for (int col = 0; col < sz ; col++) {
                if (grelha[lin][col] == grelha[lin][col + 1] ||
                    grelha[lin][col] == grelha[lin + 1][col]) return 0;
            }
        }
    }
    else if (zerMatriz(grelha,sz) == 1) return 0;
    return 1;
}

/*int jogGanho(int grelha[MAX_SIZE][MAX_SIZE], int sz)
{
    for (int lin = 0;lin < sz ; lin++) {
        for (int col = 0; col < sz ; col++) {
            if (grelha[lin][col] == 2048) return 1;

        }
    }
    return 0;
}*/


int main() {
    srand(time(NULL));
    char caracter;
    int pontos=0;
    int grelha[MAX_SIZE][MAX_SIZE];
    int grelha2[MAX_SIZE][MAX_SIZE];

    int sz = 0;
    printf("Insira um tamanho entre 4 e %d:\n", MAX_SIZE);
    scanf("%d",&sz);

    while(sz<4 || sz>MAX_SIZE){
         printf("Insira um tamanho entre 4 e %d ", MAX_SIZE);
         scanf("%d",&sz);
    }

    numerosIniciais(grelha,sz);
    mostrar(grelha,sz);

    printf("DIGITE: ");
    scanf("%c",&caracter);
    while(toupper(caracter)!='F'){
        scanf("%c",&caracter);

        if (jogDisponiveis(grelha,sz) == 1) {
            printf("\nSEM JOGADAS DIPONIVEIS");
            break;
        }

        copiarGrelha(grelha,grelha2,sz);

        if (toupper(caracter) == 'B') {
            pontos += jogada(grelha, sz, 'B');
            numerosAleatorios(grelha,sz);
            mostrar(grelha, sz);
        }else if (toupper(caracter) == 'C') {
            pontos += jogada(grelha, sz, 'C');
            numerosAleatorios(grelha,sz);
            mostrar(grelha, sz);
        }else if (toupper(caracter) == 'D') {
            pontos += jogada(grelha, sz, 'D');
            numerosAleatorios(grelha,sz);
            mostrar(grelha, sz);
        }else if (toupper(caracter) == 'E') {
            pontos += jogada(grelha, sz, 'E');
            numerosAleatorios(grelha,sz);
            mostrar(grelha, sz);
        }else
            continue;

      /*  if (jogGanho(grelha,sz) == 1) {
            printf("\nJOGO GANHO !!");
            break;
        }*/

        if (compararGrelha(grelha,grelha2,sz) == 0)
            continue;
    }
    printf("\nPECAS COMBINADAS: %d\n", pontos);
    contagem(grelha,sz);
    return 0;

}
