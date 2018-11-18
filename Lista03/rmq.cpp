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

        if (begin == end) {
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
        if (a > b || a > node->end || b < node->begin) {
            return INT_MAX;
        } else if (a == node->begin && b == node->end) {
            return node->value;
        } else {
            int h = (node->begin + node->end)/2;
            return min(RMQ(node->left, max(a, node->begin), min(b, h)), RMQ(node->right, max(a, h+1), min(b, node->end)));
        }
    }

    void UPD(Node *node, int i, int x) {
        if (node->begin == i && node->end == i) {
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

    void PRT(Node *node, int a, int b) {
        if (node->end > node->begin) {
            if (node->left->end >= a) {
                PRT(node->left, a, b);
                cout << node->left->value << " ";
            }

            if (node->right->begin <= b) {
                PRT(node->right, a, b);
                cout << node->right->value << " ";
            }

        }

    }

};


int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_sensors, sensors, i, x, a, b;
    string event;

    cin >> num_sensors;
    int *arraySensors = new int[num_sensors];
    event = " ";

    for (int i = 0; i < num_sensors; ++i) {
        cin >> sensors;
        arraySensors[i] = sensors;
    }

    Node *node = new Node(0, num_sensors - 1, arraySensors);
    Segment_tree *tree = new Segment_tree(node);

    while (event != "END") {
        cin >> event;

        if (event == "UPD") {
            cin >> i >> x;
            tree->UPD(tree->root, i, x);
        } else if (event == "RMQ") {
            cin >> a >> b;
            cout << tree->RMQ(tree->root, a, b) << endl;
        } else if (event == "PRT") {
            cin >> a >> b;
            tree->PRT(tree->root, a, b);
            cout << node->value << endl;
        }
    }

    return 0;
}