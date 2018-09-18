#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct node {
    int id;
    int hours;
    node *next;

    node(int id, int hours) : id(id), hours(hours), next(nullptr) {}

};

struct queue {
    node *head;
    node *tail;

    queue() : head(nullptr), tail(nullptr) {}

    void insert(int id, int hours) {
        node *n = new node(id, hours);
        if (!this->tail) {
            this->head = n;
            this->tail = n;
        } else {
            this->tail->next = n;
            this->tail = n;
        }
    }

    void remove() {
        if (this->head) {
            this->head->next = ;
        }
    }

    int size() {
        if (this->head) {

        } else if (!this->head) {
            return 0;
        }
    }

};

struct stack {
    node *head;
    node *tail;

    stack() : head(nullptr), tail(nullptr) {}
    
};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int e, process, id, p_hours, w_hours;

    cin >> e;
    Queue *elements = new Queue[e];

    for (int i = 0; i < e; ++i) {
        cin >> process;
        for (int j = 0; j < process; ++j) {
            cin >> id, p_hours;
            elements[i].insert(id, p_hours);
        }
    }


    return 0;
}