#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Função que resolve o problema do menor caminho entre todos os pares usando o algoritmo de Floyd-Warshall
void floydWarshall(vector<vector<int>> &dist, int vertices, string outputPath);