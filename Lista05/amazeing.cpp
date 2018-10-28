#include <iostream>
#include <list>
#include <queue>
#define endl '\n'

using namespace std;

struct Graph {
    int nodes; // número de vértices
    list<int> *adjacent; // lista de vertices ajdancetes

    Graph(int mazeSize) { // construtor
        this->nodes = mazeSize;
        this->adjacent = new list<int>[this->nodes];
    }

    int bfs(int a, int b) { // verifica se existe um caminho de A para B
        queue<int> aux; // fila auxiliar para guardar os vértices adjacentes que ainda precisam ser visitados
        bool visited[this->nodes]; // um array complementar, para verificar se o vértice já foi visitado

        if (a > b) { // inverte a ordem da busca na lista, o objetivo é ir do menor vértice para o maior.
            int m = a;
            a = b;
            b = m;
        }

        for (int i = 0; i < this->nodes; ++i) {
            visited[i] = false;
        }

        visited[a] = true;

        while (true) {
            list<int>::iterator it; // iterator para fazer a busca na lista

            for (it = this->adjacent[a].begin(); it != this->adjacent[a].end(); it++) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    aux.push(*it);
                }
            }

            if (*it == b || a == b) {
                return 1;
            }

            if (!aux.empty()) {
                a = aux.front();
                aux.pop();
            } else {
                return 0;
            }

        }

    }

    void removeWall(int w) { // remove a parede do labirinto e já conecta os vértices adjacentes
        
    }

};


int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases, mazeSize, num_wallsRemoved, num_queries;

    cin >> cases;

    for (int i = 0; i < cases; ++i) {
        cin >> mazeSize >> num_wallsRemoved >> num_queries;
        mazeSize = mazeSize * mazeSize;
        Graph g(mazeSize);

        for (int j = 0; j < num_wallsRemoved; ++j) {
            int w;
            cin >> w;
            g.removeWall(w);
        }

        for (int k = 0; k < num_queries; ++k) {
            int a, b, c;
            cin >> a >> b;
            c = g.bfs(a, b);
            cout << i << "." << k << " " << c << endl;
        }

        cout << endl;

    }

    return 0;
}