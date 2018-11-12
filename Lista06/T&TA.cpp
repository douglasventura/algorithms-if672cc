#include <iostream>
#include <list>
#define endl '\n'

using namespace std;

struct NodeWeight { // objeto nó com o peso.
    int link; // ligacao com o nó
    double weight; // peso do nó

    NodeWeight(int link, double weight) : link(link), weight(weight) {}

};


struct MinHeap {
    NodeWeight **f;
    int arraySize;
    int heapSize;

    MinHeap() {
        this->f = new NodeWeight*[2];
        this->arraySize = 2;
        this->heapSize = 0;
    }

    void heap_insert(NodeWeight *n) {
        if (this->arraySize == this->heapSize) {
            double_size();
        }
        f[this->heapSize] = n;
        this->heapSize++;
        bubble_up(heapSize);
    }

    void double_size() {
        NodeWeight **aux = new NodeWeight*[2* this->arraySize];
        for (int i = 0; i < this->arraySize; ++i) {
            aux[i] = this->f[i];
        }
        this->f = aux;
        this->arraySize = 2* this->arraySize;
    }

    void bubble_up(int heapSize) {
        int i = heapSize - 1;

        while (i > 0 && this->f[i]->weight < this->f[(i-1)/2]->weight) {
            NodeWeight *aux2 = this->f[i];
            this->f[i] = f[(i-1)/2];
            this->f[(i-1)/2] = aux2;
            i = (i-1)/2;
        }
    }

    NodeWeight* heap_extract() {
        NodeWeight *aux3 = this->f[0];
        this->f[0] = this->f[this->heapSize - 1];
        this->f[this->heapSize - 1] = nullptr;
        this->heapSize--;
        heapify(0);

        return aux3;
    }

    void heapify(int i) {
        int m = i;
        int l = (2 * i) + 1;
        int r = (2 * i) + 2;

        if (l < this->heapSize && this->f[l]->weight <= this->f[m]->weight) {
            m = l;
        }

        if (r < this->heapSize && this->f[r]->weight <= this->f[m]->weight) {
            m = r;
        }

        if (m != i) {
            NodeWeight *aux4 = this->f[i];
            this->f[i] = this->f[m];
            this->f[m] = aux4;
            heapify(m);
        }

    }
};


struct Graph {
    int nodes; // número de nós
    list<NodeWeight> *adjacent; // lista dos vértices adjacentes com o peso

    Graph(int nodes) {
        this->nodes = nodes;
        this->adjacent = new list<NodeWeight>[this->nodes];
    }

    void addEdge(int nodeX, int nodeY, NodeWeight *x, NodeWeight *y) { // adiciona a conexão entre os vértices
        this->adjacent[nodeX].push_back(*x);
        this->adjacent[nodeY].push_back(*y);
    }

    int* dijkstra(int origin, int destiny) {
        double weights[this->nodes]; // vetor com os pesos entre os vértices
        int *precursor = new int[this->nodes]; // vetor com os precusores do menor caminho
        bool visited[this->nodes]; // vetor de vértices visitados


        for(int i = 0; i < this->nodes; ++i) {
            weights[i] = INT_MAX;
            precursor[i] = -1;
            visited[i] = false;
        }

        weights[origin] = 0;
        precursor[0] = origin;

        MinHeap *h = new MinHeap();
        NodeWeight *aux = new NodeWeight(origin, 0);

        h->heap_insert(aux);

        int index = 1;

        while(h) { // enquanto tiver elemento na MinHeap
            aux = h->heap_extract();
            int u = aux->link;

            if(!visited[u]) {
                visited[u] = true;

                list<NodeWeight>::iterator it;

                for (it = this->adjacent[u].begin(); it != this->adjacent[u].end() && !this->adjacent[u].empty(); it++) {
                    int v = it->link;
                    double c = it->weight;

                    if (v != destiny && weights[v] > weights[u] + c) {
                        weights[v] = weights[u] + c;
                        aux = new NodeWeight(v, weights[v]);
                        h->heap_insert(aux);

                    } else {
                        precursor[index] = destiny;
                        return precursor;
                    }

                }

                precursor[index] = h->heap_extract()->link;
                index++;

            }

        }

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

        NodeWeight *x = new NodeWeight(nodeY, w);
        NodeWeight *y = new NodeWeight(nodeX, w);

        g.addEdge(nodeX, nodeY, x, y);

    }

    while(cin) {
        cin >> origin >> destiny;

        int *precursor;
        precursor = g.dijkstra(origin, destiny);

        for(int i = 0; precursor[i] != -1; ++i) {
            cout << precursor[i];

            if(precursor[i+1] != - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}
