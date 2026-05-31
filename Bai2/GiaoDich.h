#pragma once
#include <iostream>
#include <string>
using namespace std;

class GiaoDich {
protected:
    string maGD;
    string ngayGD;
    double donGia;
    double dienTich;

public:
    virtual void nhap() {
        cin.ignore();

        cout << "Ma giao dich: ";
        getline(cin, maGD);

        cout << "Ngay giao dich (dd/mm/yyyy): ";
        getline(cin, ngayGD);

        cout << "Don gia: ";
        cin >> donGia;

        cout << "Dien tich: ";
        cin >> dienTich;
    }

    virtual void xuat() {
        cout << "Ma GD: " << maGD << endl;
        cout << "Ngay GD: " << ngayGD << endl;
        cout << "Don gia: " << donGia << endl;
        cout << "Dien tich: " << dienTich << endl;
    }

    virtual double thanhTien() = 0;

    string getNgayGD() {
        return ngayGD;
    }

    virtual ~GiaoDich() {}
};

