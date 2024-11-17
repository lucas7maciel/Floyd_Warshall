#include <iostream>
#include <vector>
#include <climits>
#include <limits.h>
#include <string.h>
#include <fstream>
#include <sstream>

#include "../include/floyd_warshall.h"

using namespace std;

void printSolution(const vector<vector<int>> &dist, int vertices, ofstream &outputFile);

// Função que resolve o problema do menor caminho entre todos os pares usando o algoritmo de Floyd-Warshall
void floydWarshall(vector<vector<int>> &dist, int vertices, string outputPath)
{
    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][j] > (dist[i][k] + dist[k][j]))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Verificação de ciclos negativos
    ofstream outputFile(outputPath);

    for (int i = 0; i < vertices; i++)
    {
        if (dist[i][i] < 0)
        {
            if (outputFile.is_open())
            {
                outputFile << "Ciclo negativo detectado no vértice " << i + 1 << ".\n";
            }
            else
            {
                cout << "Ciclo negativo detectado no vértice " << i + 1 << ".\n";
            }
            return;
        }
    }

    // Imprime a matriz de distâncias mais curtas
    printSolution(dist, vertices, outputFile);
}

// Função para imprimir a matriz de solução
void printSolution(const vector<vector<int>> &dist, int vertices, ofstream &outputFile)
{
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            int distance = dist[i][j] == INT_MAX ? -1 : dist[i][j]; // -1 para distâncias infinitas

            if (outputFile.is_open())
            {
                outputFile << j + 1 << ":" << distance << " ";
            }
            else
            {
                // Imprime no formato: <vértice>:<distância>
                printf("%i:%i ", j + 1, distance);
            }
        }

        if (outputFile.is_open())
        {
            outputFile << endl;
        }
        else
        {
            printf("\n");
        }
    }

    if (outputFile.is_open())
    {
        outputFile.close();
    }
}
