#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int f, numLemmings, lemmings;

    cin >> f;

    for (int i = 0; i < f; ++i) {
        cin >> numLemmings;

        queue<int> inputLemmings;
        queue<int> outputLemmings;

        for (int j = 0; j < numLemmings; ++j) {
            cin >> lemmings;
            inputLemmings.push(lemmings);
        }

        for (int k = 0; k < numLemmings; ++k) {
            cin >> lemmings;
            outputLemmings.push(lemmings);
        }

    }

    return 0;
}
