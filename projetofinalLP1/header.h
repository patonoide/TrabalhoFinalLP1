




#include<stdio.h>
#include<stdlib.h>

struct filme {
    int codigo;
    char titulo[100];
    int ano;
    int quantidade;
    char genero[10];
  
};
typedef struct filme Filme;

struct lista{
    int tamanho;
    Filme * filme;

};
typedef struct lista Lista;


Lista* iniciarPrincipal();
void iniciarAtual(Lista * lista2);
Lista * locarFilme(Lista * original, Lista * atual);
Lista * entregarFilme(Lista * original, Lista * atual);
void imprimir(Lista*atual);
void buscar(Lista*atual);
void relAno(Lista * lista);
void relGenero(Lista * lista);