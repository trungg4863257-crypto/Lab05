#pragma once
#include <iostream>
#include <string>
using namespace std;

class NhanVien {
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string sdt;
    string email;
    double luongCoBan;

public:
    virtual void nhap() {
        cin.ignore();

        cout << "Ma nhan vien: ";
        getline(cin, maNV);

        cout << "Ho ten: ";
        getline(cin, hoTen);

        cout << "Tuoi: ";
        cin >> tuoi;

        cin.ignore();

        cout << "So dien thoai: ";
        getline(cin, sdt);

        cout << "Email: ";
        getline(cin, email);

        cout << "Luong co ban: ";
        cin >> luongCoBan;
    }

    virtual void xuat() {
        cout << "Ma NV: " << maNV << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Email: " << email << endl;
        cout << "Luong co ban: " << luongCoBan << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }

    virtual double tinhLuong() = 0;

    virtual ~NhanVien() {}
};
