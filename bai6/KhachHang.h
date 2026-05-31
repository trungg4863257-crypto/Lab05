#pragma once
#include <iostream>
#include <string>
using namespace std;

class KhachHang {
protected:
    string tenKH;
    int soLuong;
    double donGia;

public:
    virtual void nhap(ifstream& fin) {
        getline(fin, tenKH);
        fin >> soLuong;
        fin >> donGia;
        fin.ignore();
    }

    virtual double tinhTien() = 0;

    string getTenKH() {
        return tenKH;
    }

    virtual ~KhachHang() {}
};
