#pragma once
#include "GiaoDich.h"

class GiaoDichDat : public GiaoDich {
private:
    char loaiDat;

public:
    void nhap() override {
        GiaoDich::nhap();

        cout << "Loai dat (A/B/C): ";
        cin >> loaiDat;
    }

    double thanhTien() override {
        if (loaiDat == 'A')
            return dienTich * donGia * 1.5;

        return dienTich * donGia;
    }

    void xuat() override {
        GiaoDich::xuat();

        cout << "Loai dat: " << loaiDat << endl;
        cout << "Thanh tien: " << thanhTien() << endl;
    }
};
