
/*
 * Trabalho final LAPROI - Candy Crush
 * Professor Marco Mangan
 *
 * Desenvolvedores:
 *
 * Gustavo Francisco - guga_581@hotmail.com
 * Rodrigo Franzoi Scroferneker - rodrigo.scroferneker@gmail.com
 *
 * Data da ultima alteração: 15/06/2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <libio.h>

#include "candy.h"

#define SIZE_TAB 9
#define SIZE_RGBY 4
#define SIZE_MOVE 50
#define SIZE_PLAYS 20


int main(void)
{

    const char *const normal = "\033[0m";
    const char *const azul = "\033[0;40;46m";
    const char *const cor = "\033[0;40;44m";

    int i1, i2, j1, j2;
    char tab[SIZE_TAB][SIZE_TAB];
    char letras[SIZE_RGBY] =  {'R', 'G', 'B', 'Y'};
    char move[SIZE_MOVE];
    char name[50];
    char nada[10];
    int moveType;
    int ver;
    int ver1;
    int pont;
    int aux;
    int plays;



    srand((unsigned)time(NULL));

    pont = 0;
    ver = 1;

    while(ver != 0)
    {
        printf("\33[2J");
        system("clear");
        printf("\n");
        printf("\t\t%s   CANDY CRUSH!!   %s\n\n",azul , normal);
        printf("\n\n");
        printf("\t  %s Digite as seguintes opçoes:%s", azul, normal);
        printf("\n\n");
        printf("\t\t   %s->  START  %s \n", azul, normal);
        printf("\t\t   %s-> RANKING %s \n", azul, normal);
        printf("\t\t   %s-> RULES   %s \n", azul, normal);
        printf("\t\t   %s->  EXIT   %s \n", azul, normal);

        gets(move);
        ver =  verifyString(move, &i1, &j1, &i2, &j2, &moveType);
        if(ver == 5) //caso digitado RANKING imprime o ranking, fazendo a limpeza da tela
        {
            system("clear");
            printRanking();
            sleep(10);
            system("clear");
        }

        while (ver == 7)//caso digitado RULES imprime as regras, fazendo a limpeza da tela
        {
            system("clear");
            printRegras();
            gets(nada);
            if(!strcmp(nada, "Q"))
            {
                printf("\33[2J");
                system("clear");
                break;
            }
        }

        if (ver == 4)//caso digitado START imprime o jogo
        {
            while((ver != 0) && (ver !=6))
            {
                if(ver == 4) // caso o jogo esteja comecando
                {
                    pont=0;
                    plays=0;
                    startGame(tab, letras);
                    printf("\33[2J");
                    menu(pont, plays);
                    printTab(tab);
                    aux = 0;

                }
                printf("\33[2J");
                system("clear");
                menu(pont,plays);
                printTab(tab);
                if(aux == 1) // caso o comando nao forme uma sequencia
                {
                    printf("\n Opss! \n");
                }


                gets(move);
                if (!strcmp(move,"HOME")) // caso o jogador queira voltar para o menu
                {
                    ver=5;

                    break;
                }
                if (!strcmp(move,"EXIT"))// caso o jogador queira sair do jogo
                {
                    return 0;
                }
                ver = verifyString(move, &i1, &j1, &i2, &j2, &moveType); // verifica o tipo de jogada e o movimento

                while(ver == -1) // caso informe um movimento incorreto
                {
                    system("clear");
                    menu(pont,plays);
                    printTab(tab);
                    printf("\n Comando Incorreto! \n");
                    gets(move);
                    ver = verifyString(move, &i1, &j1, &i2, &j2, &moveType);
                    if (!strcmp(move,"HOME"))
                    {
                        ver=5;

                        break;
                    }
                    if (!strcmp(move,"EXIT"))
                    {
                        return 0;
                    }
                }
                if (!strcmp(move,"HOME"))
                {
                    ver=5;

                    break;
                }
                if (!strcmp(move,"EXIT"))
                {
                    return 0;
                }
                swap1(tab, i1, j1, i2, j2); // troca os doces
                system("clear");
                menu(pont,plays);
                printTab(tab);
                sleep(1);
                system("clear");
                ver1 = createX(tab, &pont); // verifica se foi um valor valido
                if (ver1 == 0) // caso nao seja um valor valido os doces voltam para a posicao inicial
                {
                    system("clear");
                    swap1(tab, i1, j1, i2, j2);
                    menu(pont,plays);
                    printTab(tab);
                    aux = 1;
                }
                else
                {
                    aux = 0;
                }
                if(ver1 == 1) // se foi uma jogada valida
                {
                    plays+=1; // conta jogadas
                    while(ver1 != 0) // verifica ate que nao haja doces em sequencia
                    {
                        menu(pont,plays);
                        printTab(tab);
                        cai(tab);
                        sleep(1);
                        system("clear");
                        menu(pont,plays);
                        printTab(tab);
                        sleep(1);
                        system("clear");
                        Aleatorizar(tab);
                        menu(pont,plays);
                        printTab(tab);
                        sleep(1);
                        ver1 = createX(tab, &pont);
                        system("clear");

                    }
                }


                menu(pont,plays);
                printTab(tab);


                if(plays>=SIZE_PLAYS) // caso atinja o limite de jogadas
                {
                    system("clear");
                    printf("%sAcabou o seu numero de jogadas!\nEscreva o nome do campeao:%s ", cor, normal);
                    scanf("%s", name);
                    trocaArquivo(pont, name);
                    sleep(1);
                    system("clear");
                    printRanking();
                    sleep(10);

                    break;
                }

            }
            system("clear");

        }
        system("clear");
    }




    return 0; //FIMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
}
