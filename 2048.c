//
// Created by JSM on 11/01/2020.
//

#define MAX_SIZE 10

int baixo(int grelha[MAX_SIZE][MAX_SIZE], int sz);

int cima(int grelha[MAX_SIZE][MAX_SIZE], int sz);

int direita(int grelha[MAX_SIZE][MAX_SIZE], int sz);

int esquerda(int grelha[MAX_SIZE][MAX_SIZE], int sz);

int jogada(int grelha[MAX_SIZE][MAX_SIZE], int sz, char sentido);

void mostrar(int grelha[MAX_SIZE][MAX_SIZE], int sz);

void contagem(int grelha[MAX_SIZE][MAX_SIZE], int sz);


int cima(int grelha[MAX_SIZE][MAX_SIZE], int sz){
    int pontos =0;
    for(int i=0;i<=sz-1;i++) {
        int lin = -1;
        for (int y = 0; y < sz; y++) {
            if (grelha[y][i] == 0)
                continue;
            if (lin == -1)
            {
                lin = y; //GUARDAR COLUNA
                continue;
            }
            if (grelha[lin][i] != grelha[y][i])
            {
                lin = y; // GUARDAR COLUNA
                continue;
            }
            if (grelha[lin][i] == grelha[y][i])
            {
                grelha[lin][i] += grelha[y][i]; // JUNTAR OS MESMOS NUMEROS
                pontos+=1;
                grelha[y][i] = 0;
                lin = -1; // RESETAR
            }
        }
        // MOVER OS NUMEROS
        for (int k = 0; k < sz*sz; k++) {
            int y = k % sz;
            if (y == sz - 1)
                continue;
            if (grelha[y][i] == 0 && grelha[y+1][i] != 0) // SE O ESTE ESTA VAZIO E O PROXIMO NAO
            {
                grelha[y][i] = grelha[y+1][i]; // MUDAR O PROXIMO PARA  ATUAL
                grelha[y+1][i] = 0;
            }
        }
    }
    return pontos;
}

int baixo(int grelha[MAX_SIZE][MAX_SIZE], int sz) {
    int pontos=0;
    for(int i=0;i<sz;i++) {
        int lin = -1;
        for (int y = sz-1 ; y >=0; y--) {
            if (grelha[y][i] == 0)
                continue;
            if (lin == -1) {
                lin = y; // GUARDAR COLUNA
                continue;
            }
            if (grelha[lin][i] != grelha[y][i]) {
                lin = y; // GUARDAR COLUNA
                continue;
            }
            if (grelha[lin][i] == grelha[y][i]) {
                grelha[lin][i] += grelha[y][i]; // JUNTAR OS MESMOS NUMEROS
                pontos += 1;
                grelha[y][i] = 0;
                lin = -1; // reset
            }
        }

        // MOVER OS NUMEROS
        for (int k = sz*sz-1; k >= 0; k--) {
            int y = k % sz;
            if (y==0)
                continue;
            if (grelha[y][i] == 0 && grelha[y-1][i] != 0) // SE O ESTE ESTA VAZIO E O ANTERIOR NAO
            {
                grelha[y][i] = grelha[y-1][i]; // MUDAR O ANTERIOR PARA  ATUAL
                grelha[y-1][i] = 0;
            }
        }
    }
    return pontos;
}

int direita(int grelha[MAX_SIZE][MAX_SIZE], int sz) {
    int pontos=0;
    for(int i=0;i<=sz-1;i++) {
        int col = -1;
        for (int y = sz - 1; y >= 0; y--){
            if (grelha[i][y] == 0)
                continue;
            if (col == -1)
            {
                col = y; // GUARDAR COLUNA
                continue;
            }
            if (grelha[i][col] != grelha[i][y])
            {
                col = y; // GUARDAR COLUNA
                continue;
            }
            if (grelha[i][col] == grelha[i][y])
            {
                grelha[i][col] += grelha[i][y]; // JUNTAR OS MESMOS NUMEROS
                pontos+=1;
                grelha[i][y] = 0;
                col = -1; // reset
            }
        }
        // MOVER OS NUMEROS
        for (int k = sz * sz - 1; k >= 0; k--)
        {
            int y = k % sz;

            if (y == 0) continue;
            if (grelha[i][y] == 0 && grelha[i][y - 1] != 0) // SE O ESTE ESTA VAZIO E O ANTERIOR NAO
            {
                grelha[i][y] = grelha[i][y - 1]; // MUDAR O ANTERIOR PARA  ATUAL
                grelha[i][y - 1] = 0;
            }
        }
    }
    return pontos;
}

