#include <iostream>
#include <list>
#define endl '\n'

using namespace std;

struct Graph {

}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double p;
    int n, m, nodeX, nodeY, speed, cost, origin, destiny;
    int[] shortest_path;

    cin >> p;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> nodeX >> nodeY >> speed >> cost;


    }

    while (cin.hasNextInt()) {
        cin >> origin >> destiny;

        shortest_path = dijkstra(origin, destiny);

        for (int i = 0; i < shortest_path.size(); ++i) {
            cout << shortest_path[i];

            if (i < shortest_path.size() - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        } 
    }

    return 0;
}
