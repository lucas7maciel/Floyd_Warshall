#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <sstream>
#include <climits>

#include "../include/floyd_warshall.h"
#include "../include/helper.h"

using namespace std;

int main(int argc, char **args)
{
    string inputPath, outputPath;

    // Receber opcoes do usuario
    for (int i = 0; i < argc; i++)
    {
        // Indicar arquivo que contem o grafo de entrada
        if (!strcmp(args[i], "-f") && i != argc - 1)
        {
            inputPath = args[++i];
        }
        else if (!strcmp(args[i], "-f"))
        {
            printf("Um caminho para o arquivo precisa ser especificado apos '-f'\n");
            return 1;
        }

        // Indicar arquivo em que a saida sera armazenada (opcional)
        if (!strcmp(args[i], "-o") && i != argc - 1)
        {
            outputPath = args[++i];
        }
        else if (!strcmp(args[i], "-o"))
        {
            printf("Um caminho para o arquivo de saida precisa ser especificado apos '-o'\n");
            return 1;
        }

        // Verifica se o usuario precisa do helper
        if (!strcmp(args[i], "-h"))
        {
            printHelper();
        }
    }

    // Recebe inputs do usuario
    int vertices, arcos;

    ifstream inputFile(inputPath);
    string line;

    // - Caso um arquivo de entrada nao tenha sido informado (-f <arquivo>)
    //   o usuario pode digitar a pelo proprio terminal
    if (inputPath.empty())
    {
        cout << "Digite o numero de vertices e arestas:\n";
        cin >> vertices >> arcos;
    }
    // Caso um caminho para o arquivo de entrada tenha sido informado
    // *a formatação necessária pode ser encontrada no helper
    else
    {
        if (!inputFile.is_open())
        {
            printf("Falha ao abrir arquivo de entrada, por favor verifique o caminho informado\n");
            return 1;
        }

        if (!getline(inputFile, line))
        {
            printf("Falha ao ler inputs do usuario\n");
            return 1;
        }

        stringstream ss(line);

        if (!(ss >> vertices >> arcos))
        {
            printf("Falha ao ler definicoes do grafo\n");
            return 1;
        }
    }

    // Com a definição do número de vértices e arestas:
    // Cria uma matriz de distâncias inicializando com INT_MAX
    vector<vector<int>> grafo(vertices, vector<int>(vertices, INT_MAX));

    // Inicializa a diagonal principal com 0
    for (int i = 0; i < vertices; i++)
    {
        grafo[i][i] = 0;
    }

    // Leitura das arestas
    if (!inputFile.is_open())
        printf("Digite as arestas no formato origem destino peso:\n");

    for (int i = 0; i < arcos; i++)
    {
        int origem, destino, peso;

        // Com arquivo de entrada
        if (inputFile.is_open() && getline(inputFile, line))
        {
            stringstream ss(line);

            if (!(ss >> origem >> destino >> peso))
            {
                printf("Falha ao ler valores\n");
                return 1;
            }
        }
        else if (inputFile.is_open())
        {
            printf("O arquivo de entrada tem linhas insuficientes\n");
            return 1;
        }
        // Sem arquivo de entrada
        else
        {
            cin >> origem >> destino >> peso;
        }

        grafo[origem - 1][destino - 1] = peso; // Ajusta para 0-indexed
    }

    // Chama a função Floyd-Warshall
    floydWarshall(grafo, vertices, outputPath);

    return 0;
}