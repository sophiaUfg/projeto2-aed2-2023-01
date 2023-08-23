/*  Algoritmo de Bellman-Ford - Detecta Caminhos Minimos
    Disciplina: Algoritmo e Estrutura de Dados 2 - 2023/01
    Grupo 7:
    Sophia F. M. Almeida
    Lucas Gabriel Nunes Alves
    Arthur Nucada Félix de Souza
*/

#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

// Estrutura para representar uma aresta no grafo
struct Aresta {
    int origem, destino, peso;
};

// Estrutura para representar o grafo
struct Grafo {
    int V, E;
    vector<Aresta> arestas;
};

// Função para criar um novo grafo com V vértices e E arestas
struct Grafo* criarGrafo(int V, int E) {
    struct Grafo* grafo = new Grafo;
    grafo->V = V;
    grafo->E = E;
    return grafo;
}

// Função para imprimir as distâncias a partir da origem
void imprimirDistancias(int dist[], int n) {
    cout << "Distancia do Vertice a Origem\n";
    for (int i = 0; i < n; ++i) {
        cout << i << "\t\t" << dist[i] << "\n";
    }
}

// Algoritmo de Bellman-Ford para encontrar os caminhos mais curtos
// em um grafo com pesos nas arestas a partir de um vértice de origem
void BellmanFord(struct Grafo* grafo, int origem) {
    int V = grafo->V;
    int E = grafo->E;
    vector<int> dist(V, INT_MAX); // Inicializa todas as distâncias com infinito
    dist[origem] = 0; // Define a distância da origem para ela mesma como 0

    // Relaxa todas as arestas V-1 vezes
    for (int i = 1; i <= V - 1; i++) {
        for (const Aresta& aresta : grafo->arestas) {
            int u = aresta.origem;
            int v = aresta.destino;
            int peso = aresta.peso;
            // Atualiza a distância se um caminho mais curto for encontrado
            if (dist[u] != INT_MAX && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
            }
        }
    }

    bool temCicloNegativo = false;
    // Verifica a presença de ciclos de peso negativo
    for (const Aresta& aresta : grafo->arestas) {
        int u = aresta.origem;
        int v = aresta.destino;
        int peso = aresta.peso;
        // Se uma distância menor for encontrada, há um ciclo negativo
        if (dist[u] != INT_MAX && dist[u] + peso < dist[v]) {
            temCicloNegativo = true;
            break;
        }
    }

    if (temCicloNegativo) {
        cout << "O grafo contém um ciclo de peso negativo\n";
    } else {
        imprimirDistancias(dist.data(), V); // Imprime as distâncias mais curtas
    }
}

int main() {
    int V = 5;
    int E = 8;
    struct Grafo* grafo = criarGrafo(V, E);

    // Adiciona as arestas do grafo
    grafo->arestas.push_back({0, 1, -1});
    grafo->arestas.push_back({0, 2, 4});
    grafo->arestas.push_back({1, 2, 3});
    grafo->arestas.push_back({1, 3, 2});
    grafo->arestas.push_back({1, 4, 2});
    grafo->arestas.push_back({3, 2, 5});
    grafo->arestas.push_back({3, 1, 1});
    grafo->arestas.push_back({4, 3, -3});

    // Chama o algoritmo Bellman-Ford a partir do vértice 0 como origem
    BellmanFord(grafo, 0);

    return 0;
}
