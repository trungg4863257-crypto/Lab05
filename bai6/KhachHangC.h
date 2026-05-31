#pragma once
#include "KhachHang.h"

class KhachHangC : public KhachHang {
public:

    double tinhTien() override {

        double tienHang =
            soLuong * donGia;

        return tienHang * 0.5 * 1.1;
    }
};
