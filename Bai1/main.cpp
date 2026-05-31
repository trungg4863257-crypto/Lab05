#include <iostream>
#include <vector>
#include "NhanVienSanXuat.h"
#include "NhanVienVanPhong.h"

using namespace std;

int main() {
    vector<NhanVien*> ds;

    int nSX, nVP;

    cout << "Nhap so nhan vien san xuat: ";
    cin >> nSX;

    for (int i = 0; i < nSX; i++) {
        cout << "\nNhan vien san xuat " << i + 1 << endl;

        NhanVien* nv = new NhanVienSanXuat();
        nv->nhap();
        ds.push_back(nv);
    }

    cout << "\nNhap so nhan vien van phong: ";
    cin >> nVP;

    for (int i = 0; i < nVP; i++) {
        cout << "\nNhan vien van phong " << i + 1 << endl;

        NhanVien* nv = new NhanVienVanPhong();
        nv->nhap();
        ds.push_back(nv);
    }

    cout << "\n===== DANH SACH NHAN VIEN =====\n";

    double tongLuong = 0;

    for (auto nv : ds) {
        nv->xuat();
        cout << "-------------------\n";

        tongLuong += nv->tinhLuong();
    }

    cout << "\nTong luong cong ty phai tra: "
        << tongLuong << endl;

    // NV sản xuất lương thấp nhất
    NhanVienSanXuat* minSX = nullptr;

    for (auto nv : ds) {
        NhanVienSanXuat* sx =
            dynamic_cast<NhanVienSanXuat*>(nv);

        if (sx != nullptr) {
            if (minSX == nullptr ||
                sx->tinhLuong() < minSX->tinhLuong())
                minSX = sx;
        }
    }

    if (minSX) {
        cout << "\nNhan vien san xuat luong thap nhat:\n";
        minSX->xuat();
    }

    // NV văn phòng tuổi cao nhất
    NhanVienVanPhong* maxVP = nullptr;

    for (auto nv : ds) {
        NhanVienVanPhong* vp =
            dynamic_cast<NhanVienVanPhong*>(nv);

        if (vp != nullptr) {
            if (maxVP == nullptr ||
                vp->getTuoi() > maxVP->getTuoi())
                maxVP = vp;
        }
    }

    if (maxVP) {
        cout << "\nNhan vien van phong tuoi cao nhat:\n";
        maxVP->xuat();
    }

    for (auto nv : ds)
        delete nv;

    return 0;
}