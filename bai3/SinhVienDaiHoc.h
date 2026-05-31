#pragma once
#include "SinhVien.h"

class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;

public:
    void nhap() override {
        SinhVien::nhap();

        cin.ignore();

        cout << "Ten luan van: ";
        getline(cin, tenLuanVan);

        cout << "Diem luan van: ";
        cin >> diemLuanVan;
    }

    bool duDieuKienTotNghiep() override {
        return tongTinChi >= 170 &&
            diemTB >= 5 &&
            diemLuanVan >= 5;
    }

    void xuat() override {
        SinhVien::xuat();

        cout << "Ten luan van: "
            << tenLuanVan << endl;

        cout << "Diem luan van: "
            << diemLuanVan << endl;
    }
};