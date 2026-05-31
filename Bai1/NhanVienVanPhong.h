#pragma once
#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;

public:
    void nhap() override {
        NhanVien::nhap();

        cout << "So ngay lam viec: ";
        cin >> soNgayLamViec;
    }

    double tinhLuong() override {
        return soNgayLamViec * 100000;
    }

    void xuat() override {
        NhanVien::xuat();
        cout << "Luong: " << tinhLuong() << endl;
    }
};#pragma once
