#pragma once
#include "GiaoDich.h"

class GiaoDichNhaPho : public GiaoDich {
private:
    string loaiNha;
    string diaChi;

public:
    void nhap() override {
        GiaoDich::nhap();

        cin.ignore();

        cout << "Loai nha (cao cap/thuong): ";
        getline(cin, loaiNha);

        cout << "Dia chi: ";
        getline(cin, diaChi);
    }

    double thanhTien() override {
        if (loaiNha == "cao cap")
            return dienTich * donGia;

        return dienTich * donGia * 0.9;
    }

    void xuat() override {
        GiaoDich::xuat();

        cout << "Loai nha: " << loaiNha << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Thanh tien: " << thanhTien() << endl;
    }
};
#pragma once
