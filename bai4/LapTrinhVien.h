#pragma once
#include "NhanVien.h"

class LapTrinhVien : public NhanVien {
private:
    int soGioOT;

public:
    void nhap() override {
        NhanVien::nhap();

        cout << "So gio overtime: ";
        cin >> soGioOT;
    }

    double tinhLuong() override {
        return luongCoBan + soGioOT * 200000;
    }

    void xuat() override {
        cout << "\n=== LAP TRINH VIEN ===\n";
        NhanVien::xuat();
    }
};
