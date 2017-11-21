/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Asus
 *
 * Created on 6 de Outubro de 2017, 15:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

/*
 * 
 */
int main(int argc, char** argv) {

    int opcao = 1;
    Lista * original;
    Lista * modificado;
    original = iniciarPrincipal();
    modificado = iniciarPrincipal();
    while (opcao != 0) {
        
        printf("\nMenu:\n 1-Locar filme\n 2-Entregar filme\n 3-Buscar titulo\n 4-Imprimir acervo atual \n 5-Fazer back-up do acervo atual em arquivo \n 6-Imprimir acervo original \n 7-Gerar relatorio ano \n 8-Gerar relatorio genero \n 0-Sair  \nOpcao: ");
        scanf("%i", &opcao);
        switch (opcao) {
            case 0:
            {
               
                printf("\nSaindo...\n");
                break;
            }
            case 1:
            {
                modificado = locarFilme(original, modificado);
                break;
            }

            case 2:
            {
                modificado = entregarFilme(original, modificado);
                break;
            }

            case 3:
            {
                buscar(modificado);
                break;
            }
            case 4:
            {
                imprimir(modificado);
                break;
            }
            case 5:
            {
                iniciarAtual(modificado);
                break;
            }
            case 6:
            {
                imprimir(original);
                
                break;
            }
            
            case 7:
            {
                
                relAno(modificado);
                break;
            }
            case 8:
            {
                
                relGenero(modificado);
                break;
            }
            default:
            {
                printf("Opcao invalida.");
                break;
            }

        }

    }

    return (EXIT_SUCCESS);
}

