#ifndef VPP_H
#define VPP_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct VPP {
    string maVPP;
    string tenVPP;
    string loai;
    int soLuong;
    double donGia;

    VPP() : maVPP(""), tenVPP(""), loai(""), soLuong(0), donGia(0) {}

    VPP(string ma, string ten, string l, int sl, double gia) {
        maVPP = ma;
        tenVPP = ten;
        loai = l;
        soLuong = sl;
        donGia = gia;
    }

    void nhap() {
        cout << "\nNhap ma VPP: ";
        cin >> maVPP;
        cin.ignore();
        cout << "Nhap ten VPP: ";
        getline(cin, tenVPP);
        cout << "Nhap loai: ";
        getline(cin, loai);
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    void xuat() const {
        cout << left << setw(10) << maVPP
            << setw(25) << tenVPP
            << setw(15) << loai
            << setw(10) << soLuong
            << setw(12) << fixed << setprecision(0) << donGia << endl;
    }

    double thanhTien() const {
        return soLuong * donGia;
    }
};

#endif