/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

Lista* iniciarPrincipal() {
    FILE * principal;
    int x = 0, codigo = 0, y = 0, contano = 0, contagenero = 0;
    char ano[4] = "";
    char c, pontoevirgula = ';';
    char titulo[100];
    fflush(stdout);
    char genero[10];

    int tamanho = 0;
    if ((principal = fopen("entrada.txt", "rt")) == NULL) {
        printf("Deu erro");
    }
    fscanf(principal, "%d", &tamanho);
    Filme * auxf = NULL;
    Lista * lista = NULL;
    lista = (Lista *) malloc(sizeof (Lista));



    lista->filme = (Filme *) malloc(tamanho * sizeof (Filme));
    auxf = lista->filme;
    lista->tamanho = tamanho;

    x = 0;



    lista->filme = auxf;
    x = 0;
    c = fgetc(principal);
    do {
        fflush(stdout);
        c = fgetc(principal);
        if (c == pontoevirgula) {
            codigo++;
            c = fgetc(principal);
        };
        if (codigo == 0) {

            titulo[y] = c;
            y++;
        }
        if (codigo == 1) {
            titulo[y++] = '\0';
            fflush(stdout);
            strcpy(lista->filme->titulo, titulo);
            ano[contano] = c;
            contano++;
        }
        if (codigo == 2) {
            lista->filme->quantidade = c - '0';
        }
        if (codigo == 3) {
            genero[contagenero] = c;
            contagenero++;
        }
        if (c == '\n') {
            genero[contagenero++] = '\0';
            strcpy(lista->filme->genero, genero);
            lista->filme->ano = atoi(ano);
            lista->filme->codigo = x;
            x++;
            memset(ano, 0, sizeof (ano));
            contano = 0;
            contagenero = 0;
            codigo = 0;
            y = 0;
            lista->filme++;
        }
    } while (x < tamanho);

    lista->filme = auxf;
    fclose(principal);
    return lista;
}

void iniciarAtual(Lista * lista2) {
    int w = 0;
    FILE * atual;
    Filme * filme = lista2->filme;
    if ((atual = fopen("atual.txt", "w")) == NULL) {
        printf("Deu erro");
    }
    fprintf(atual, "%d", lista2->tamanho);
    fprintf(atual, "%s", "\n");
    while (w < lista2->tamanho) {
        fprintf(atual, "%s", filme->titulo);
        fprintf(atual, "%s", ";");
        fprintf(atual, "%d", filme->ano);
        fprintf(atual, "%s", ";");
        fprintf(atual, "%d", filme->quantidade);
        fprintf(atual, "%s", ";");
        fprintf(atual, "%s", filme->genero);
        fflush(stdout);


        w++;
        filme++;

    }
    fclose(atual);
    printf("\nSucesso");
}

Lista * locarFilme(Lista * original, Lista * atual) {
    Filme * f = atual->filme;
    Filme * o = original->filme;
    int codigo;
    int x = 0;
    Filme * auxf = atual->filme;

    while (x < atual->tamanho) {
        printf("\nCodigo: %d", f->codigo);
        printf("\nNome: %s", f->titulo);
        printf("\nAno: %d", f->ano);
        printf("\nQuantidade: %d", f->quantidade);
        x++;
        f++;

    }
    f = auxf;
    printf("\nDigite o codigo do filme que deseja: ");
    scanf("%d", &codigo);
    x = 0;
    while (x < atual->tamanho) {
        if (f->codigo == codigo && (f->quantidade - 1) >= 0) {
            f->quantidade--;
        }
        o++;
        f++;
        x++;
    }
    f = auxf;
    atual->filme = f;
    return atual;
}

Lista * entregarFilme(Lista * original, Lista * atual) {
    Filme * f = atual->filme;
    Filme * o = original->filme;
    int codigo;
    int x = 0;
    Filme * auxf = atual->filme;

    while (x < atual->tamanho) {
        printf("\nCodigo: %d", f->codigo);
        printf("\nNome: %s", f->titulo);
        printf("\nAno: %d", f->ano);
        printf("\nQuantidade: %d", f->quantidade);
        x++;
        f++;

    }
    f = auxf;
    printf("\nDigite o codigo do filme que deseja entregar: ");
    scanf("%d", &codigo);
    x = 0;
    while (x < atual->tamanho) {
        if (f->codigo == codigo && (f->quantidade + 1) <= o->quantidade) {
            f->quantidade++;
        }
        o++;
        f++;
        x++;
    }

    f = auxf;
    atual->filme = f;
    return atual;
}

