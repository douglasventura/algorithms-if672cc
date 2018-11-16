#include <iostream>
#define endl '\n'

using namespace std;

struct node {
    int begin;
    int end;
    int value;
    node *right;
    node *left;

    node(int begin, int end, int value){
        int interval = (begin + end)/2;
        if(begin == end) {
                
        } else {
            left = new node(0, interval, );
            right = new node(interval + 1, end, );
        }
    }
};


struct binary_tree {
    node *root;

    binary_tree() {
        
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