#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

string branch_bound(int* inputLemmings[], int* outputLemmings[], int begin, int end) {

}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int f, numLemmings, lemmings;
    string solution;

    cin >> f;

    for (int i = 0; i < f; ++i) {
        cin >> numLemmings;

        int* inputLemmings = new int(numLemmings);
        int* outputLemmings = new int(numLemmings);

        for (int j = 0; j < numLemmings; ++j) {
            cin >> lemmings;
            inputLemmings[i] = lemmings;
        }

        for (int k = 0; k < numLemmings; ++k) {
            cin >> lemmings;
            outputLemmings[k] = lemmings;
        }
    
    solution = branch_bound(&inputLemmings, &outputLemmings, 0, numLemmings - 1);

    cout << solution << endl;

    }

    return 0;
}
