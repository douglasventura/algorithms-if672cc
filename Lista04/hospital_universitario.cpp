#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct pacient {
    int age;
    int urgency;
    int service;

    pacient (int age, int urgency, int service) : age(age), urgency(urgency), service(service) {}    
}

class Heap {
    

}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_services, age, urgency, service;
    string command;

    cin << num_services;
    cin << command;

    while (command != "END") {
        cin << command;
        
        if (command == "CIN") {
            cin << age, urgency, service;



        } else if (command == "NXT") {
            


        } else if (command == "STD") {



        }
    }

    return 0;
}
