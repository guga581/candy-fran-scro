
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
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <libio.h>

#include "../include/candy.h"


void printRegras(void) //procedimento para imprimir as regras
{
    printf("\33[2J");
    system("clear");
    int x;
    x=0;
    const char *const normal = "\033[0m";
    const char *const cor = "\033[0;32;40m";
    const char *const blue = "\033[0;40;35m";
    FILE *regras;

    regras = fopen("rules.txt", "r");

    char regras1[10000];
    while(fgets(regras1, 10000, regras) != NULL)
    {
        if (x==6)
        {
            printf("%s%s%s", blue, regras1, normal);

        }
        else
        {


        printf("%s%s%s", cor, regras1, normal);
        x+=1;
        }
    }

}

void printRanking(void) //procedimento para imprimir o ranking
{
    const char *const normal = "\033[0m";
    const char *const cor = "\033[0;40;44m";

    FILE *primeiro, *segundo, *terceiro, *quarto, *quinto, *p1, *p2, *p3, *p4, *p5;

    int pont1;
    int pont2;
    int pont3;
    int pont4;
    int pont5;

    char pri[100];
    char seg[100];
    char ter[100];
    char qua[100];
    char qui[100];

    p1 = fopen("../ranking/p1.txt", "r");
    p2 = fopen("../ranking/p2.txt", "r");
    p3 = fopen("../ranking/p3.txt", "r");
    p4 = fopen("../ranking/p4.txt", "r");
    p5 = fopen("../ranking/p5.txt", "r");

    primeiro = fopen("../ranking/primeiro.txt", "r");
    segundo = fopen("../ranking/segundo.txt", "r");
    terceiro = fopen("../ranking/terceiro.txt", "r");
    quarto = fopen("../ranking/quarto.txt", "r");
    quinto = fopen("../ranking/quinto.txt", "r");

    while(fgets(pri, 100, primeiro) != NULL)
    while(fgets(seg, 100, segundo) != NULL)
    while(fgets(ter, 100, terceiro) != NULL)
    while(fgets(qua, 100, quarto) != NULL)
    while(fgets(qui, 100, quinto) != NULL)

    fscanf(p1, "%d", &pont1);
    fscanf(p2, "%d", &pont2);
    fscanf(p3, "%d", &pont3);
    fscanf(p4, "%d", &pont4);
    fscanf(p5, "%d", &pont5);

    printf("\t\t %s RANKING %s\n\n\n", cor, normal);
    printf("\t\t%s 1 - %d\t%s%s \n\n", cor, pont1, pri, normal);
    printf("\t\t%s 2 - %d\t%s%s \n\n", cor, pont2, seg, normal);
    printf("\t\t%s 3 - %d\t%s%s \n\n", cor, pont3, ter, normal);
    printf("\t\t%s 4 - %d\t%s%s \n\n", cor, pont4, qua, normal);
    printf("\t\t%s 5 - %d\t%s%s \n\n", cor, pont5, qui, normal);

    fclose(p1);
    fclose(p2);
    fclose(p3);
    fclose(p4);
    fclose(p5);

    fclose(primeiro);
    fclose(segundo);
    fclose(terceiro);
    fclose(quarto);
    fclose(quinto);



}

void menu(int pont, int plays) //procedimento para imprimir o cabecalho do jogo
{

    const char *const normal = "\033[0m";
    const char *const azul = "\033[0;40;46m";


    printf("\n");
    printf("\t\t%s   CANDY CRUSH!!   %s\n\n",azul , normal);
    printf("\t SCORE: %d\t JOGADAS RESTANTES: %d %s\t%s HOME %s\t%s EXIT %s\n", pont , SIZE_PLAYS-plays, normal, azul, normal, azul, normal);
}

void startGame(char tab[SIZE_TAB][SIZE_TAB], char letras[]) //procedimento que inicializa o tabuleiro com doces aleatorios
{
    int pont;
    int i,j;
    int x;
    pont = 0;
    for (i = 0; i<SIZE_TAB; i++)
    {
        for (j = 0; j<SIZE_TAB; j++)
        {
            x = rand() % 4;
            tab[i][j]= letras[x];
        }

    }
    x = 1;

    while(x!=0)
    {
        x = createX(tab, &pont);
        cai(tab);
        Aleatorizar(tab);
        printf("\33[2J");
    }
    printf("\33[2J");

}

