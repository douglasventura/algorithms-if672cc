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

};

int binary_search(int id, archive *oldFiles[]) {
    int l = 0;
    int r = sizeof(oldFiles)/sizeof(oldFiles[0]) - 1;
    int m, position;

    while(l <= r) {
        m = (l+r)/2;
        if (oldFiles[m]->id == id) {
            return m;
        } else if (oldFiles[m]->id > id) {
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return -1;
}


int hash_table(string key, int num_drawers) {
    int drawer;
    int k = 0;

    for (int i = 0; i < key.length(); ++i) {
        k += (i+1) * key[i];
    }

    drawer = k % num_drawers;

    return drawer;
}


int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_oldFiles, id, num_drawers, num_fileTransf, id_transf, position, fileTransf, num_consultFiles;
    string name, consultFile;

    cin >> num_oldFiles;

    archive *oldFiles [num_oldFiles];

    for (int i = 0; i < num_oldFiles; ++i) {
        cin >> name >> id;
        archive *file = new archive(name, id);
        oldFiles[i] = file;
    }

    cin >> num_drawers >> num_fileTransf;

    list *drawer = new list [num_drawers];

    for (int j = 0; j < num_fileTransf; ++j) {
        cin >> id_transf;
        position = binary_search(id_transf, oldFiles);
        fileTransf = hash_table(oldFiles[position]->name, num_drawers);
        drawer[fileTransf].add(oldFiles[position]);
    }

    cin >> num_consultFiles;

    for (int k = 0; k < num_consultFiles; ++k) {
        // drawer[k]
    }


    return 0;
};