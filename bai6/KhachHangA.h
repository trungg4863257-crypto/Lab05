#pragma once
#include "KhachHang.h"

class KhachHangA : public KhachHang {
public:

    double tinhTien() override {

        double tienHang =
            soLuong * donGia;

        return tienHang * 1.1;
    }
};
