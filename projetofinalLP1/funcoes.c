/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cabecalho.h"
#include <stdio.h>
#include <string.h>


Lista * iniciarPrincipal() {
    FILE * principal;
    int x = 0, codigo = 0, y = 0, contano = 0, contagenero = 0;
    char ano[4];
    char c;
    Lista * lista;
    int tamanho;
    principal = fopen("entrada.txt", "rt");
    fscanf(principal, "%d", &tamanho);
    lista = (Lista *) malloc(sizeof (Lista));
    lista->filme = (Filme *) malloc(tamanho * (sizeof (Filme)));
    while (x != tamanho) {
        c = fgetc(principal);
        if (strcmp(c, ";") == 0) {
            codigo++;
            c = fgetc(principal);
        };
        if (codigo == 0) {
            strcpy(lista->filme->titulo[y], c);
            y++;
        }
        if (codigo == 1) {
            ano[contano] = c;
            contano++;
        }
        if (codigo == 2) {
            lista->filme->quantidade = c;
        }
        if (codigo == 3) {
            lista->filme->genero[contagenero] = c;
            contagenero++;
        }
        if (c == '\n') {
            lista->filme->ano = atoi(ano);
            x++;
            contano = 0;
            contagenero = 0;
            lista->filme = lista->prox;
        }
    }
    fclose(principal);
    return lista;
}