void printTab(char Matriz[SIZE_TAB][SIZE_TAB])  //procedimento para imprimir o tabuleiro
{
    const char *const green = "\033[0;40;32m";
    const char *const yellow = "\033[0;40;33m";
    const char *const red = "\033[0;40;31m";
    const char *const blue = "\033[0;40;35m";
    const char *const normal = "\033[0m";
    const char *const azul = "\033[0;40;36m";
    int i,j;
    printf("\n    0 1 2 3 4 5 6 7 8  \n\n");
    for (i = 0; i<SIZE_TAB; i++)
    {
        printf("%d  ", i);
        for (j = 0; j<SIZE_TAB; j++)
        {
            if (Matriz[i][j]=='G')
                printf(" %s%c%s",green,Matriz[i][j],normal);
            if (Matriz[i][j]=='Y')
                printf(" %s%c%s",yellow,Matriz[i][j],normal);
            if (Matriz[i][j]=='R')
                printf(" %s%c%s",red,Matriz[i][j],normal);
            if (Matriz[i][j]=='B')
                printf(" %s%c%s",blue,Matriz[i][j],normal);
            if (Matriz[i][j]=='X')
                printf(" %s%c%s",azul,Matriz[i][j],normal);
        }
        printf("  %d", i);
        printf("\n");

    }
    printf("\n    0 1 2 3 4 5 6 7 8  \n");
}

