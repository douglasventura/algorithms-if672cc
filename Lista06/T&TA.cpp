#include <iostream>
#include <list>
#define endl '\n'

using namespace std;

struct NodeWeight { // objeto nó com o peso.
    int link; // ligacao com o nó
    int weight; // peso do nó

    NodeWeight(int link, int weight) : link(link), weight(weight) {}

};

struct Graph {
    int nodes; // número de nós
    list<NodeWeight> *adjacent; // lista dos vértices adjacentes com o peso

    Graph(int nodes) {
        this->nodes = nodes;
        this->adjacent = new list<NodeWeight>[this->nodes];
    }

    void addEdge(int nodeX, int nodeY, NodeWeight *x, NodeWeight *y) { // adiciona a conexão entre os vértices
        this->adjacent[nodeX].push_back(*y);
        this->adjacent[nodeY].push_back(*x);
    }

    int* dijkstra(int origin, int destiny) {
        int dist[this->nodes]; // vetor com as distâncias entre os vértices
        int visited[this->nodes]; // vetor de vértices visitados

        for(int i = 0; i < this->nodes; ++i) {
           dist[i] = INT_MAX; // atribuindo infinito (maior valor inteiro) as distâncias
           visited[i] = false; // marcando todos os vértices como não visitados
        }

        dist[origin] = 0; // a distância do vértice de origem para ele mesmo é 0


        // inserir na MinHeap aqui;

        while() { // enquanto tiver elemento na MinHeap
            // extrair o vértice e o peso do topo da MinHeap
            // obter o vértice
            // remover da fila

            int u;

            if(!visited[u]) {
                visited[u] = false;

                // percorrer a lista com um interator

                // percorrer os vértices adjacentes de u

                    // obter o vértice adjacente e o custo da aresta
            }

        }

    }

};

struct MinHeap {

};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double p, w;
    int numNodes, links, nodeX, nodeY, speed, cost, origin, destiny;

    cin >> p;
    cin >> numNodes >> links;

    Graph g(numNodes);

    for(int i = 0; i < links; ++i) {
        cin >> nodeX >> nodeY >> speed >> cost;

        w = (p*speed + ((1-p)*cost)) / (speed+cost);

        NodeWeight *x = new NodeWeight(nodeY, w);
        NodeWeight *y = new NodeWeight(nodeX, w);

        g.addEdge(nodeX, nodeY, x, y);

    }

    while(cin.eof()) {
        cin >> origin >> destiny;

        int *shortest_path;
        shortest_path = g.dijkstra(origin, destiny);

        for(int i = 0; i < (sizeof(shortest_path) / sizeof(*shortest_path)); ++i) { // prescisa ajeitar
            cout << shortest_path[i];

            if(i < sizeof(shortest_path) / sizeof(*shortest_path) - 1) { // prescisa ajeitar
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}
