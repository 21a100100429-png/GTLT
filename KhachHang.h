#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct KhachHang {
    string maKH;
    string tenKH;
    string SDT;
    int diemTichLuy;

    KhachHang() : maKH(""), tenKH(""), SDT(""), diemTichLuy(0) {}

    KhachHang(string ma, string ten, string sdt, int diem) {
        maKH = ma;
        tenKH = ten;
        SDT = sdt;
        diemTichLuy = diem;
    }

    void nhap() {
        cout << "\nNhap ma khach hang: ";
        cin >> maKH;
        cin.ignore();
        cout << "Nhap ten khach hang: ";
        getline(cin, tenKH);
        cout << "Nhap so dien thoai: ";
        getline(cin, SDT);
        cout << "Nhap diem tich luy: ";
        cin >> diemTichLuy;
    }

    void xuat() const {
        cout << left << setw(12) << maKH
            << setw(25) << tenKH
            << setw(15) << SDT
            << setw(10) << diemTichLuy << endl;
    }
};
#endif