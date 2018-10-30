#include <iostream>
#include <list>
#include <queue>
#define endl '\n'

using namespace std;

struct Graph {
    int nodes; // número de vértices
    list<int> *adjacent; // lista de vértices ajdancetes

    Graph(int mazeSize) { // construtor
        this->nodes = mazeSize * mazeSize;
        this->adjacent = new list<int>[this->nodes];
    }

    int bfs(int a, int b) { // verifica se existe um caminho de A para B
        queue<int> aux; // fila auxiliar para guardar os vértices adjacentes que ainda precisam ser visitados
        bool visited[this->nodes]; // um array complementar, para verificar se o vértice já foi visitado

        if (a == b) {
            return 1;
        }
        
        for (int i = 0; i < this->nodes; ++i) {
            visited[i] = false;
        }

        visited[a] = true;
        int last; // guarda o ultimo penultimo incremento de "it"

        while (true) {
            list<int>::iterator it; // iterator para fazer a busca na lista

            for (it = this->adjacent[a].begin(); it != this->adjacent[a].end(); it++) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    aux.push(*it);
                    last = *it;
                }

                if (last == b || a == b) {
                    return 1;
                }

            }

            if (!aux.empty()) {
                a = aux.front();
                aux.pop();
            } else {
                return 0;
            }

        }

    }

    void removeWall(int w, int n) { // remove a parede "W" do labirinto e já conecta os vértices adjacentes, o "N" é o tamanho do labirinto
        int node, valor;

        valor = ((2 * (n-1)) + 1);

        if (w % valor < n - 1) { // caso a parede seja vertical
            node = ((w/valor) * n) + (w % valor); // retorna o valor do vértice
            this->adjacent[node].push_back(node + 1); // adiciona o vértice adjacente na lista
            this->adjacent[node + 1].push_back(node);

        } else { // caso a parede seja horizontal
            node = ((w/valor) * n) + ((w % valor) + 1); // retorna o valor do vértice
            this->adjacent[node].push_back(node - n); // adiciona o vértice adjacente na lista
            this->adjacent[node - n].push_back(node);
        }

    }

};


int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases, mazeSize, num_wallsRemoved, num_queries;

    cin >> cases;

    for (int i = 0; i < cases; ++i) {
        cin >> mazeSize >> num_wallsRemoved >> num_queries;
        Graph g(mazeSize);

        for (int j = 0; j < num_wallsRemoved; ++j) {
            int w;
            cin >> w;
            g.removeWall(w, mazeSize);
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