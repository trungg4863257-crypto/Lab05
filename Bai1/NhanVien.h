#pragma once
#include <iostream>
#include <string>
using namespace std;

class NhanVien {
protected:
    string hoTen;
    string ngaySinh;

public:
    virtual void nhap() {
        cin.ignore();
        cout << "Ho ten: ";
        getline(cin, hoTen);

        cout << "Ngay sinh: ";
        getline(cin, ngaySinh);
    }

    virtual void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Ngay sinh: " << ngaySinh << endl;
    }

    virtual double tinhLuong() = 0;

    virtual int getTuoi() {
        int nam;
        string tmp = ngaySinh.substr(6, 4);
        nam = stoi(tmp);
        return 2026 - nam;
    }

    virtual ~NhanVien() {}
};
