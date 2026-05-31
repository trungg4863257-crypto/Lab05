#include <iostream>
#include <vector>

#include "GiaoDichDat.h"
#include "GiaoDichNhaPho.h"
#include "GiaoDichCanHo.h"

using namespace std;

int main() {

    vector<GiaoDich*> ds;

    int nDat, nNhaPho, nCanHo;

    cout << "Nhap so giao dich dat: ";
    cin >> nDat;

    for (int i = 0; i < nDat; i++) {
        cout << "\nGiao dich dat " << i + 1 << endl;

        GiaoDich* gd = new GiaoDichDat();
        gd->nhap();

        ds.push_back(gd);
    }

    cout << "\nNhap so giao dich nha pho: ";
    cin >> nNhaPho;

    for (int i = 0; i < nNhaPho; i++) {
        cout << "\nGiao dich nha pho " << i + 1 << endl;

        GiaoDich* gd = new GiaoDichNhaPho();
        gd->nhap();

        ds.push_back(gd);
    }

    cout << "\nNhap so giao dich can ho: ";
    cin >> nCanHo;

    for (int i = 0; i < nCanHo; i++) {
        cout << "\nGiao dich can ho " << i + 1 << endl;

        GiaoDich* gd = new GiaoDichCanHo();
        gd->nhap();

        ds.push_back(gd);
    }

    cout << "\n===== DANH SACH GIAO DICH =====\n";

    for (auto gd : ds) {
        gd->xuat();
        cout << "---------------------\n";
    }

    // Tổng số lượng từng loại

    int demDat = 0;
    int demNhaPho = 0;
    int demCanHo = 0;

    double tongTienCanHo = 0;

    GiaoDichNhaPho* maxNhaPho = nullptr;

    for (auto gd : ds) {

        if (dynamic_cast<GiaoDichDat*>(gd))
            demDat++;

        if (dynamic_cast<GiaoDichNhaPho*>(gd)) {
            demNhaPho++;

            GiaoDichNhaPho* np =
                dynamic_cast<GiaoDichNhaPho*>(gd);

            if (maxNhaPho == nullptr ||
                np->thanhTien() >
                maxNhaPho->thanhTien())
                maxNhaPho = np;
        }

        if (dynamic_cast<GiaoDichCanHo*>(gd)) {
            demCanHo++;

            tongTienCanHo += gd->thanhTien();
        }
    }

    cout << "\nTong giao dich dat: "
        << demDat << endl;

    cout << "Tong giao dich nha pho: "
        << demNhaPho << endl;

    cout << "Tong giao dich can ho: "
        << demCanHo << endl;

    // Trung bình thành tiền căn hộ

    if (demCanHo > 0)
        cout << "\nTrung binh thanh tien can ho: "
        << tongTienCanHo / demCanHo
        << endl;

    // Nhà phố giá trị cao nhất

    if (maxNhaPho != nullptr) {
        cout << "\nGiao dich nha pho co gia tri cao nhat:\n";
        maxNhaPho->xuat();
    }

    // Giao dịch tháng 12/2024

    cout << "\n===== GIAO DICH THANG 12/2024 =====\n";

    for (auto gd : ds) {

        string ngay = gd->getNgayGD();

        if (ngay.substr(3, 2) == "12" &&
            ngay.substr(6, 4) == "2024") {

            gd->xuat();
            cout << "-----------------\n";
        }
    }

    for (auto gd : ds)
        delete gd;

    return 0;
}
