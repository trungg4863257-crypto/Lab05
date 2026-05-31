#include <iostream>
#include <fstream>
#include <vector>

#include "KhachHangA.h"
#include "KhachHangB.h"
#include "KhachHangC.h"

using namespace std;

int main() {

    ifstream fin("XYZ.INP");

    if (!fin) {
        cout << "Khong mo duoc file!";
        return 0;
    }

    int x, y, z;

    fin >> x >> y >> z;
    fin.ignore();

    vector<KhachHang*> ds;

    // Khách hàng A

    for (int i = 0; i < x; i++) {

        KhachHang* kh =
            new KhachHangA();

        kh->nhap(fin);

        ds.push_back(kh);
    }

    // Khách hàng B

    for (int i = 0; i < y; i++) {

        KhachHang* kh =
            new KhachHangB();

        kh->nhap(fin);

        ds.push_back(kh);
    }

    // Khách hàng C

    for (int i = 0; i < z; i++) {

        KhachHang* kh =
            new KhachHangC();

        kh->nhap(fin);

        ds.push_back(kh);
    }

    fin.close();

    ofstream fout("XYZ.OUT");

    double tongThu = 0;

    fout << x << " "
        << y << " "
        << z << endl;

    for (auto kh : ds) {

        fout << kh->getTenKH()
            << endl;

        fout << kh->tinhTien()
            << endl;

        tongThu += kh->tinhTien();
    }

    fout << tongThu;

    fout.close();

    for (auto kh : ds)
        delete kh;

    cout << "Da ghi ket qua vao file XYZ.OUT";

    return 0;
}