int esquerda(int grelha[MAX_SIZE][MAX_SIZE], int sz){
    int pontos=0;

    for(int i=0;i<sz;i++) {
        int col = -1;
        for (int y = 0; y < sz; y++) {
            if (grelha[i][y] == 0)
                continue;
            if (col == -1) {
                col = y; // GUARDAR COLUNA
                continue;
            }
            if (grelha[i][col] != grelha[i][y]) {
                col = y; // GUARGAR COLUNA
                continue;
            }
            if (grelha[i][col] == grelha[i][y]) {
                grelha[i][col] += grelha[i][y]; // JUNTAR OS MESMOS NUMEROS
                pontos += 1;
                grelha[i][y] = 0;
                col = -1; // RESETAR
            }
        }

        // MOVER OS NUMEROS
        for (int k = 0; k < sz*sz; k++) {
            int y = k % sz;
            if (y == sz - 1)
                continue;
            if (grelha[i][y] == 0 && grelha[i][y + 1] != 0) // SE O ESTE ESTA VAZIO E O PROXIMO NAO
            {
                grelha[i][y] = grelha[i][y + 1]; // MUDAR O PROXIMO PARA  ATUAL
                grelha[i][y + 1] = 0;
            }
        }
    }
    return pontos;
}

int jogada(int grelha[MAX_SIZE][MAX_SIZE], int sz, char sentido){
    int pontos=0;
    if(sentido=='C'){
        pontos=cima(grelha,sz);
    } else if(sentido=='B'){
        pontos=baixo(grelha, sz);
    } else if(sentido=='D'){
        pontos=direita(grelha,sz);
    } else if (sentido=='E'){
        pontos=esquerda(grelha,sz);
    }
    return pontos;

}

void mostrar (int grelha[MAX_SIZE][MAX_SIZE], int sz){

    printf("--------------------------\n");
    for (int j = 0; j < sz; ++j) {
        printf("|");
        for (int i = 0; i < sz; ++i) {
            if (grelha[j][i]!=0)
                printf("%4d  ", grelha[j][i]);
            else
                printf("      ");
        }
        printf("|\n");
    }
    printf("--------------------------\n");
}

void contagem(int grelha[MAX_SIZE][MAX_SIZE], int sz){

//----------------CONVERTER A MATRIZ EM VETOR
    int vetor[sz*sz];
    int indice =0, aux =0;
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            vetor[indice]=grelha[i][j];
            indice++;
        }
    }
//-----------------ORDEM CRESCENTE
    for(int i=0;i<sz*sz;i++){
        for(int j=i+1;j<sz*sz;j++){
            if(vetor[i]>vetor[j]){
                aux=vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=aux;
            }
        }
    }
//-------------------CONTADOR
    printf("CONTAGEM: ");
    int cont = 1; //Se está na lista então aparece pelo menos 1 vez
    for(int i=1; i<sz*sz; i++){ //Começa com i=1 para já comparar o segundo com o primeiro no if abaixo:
        if(vetor[i] == vetor[i-1] && vetor[i]!=0){ //Se é igual ao anterior incrementa o contador
            cont++;
        } else if (vetor[i]==0) {
            cont=0;
        }
        else {
            //o número de vezes que ele aparece:
            printf("%d ", cont);

            //Recomeça a contagem para o novo número:
            cont = 1;
        }
    }
    //Também imprime para o último número:
    printf("%d\n", cont);
}
