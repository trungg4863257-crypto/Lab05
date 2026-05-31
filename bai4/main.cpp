#include <iostream>
#include <vector>

#include "LapTrinhVien.h"
#include "KiemChungVien.h"

using namespace std;

int main() {

    vector<NhanVien*> ds;

    int nLTV, nKCV;

    cout << "Nhap so lap trinh vien: ";
    cin >> nLTV;

    for (int i = 0; i < nLTV; i++) {
        cout << "\nLap trinh vien "
            << i + 1 << endl;

        NhanVien* nv = new LapTrinhVien();
        nv->nhap();

        ds.push_back(nv);
    }

    cout << "\nNhap so kiem chung vien: ";
    cin >> nKCV;

    for (int i = 0; i < nKCV; i++) {
        cout << "\nKiem chung vien "
            << i + 1 << endl;

        NhanVien* nv = new KiemChungVien();
        nv->nhap();

        ds.push_back(nv);
    }

    // b. Xuất danh sách

    cout << "\n===== DANH SACH NHAN VIEN =====\n";

    double tongLuong = 0;

    for (auto nv : ds) {
        nv->xuat();
        cout << "-------------------\n";

        tongLuong += nv->tinhLuong();
    }

    // c. Lương trung bình

    double luongTB = tongLuong / ds.size();

    cout << "\nLuong trung binh: "
        << luongTB << endl;

    cout << "\n===== NHAN VIEN CO LUONG THAP HON TB =====\n";

    for (auto nv : ds) {
        if (nv->tinhLuong() < luongTB) {
            nv->xuat();
            cout << "-------------------\n";
        }
    }

    // d,e,f,g

    NhanVien* maxLuong = nullptr;
    NhanVien* minLuong = nullptr;

    LapTrinhVien* maxLTV = nullptr;
    KiemChungVien* minKCV = nullptr;

    for (auto nv : ds) {

        if (maxLuong == nullptr ||
            nv->tinhLuong() > maxLuong->tinhLuong())
            maxLuong = nv;

        if (minLuong == nullptr ||
            nv->tinhLuong() < minLuong->tinhLuong())
            minLuong = nv;

        LapTrinhVien* ltv =
            dynamic_cast<LapTrinhVien*>(nv);

        if (ltv != nullptr) {

            if (maxLTV == nullptr ||
                ltv->tinhLuong() >
                maxLTV->tinhLuong())
                maxLTV = ltv;
        }

        KiemChungVien* kcv =
            dynamic_cast<KiemChungVien*>(nv);

        if (kcv != nullptr) {

            if (minKCV == nullptr ||
                kcv->tinhLuong() <
                minKCV->tinhLuong())
                minKCV = kcv;
        }
    }

    cout << "\n===== NHAN VIEN LUONG CAO NHAT =====\n";
    if (maxLuong) maxLuong->xuat();

    cout << "\n===== NHAN VIEN LUONG THAP NHAT =====\n";
    if (minLuong) minLuong->xuat();

    cout << "\n===== LAP TRINH VIEN LUONG CAO NHAT =====\n";
    if (maxLTV) maxLTV->xuat();

    cout << "\n===== KIEM CHUNG VIEN LUONG THAP NHAT =====\n";
    if (minKCV) minKCV->xuat();

    for (auto nv : ds)
        delete nv;

    return 0;
}