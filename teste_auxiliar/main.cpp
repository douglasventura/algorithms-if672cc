#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct node {
    int num;
    node *prox; 

    node(int n): num(n), prox(nullptr){}
};

struct fila {
    int quant = 0;
    node *front;
    node *hear;

    fila(): front(new node(0)), hear(nullptr){}

    void add(node *novo) {
        if (!this->hear) {
            this->front->prox = novo;
            this->hear = novo;
        } else {
            this->hear->prox = novo;
            this->hear = novo;
        }
        quant++;
    }

    void remove() {
        if (quant == 1) {
            this->front->prox = nullptr;
            this->hear = nullptr;
            quant--;
        } else {
            this->front->prox = this->front->prox->prox;
            quant--;
        }
    
    }

    void print(){
        node *cur = this->front->prox;
        while(cur){
            cout << cur->num << " ";
            cur = cur->prox;
        }
        cout << endl;
    }
};




int main(int argc, char *argv[]) {
    
    fila f;
    
    f.add(new node(1));
    f.add(new node(2));
    f.add(new node(5));

     

    f.print();

    cout << "______________________________" << endl;

    f.remove();
    f.print();

    cout << "______________________________" << endl;

    f.remove();
    f.print();

    cout << "______________________________" << endl;

    f.remove();
    f.print();


    return 0;
}
