#pragma once
#include <iostream>
#include <string>
using namespace std;

class SinhVien {
protected:
    string mssv;
    string hoTen;
    string diaChi;
    int tongTinChi;
    double diemTB;

public:
    virtual void nhap() {
        cin.ignore();

        cout << "MSSV: ";
        getline(cin, mssv);

        cout << "Ho ten: ";
        getline(cin, hoTen);

        cout << "Dia chi: ";
        getline(cin, diaChi);

        cout << "Tong tin chi: ";
        cin >> tongTinChi;

        cout << "Diem trung binh: ";
        cin >> diemTB;
    }

    virtual void xuat() {
        cout << "MSSV: " << mssv << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Tong tin chi: " << tongTinChi << endl;
        cout << "Diem TB: " << diemTB << endl;
    }

    virtual bool duDieuKienTotNghiep() = 0;

    double getDiemTB() {
        return diemTB;
    }

    virtual ~SinhVien() {}
};