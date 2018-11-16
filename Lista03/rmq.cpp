#include <iostream>
#define endl '\n'

using namespace std;

struct Node {
    int begin;
    int end;
    int value;
    Node *right;
    Node *left;

    Node(int begin, int end, int* array) {
        this->begin = begin;
        this->end = end;

        if(begin == end) {
            this->value = array[begin];
            this->right = nullptr;
            this->left = nullptr;
        } else {
            int interval = (begin + end)/2;
            this->left = new Node(begin, interval, array);
            this->right = new Node(interval + 1, end, array);
            this->value = min(this->left->value, this->right->value);
        }
    }
};


struct Segment_tree {
    Node *root;

    Segment_tree(Node *root) {
        this->root = root;
    }

    int RMQ(Node *node,int a, int b) {
        if(a > b || a > node->end || b < node->begin) {
            return INT_MAX;
        } else if(a == node->begin && b == node->end) {
            return node->value;
        } else {
            int h = (node->begin + node->end)/2;
            return min(RMQ(node->left, max(a, node->begin), min(b, h)), RMQ(node->right, max(a, h+1), min(b, node->end)));
        }
    }

    void UPD(Node *node, int i, int x) {
        if(node->begin == i && node->end == i) {
            node->value = x;
        } else {
            int h = (node->begin + node->end)/2;
            if(i <= h) {
                UPD(node->left, i, x);
            } else {
                UPD(node->right, i, x);
            }
            node->value = min(node->left->value, node->right->value);
        }
    }


};


int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int *array = new int[10];
    for (int i = 0; i < 10; ++i) {
        array[i] = i;
    }

    Node *teste = new Node(0,9, array);

    Segment_tree *arvore = new Segment_tree(teste);
    cout << arvore->RMQ(arvore->root, 0,9) << endl;

    arvore->UPD(arvore->root , 4, -1);
    cout << arvore->RMQ(arvore->root, 0, 9);

    /*
    int num_sensors, sensors, a, b;
    string event;

    cin >> num_sensors;
    int vecSensors[num_sensors];
    event = " ";

    for (int i = 0; i < num_sensors; ++i) {
        cin >> sensors;
        vecSensors[i] = sensors;
    }

    while (event != "END") {
        cin >> event >> a >> b;

        if (event == "UPD") {

        } else if (event == "RMQ") {

        } else if (event == "PRT") {

        }
    }
     */
    return 0;
}