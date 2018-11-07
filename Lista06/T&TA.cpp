#include <iostream>
#include <list>
#define endl '\n'

using namespace std;

struct NodeWeight { // objeto nó com os pesos.
    int node, speed, cost;

    NodeWeight(int node, int speed, int cost) : node(node), speed(speed), cost(cost) {}

};

struct Graph {
    int nodes; 
    list<NodeWeight> *adjacent;

    Graph(int nodes) {
        this->nodes = nodes;
        this->adjacent = new list<NodeWeight>[this->nodes];
    }

    void addEdge(int nodeX, int nodeY, NodeWeight *x, NodeWeight *y) {
        this->adjacent[nodeX].push_back(*y);
        this->adjacent[nodeY].push_back(*x);
    }

    int* dijkstra(int origin, int destiny) {
        
    }

};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double p;
    int n, m, nodeX, nodeY, speed, cost, origin, destiny;
    int *shortest_path = new int[1];

    cin >> p;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        cin >> nodeX >> nodeY >> speed >> cost;

        NodeWeight *x = new NodeWeight(nodeX, speed, cost);
        NodeWeight *y = new NodeWeight(nodeY, speed, cost);

        g.addEdge(nodeX, nodeY, x, y);

    }

    while (cin.eof()) {
        cin >> origin >> destiny;

        shortest_path = g.dijkstra(origin, destiny);

        for (int i = 0; i < sizeof(shortest_path); ++i) {
            cout << shortest_path[i];

            if (i < sizeof(shortest_path) - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}
