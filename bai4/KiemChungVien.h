#pragma once
#include "NhanVien.h"

class KiemChungVien : public NhanVien {
private:
    int soLoi;

public:
    void nhap() override {
        NhanVien::nhap();

        cout << "So loi phat hien: ";
        cin >> soLoi;
    }

    double tinhLuong() override {
        return luongCoBan + soLoi * 50000;
    }

    void xuat() override {
        cout << "\n=== KIEM CHUNG VIEN ===\n";
        NhanVien::xuat();
    }
};
