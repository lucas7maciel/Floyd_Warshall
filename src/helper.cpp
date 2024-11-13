#include <stdio.h>

#include "../include/helper.h"

void printHelper() {
    printf("Esta aplicacao calcula o caminho minimo entre todos os pares de vertice em um grafo ponderado ");
    printf("utilizando o algoritmo de Floyd Warshall!\n\n");

    printf("O usuario pode escolher as seguintes opcoes atraves do terminal:\n");
    printf("-f <arquivo> : Faz a leitura dos inputs utilizados a partir do arquivo informado\n");
    printf("-o <arquivo> : Redireciona a saida da aplicacao para o arquivo especificado\n");
    printf("-h           : Exibe este helper\n\n");

    printf("Formatacao desejada do input:\n");
    printf("-vertices -arestas\n");
    printf("-v1 -v2 -peso\n");
    printf("-v1 -v2 -peso\n");
    printf("(...)\n\n");
}