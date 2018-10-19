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
        this->heapSize++;
        bubble_up(heapSize);
    }

    void double_size() {
        patient *aux = new patient[(2* this->arraySize) + 1];
        for (int i = 0; i < this->arraySize; ++i) {
            aux[i] = this->f[i];
        }
        delete this->f;
        this->f = aux;
        this->arraySize = (2* this->arraySize) + 1;
    }

    void bubble_up(int heapSize) {
        int i = heapSize - 1;
        while (i > 0 && this->f[i].urgency >= this->f[(i-1) / 2].urgency) {
            patient aux2 = this->f[i];
            this->f[i] = f[(i-1) / 2];
            this->f[(i-1) / 2] = aux2;
            i = ((i-1)/2) - 1;
        }
    }

    patient heap_extract() {
        patient aux3 = this->f[0];
        this->f[0] = this->f[this->heapSize - 1];
        this->heapSize--;
        heapify(0);

        return aux3;
    }

    void heapify(int i) {
        int m = i;
        int l = (2 * i) + 1;
        int r = (2 * i) + 2;

        if (l < this->heapSize && this->f[l].urgency <= this->f[m].urgency) {
            if (this->f[l].urgency == this->f[m].urgency) {
                if (this->f[l].age > this->f[m].age) {
                    m = l;
                } else if (this->f[l].age == this->f[m].age) {
                    if (this->f[l].arrival < this->f[m].arrival) {
                        m = l;
                    }
                }
            } else {
                m = l;
            }
        }

        if (r < this->heapSize && this->f[r].urgency <= this->f[m].urgency) {
            if (this->f[r].urgency == this->f[m].urgency) {
                if (this->f[r].age > this->f[m].age) {
                    m = r;
                } else if (this->f[r].age == this->f[m].age) {
                    if (this->f[r].arrival < this->f[m].arrival) {
                        m = r;
                    }
                }
            } else {
                m = r;
            }
        }

        if (m != i) {
            patient aux4 = this->f[i];
            this->f[i] = this->f[m];
            this->f[m] = aux4;
            heapify(m);
        }

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

    for (int i = 0; i < numServices; i++) {
        services[i] = new heap();
    }

    while (command != "END") {
        cin >> command;

        if (command == "CIN") {
            cin >> age >> urgency >> service;
            p = new patient(age, urgency, arrival);
            services[service]->heap_insert(p);
            ++arrival;

        } else if (command == "NXT") {
            cin >> index;

            if (services[index]->f) {
                *p = services[index]->heap_extract();
                cout << index << " " << p->age << " " << p->urgency << endl;
            } else {
                cout << -1 -1 -1 << endl;
            }

        } else if (command == "STD") {
            cout << 0 << " " << p->age << " " << p->urgency << endl;
        }
    }

    return 0;
}
