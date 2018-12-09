#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string *s = new string();
int bestSolution;

int branch_bound(deque<int>* inputLemmings, deque<int>* outputLemmings, stack<int>* pilha, int numLemmings, int lb, string* way) {

    int lowerBound;
    if (pilha->size() > lb) {
        lowerBound = pilha->size();
    } else {
        lowerBound = lb;
    }
    
    if (lowerBound > bestSolution) {
        return bestSolution;
    } else {
        if (way->size() == 2 * numLemmings) {
            if (!outputLemmings->empty()) {
                return bestSolution;
            }
            if (lowerBound < bestSolution) {
                *s = *way;

                bestSolution = lowerBound;
                return lowerBound;
            } else if (bestSolution == lowerBound){
                for (int i = 0; i < way->size(); ++i) {

                    if ((*way)[i] != (*s)[i]) {
                        if ((*way)[i] < (*s)[i]) {
                            *s = *way;
                            return lowerBound;
                        } else {
                            return bestSolution;
                        }
                    }
                }
            } else {
                return bestSolution;
            }
        } else {
            int r = bestSolution;

            for (int i = 0; i < 2; ++i) {
                int a;

                if (i == 0) {
                    if (inputLemmings->empty()) {
                        continue;
                    }
                    a = inputLemmings->front();
                    inputLemmings->pop_front();
                    pilha->push(a);
                    way->push_back('O');

                    r = branch_bound(inputLemmings, outputLemmings, pilha, numLemmings, lowerBound, way);

                    inputLemmings->push_front(pilha->top());
                    pilha->pop();
                    way->pop_back();

                } else {
                    if (!pilha->empty() && pilha->top() == outputLemmings->front()) {
                        a = pilha->top();
                        pilha->pop();
                        int b = outputLemmings->front();
                        outputLemmings->pop_front();
                        way->push_back('Y');

                        r = branch_bound(inputLemmings, outputLemmings, pilha, numLemmings, lowerBound, way);

                        pilha->push(a);
                        way->pop_back();
                        outputLemmings->push_front(b);

                    }
                }

            }
            return r;
        }
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int f, numLemmings, lemmings, solution;
    string *way = new string();

    cin >> f;

    for (int i = 0; i < f; ++i) {
        cin >> numLemmings;

        deque<int> *inputLemmings = new deque<int>(0);
        deque<int> *outputLemmings = new deque<int>(0);
        bestSolution = numLemmings;
        for (int j = 0; j < numLemmings; ++j) {
            cin >> lemmings;
            inputLemmings->push_back(lemmings);
        }

        for (int k = 0; k < numLemmings; ++k) {
            cin >> lemmings;
            outputLemmings->push_back(lemmings);
        }

        stack<int> *pilha = new stack<int>();
        bestSolution = numLemmings;

        solution = branch_bound(inputLemmings, outputLemmings, pilha, numLemmings, 0, way);

        cout << *s << " " << bestSolution << endl;
    }

    return 0;
}
