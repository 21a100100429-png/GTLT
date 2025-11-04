#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class VPP {
public:
    string maVPP;
    string tenVPP;
    string loaiVPP;
    double donGia;
    int soLuongTon;

    VPP() : donGia(0), soLuongTon(0) {}
    VPP(string ma, string ten, string loai, double gia, int sl)
        : maVPP(ma), tenVPP(ten), loaiVPP(loai), donGia(gia), soLuongTon(sl) {}

    void hienThi() const {
        cout << left;
        cout << "| " << setw(10) << maVPP
            << "| " << setw(25) << tenVPP
            << "| " << setw(15) << loaiVPP
            << "| " << setw(10) << donGia
            << "| " << setw(8) << soLuongTon << " |" << endl;
    }

    friend istream& operator>>(istream& is, VPP& v) {
        cout << "Nhap ma VPP: ";     getline(is >> ws, v.maVPP);
        cout << "Nhap ten VPP: ";    getline(is >> ws, v.tenVPP);
        cout << "Nhap loai VPP: ";   getline(is >> ws, v.loaiVPP);
        cout << "Nhap don gia: ";    is >> v.donGia;
        cout << "Nhap so luong ton: "; is >> v.soLuongTon;
        return is;
    }

    friend ostream& operator<<(ostream& os, const VPP& v) {
        os << v.maVPP << "," << v.tenVPP << "," << v.loaiVPP << ","
            << v.donGia << "," << v.soLuongTon << endl;
        return os;
    }
};