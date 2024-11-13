#include <iostream>
#include <vector>
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
    if (outputFile.is_open())
    {
        outputFile << "Matriz das distancias mais curtas entre cada par de vertices:\n";
    }
    else
    {
        cout << "Matriz das distancias mais curtas entre cada par de vertices:\n";
    }

    for (int i = 0; i < vertices; i++)
    {
        // Otimizar essa parte
        for (int j = 0; j < vertices; j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                if (outputFile.is_open())
                {
                    outputFile << "INF ";
                }
                else
                {
                    cout << "INF ";
                }
            }
            else
            {
                if (outputFile.is_open())
                {
                    outputFile << dist[i][j] << "   ";
                }
                else
                {
                    cout << dist[i][j] << "   ";
                }
            }
        }

        if (outputFile.is_open())
        {
            outputFile << endl;
        }
        else
        {
            cout << endl;
        }
    }
}
