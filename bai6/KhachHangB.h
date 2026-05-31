#pragma once
#include "KhachHang.h"

class KhachHangB : public KhachHang {
private:
    int soNamThanThiet;

public:

    void nhap(ifstream& fin) override {

        KhachHang::nhap(fin);

        fin >> soNamThanThiet;
        fin.ignore();
    }

    double tinhTien() override {

        double giamGia =
            soNamThanThiet * 0.05;

        if (giamGia > 0.5)
            giamGia = 0.5;

        double tienHang =
            soLuong * donGia;

        return tienHang * (1 - giamGia) * 1.1;
    }
};