void swap1(char tab[SIZE_TAB][SIZE_TAB],int i1,int j1,int i2,int j2)//procedimento para trocar as prosiçoes dos doces
{
    char aux;
    aux = tab[i1][j1];
    tab[i1][j1] = tab[i2][j2];
    tab[i2][j2] = aux;
}
int verifyString(char move[], int *i1,int *j1,int *i2,int *j2,int *moveType) //funçao generica para ler um comando e verificar se ele é valido e que tipo de comando é vide explicaçao abaixo
{
    /*
    -1 = Erro de digitacao
    0 = Sair do jogo
    1 = Salvar jogo NAO TERA MAIS SAVE GAME
    2 = Sair e salvar NAO TERA MAIS SAVE GAME
    3 = Todas variaveis estao corretas
    4 = ENTRAR NO JOGO
    5 = ranking
    6 = MENU

    moveType

    1 top
    1down
    2 left
    2 right

    */
    char I1[10];
    char J1[10];

    if (!strcmp(move, "EXIT"))
    {
        return 0;
    }
    if (!strcmp(move, "RANKING"))
    {
        return 5;
    }
    if (!strcmp(move, "MENU"))
    {
        return 6;
    }
    if (!strcmp(move, "START"))
    {
        return 4;
    }

    if (!strcmp(move, "RULES"))
    {
        return 7;
    }


    if ((move[0]=='{') && (move[1]=='(') && (move[3]==',') && (move[5]==')') && (move[10]=='}') && (move[6]==','))
    {
        I1[0] = move[2];
        J1[0] = move[4];
        if((move[7]== 'T') && (move[8]== 'O') && (move[9]== 'P'))
        {
            *i1 = atoi(I1);
            *j1 = atoi(J1);
            *i2 = (*i1 -1);
            *j2 = *j1;
            *moveType = 1;

            if((*j2 > 8) || (*i2 > 8) || (*j2 < 0) || (*i2 < 0))
            {
                return -1;
            }
            else
            {
                return 3;
            }
        }

        else if((move[7]== 'D') && (move[8]== 'W') && (move[9]== 'N'))
        {
            *i1 = atoi(I1);
            *j1 = atoi(J1);
            *i2 = (*i1 +1);
            *j2 = *j1;
            *moveType = 1;

            if((*j2 > 8) || (*i2 > 8) || (*j2 < 0) || (*i2 < 0))
            {
                return -1;
            }
            else
            {
                return 3;
            }
        }

        else if((move[7]== 'L') && (move[8]== 'F') && (move[9]== 'T'))
        {
            *i1 = atoi(I1);
            *j1 = atoi(J1);
            *i2 = *i1;
            *j2 = (*j1 -1);
            *moveType = 2;
            if((*j2 > 8) || (*i2 > 8) || (*j2 < 0) || (*i2 < 0))
            {
                return -1;
            }
            else
            {
                return 3;
            }
        }

        else if((move[7]== 'R') && (move[8]== 'G') && (move[9]== 'T'))
        {
            *i1 = atoi(I1);
            *j1 = atoi(J1);
            *i2 = *i1;
            *j2 = (*j1 +1);
            *moveType = 2;

            if((*j2 > 8) || (*i2 > 8) || (*j2 < 0) || (*i2 < 0))
            {
                return -1;
            }
            else
            {

                return 3;
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }



    return 0;
}



void cai(char Matriz[SIZE_TAB][SIZE_TAB]) //procedimento para os doces cairem do tabuleiro
{
    int i,j;
    for (i=0; i<SIZE_TAB; i++)
    {
        for (j=0; j<SIZE_TAB; j++)
        {
            if (Matriz[i][j]=='X')
            {
                int h=i;
                while (h>0)
                {
                    char auxi;
                    auxi=Matriz[h][j];
                    Matriz[h][j]=Matriz[h-1][j];
                    Matriz[h-1][j]=auxi;
                    h=h-1;
                }
            }
        }
    }
}

void Aleatorizar(char Matriz[SIZE_TAB][SIZE_TAB]) // procedimento para aleatorizar os doces em sequencia
{
    int i,j;
    int x;

    char Letras[SIZE_RGBY]= {"YBGR"};
    for (i=0; i<SIZE_TAB; i++)
    {
        for (j=0; j<SIZE_TAB; j++)
        {
            if (Matriz[i][j]=='X')
            {
                x= (rand()%4);
                Matriz[i][j] = Letras[x];
            }
        }
    }

}

void trocaArquivo(int pont, char *nome) //procedimento para reordenar o ranking
{
    FILE *primeiro, *segundo, *terceiro, *quarto, *quinto, *p1, *p2, *p3, *p4, *p5;
    int pont1;
    int pont2;
    int pont3;
    int pont4;
    int pont5;

    p1 = fopen("../ranking/p1.txt", "r");
    p2 = fopen("../ranking/p2.txt", "r");
    p3 = fopen("../ranking/p3.txt", "r");
    p4 = fopen("../ranking/p4.txt", "r");
    p5 = fopen("../ranking/p5.txt", "r");

    fscanf(p1, "%d", &pont1);
    fscanf(p2, "%d", &pont2);
    fscanf(p3, "%d", &pont3);
    fscanf(p4, "%d", &pont4);
    fscanf(p5, "%d", &pont5);

    fclose(p1);
    fclose(p2);
    fclose(p3);
    fclose(p4);
    fclose(p5);

    if(pont >= pont1)
    {
        p4 = fopen("../ranking/p4.txt", "r");
        p5 = fopen("../ranking/p5.txt", "w");
        quarto = fopen("../ranking/quarto.txt", "r");
        quinto = fopen("../ranking/quinto.txt", "w");

        copiarArquivo(p4, p5);
        copiarArquivo(quarto, quinto);

        fclose(p4);
        fclose(p5);
        fclose(quarto);
        fclose(quinto);


        p3 = fopen("../ranking/p3.txt", "r");
        p4 = fopen("../ranking/p4.txt", "w");
        terceiro = fopen("../ranking/terceiro.txt", "r");
        quarto = fopen("../ranking/quarto.txt", "w");

        copiarArquivo(p3, p4);
        copiarArquivo(terceiro, quarto);

        fclose(p3);
        fclose(p4);
        fclose(terceiro);
        fclose(quarto);


        p2 = fopen("../ranking/p2.txt", "r");
        p3 = fopen("../ranking/p3.txt", "w");
        segundo = fopen("../ranking/segundo.txt", "r");
        terceiro = fopen("../ranking/terceiro.txt", "w");

        copiarArquivo(p2, p3);
        copiarArquivo(segundo, terceiro);

        fclose(p2);
        fclose(p3);
        fclose(segundo);
        fclose(terceiro);



        p1 = fopen("../ranking/p1.txt", "r");
        p2 = fopen("../ranking/p2.txt", "w");
        primeiro = fopen("../ranking/primeiro.txt", "r");
        segundo = fopen("../ranking/segundo.txt", "w");

        copiarArquivo(p1, p2);
        copiarArquivo(primeiro, segundo);

        fclose(p1);
        fclose(p2);
        fclose(primeiro);
        fclose(segundo);

        p1 = fopen("../ranking/p1.txt", "w");
        primeiro = fopen("../ranking/primeiro.txt", "w");
        fprintf(p1, "%d", pont);
        fprintf(primeiro, "%s", nome);
        fclose(p1);
        fclose(primeiro);
    }
    else if(pont >= pont2)
    {
        p4 = fopen("../ranking/p4.txt", "r");
        p5 = fopen("../ranking/p5.txt", "w");
        quarto = fopen("../ranking/quarto.txt", "r");
        quinto = fopen("../ranking/quinto.txt", "w");

        copiarArquivo(p4, p5);
        copiarArquivo(quarto, quinto);

        fclose(p4);
        fclose(p5);
        fclose(quarto);
        fclose(quinto);


        p3 = fopen("../ranking/p3.txt", "r");
        p4 = fopen("../ranking/p4.txt", "w");
        terceiro = fopen("../ranking/terceiro.txt", "r");
        quarto = fopen("../ranking/quarto.txt", "w");

        copiarArquivo(p3, p4);
        copiarArquivo(terceiro, quarto);

        fclose(p3);
        fclose(p4);
        fclose(terceiro);
        fclose(quarto);


        p2 = fopen("../ranking/p2.txt", "r");
        p3 = fopen("../ranking/p3.txt", "w");
        segundo = fopen("../ranking/segundo.txt", "r");
        terceiro = fopen("../ranking/terceiro.txt", "w");

        copiarArquivo(p2, p3);
        copiarArquivo(segundo, terceiro);

        fclose(p2);
        fclose(p3);
        fclose(segundo);
        fclose(terceiro);

        p2 = fopen("../ranking/p2.txt", "w");
        segundo = fopen("../ranking/segundo.txt", "w");
        fprintf(p2, "%d", pont);
        fprintf(segundo, "%s", nome);
        fclose(p2);
        fclose(segundo);
    }
    else if(pont >= pont3)
    {
        p4 = fopen("../ranking/p4.txt", "r");
        p5 = fopen("../ranking/p5.txt", "w");
        quarto = fopen("../ranking/quarto.txt", "r");
        quinto = fopen("../ranking/quinto.txt", "w");

        copiarArquivo(p4, p5);
        copiarArquivo(quarto, quinto);

        fclose(p4);
        fclose(p5);
        fclose(quarto);
        fclose(quinto);


        p3 = fopen("../ranking/p3.txt", "r");
        p4 = fopen("../ranking/p4.txt", "w");
        terceiro = fopen("../ranking/terceiro.txt", "r");
        quarto = fopen("../ranking/quarto.txt", "w");

        copiarArquivo(p3, p4);
        copiarArquivo(terceiro, quarto);

        fclose(p3);
        fclose(p4);
        fclose(terceiro);
        fclose(quarto);


        p3 = fopen("../ranking/p3.txt", "w");
        terceiro = fopen("../ranking/terceiro.txt", "w");
        fprintf(p3, "%d", pont);
        fprintf(terceiro, "%s", nome);
        fclose(p3);
        fclose(terceiro);
    }
    else if(pont >= pont4)
    {
        p4 = fopen("../ranking/p4.txt", "r");
        p5 = fopen("../ranking/p5.txt", "w");
        quarto = fopen("../ranking/quarto.txt", "r");
        quinto = fopen("../ranking/quinto.txt", "w");

        copiarArquivo(p4, p5);
        copiarArquivo(quarto, quinto);

        fclose(p4);
        fclose(p5);
        fclose(quarto);
        fclose(quinto);



        p4 = fopen("../ranking/p4.txt", "w");
        quarto = fopen("../ranking/quarto.txt", "w");
        fprintf(p4, "%d", pont);
        fprintf(quarto, "%s", nome);
        fclose(p4);
        fclose(quarto);
    }
    else if(pont >= pont5)
    {

        p5 = fopen("../ranking/p5.txt", "w");
        quinto = fopen("../ranking/quinto.txt", "w");
        fprintf(p5, "%d", pont);
        fprintf(quinto, "%s", nome);
        fclose(p5);
        fclose(quinto);
    }
}

void copiarArquivo(FILE *file1, FILE *file2) // procedimento para copiar um arquivo em outro
{
    char copiador[100];

    while(fgets(copiador, 100, file1) != NULL)

        fputs(copiador, file2);
}

int createX(char tab[SIZE_TAB][SIZE_TAB], int *pont)  //detecta todos os doces em sequencia e transforma em x
{
    int x, j, i, cont;
    char auxTab[SIZE_TAB][SIZE_TAB]={{0},{0}};
    x=0;

    for (i = 0; i<SIZE_TAB; i++)
    {
        for(j = 0; j<SIZE_TAB-2; j++)
        {
            if((tab[i][j] == tab[i][j+1]) && (tab[i][j] == tab[i][j+2]))
            {
                auxTab[i][j] = 'X';
                auxTab[i][j+1] = 'X';
                auxTab[i][j+2] = 'X';
                x=1;

                if(j<6)
                {
                    for(cont = j+3; cont <SIZE_TAB ; cont++)
                        if(tab[i][j] == tab[i][cont])
                        {
                            auxTab[i][cont] = 'X';

                        }
                        else
                        {
                            break;
                        }
                }
            }
        }
    }


    for (j = 0; j<SIZE_TAB; j++)
    {
        for(i = 0; i<SIZE_TAB-2; i++)
        {
            if((tab[i][j] == tab[i+1][j]) && (tab[i][j] == tab[i+2][j]))
            {
                auxTab[i][j] = 'X';
                auxTab[i+1][j] = 'X';
                auxTab[i+2][j] = 'X';
                x=1;

                if(j<6)
                {
                    for(cont = i+3; cont <SIZE_TAB ; cont++)
                        if(tab[i][j] == tab[cont][j])
                        {
                            auxTab[cont][j] = 'X';

                        }
                        else
                        {
                            break;
                        }
                }
            }
        }
    }

    for (i = 0; i<SIZE_TAB; i++)
    {
        for(j = 0; j<SIZE_TAB; j++)
        {
            if(auxTab[i][j] == 'X')
            {
                tab[i][j] = auxTab[i][j];
                *pont+=1;
            }

        }
    }
    return x;
}

