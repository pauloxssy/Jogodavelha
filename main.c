#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "cores.h"

/* Nome: Sophia Maria Vieira Galvao(Matricula: 202454071) */   
/* Nome: Bruno Rafael Severo dos Santos Silva(Matricula: 202463553) */
/* Nome: Paulo André Menezes Rocha (Matricula: 202454160) */

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

void Pikachu(){
    int i, j;

    do{
        i = rand() % 3;
        j = rand() % 3;

    } while(tabuleiro[i][j] != '_');
        printf(YELLOW"Pikachu atacou na posicao: %d %d\n"RESET, i, j);
        tabuleiro[i][j] = 'P';
        

}

void Charmander(){
    int i, j;

    do{
        i = rand() % 3;
        j = rand() % 3;

    } while(tabuleiro[i][j] != '_');
        printf(RED"Charmander atacou na posicao: %d %d\n"RESET, i, j);
        tabuleiro[i][j] = 'C';

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
printf(MAGENTA"\t\t4 - Rinha Pokemon (Treinador(a) X Rival)\n"RESET);
printf(MAGENTA"\t\t5 - Lucros e Percas das Rinhas (Treinador(a) X Rival)\n"RESET);
printf(MAGENTA"\t\t6 - Sair\n"RESET);
printf(BLUE"\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"RESET);

}

int main(){
    int opcao, moeda = Cara_Coroa(),placar_j1 = 0, placar_cpu = 0, placar_j2 = 0, placar_empt_j1_cpu = 0, placar_empt_j1_j2 = 0; 
    char sair = 'N', ganhador = ' ', lucro_mon_ganho_t = 0, lucro_mon_perdido_t = 0, lucro_mon_ganho_r = 0, lucro_mon_perdido_r = 0;
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
            printf(BLUE"Ola treinador(a)! O seu pokemon para a rinha ser o Pikachu e o do seu rival sera o Charmander.\n"RESET);
            printf(BLUE"Quem ganha recebe R$10 reais. Quem perder perde 10. E caso der empate, ambos ganham R$5 reais\n"RESET);

            CriandoTabuleiro();
            sleep(1);
            ImprimindoTabuleiro();
            sleep(1);
            printf(BLUE"Lancando a moeda pokemon para sortear(Treinador(a) = cara e Rival = coroa)...\n"RESET);

            if (moeda == 0){
                printf(YELLOW"Cara! O Treeinador(a) comeca!\n"RESET);
                sleep(1);
                for (int t = 0; t < 9 && ganhador == ' '; t++){

                    if(t % 2 == 0){
                        Pikachu();
                        sleep(1); 
                    } 
                    else{ 
                        Charmander();
                        sleep(1);
                    }

                    ImprimindoTabuleiro();
                    sleep(1);
                    ganhador = Resultado();
                    sleep(1);

                }
            }

            else{
                    printf(RED"Coroa! O Rival comeca!\n"RESET);
                    sleep(1);
                    for (int t = 1; t < 10 && ganhador == ' '; t++){

                        if(t % 2 != 0){
                            Charmander();
                            sleep(1);
                        }
                        else{
                            Pikachu();
                            sleep(1);
                        }

                        ImprimindoTabuleiro();
                        sleep(1);
                        ganhador = Resultado();
                        sleep(1);
        
                    }

            }

            //Verificando resultado Treinador X Rival
            if(ganhador == 'P'){
                    sleep(1);
                    printf(YELLOW"Pikachu ganhou a rinha! Voce ganhou R$10 reais.\n"RESET);
                    sleep(1);
                    lucro_mon_ganho_t = lucro_mon_ganho_t + 10;
                    sleep(1);
                    lucro_mon_perdido_r = lucro_mon_perdido_r + 10;
                    sleep(1);
            }
            if(ganhador == 'C'){
                    sleep(1);
                    printf(RED"Rival venceu! Voce perdeu R$10 reais\n"RESET);
                    sleep(1);
                    lucro_mon_perdido_t = lucro_mon_perdido_t + 10;
                    sleep(1);
                    lucro_mon_ganho_r = lucro_mon_ganho_r + 10;
                    sleep(1);
            }
            if(ganhador != 'P' && ganhador != 'C' && ganhador != ' '){
                sleep(1);
                printf(WHITE"Empate! Ambos vao ganhar R$5 reais.\n"RESET);
                sleep(1);
                lucro_mon_ganho_t = lucro_mon_ganho_t + 5;
                sleep(1);
                lucro_mon_ganho_r = lucro_mon_ganho_r + 5;
                sleep(1);

            }
            
            

        }//opcao 4

        else if(opcao == 5){
            printf(WHITE"Lucros e Percas das Rinhas:\n"RESET);
            printf(YELLOW"Treinador(a) ganhou: R$%d reais\n"RESET, lucro_mon_ganho_t);
            printf(YELLOW"Treinador(a) perdeu: R$%d reias\n"RESET, lucro_mon_perdido_t);
            printf(RED"Rival ganhou: R$%d\n"RESET, lucro_mon_ganho_r);
            printf(RED"Rival perdeu: %d\n"RESET, lucro_mon_perdido_r);

        }//opcao 5


        else if(opcao == 6){
            printf(YELLOW"Voce quer realmente sair?:"RESET);
            scanf(" %c", &sair);

            if(sair == 'S' || sair == 's'){
                printf(BLUE"Fim do programa :(\n"RESET);
                break;
            }

        }//opcao 6

        else{
            printf(RED"Nao tem essa opcao. Por favor digite novamente.\n\n"RESET);
        }



    }//fim do while


    system("pause");
    return 0;

}