void imprimir(Lista*atual) {
    Filme * f = atual->filme;
    int x = 0;
    Filme * auxf = f;
    while (x < atual->tamanho) {
        printf("\nCodigo: %d", f->codigo);
        printf("\nNome: %s", f->titulo);
        printf("\nAno: %d", f->ano);
        printf("\nQuantidade: %d", f->quantidade);
        f++;
        x++;
    }
    atual->filme = auxf;
}

void buscar(Lista*atual) {
    Filme * f = atual->filme;
    int opcao, codigo;
    printf("Digite a forma como deseja buscar o titulo\n1-Codigo\n2-Nome\n3-Ano\n4-Genero\nOpcao: ");
    scanf("%d", &opcao);
    int x = 0;
    char nome[100];
    char genero[10];
    switch (opcao) {

        case 1:
        {
            printf("Digite o codigo do filme: ");
            scanf("%d", &codigo);


            while (x < atual->tamanho) {
                if (codigo == f->codigo) {
                    printf("\n");
                    printf("\nCodigo: %d", f->codigo);
                    printf("\nNome: %s", f->titulo);
                    printf("\nAno: %d", f->ano);
                    printf("\nQuantidade: %d", f->quantidade);
                }
                f++;
                x++;
            }
            break;
        }
        case 2:
        {
            printf("Digite o nome do Filme: ");
            fflush(stdin);
            fgets(nome, 100, stdin);
            while (x < atual->tamanho) {
                if (strcasecmp(strtok(nome,"\n"), f->titulo) == 0) {
                    printf("\n");
                    printf("\nCodigo: %d", f->codigo);
                    printf("\nNome: %s", f->titulo);
                    printf("\nAno: %d", f->ano);
                    printf("\nQuantidade: %d", f->quantidade);
                }
                f++;
                x++;
            }
            break;
        }
        case 3:
        {
            int ano;
            printf("Digite o ano: ");
            scanf("%d", &ano);
            while (x < atual->tamanho) {
                if (ano == f->ano) {
                    printf("\n");
                    printf("\nCodigo: %d", f->codigo);
                    printf("\nNome: %s", f->titulo);
                    printf("\nAno: %d", f->ano);
                    printf("\nQuantidade: %d", f->quantidade);
                }
                f++;
                x++;
            }
            break;
        }
        case 4:
        {


            printf("Digite o genero do Filme: ");
            fflush(stdin);
            fgets(genero, 10, stdin);
            while (x < atual->tamanho) {
                if (strcasecmp(genero, f->genero) == 0) {
                    printf("\n");
                    printf("\nCodigo: %d", f->codigo);
                    printf("\nNome: %s", f->titulo);
                    printf("\nAno: %d", f->ano);
                    printf("\nQuantidade: %d", f->quantidade);
                }
                f++;
                x++;
            }
            break;
        }



    }

}

void relAno(Lista * lista) {
    Filme * f = lista->filme;
    int w = 0;
    int ano = 0;

    printf("\nDigite o ano que voce deseja: ");
    scanf("%d", &ano);
    FILE * atual;
    if ((atual = fopen("relatorio_ano.txt", "w")) == NULL) {
        printf("Deu erro");
    }
    while (w < lista->tamanho) {

        if (ano == f->ano) {
            fprintf(atual, "%s", f->titulo);
            fprintf(atual, "%s", ";");
            fprintf(atual, "%d", f->ano);
            fprintf(atual, "%s", ";");
            fprintf(atual, "%d", f->quantidade);
            fprintf(atual, "%s", ";");
            fprintf(atual, "%s", f->genero);
            fflush(stdout);



        }
        w++;
        f++;
    }
    fclose(atual);
    printf("\nSucesso");
}

void relGenero(Lista * lista) {
    Filme * f = lista->filme;
    int w = 0;
    char genero[10];

    printf("\nDigite o genero que voce deseja: ");
    fflush(stdin);
    fgets(genero, 10, stdin);
    FILE * atual;
    if ((atual = fopen("relatorio_genero.txt", "w")) == NULL) {
        printf("Deu erro");
    }
    while (w < lista->tamanho) {

        if (strcasecmp(f->genero, genero) == 0) {
            fprintf(atual, "%s", f->titulo);
            fprintf(atual, "%s", ";");
            fprintf(atual, "%d", f->ano);
            fprintf(atual, "%s", ";");
            fprintf(atual, "%d", f->quantidade);
            fprintf(atual, "%s", ";");
            fprintf(atual, "%s", f->genero);
            fflush(stdout);



        }
        w++;
        f++;
    }
    fclose(atual);
    printf("\nSucesso");
}