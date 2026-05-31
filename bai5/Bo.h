#pragma once
#include "GiaSuc.h"

class Bo : public GiaSuc {
public:

    void keu() override {
        cout << "Bo: Moo Moo\n";
    }

    int choSua() override {
        return 20;
    }
};