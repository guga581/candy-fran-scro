
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

#define SIZE_TAB 9
#define SIZE_RGBY 4
#define SIZE_MOVE 50
#define SIZE_PLAYS 1

void startGame(char tab[SIZE_TAB][SIZE_TAB], char letras[]); //GU
void printTab(char tab[SIZE_TAB][SIZE_TAB]); // GU
void swap1(char tab[SIZE_TAB][SIZE_TAB],int i1,int j1,int i2,int j2); //GU
int verifyString(char move[], int *i1,int *j1,int *i2,int *j2, int *moveType); //RO
int createX(char Matriz[SIZE_TAB][SIZE_TAB], int *pont); // RO
void cai(char Matriz[SIZE_TAB][SIZE_TAB]); //GU
void Aleatorizar(char Matriz[SIZE_TAB][SIZE_TAB]); //GU
void menu(int pont, int plays); //RO
void trocaArquivo(int pont, char *nome); //RO
void copiarArquivo(FILE *file1, FILE *file2); //RO
void printRanking(void);    //RO
void printRegras(void); //RO
