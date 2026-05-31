#pragma once
#include "GiaSuc.h"

class Cuu : public GiaSuc {
public:

    void keu() override {
        cout << "Cuu: Baa Baa\n";
    }

    int choSua() override {
        return 10;
    }
};