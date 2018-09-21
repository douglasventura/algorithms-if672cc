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

};

int binary_search(int id, archive *oldFiles[], int num_oldFiles) {
    int l = 0;
    int r = num_oldFiles - 1;
    int m;

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

int find_element(string name, list *drawer) {
    archive *cur = drawer->front;
    int position = 1;

    while (cur->next && cur->next->name != name) {
        cur = cur->next;
        position++;
    }
    return position;
}


int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_oldFiles, id, num_drawers, num_fileTransf, id_transf, position, fileTransf, num_consultFiles, drawer_position;
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
        position = binary_search(id_transf, oldFiles, num_oldFiles);
        fileTransf = hash_table(oldFiles[position]->name, num_drawers);
        drawer[fileTransf].add(oldFiles[position]);
    }

    cin >> num_consultFiles;

    for (int l = 0; l < num_drawers; ++l) {
        cout << l << ": " << drawer[l].quant << endl;
    }

    for (int k = 0; k < num_consultFiles; ++k) {
        cin >> consultFile;

        drawer_position = hash_table(consultFile, num_drawers);
        position = find_element(consultFile, &drawer[drawer_position]);

        cout << k << ": " << position << endl;
    }

    return 0;
};