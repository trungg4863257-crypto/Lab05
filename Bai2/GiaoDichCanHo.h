#pragma once
#include "GiaoDich.h"

class GiaoDichCanHo : public GiaoDich {
private:
    string maCan;
    int tang;

public:
    void nhap() override {
        GiaoDich::nhap();

        cin.ignore();

        cout << "Ma can: ";
        getline(cin, maCan);

        cout << "Tang: ";
        cin >> tang;
    }

    double thanhTien() override {
        if (tang == 1)
            return dienTich * donGia * 2;

        if (tang >= 15)
            return dienTich * donGia * 1.2;

        return dienTich * donGia;
    }

    void xuat() override {
        GiaoDich::xuat();

        cout << "Ma can: " << maCan << endl;
        cout << "Tang: " << tang << endl;
        cout << "Thanh tien: " << thanhTien() << endl;
    }
};
#pragma once
