#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <conio.h>
#include <set>
#include <chrono>

using namespace std;

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

class Graph
{
private:
    vector<vector<int>> adjList;
    int numVertices;

public:
    Graph(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cerr << "Arquivo: " << filename << " nao existe" << endl;
            return;
        }

        file >> numVertices;

        adjList.resize(numVertices + 1); // +1 para considerar o vértice 0

        int numEdges;
        file >> numEdges;

        for (int i = 0; i < numEdges; i++)
        {
            int v1, v2;
            file >> v1 >> v2;
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }

        file.close();

        cout << "Leitura das arestas completa." << endl;
    }

    bool isBiconnected()
    {
        auto start = chrono::high_resolution_clock::now();
        
        for (int v = 1; v <= numVertices; v++)
        {
            vector<vector<int>> tmpGraph = removeVertex(v);

            if (!isConnected(tmpGraph, v))
            {
                return false;
            }
        }

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        auto seconds = duration.count() / 1000;
        auto minutes = seconds / 60;
        seconds %= 60;
        auto milliseconds = duration.count() % 1000;
        system("CLS");
        cout << "Algoritmo executado em: " << minutes << " minutos, " << seconds << " segundos e " << milliseconds << " milissegundos" << endl;

        return true;
    }

private:
    vector<vector<int>> removeVertex(int v)
    {
        vector<vector<int>> result;
        result.resize(numVertices + 1);
        for (int i = 1; i <= numVertices; i++)
        {
            if (i != v)
            {
                vector<int> tmp;
                for (auto &neighbor : adjList[i])
                {
                    if (neighbor != v)
                    {
                        tmp.push_back(neighbor);
                    }
                }
                result[i] = tmp;
            }
        }
        return result;
    }

    bool isConnected(vector<vector<int>> &graph, int v)
    {
        vector<bool> visited(numVertices + 1, false);
        stack<int> s;

        // escolher um vértice qualquer para começar
        for (int i = 1; i <= numVertices; i++)
        {
            if (i != v)
            {
                s.push(i);
                break;
            }
        }

        while (!s.empty())
        {
            int v = s.top();
            s.pop();

            for (auto neighbor : graph[v])
            {
                if (!visited[neighbor])
                {
                    s.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        for (int i = 1; i <= numVertices; i++)
        {
            if (!visited[i] && i != v)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string filename = selectFile();
    Graph test = Graph(filename);
    if (test.isBiconnected())
    {
        cout << "O grafo eh biconexo." << endl;
    }
    else
    {
        cout << "O grafo nao eh biconexo." << endl;
    }

    return 0;
}