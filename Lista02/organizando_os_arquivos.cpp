#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct archive {
    string name;
    int id;
    archive *next;

    archive(string name, int id) : name(name), id(id), next(nullptr) {}

};

struct queue {
    int quant = 0;
    archive *front;
    archive *back;

    archive(): front(new archive(" ", 0)), back(nullptr){}

    void add(archive *n) {
        if (!this->back) {
            this->front->next = n;
            this->back = n;
        } else {
            this->back->next = n;
            this->back = n;
        }
        quant++;
    }

    void print(){
        archive *cur = this->front->next;
        while(cur){
            cout << cur->nome << " " << cur->id << endl;
            cur = cur->next;
        }
    }
};


struct hash_table {

};


int main(int argc, har *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_oldFiles, id;
    string name;

    cin >> num_oldFiles;

    archive *oldFiles [num_oldFiles];

    for (int i = 0; i < num_oldFiles; i++) {
        cin >> name;
        cin >> id;
        archive *file = new archive(name, id);
        oldFiles[i] = file;
    }

    oldFiles.print();

    
    return 0;
};