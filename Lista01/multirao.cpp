#include <iostream>
#define endl '\n'

using namespace std;

struct Node {
    int id;
    int hours;
    int company;
    Node *next;

    Node(int id, int hours, int company) : id(id), hours(hours), company(company), next(nullptr) {}

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
        totalProcess += totalProcess;

        for (int j = 0; j < qProcess; ++j) {
            cin >> id >> hours;
            f[i].insert(new Node(id, hours, i));
        }
    }

    cin >> numJugdes;

    MyStack p[numJugdes];

    int count, curJudge, curCompany;
    count = curJudge = curCompany = 0;

    while (count < qProcess) {
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


    return 0;
}