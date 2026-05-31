#pragma once
#include "SinhVien.h"

class SinhVienCaoDang : public SinhVien {
private:
    double diemThiTN;

public:
    void nhap() override {
        SinhVien::nhap();

        cout << "Diem thi tot nghiep: ";
        cin >> diemThiTN;
    }

    bool duDieuKienTotNghiep() override {
        return tongTinChi >= 120 &&
            diemTB >= 5 &&
            diemThiTN >= 5;
    }

    void xuat() override {
        SinhVien::xuat();

        cout << "Diem thi TN: "
            << diemThiTN << endl;
    }
};
