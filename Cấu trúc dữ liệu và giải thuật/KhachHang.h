#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class KhachHang {
public:
    string maKH;
    string tenKH;
    string sdt;
    int diemTichLuy;

    KhachHang() : diemTichLuy(0) {}
    KhachHang(string ma, string ten, string sdt, int diem)
        : maKH(ma), tenKH(ten), sdt(sdt), diemTichLuy(diem) {}

    void hienThi() const {
        cout << left;
        cout << "| " << setw(10) << maKH
            << "| " << setw(25) << tenKH
            << "| " << setw(15) << sdt
            << "| " << setw(10) << diemTichLuy << " |" << endl;
    }

    friend istream& operator>>(istream& is, KhachHang& kh) {
        cout << "Nhap ma KH: ";     getline(is >> ws, kh.maKH);
        cout << "Nhap ten KH: ";    getline(is >> ws, kh.tenKH);
        cout << "Nhap SDT: ";       getline(is >> ws, kh.sdt);
        cout << "Nhap diem tich luy: "; is >> kh.diemTichLuy;
        return is;
    }

    friend ostream& operator<<(ostream& os, const KhachHang& kh) {
        os << kh.maKH << "," << kh.tenKH << "," << kh.sdt << ","
            << kh.diemTichLuy << endl;
        return os;
    }
};