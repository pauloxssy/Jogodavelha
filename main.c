#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Nome: Sophia Maria Vieira Galvao(Matricula: 202454071) */   
/* Nome: Bruno Rafael Severo dos Santos Silva(Matricula: xxxxxxxxx) */
/* Nome: Paulo André Menezes RochaMatricula: xxxxxxxxx) */



//Variávei Globais

char tabuleiro[3][3];
int placar_jogador1 = 0;
int placar_maquina = 0;
int placar_jogador2 = 0;
int opcao; //Vai ser a variável do menu;

int Cara_Coroa(){
    
    return rand() % 2;
}

void CriandoTabuleiro(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            tabuleiro[i][j] = '_';
        }
    }

}

void ImprimindoTabuleiro() {
    printf("\n");
    for(int i=0; i<3; i++){
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if(i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

void Jogador1(){

    int i, j;
        
        do{
            printf("Jogador 1 digite a posicao (linha de 0-2 e coluna de 0-2: ");
            scanf("%d %d", &i, &j);
            
            if (tabuleiro[i][j] == 'X' || tabuleiro[i][j] == 'O'){
            
            printf("Este espaco ja esta preenchido!\n");
            }

        }

        while(i < 0 || i > 2 || j < 0 || j > 2 || tabuleiro[i][j] != '_');

            tabuleiro[i][j] = 'X';
            
        
        
    

}

void Jogador2(){

    int i, j;

    do{
        printf("Jogador 2 digite a posicao (linha de 0-2 e coluna de 0-2: ");
        scanf("%d %d", &i, &j);
        if (tabuleiro[i][j] == 'X' || tabuleiro[i][j] == 'O'){
            
            printf("Este espaco ja esta preenchido!\n");
            }

    } while(i < 0 || i > 2 || j < 0 || j > 2 || tabuleiro[i][j] != '_');

        tabuleiro[i][j] = 'O';

}

void Maquina(){

    int i, j;

    do{
        i = rand() % 3;
        j = rand() % 3;

    } while(tabuleiro[i][j] != '_');

        printf("Maquina jogou: %d %d\n", i, j);
        tabuleiro[i][j] = 'O';

}

char Resultado(){

    for(int i=0; i<3; i++){

        if((tabuleiro[i][0] == tabuleiro[i][1]) && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != '_'){
            return tabuleiro[i][0];
        }

        if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != '_'){
            return tabuleiro[0][i];
        }

        if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0]!='_'){

            return tabuleiro[0][0];
        }

        if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2]!='_'){

            return tabuleiro[0][2];
        }

    }

    return ' '; // Ainda não há vencedor. Deixar o return fora do for para reconhecer os casos em que a máquina venceu.

}


int main(){

    srand(time(0));

    CriandoTabuleiro();
    ImprimindoTabuleiro();

    //opcoes de menu:
    //1- Iniciar Jogo(Jogador 1 x Maquina);
    //2 - Modo 2 Jogadores;
    //Placar (Jogador 1, Jogador 2 e Máquina);
    //Sair(Iremos usar o comando exit());

 //Antes de Iniciar o Jogo(Seja na opcao 1 ou na opcao 2) devemos sortear quem vai começar;

    char ganhador = ' ';
    
    printf("Fazendo o sorteio (cara ou coroa)...\n");
    int moeda = Cara_Coroa();
    
    if (moeda == 0){
        
        printf("Cara! O Jogador 1 comeca!\n");
        
        for (int t = 0; t < 9 && ganhador == ' '; t++){

            if(t % 2 == 0){

                Jogador1(); } else{ Maquina();

            }

            ImprimindoTabuleiro();
            ganhador = Resultado();

        }
        
        
        if(ganhador == 'X'){
            printf("Parabens! Voce venceu!\n");
            placar_jogador1 ++;
        }
        if(ganhador == 'O'){
            printf("Maquina venceu!\n");
            placar_maquina ++;
        }
        else{
            printf("Empate!\n");
        }
    
    } else{
        
        printf("Coroa! A Maquina começa!\n");
        for (int t = 1; t < 10 && ganhador == ' '; t++){

            if(t % 2 != 0){
                
                Maquina();
                

            }

            else{

                Jogador1();

            }

            ImprimindoTabuleiro();
            ganhador = Resultado();
        
        }
        
        if(ganhador == 'X'){
            printf("Parabens! Voce venceu!\n");
            placar_jogador1 ++;
        }
        if(ganhador == 'O'){
            printf("Maquina venceu!\n");
            placar_maquina ++;
        }
        else{
            printf("Empate!\n");
        }
        
    }

    system("pause");
    return 0;

}
