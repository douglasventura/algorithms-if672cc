#include <iostream>
#define endl '\n'

using namespace std;

struct archive {
    string name;
    int id;
    archive *next;

    archive(string name, int id) : name(name), id(id), next(nullptr) {}

};

struct list {
    int quant = 0;
    archive *front;
    archive *rear;

    list(): front(new archive(" ", 0)), rear(nullptr){}

    void add(archive *n) {
        if (!this->rear) {
            this->front->next = n;
            this->rear = n;
        } else {
            this->rear->next = n;
            this->rear = n;
        }
        quant++;
    }

    void print(){
        archive *cur = this->front->next;
        while(cur) {
            cout << cur->name << endl << cur->id << endl;
            cur = cur->next;
        }
    }
/*
    int *binary_search(int id, list *oldFiles) {
        int *cur = oldFiles[0]->front->next;
        while(cur) {
            if(cur->id == id) {
                break;
            } else {
                cur = cur->next;
            }
        }
        return &cur;
    }
*/
};


struct hash_table {

};


int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_oldFiles, id, num_drawers, num_transf, id_transf;
    string name;

    cin >> num_oldFiles;

    archive *oldFiles [num_oldFiles];

    for (int i = 0; i < num_oldFiles; ++i) {
        cin >> name >> id;
        archive *file = new archive(name, id);
        oldFiles[i] = file;
    }
/*
    cin >> num_drawers >> num_transf;

    list drawers [num_drawers];

    for (int j = 0; j < num_transf; ++j) {
        cin >> id_transf;

        drawers[j] = oldFiles.binary_search(id_transf, *oldFiles);
    }

*/
    return 0;
};