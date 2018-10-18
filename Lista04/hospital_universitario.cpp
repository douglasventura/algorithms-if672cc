#include <iostream>
#define endl '\n'

using namespace std;


struct patient {
    int age;
    int urgency;
    int arrival;

    patient() {}
    patient(int age, int urgency, int arrival) : age(age), urgency(urgency), arrival(arrival) {}

};


struct heap {
    patient *f;
    int arraySize;
    int heapSize;

    heap() {
        this->f = nullptr;
        this->arraySize = 1;
        this->heapSize = 0;
        this->f = new patient[arraySize];
    }

    void heap_insert(patient *p) {
        if (this->arraySize == this->heapSize) {
            double_size();
        }
        f[this->heapSize] = *p;
        bubble_up(heapSize);
        this->heapSize++;
    }

    void double_size() {

    }

    void bubble_up(int heapSize) {
        int i = heapSize;
        while (i > 0 && this->f[i].urgency >= this->f[(i-1) / 2].urgency) {
            if ()
            patient *aux;
            aux = this->p[i];
            this->p[i] = p[(i-1) / 2];
            this->p[(i-1) / 2] = aux;
            i = ((i-1)/2) - 1;
        }
    }

    void heap_remove() {


    }

};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numServices, age, urgency, service, index, arrival;
    string command;
    patient *p;

    command = " ";
    arrival = 0;

    cin >> numServices;

    heap *services[numServices];

    while (command != "END") {
        cin >> command;

        if (command == "CIN") {
            cin >> age >> urgency >> service;
            p = new patient(age, urgency, arrival);
            services[service]->heap_insert(p);
            ++arrival;

        } else if (command == "NXT") {
            cin >> index;
            p = services[index]->nxt();
            cout << index << p->age << p->urgency << endl;
            services[index]->heap_remove();

        } else if (command == "STD") {
            // p = services[]->std();

            cout << 0 << p->age << p->urgency << endl;
        }
    }

    return 0;
}
