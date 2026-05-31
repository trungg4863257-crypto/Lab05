#include <iostream>
#include <vector>

#include "SinhVienCaoDang.h"
#include "SinhVienDaiHoc.h"

using namespace std;

int main() {

    vector<SinhVien*> ds;

    int nCD, nDH;

    cout << "Nhap so sinh vien Cao Dang: ";
    cin >> nCD;

    for (int i = 0; i < nCD; i++) {
        cout << "\nSinh vien Cao Dang "
            << i + 1 << endl;

        SinhVien* sv =
            new SinhVienCaoDang();

        sv->nhap();

        ds.push_back(sv);
    }

    cout << "\nNhap so sinh vien Dai Hoc: ";
    cin >> nDH;

    for (int i = 0; i < nDH; i++) {
        cout << "\nSinh vien Dai Hoc "
            << i + 1 << endl;

        SinhVien* sv =
            new SinhVienDaiHoc();

        sv->nhap();

        ds.push_back(sv);
    }

    // b. Xuất danh sách sinh viên

    cout << "\n===== DANH SACH SINH VIEN =====\n";

    for (auto sv : ds) {
        sv->xuat();
        cout << "-----------------\n";
    }

    // c. Danh sách đủ điều kiện tốt nghiệp

    cout << "\n===== DU DIEU KIEN TOT NGHIEP =====\n";

    for (auto sv : ds) {
        if (sv->duDieuKienTotNghiep()) {
            sv->xuat();
            cout << "-----------------\n";
        }
    }

    // d. Danh sách không đủ điều kiện

    cout << "\n===== KHONG DU DIEU KIEN =====\n";

    for (auto sv : ds) {
        if (!sv->duDieuKienTotNghiep()) {
            sv->xuat();
            cout << "-----------------\n";
        }
    }

    // e. Sinh viên đại học điểm TB cao nhất

    SinhVienDaiHoc* maxDH = nullptr;

    for (auto sv : ds) {

        SinhVienDaiHoc* dh =
            dynamic_cast<SinhVienDaiHoc*>(sv);

        if (dh != nullptr) {

            if (maxDH == nullptr ||
                dh->getDiemTB() >
                maxDH->getDiemTB())

                maxDH = dh;
        }
    }

    if (maxDH != nullptr) {

        cout << "\n===== SINH VIEN DAI HOC DIEM TB CAO NHAT =====\n";

        maxDH->xuat();
    }

    // f. Sinh viên cao đẳng điểm TB cao nhất

    SinhVienCaoDang* maxCD = nullptr;

    for (auto sv : ds) {

        SinhVienCaoDang* cd =
            dynamic_cast<SinhVienCaoDang*>(sv);

        if (cd != nullptr) {

            if (maxCD == nullptr ||
                cd->getDiemTB() >
                maxCD->getDiemTB())

                maxCD = cd;
        }
    }

    if (maxCD != nullptr) {

        cout << "\n===== SINH VIEN CAO DANG DIEM TB CAO NHAT =====\n";

        maxCD->xuat();
    }

    // g. Đếm SV không đủ điều kiện tốt nghiệp

    int demCD = 0;
    int demDH = 0;

    for (auto sv : ds) {

        if (!sv->duDieuKienTotNghiep()) {

            if (dynamic_cast<SinhVienCaoDang*>(sv))
                demCD++;

            if (dynamic_cast<SinhVienDaiHoc*>(sv))
                demDH++;
        }
    }

    cout << "\nSo sinh vien Cao Dang khong du dieu kien: "
        << demCD << endl;

    cout << "So sinh vien Dai Hoc khong du dieu kien: "
        << demDH << endl;

    for (auto sv : ds)
        delete sv;

    return 0;
}