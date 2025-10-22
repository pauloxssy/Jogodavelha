# Jogo da velha
## Descrição do projeto
Projeto proposto para a nota da segunda avaliação da disciplina de Programação 1, na Universidade Federal de Alagoas. Grupo composto pelos alunos:

Nome: Sophia Maria Vieira Galvao(Matricula: 202454071)

Nome: Bruno Rafael Severo dos Santos Silva(Matricula: 202463553)

Nome: Paulo André Menezes RochaMatricula: (xxxxxxxxx) 


## Descrição do Jogo da Velha
O jogo da velha é um jogo composto de um tabuleiro 3x3, onde dois jogadores
jogam, em turnos alternados, colocando um X (jogador 1) ou um O (jogador 2) em
alguma posição livre do tabuleiro. Caso o jogador consiga três X ou três O em sequência
(horizontal, vertical ou diagonal), este jogador se torna o vencedor da partida, caso
contrário, a partida termina em empate. O projeto final consiste na implementação de
um jogo da velha tendo um jogador humano e a máquina como oponente.




## Funcionalidades míninas
- [X] Menu de opções
    - [X] Iniciar
        - [X] Apresentar o tabuleiro vazio das 9 posições do tabuleiro
        - [X] Sortear a vez de início, para definir de forma automática quem irá iniciar jogando (humano ou máquina)
        - [X] Caso seja a vez do jogador humano, o sistema deve pedir para o usuário entrar com a posição que ele deseja jogar o ‘X’. O tabuleiro deve ser atualizado com a jogada, caso seja válida, ou pedir para o jogador inserir novamente uma nova posição, caso o valor digitado anteriormente seja inválido
        - [X] Caso seja a vez do jogador máquina, o sistema deve gerar uma posição válida, de forma aleatória, (ou, se desejar, pode implementar uma maneira mais eficaz), onde deverá ser colocado o ‘O’. O tabuleiro deve ser atualizado com a jogada.
        - [X] A cada jogada, o sistema deve verificar se algum jogador conseguiu completar a sequência e se tornou vencedor ou se os espaços em branco do tabuleiro se acabaram.
            - [X] Caso haja um vencedor, o jogo acaba e uma mensagem deve ser apresentada com o jogador que venceu
            - [X] Caso não haja mais espaços e nenhum jogador venceu, o sistema deve mostrar uma mensagem que terminou a partida em empate
            - [X] Em ambos os casos, o sistema deve voltar para o menu inicial.
    - [X] Placar
        - [X] O sistema deve mostrar um placar com a quantidade de vitórias do jogador humano, a quantidade de vitórias do jogador máquina e a quantidade de empates.
    - [ ] Sair
        - [ ]  O sistema deverá perguntar se o usuário realmente deseja sair. Caso o usuário confirme, o programa é finalizado. Caso o usuário desista, o programa volta ao menu principal.