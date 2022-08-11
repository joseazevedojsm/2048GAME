#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include "2048.c"


int main() {

    int grelha[MAX_SIZE][MAX_SIZE], tamanho = 0, i = 0,l=0, pontos=0;
    char num[50], tam[50],com[100],comandos[100];
    FILE *file = fopen("grelha.txt", "r"); // windows (..//)

    fscanf(file, "%s", tam);
    tamanho = atoi(tam);
    for (int i = 0; i < tamanho; ++i) {
        for (int k = 0; k < tamanho; ++k) {
            fscanf(file, "%s", num);
            grelha[i][k] = atoi(num);
        }
    }

    while (fscanf(file, "%s", com) != -1){
        strcpy(&comandos[i],com);
        i++;
    }

    fclose(file);

   /* for (int i=0; i<4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d  ", grelha[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //printf("%s", comandos);
    //printf("\n");
    //printf("\n");
    */

    while (l<i){
        if (toupper(comandos[l]) == 'B') {
            pontos += jogada(grelha, tamanho, 'B');
           // mostrar(grelha, tamanho);
        }else if (toupper(comandos[l]) == 'C') {
            pontos += jogada(grelha, tamanho, 'C');
            //mostrar(grelha, tamanho);
        }else if (toupper(comandos[l]) == 'D') {
            pontos += jogada(grelha, tamanho, 'D');
            //mostrar(grelha, tamanho);
        }else if (toupper(comandos[l]) == 'E') {
            pontos += jogada(grelha, tamanho, 'E');
            //mostrar(grelha, tamanho);
        }else
            continue;
        l++;
    }
    printf("\nPECAS COMBINADAS: %d\n", pontos);
    contagem(grelha,tamanho);
}