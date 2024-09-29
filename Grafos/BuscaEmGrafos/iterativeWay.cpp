#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <chrono>
#include <conio.h>
#include <algorithm>

using namespace std;
class Graph
{
private:
    vector<int> pointer;
    vector<int> arc_dest;

public:
    int getPointerSize()
    {
        return pointer.size();
    }

    Graph(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cerr << "Arquivo: " << filename << " não existe" << endl;
            return;
        }

        int numVertices, numEdges;
        file >> numVertices >> numEdges;

        pointer.reserve(numVertices + 2);
        arc_dest.reserve(numEdges + 1);

        // alocando lixo nos indices 0 dos vetores
        pointer.emplace_back(1);
        arc_dest.emplace_back(1);

        int counter = 0;
        int tmp = 0;
        for (int i = 1; i <= numEdges; i++)
        {
            int v1, v2;
            file >> v1 >> v2;

            if (tmp < v1)
            {
                tmp++;
                pointer.emplace_back(i);
            }

            arc_dest.emplace_back(v2);

            counter++;
            if (counter % (numEdges / 10) == 0)
            {
                system("CLS");
                cout << "Arestas lidas: " << (counter * 100) / numEdges << "%" << endl;
            }
        }
        pointer.emplace_back(numEdges + 1); // Setando ponteiro final

        file.close();

        cout << "Leitura das arestas completa." << endl;
    }

    vector<int> getAdjacentVertices(int Vx)
    {
        vector<int> adjacentVertices;
        for (int i = pointer[Vx]; i < pointer[Vx + 1]; i++)
        {
            adjacentVertices.push_back(arc_dest[i]);
        }
        sort(adjacentVertices.begin(), adjacentVertices.end());
        return adjacentVertices;
    }

    void classifyEdges(int Vx)
    {
        // pointer.size() - 2 é o numero de vertices, pois não estamos utilizando a pos 0, então temos q alocar numero de vertices mais um
        // TD = tempo de descoberta, TT = tempo de termino
        vector<int> TD(pointer.size() - 1, 0);
        vector<int> TT(pointer.size() - 1, 0);
        vector<int> adjacentVertices;
        vector<string> treeEdges;
        vector<string> VxEdgesClassification;
        int w;
        string stringTmp;
        int tree_counter = 0;
        int back_counter = 0;
        int forward_counter = 0;
        int cross_counter = 0;
        int Vx_tree_counter = 0;

        // Realiza DFS
        stack<int> pilha;
        int vertice_atual, t = 0;

        // procura se tem algum vertice não explorado dentro de todos os vertices do grafo
        for (int i = 1; i < pointer.size() - 1; i++)
        {
            if (TD[i] == 0)
            {
                pilha.push(i);
                t++;
                TD[i] = t;
            }
            while (!pilha.empty())
            {
                if (pilha.size() % 10 == 0)
                {
                    system("CLS");
                    cout << pilha.size() << " sao quantos vertices estao na pilha" << endl;
                }

                vertice_atual = pilha.top();
                adjacentVertices = getAdjacentVertices(vertice_atual);

                // variavel para marcar caso ache alguma aresta de arvore para aprofundar mais a busca
                bool achou = false;
                // itera as arestas que saem do vertice atual
                for (int j = 0; j < adjacentVertices.size(); j++)
                {
                    w = adjacentVertices[j];
                    if (TD[w] == 0)
                    {
                        stringTmp = to_string(vertice_atual) + " -> " + to_string(w) + " Aresta de arvore";
                        treeEdges.push_back(stringTmp);
                        achou = true;
                        pilha.push(w);
                        t++;
                        TD[w] = t;
                        if (vertice_atual == Vx)
                        {
                            VxEdgesClassification.push_back(stringTmp);
                            Vx_tree_counter++;
                        }
                        tree_counter++;
                        break;
                    }
                    else
                    {
                        // como é necessário produzir a classificação de todas as arestas apenas para o vértice informado
                        if (vertice_atual == Vx)
                        {
                            if (TT[w] == 0)
                            {
                                stringTmp = to_string(vertice_atual) + " -> " + to_string(w) + " Aresta de retorno";
                                back_counter++;
                            }
                            else if (TD[vertice_atual] < TD[w])
                            {
                                stringTmp = to_string(vertice_atual) + " -> " + to_string(w) + " Aresta de avanço";
                                forward_counter++;

                            }
                            else
                            {
                                stringTmp = to_string(vertice_atual) + " -> " + to_string(w) + " Aresta de cruzamento";
                                cross_counter++;
                            }
                            VxEdgesClassification.push_back(stringTmp);
                        }
                    }
                }
                if (!achou)
                {
                    // não foi encontrada nenhuma aresta de arvore então chegou o tempo de termino do vertice do topo da pilha
                    t++;
                    TT[vertice_atual] = t;
                    pilha.pop();
                }
            }
        }

        system("CLS");

        ofstream outputFile("tree_edges_iw.txt");
        if (outputFile)
        {
            outputFile << "Arestas de arvore: " << endl;
            for (const auto &str : treeEdges)
            {
                outputFile << str << endl;
            }
            outputFile << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\nForam encontradas " << tree_counter << " arestas de arvore" << endl;
            outputFile.close();
            cout << "Classificacao das arestas escrita no arquivo: tree_edges_iw.txt" << endl;
        }
        else
        {
            cerr << "Error: nao foi possivel escrever no arquivo tree_edges_iw.txt" << endl;
        }

        ofstream outputFileX("vertex_edges_classification_iw.txt");
        if (outputFileX)
        {
            outputFileX << "Classificacao das arestas que saem do vertice " << Vx << ":" << endl;
            for (const auto &str : VxEdgesClassification)
            {
                outputFileX << str << endl;
            }
            outputFileX << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\nSaindo do vertice " << Vx << " foram encontradas: \n"
                        << Vx_tree_counter << " arestas de arvore\n"
                        << back_counter << " arestas de retorno\n"
                        << forward_counter << " arestas de avanço\n"
                        << cross_counter << " arestas de cruzamento" << endl;
            outputFileX.close();
            cout << "Classificacao das arestas que saem do vertice X escrita no arquivo: vertex_edges_classification_iw.txt" << endl;
        }
        else
        {
            cerr << "Error: nao foi possivel escrever no arquivo vertex_edges_classification_iw.txt" << endl;
        }
    }
};

string selectFile()
{
    string graphFiles[] = {"graph-test-50000.txt", "graph-test-100.txt"};
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

int main()
{
    string filename = selectFile();
    Graph graph(filename);

    int Vx;
    cout << "Digite um dos vertices desse grafo para ser o vertice X: ";
    while (true)
    {
        cin >> Vx;
        if (Vx > 0 && Vx < graph.getPointerSize() - 1)
        {
            break;
        }
        else
        {
            system("CLS");
            cout << "Out of bounds, digite um vertices contido no grafo: ";
        }
    }
    graph.classifyEdges(Vx);

    return 0;
}