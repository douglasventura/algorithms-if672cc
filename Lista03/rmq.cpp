#include <iostream>
#define endl '\n'

using namespace std;

struct node {
    int l;
    int r;
    int value;
    node *right;
    node *left;

    node(int l, int r, int value) : l(l), r(r), value(value), root(nullptr) {}
};


struct binary_tree {
    node *root;

    binary_tree(int *arr_sensors[], int l, int r) {
        this->right = nullptr;
        this->left = nullptr;

        if(l == r) {
            this->root->l = l;
            this->root->r = r;
        } else if () {

        }
    }
};


int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_sensors, sensors, a, b;
    string event;

    cin >> num_sensors;
    int arr_sensors[num_sensors];
    event = " ";

    for (int i = 0; i < num_sensors; ++i) {
        cin >> sensors;
        arr_sensors[i] = sensors;
    }

    while (event != "END") {
        cin >> event >> a >> b;

        if (event == "UPD") {

        } else if (event == "RMQ") {

        } else if (event == "PRT") {

        }
    }

    return 0;
}