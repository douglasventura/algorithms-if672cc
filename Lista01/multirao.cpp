#include <iostream>
#define endl '\n'

using namespace std;

struct Node {
    int id;
    int hours;
    int company;
    int originalPos;
    Node *next;

    Node(int id, int hours, int company, int originalPos) : id(id), hours(hours), company(company), originalPos(originalPos), next(nullptr) {}

};

struct MyQueue {
    Node *head;
    Node *tail;

    MyQueue() : head(nullptr), tail(nullptr) {}

    void insert(Node *n) {
        if (!this->head) {
            this->head = n;
            this->tail = n;
        } else {
            this->tail->next = n;
            this->tail = n;
        }
    }

    Node* remove() {
        Node *removed = nullptr;
        if (this->head == this->tail) {
            removed = this->head;
            this->head = nullptr;
            this->tail = nullptr;
        } else if (this->head->next == this->tail) {
            removed = this->head;
            this->head = this->tail;
        } else {
            removed = this->head;
            this->head = this->head->next;
        }
        removed->next = nullptr;
        return removed;
    }

};

struct MyStack {
    Node *top;

    MyStack() : top(nullptr) {}

    void push(Node *n) {
        if (!this->top) {
            this->top = n;
        } else {
            n->next = this->top;
            this->top = n;
        }
    }

    Node* pop() {
        Node *removed = nullptr;

        if (this->top) {
            removed = this->top;
            this->top = this->top->next;
        }
        removed->next = nullptr;
        return removed;
    }

};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int e, qProcess, totalProcess, id, hours, numJugdes;

    cin >> e;
    totalProcess = 0;

    MyQueue f[e];

    for (int i = 0; i < e; ++i) {
        cin >> qProcess;
        totalProcess += qProcess;

        for (int j = 0; j < qProcess; ++j) {
            cin >> id >> hours;
            f[i].insert(new Node(id, hours, i, j));
        }
    }

    cin >> numJugdes;

    MyStack p[numJugdes];

    int count, curJudge, curCompany;
    count = curJudge = curCompany = 0;

    while (count < totalProcess) {
        if (f[curCompany].head) {
            p[curJudge].push(f[curCompany].remove());
            curJudge++;
            count++;
        }

        curCompany++;

        if (curJudge == numJugdes) {
            curJudge = 0;
        }
        if (curCompany == e) {
            curCompany = 0;
        }
    }

    MyStack aux;
    int q = 0;

    for(int i = 0; i < numJugdes; i++) {
        for(int j = 0; j < numJugdes; j++) {
            if (i != j && p[i].top->id == j) {
                p[j].push(p[i].pop());
            } else if (i != j) {
                aux.push(p[i].pop());
            }
            if (i != j && p[i].top) {
                j--;
            } else if (i != j) {
                p[i] = aux;
                aux.top = nullptr;
            }
        }

    }

    int qHours[numJugdes];
    int auxHours[numJugdes];

    for (int k = 0; k < numJugdes; ++k) {
        cin >> qHours[k];
        auxHours[k] = qHours[k];
    }

    while(totalProcess > 0) {
        for(int j = 0; j < 24; j++) {
            for(int k = 0; k < numJugdes; k++) {
                if(p[k].top) {
                    if(qHours[k] > 0) {
                        qHours[k] -= 1;
                        p[k].top->hours -= 1;

                        if(p[k].top->hours <= 0) {
                            cout << k << " " << p[k].top->company << " " << p[k].top->originalPos << endl;
                            p[k].pop();
                            totalProcess--;
                        }
                    }
                }
            }
        }

        for(int j = 0; j < numJugdes; j++) {
            qHours[j] = auxHours[j];
        }
    }

    return 0;
}