#include <iostream>
#include <vector>
#include <list>
#define endl '\n'
#define INFINITE 10000

using namespace std;

struct MinHeap { // MinHeap construída com os nós e pesos
    vector<pair<int, double>> f;

    void heap_insert(pair<int, double> n) {
        f.push_back(n);
        bubble_up(f.size());
    }

    void heap_update(pair<int, double> n) {
        bool a = true;
        for (int i = 0; i < f.size() && a; ++i) {
            if (f[i].first == n.first) {
                f[i].second = n.second;
                bubble_up(f.size());
                a = false;
            }
        }

        if(a) {
            heap_insert(n);
        }
    }

    void bubble_up(int heapSize) {
        int i = f.size() - 1;

        while (i > 0 && this->f[i].second < this->f[(i-1)/2].second) {
            pair<int, double> aux2 = this->f[i];
            this->f[i] = f[(i-1)/2];
            this->f[(i-1)/2] = aux2;
            i = (i-1)/2;
        }
    }

    pair<int, double> heap_extract() {
        pair<int, double> aux3;
        aux3 = this->f[0];
        this->f[0] = this->f[this->f.size() - 1];
        this->f.pop_back();
        heapify(0);

        return aux3;
    }

    void heapify(int i) {
        int m = i;
        int l = (2 * i) + 1;
        int r = (2 * i) + 2;

        if (l < this->f.size() && this->f[l].second <= this->f[m].second) {
            m = l;
        }

        if (r < this->f.size() && this->f[r].second <= this->f[m].second) {
            m = r;
        }

        if (m != i) {
            pair<int, double> aux4 = this->f[i];
            this->f[i] = this->f[m];
            this->f[m] = aux4;
            heapify(m);
        }

    }
};


struct Graph {
    int nodes; // número de nós
    list<pair<int, double> > *adjacent; // lista dos vértices adjacentes com o peso

    Graph(int nodes) {
        this->nodes = nodes;
        this->adjacent = new list<pair<int, double> >[this->nodes];
    }

    void addEdge(int nodeX, int nodeY, double w) { // adiciona a conexão entre os vértices
        this->adjacent[nodeX].push_back({nodeY, w});
        this->adjacent[nodeY].push_back({nodeX, w});
    }

    int* dijkstra(int origin) {
        double weights[this->nodes]; // vetor com os pesos entre os vértices
        int *precursor = new int[this->nodes]; // vetor com os precusores do menor caminho


        for(int i = 0; i < this->nodes; ++i) {
            weights[i] = INFINITE;
            precursor[i] = -1;
        }

        weights[origin] = 0;
        precursor[origin] = origin;

        MinHeap *h = new MinHeap();
        h->heap_insert({origin, 0});

        while(h->f.size() != 0) { // enquanto tiver elemento na MinHeap
            pair<int, double> aux = h->heap_extract();

            if(aux.second > weights[aux.first]) {
                continue;
            }

            int u = aux.first;

            list<pair<int, double> >::iterator it;

            for (it = this->adjacent[u].begin(); it != this->adjacent[u].end(); it++) {
                int v = it->first;
                double c = it->second;

                if (weights[v] > weights[u] + c) {
                    weights[v] = weights[u] + c;
                    precursor[v] = u;
                    pair<int, double> aux;
                    aux = {v, weights[v]};
                    h->heap_update(aux);
                }

            }

        }

        return precursor;

    }

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
        g.addEdge(nodeX, nodeY, w);

    }

    while(cin >> origin >> destiny) {
        int *precursor;
        precursor = g.dijkstra(origin);

        vector<int> shortest_path;
        shortest_path.push_back(destiny);

        for (int j = destiny; precursor[j] != origin; j = precursor[j]) {
            shortest_path.push_back(precursor[j]);
        }

        shortest_path.push_back(origin);

        while(!shortest_path.empty()) {
            cout << shortest_path.back();
            shortest_path.pop_back();

            if(!shortest_path.empty()) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}
