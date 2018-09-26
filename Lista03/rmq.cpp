#include <iostream>
#define endl '\n'

using namespace std;



int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_sensors, sensors, a, b;
    string event;
    
    cin >> num_sensors;
    event = " ";

    for (int i = 0; i < num_sensors; ++i) {

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