#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <conio.h>
#include <stack>

using namespace std;

using EdgeClassification = enum { TREE_EDGE, BACK_EDGE, FORWARD_EDGE, CROSS_EDGE };

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

void classifyEdges(const vector<int>& pointer, const vector<int>& arc_dest, int Vx) {
    //pointer.size() - 2 é o numero de vertices então temos q alocar numero de vertices mais um pois não iremos utilizar o 0
    //TD = tempo de descoberta, TT = tempo de termino, pai = vertice pai de i
    stack<int> pilha;
    int TD[pointer.size() - 1],TT[pointer.size() - 1],pai[pointer.size() - 1];
    int t = 0;
    for(int i = 1; i < pointer.size() - 1; i++) {
        TD[i] = 0;
        TT[i] = 0;
        pai[i] = 0;
    }

    int vertice_atual;
    //procura se tem algum vertice não explorado dentro de todos os vertices do grafo
    for(int i = 1; i < pointer.size() - 1; i++) {
        if (TD[i] = 0) {
            vertice_atual = i;
            pilha.push(i);
            t++;
            TD[i] = t;
            while (!pilha.empty()) {
                //procura um novo vertice para explorar buscando as arestas que saem do vertice atual
                for(int j = pointer[vertice_atual]; j < pointer[vertice_atual + 1]; j++) {

                }
            }
            
        }
        
    }
    
    


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
    classifyEdges(pointer, arc_dest, Vx);
    //numero de vertices = pointer.size() - 2


    return 0;
}