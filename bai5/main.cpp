#include <iostream>
#include <vector>

#include "Bo.h"
#include "Cuu.h"
#include "De.h"

using namespace std;

int main() {

    vector<GiaSuc*> nongTrai;

    nongTrai.push_back(new Bo());
    nongTrai.push_back(new Bo());

    nongTrai.push_back(new Cuu());
    nongTrai.push_back(new Cuu());

    nongTrai.push_back(new De());

    int tongSua = 0;

    cout << "Tieng keu cac gia suc:\n";

    for (auto gs : nongTrai) {

        gs->keu();

        tongSua += gs->choSua();
    }

    cout << "\nTong luong sua: "
        << tongSua << " lit";

    for (auto gs : nongTrai)
        delete gs;

    return 0;
}