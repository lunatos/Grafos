#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;
// Verifica se ja existe aresta entre v e u no grafo
int find(vector<pair<int, int>> &edges, int u, int v)
{
    for (int i = 0; i < edges.size(); i++)
    {
        if ((edges[i].first == u && edges[i].second == v) || (edges[i].first == v && edges[i].second == u))
        {
            return i;
        }
    }
    return -1;
}

// Fução para encontrar o pai do vertice u
int find(vector<int> &parent, int u)
{
    int root = u;
    while (parent[root - 1] != root)
    {
        root = parent[root - 1];
    }
    return root;
}

// Fução para unir os conjuntos pai
void unionSets(vector<int> &parent, int u, int v)
{
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rootU != rootV)
    {
        parent[rootU - 1] = rootV;
    }
}

// Cria uma Arvore geradora
void generateSpanningTree(int N, vector<pair<int, int>> &edges)
{
    //geradores de numeros aleatorios muito grandes
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, N);

    vector<int> parent(N);
    for (int i = 1; i <= N; i++)
    {
        parent[i - 1] = i;
    }

    // criando n-1 arestas
    for (int i = 1; i < N; i++)
    {
        system("CLS");
        cout << "Iteracao no vertice " << i << " de " << N << endl;
        uniform_int_distribution<int> distTmp(1,i);
        int u = distTmp(mt);
        int v = dist(mt);
        // enquanto u e v possuirem ancestrais em comum mudamos o v para não criarmos ciclos
        while (find(parent, u) == find(parent, v))
        {
            v = dist(mt);
        }
        unionSets(parent, u, v);
        edges.push_back({u, v});
    }
}

int main()
{
    srand(time(0));
    int N;
    cout << "Quantos vertices o grafo vai ter? ";
    cin >> N;

    // Define um número máximo de arestas para garantir que o grafo seja esparso
    int maxEdges = N - 1 + (N * (N - 1) / 4); // Ajuste a fração conforme necessário
    int M = N - 1 + rand() % (maxEdges - (N - 1) + 1); // Gera o número de arestas entre N-1 e maxEdges

    vector<pair<int, int>> edges;
    generateSpanningTree(N, edges);

    // Adiciona novas arestas ao grafo até completar M, mas com cuidado para não exceder a esparsidade
    while (edges.size() < M)
    {
        int u = 1 + rand() % N;
        int v = 1 + rand() % N;
        if (u != v && find(edges, u, v) == -1)
        {
            edges.push_back({u, v});
        }
    }

    string fileName = "graph-esparso-";
    fileName += to_string(N) + ".txt";

    ofstream file(fileName);
    file << N << "\t" << M << endl;
    for (const auto &edge : edges)
    {
        file << edge.first << "\t" << edge.second << endl;
    }
    file.close();

    cout << "O grafo possui " << M << " arestas" << endl;

    return 0;
}