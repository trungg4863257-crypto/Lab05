#pragma once
#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien {
private:
    double luongCanBan;
    int soSanPham;

public:
    void nhap() override {
        NhanVien::nhap();

        cout << "Luong can ban: ";
        cin >> luongCanBan;

        cout << "So san pham: ";
        cin >> soSanPham;
    }

    double tinhLuong() override {
        return luongCanBan + soSanPham * 5000;
    }

    void xuat() override {
        NhanVien::xuat();
        cout << "Luong: " << tinhLuong() << endl;
    }
};
