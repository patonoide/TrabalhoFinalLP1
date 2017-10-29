




#include<stdio.h>
#include<stdlib.h>



struct filme{
int codigo;
char titulo[100];
int ano;
int quantidade;
char genero[10];
};
typedef struct filme Filme;

struct lista{
    Filme * filme;
    int numero;
    Filme * prox;
};
typedef struct lista Lista;


