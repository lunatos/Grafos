#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <conio.h>

using namespace std;

string selectFile() {
    string graphFiles[] = {"graph-test-50000.txt", "graph-test-100.txt"};
    int numGraphFiles = sizeof(graphFiles) / sizeof(graphFiles[0]);
    int currentChoice = 0;

    while (true) {
        system("CLS");
        cout << "Selecione o arquivo:" << endl;
        for (int i = 0; i < numGraphFiles; i++) {
            if (i == currentChoice) {
                cout << "> " << graphFiles[i] << endl;
            } else {
                cout << "  " << graphFiles[i] << endl;
            }
        }

        int c = getch(); // o que foi digitado no console
        switch (c) {
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


pair<vector<int>, vector<int>> readGraph(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Arquivo: " << filename << " não existe" << endl;
        return make_pair(vector<int>(), vector<int>());
    }

    int numVertices, numEdges;
    file >> numVertices >> numEdges;

    auto start = chrono::high_resolution_clock::now();

    try {
        vector<int> pointer;
        pointer.reserve(numVertices + 2);
        vector<int> arc_dest;
        arc_dest.reserve(numEdges + 1);
        // alocando lixo nos indices 0 dos vetores
        pointer.emplace_back(1);
        arc_dest.emplace_back(1);
        
        int counter = 0;
        int tmp = 0;
        for (int i = 1; i <= numEdges; i++) {
            int v1, v2;
            file >> v1 >> v2;

            if(tmp < v1) {
                tmp++;
                pointer.emplace_back(i);
            }

            arc_dest.emplace_back(v2);

            counter++;
            if(counter % (numEdges / 10) == 0) {
                system ("CLS");
                cout << "Arestas lidas: " << (counter * 100) / numEdges << "%" << endl;
            }
        }
        pointer.emplace_back(numEdges + 1); // Setando ponteiro final

        file.close();

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        auto seconds = duration.count() / 1000;
        auto minutes = seconds / 60;
        seconds %= 60;
        auto milliseconds = duration.count() % 1000;

        system ("CLS");
        cout << "Leitura das arestas completa em " << minutes << " minutos, " << seconds << " segundos e " << milliseconds << " milissegundos" << endl;

        return make_pair(std::move(pointer), std::move(arc_dest));
    } catch (bad_alloc& ba) {
        cerr << "Erro: " << ba.what() << endl;
        return make_pair(vector<int>(), vector<int>());
    }
}

pair<int, vector<int>> getEdgesToVertex(const vector<int>& pointer, const vector<int>& arc_dest, int X) {
    int numEdgesToX = 0;
    vector<int> verticesWithEdgesToX;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 1; i < pointer.size() - 1; i++) {
        for (int j = pointer[i]; j < pointer[i + 1]; j++) {
            if (arc_dest[j] == X) {
                numEdgesToX++;
                verticesWithEdgesToX.push_back(i);
            }
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto seconds = duration.count() / 1000;
    auto minutes = seconds / 60;
    seconds %= 60;
    auto milliseconds = duration.count() % 1000;

    cout << "Busca de vertices predecessores: " << minutes << " minutos, " << seconds << " segundos e " << milliseconds << " milissegundos" << endl;

    return make_pair(numEdgesToX, verticesWithEdgesToX);
}

pair<int, vector<int>> getEdgesOffVertex(const vector<int>& pointer, const vector<int>& arc_dest, int X) {
    int numEdgesOffX = 0;
    vector<int> verticesWithEdgesOffX;

    auto start = chrono::high_resolution_clock::now();
    for (int i = pointer[X]; i < pointer[X + 1]; i++) {
        numEdgesOffX++;
        verticesWithEdgesOffX.push_back(arc_dest[i]);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto seconds = duration.count() / 1000;
    auto minutes = seconds / 60;
    seconds %= 60;
    auto milliseconds = duration.count() % 1000;

    cout << "Busca de vertices sucessores: " << minutes << " minutos, " << seconds << " segundos e " << milliseconds << " milissegundos" << endl;

    return make_pair(numEdgesOffX, verticesWithEdgesOffX);
}

int main() {
    string filename = selectFile();
    pair<vector<int>, vector<int>> result = readGraph(filename);

    vector<int> pointer = std::move(result.first);  
    vector<int> arc_dest = std::move(result.second);

    int Vx;
    cout << "Digite um dos vertices desse grafo: ";
    while (true)
    {
        cin >> Vx;
        if(Vx > 0 && Vx < pointer.size() - 1) {
            break;
        } else {
            system ("CLS");
            cout << "Out of bounds, digite um vertices contido no grafo: ";
        }
    }

    pair<int, vector<int>> entrada = getEdgesToVertex(pointer, arc_dest, Vx);
    int dVEntrada = std::move(entrada.first);
    vector<int> predecessores = std::move(entrada.second);

    cout << "Grau de entrada do vertice (" << Vx << "): " << dVEntrada << endl;
    cout << "Conjunto de seus predecessores: { ";
    for( int vertex : predecessores ) {
        cout << vertex << " ";
    }
    cout << "}" << endl;

    pair<int, vector<int>> saida = getEdgesOffVertex(pointer, arc_dest, Vx);
    int dVSaida = std::move(saida.first);
    vector<int> sucessores = std::move(saida.second);

    cout << "Grau de entrada do vertice (" << Vx << "): " << dVSaida << endl;
    cout << "Conjunto de seus sucessores: { ";
    for( int vertex : sucessores ) {
        cout << vertex << " ";
    }
    cout << "}" << endl;

    return 0;
}