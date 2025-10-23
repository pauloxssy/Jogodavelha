#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cores.h"

/* Nome: Sophia Maria Vieira Galvao(Matricula: 202454071) */   
/* Nome: Bruno Rafael Severo dos Santos Silva(Matricula: 202463553) */
/* Nome: Paulo André Menezes RochaMatricula: xxxxxxxxx) */

/*Foi utilizado além do codeblocks o Visual Studio Code, Git, Github, Github Desktop e Google Docs(para salvar copias do codigo por questoes de seguranca reforcada)*/

//Variávei Globais
char tabuleiro[3][3];


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
        printf(WHITE" %c | %c | %c \n"RESET, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if(i < 2) printf(WHITE"---|---|---\n"RESET);
    }
    printf("\n");
}

void Jogador1(){
    int i, j;
        
        do{
            printf(CYAN"Jogador 1 digite a posicao (linha de 0-2 e coluna de 0-2): "RESET);
            scanf("%d %d", &i, &j);
            
            if (tabuleiro[i][j] == 'X' || tabuleiro[i][j] == 'O'){
                printf(RED"Este espaco ja esta preenchido!\n"RESET);
            }
            if(i > 2 || j > 2 || i < 0 || j < 0){
                printf(RED"Nao tem essa posicao!\n"RESET);
            }

        } while(i < 0 || i > 2 || j < 0 || j > 2 || tabuleiro[i][j] != '_');
            tabuleiro[i][j] = 'X';
            
}

void Jogador2(){
    int i, j;

    do{
        printf(GREEN"Jogador 2 digite a posicao (linha de 0-2 e coluna de 0-2): "RESET);
        scanf("%d %d", &i, &j);

        if (tabuleiro[i][j] == 'X' || tabuleiro[i][j] == 'O'){
            printf(RED"Este espaco ja esta preenchido!\n"RESET);
        }
        if(i > 2 || j > 2 || i < 0 || j < 0){
                printf(RED"Nao tem essa posicao!\n"RESET);
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
        printf(GREEN"Maquina jogou: %d %d\n"RESET, i, j);
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

void Texto_Menu(){
printf(GREEN"\t\t*******************************\n"RESET);
printf(YELLOW"\t\t\tJogo da Velha\n"RESET);
printf(GREEN"\t\t*******************************\n"RESET);

printf(BLUE"\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"RESET);
printf(MAGENTA"\t\t1- Iniciar Jogo(Jogador 1 x Maquina)\n"RESET);
printf(MAGENTA"\t\t2 - Modo 2 Jogadores\n"RESET);
printf(MAGENTA"\t\t3 - Placar\n"RESET);
printf(MAGENTA"\t\t4 - Sair\n"RESET);
printf(BLUE"\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"RESET);

}

int main(){
    int opcao, moeda = Cara_Coroa(),placar_j1 = 0, placar_cpu = 0, placar_j2 = 0, placar_empt_j1_cpu = 0, placar_empt_j1_j2 = 0; 
    char sair = 'N', ganhador = ' ';
    srand(time(0));

    while(sair == 'N' || sair == 'n'){
        Texto_Menu();
        printf(YELLOW"Digite a sua opcao: "RESET);
        scanf("%d", &opcao);

        if(opcao == 1 ){
            CriandoTabuleiro();
            ImprimindoTabuleiro();
            printf(YELLOW"Lancando a moeda para sortear(Jogador 1 = cara e Maquina = coroa)...\n"RESET);
    
            if (moeda == 0){
                printf(CYAN"Cara! O Jogador 1 comeca!\n"RESET);
        
                for (int t = 0; t < 9 && ganhador == ' '; t++){

                    if(t % 2 == 0){
                        Jogador1(); 
                    } 
                    else{ 
                        Maquina();
                    }

                    ImprimindoTabuleiro();
                    ganhador = Resultado();

                }
    
            }//cara 
            else{
                    printf(GREEN"Coroa! A Maquina comeca!\n"RESET);
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

            }//coroa

            //Verificando resultado J1 X CPU
            if(ganhador == 'X'){
                    printf(CYAN"Parabens! Voce venceu!\n"RESET);
                    placar_j1 ++;
            }
            if(ganhador == 'O'){
                    printf(GREEN"Maquina venceu!\n"RESET);
                    placar_cpu ++;
            }
            if(ganhador != 'X' && ganhador != 'O' && ganhador != ' '){
                printf(WHITE"Empate!\n"RESET);
                placar_empt_j1_cpu ++;

            }

        }//opcao 1

        else if(opcao == 2 ){
            CriandoTabuleiro();
            ImprimindoTabuleiro();
            printf(YELLOW"Lancando a moeda para sortear(Jogador 1 = cara e Jogador 2 = coroa)...\n"RESET);

            if (moeda == 0){
                printf(CYAN"Cara! O Jogador 1 comeca!\n"RESET);
        
                for (int t = 0; t < 9 && ganhador == ' '; t++){

                    if(t % 2 == 0){
                        Jogador1(); 
                    } 
                    else{ 
                        Jogador2();
                    }

                    ImprimindoTabuleiro();
                    ganhador = Resultado();

                }
    
            }//cara 
            else{
                    printf(GREEN"Coroa! Jogador 2 comeca!\n"RESET);
                    for (int t = 1; t < 10 && ganhador == ' '; t++){

                        if(t % 2 != 0){
                            Jogador2();
                        }
                        else{
                            Jogador1();
                        }

                        ImprimindoTabuleiro();
                        ganhador = Resultado();
        
                    }

            }//coroa

            //Verificando resultado J1 X J2
            if(ganhador == 'X'){
                    printf(CYAN"Parabens! Jogador 1 venceu!\n"RESET);
                    placar_j1 ++;
            }
            if(ganhador == 'O'){
                    printf(GREEN"Parabens! Jogador 2 venceu!\n"RESET);
                    placar_j2 ++;
            }
            if(ganhador != 'X' && ganhador != 'O' && ganhador != ' '){
                printf(WHITE"Empate!\n"RESET);
                placar_empt_j1_j2 ++;
            }

        }//opcao 2

        else if(opcao == 3){
            printf(YELLOW"Placar:\n"RESET);
            printf(CYAN"Jogador 1: %d\n"RESET, placar_j1);
            printf(MAGENTA"Maquina: %d\n"RESET, placar_cpu);
            printf(WHITE"Empate (Jogador 1 X Jogador 2): %d\n"RESET, placar_empt_j1_cpu);
            printf(RED"Jogador 2: %d\n"RESET, placar_j2);
            printf(WHITE"Empate (Jogador 1 X Jogador 2): %d\n"RESET, placar_empt_j1_j2);
            
        }//opcao 3

        else if(opcao == 4){
            printf(YELLOW"Voce quer realmente sair?:"RESET);
            scanf(" %c", &sair);

            if(sair == 'S' || sair == 's'){
                printf(BLUE"Fim do programa :(\n"RESET);
                break;
            }

        }//opcao 4

        else{
            printf(RED"Nao tem essa opcao. Por favor digite novamente.\n\n"RESET);
        }



    }//fim do while

    

    

    //opcoes de menu:
    //1- Iniciar Jogo(Jogador 1 x Maquina);
    //2 - Modo 2 Jogadores;
    //3 - Placar (Jogador 1, Jogador 2 e Máquina);
    //4 - Sair(Iremos usar o comando exit());

 //Antes de Iniciar o Jogo(Seja na opcao 1 ou na opcao 2) devemos sortear quem vai começar;

    
        
    

    system("pause");
    return 0;

}
