#include <iostream>
#include <algorithm>
#include <list>
#define endl '\n'

using namespace std;

void Knapsack_01(int* pItem, int* wItem, int wKnapsack, int numItems) {
    int **d = new int*[numItems +1];
    
    for(int i = 0; i < numItems +1; ++i){
        d[i] = new int[wKnapsack +1];
    }
    
    for(int m = 1; m <= numItems; ++m) {
        for(int k = 1; k <= wKnapsack; ++k) {
            if(wItem[m-1] <= k) {
                d[m][k] = max(d[m-1][k], pItem[m-1] + d[m-1][k - wItem[m-1]]);
            } else {
                d[m][k] = d[m-1][k];
            }
        }

    }

    int res = d[numItems][wKnapsack];
    list<int> *itemsSelected = new list<int>;

    int w = wKnapsack;
    for(int i = numItems; i > 0 && res > 0; i--) {
        if(res == d[i - 1][w]) {
            continue;
        } else {
            itemsSelected->push_front(i - 1);
            res = res - pItem[i - 1];
            w = w - wItem[i - 1];
        }
    }

    cout << d[numItems][wKnapsack] << endl;

    while(!itemsSelected->empty()) {
        cout << itemsSelected->front();
        itemsSelected->pop_front();

        if(!itemsSelected->empty()) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numItems, wKnapsack;

    cin >> numItems >> wKnapsack;

    int pItem[numItems];
    int wItem[numItems];

    for(int i = 0; i < numItems; ++i) {
        cin >> pItem[i] >> wItem[i];
    }

    Knapsack_01(pItem, wItem, wKnapsack, numItems);

    return 0;
}