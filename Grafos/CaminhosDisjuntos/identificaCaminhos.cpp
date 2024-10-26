#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <conio.h>
#include <algorithm>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    vector<vector<int>> capacity; // Matriz de capacidade
    int numVertices;
    int numEdges;

public:
    Graph(const string &filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Arquivo: " << filename << " não existe" << endl;
            return;
        }

        file >> numVertices >> numEdges;

        adjList.resize(numVertices + 1);
        capacity.assign(numVertices + 1, vector<int>(numVertices + 1, 0));

        for (int i = 0; i < numEdges; i++) {
            int v1, v2;
            file >> v1 >> v2;
            adjList[v1].push_back(v2);
            capacity[v1][v2]++; // Aumenta a capacidade da aresta
        }

        file.close();
        cout << "Leitura das arestas completa." << endl;
    }

    bool bfs(int s, int t, vector<int> &parent) {
        vector<bool> visited(numVertices + 1, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adjList[u]) {
                if (!visited[v] && capacity[u][v] > 0) { // Se não foi visitado e a capacidade é positiva
                    parent[v] = u;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return visited[t]; // Retorna se o destino foi alcançado
    }

    vector<vector<int>> findDisjointPaths(int source, int sink) {
        vector<vector<int>> allPaths;
        vector<int> parent(numVertices + 1);

        while (bfs(source, sink, parent)) {
            vector<int> path;
            int v = sink;

            // Reconstrói o caminho a partir do vértice destino até a origem
            while (v != source) {
                path.push_back(v);
                v = parent[v];
            }
            path.push_back(source);
            reverse(path.begin(), path.end()); // Inverte para obter o caminho na ordem correta

            allPaths.push_back(path); // Armazena o caminho encontrado

            // Remove a capacidade das arestas utilizadas no caminho
            for (size_t i = 0; i < path.size() - 1; i++) {
                int u = path[i];
                int v = path[i + 1];
                capacity[u][v]--; // Remove a capacidade da aresta
            }
        }

        return allPaths;
    }
};

string selectFile()
{
    string graphFiles[] = {
        "graph-test-5x.txt",
        "graph-test-5.txt",
        "graph-test-100.txt",
        "graph-test-1000.txt",
        "graph-test-10000.txt",
        "graph-test-100000.txt",
    };
    int numGraphFiles = sizeof(graphFiles) / sizeof(graphFiles[0]);
    int currentChoice = 0;

    while (true)
    {
        system("CLS");
        cout << "Selecione o arquivo:" << endl;
        for (int i = 0; i < numGraphFiles; i++)
        {
            if (i == currentChoice)
            {
                cout << "> " << graphFiles[i] << endl;
            }
            else
            {
                cout << "  " << graphFiles[i] << endl;
            }
        }

        int c = getch(); // o que foi digitado no console
        switch (c)
        {
        case 0x48: // seta para cima
            currentChoice = (currentChoice - 1 + numGraphFiles) % numGraphFiles;
            break;
        case 0x50: // seta para baixo
            currentChoice = (currentChoice + 1) % numGraphFiles;
            break;
        case 0x0D: // Enter
            return graphFiles[currentChoice];
        }
    }
}

int main() {
    string filename = selectFile();
    Graph test(filename);

    int source = 1; // Defina seu vértice de origem
    int target = 2; // Defina seu vértice de destino

    vector<vector<int>> disjointPaths = test.findDisjointPaths(source, target);

    cout << "Caminhos disjuntos encontrados:" << endl;
    for (const auto &path : disjointPaths) {
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}