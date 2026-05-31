#pragma once
#include "GiaSuc.h"

class De : public GiaSuc {
    public {

        void keu() override {
            cout << "De: Mee Mee\n";
        }

        int choSua() override {
            return 8;
        }
    };