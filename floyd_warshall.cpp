/*  Algoritmo de Floyd Warshall - Detecta Caminhos Minimos
    Disciplina: Algoritmo e Estrutura de Dados 2 - 2023/01
    Grupo 7:
    Sophia F. M. Almeida
    Lucas Gabriel Nunes Alves
    Arthur Nucada Félix de Souza
*/

#include <iostream>
#include <vector>

const int INF = 99999; // Define Infinito como um valor suficientemente grande

using namespace std;

void imprimirSolucao(const vector<vector<int>>& dist) {
    int V = dist.size();
    cout << "A seguinte matriz mostra as distancias mais curtas entre todos os pares de vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void algoritmoFloydWarshall(vector<vector<int>>& grafo) {
    int V = grafo.size();

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // Verifica se há uma rota melhor passando pelo vértice 'k'
                if (grafo[i][k] != INF && grafo[k][j] != INF && grafo[i][j] > grafo[i][k] + grafo[k][j]) {
                    // Se houver uma rota melhor, atualiza a distância mínima
                    grafo[i][j] = grafo[i][k] + grafo[k][j];
                }
            }
        }
    }

    imprimirSolucao(grafo);
}

int main() {
    int V = 4;
    vector<vector<int>> grafo = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    algoritmoFloydWarshall(grafo);

    return 0;
}
