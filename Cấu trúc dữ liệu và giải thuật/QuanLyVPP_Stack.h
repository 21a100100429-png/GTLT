#pragma once
#pragma once
#include "Stack.h"
#include "VPP.h"
#include <fstream>

class QuanLyVPP_Stack {
private:
    Stack<VPP> ds;
public:
    void themVPP() { VPP v; cin >> v; ds.push(v); cout << "Da them VPP.\n"; }
    void xoaVPP() { VPP x; if (ds.pop(x)) cout << "Da xoa: " << x << endl; else cout << "Stack rong.\n"; }
    void hienThi() { Node<VPP>* p = ds.getTop(); if (!p) { cout << "Danh sach rong.\n"; return; } while (p) { cout << p->data << endl; p = p->next; } }
    void timTheoMa(string ma) { Node<VPP>* p = ds.getTop(); bool f = false; while (p) { if (p->data.maVPP == ma) { cout << p->data << endl; f = true; } p = p->next; } if (!f) cout << "Khong tim thay!\n"; }
    void timTheoTen(string ten) { Node<VPP>* p = ds.getTop(); bool f = false; while (p) { if (p->data.tenVPP == ten) { cout << p->data << endl; f = true; } p = p->next; } if (!f) cout << "Khong tim thay!\n"; }
    void demVPP() { cout << "Tong so VPP: " << ds.count() << endl; }
    void tongGiaTri() { double t = 0; Node<VPP>* p = ds.getTop(); while (p) { t += p->data.soLuong * p->data.donGia; p = p->next; } cout << "Tong gia tri ton kho: " << t << endl; }
    void timMaxGia() { Node<VPP>* p = ds.getTop(); if (!p)return; Node<VPP>* max = p; while (p) { if (p->data.donGia > max->data.donGia) max = p; p = p->next; } cout << "VPP gia cao nhat: " << max->data << endl; }
    void timMinGia() { Node<VPP>* p = ds.getTop(); if (!p)return; Node<VPP>* min = p; while (p) { if (p->data.donGia < min->data.donGia) min = p; p = p->next; } cout << "VPP gia thap nhat: " << min->data << endl; }
    void timMaxSoLuong() { Node<VPP>* p = ds.getTop(); if (!p)return; Node<VPP>* max = p; while (p) { if (p->data.soLuong > max->data.soLuong) max = p; p = p->next; } cout << "VPP ton kho nhieu nhat: " << max->data << endl; }
    void timMinSoLuong() { Node<VPP>* p = ds.getTop(); if (!p)return; Node<VPP>* min = p; while (p) { if (p->data.soLuong < min->data.soLuong) min = p; p = p->next; } cout << "VPP ton kho it nhat: " << min->data << endl; }
    void tangGiaHangLoat(double phanTram) { Node<VPP>* p = ds.getTop(); while (p) { p->data.donGia *= (1 + phanTram / 100.0); p = p->next; } cout << "Da tang gia hang loat.\n"; }
    void thongKeTheoLoai(string loai) { int dem = 0; double tong = 0; Node<VPP>* p = ds.getTop(); while (p) { if (p->data.loai == loai) { dem++; tong += p->data.soLuong * p->data.donGia; } p = p->next; } cout << "Loai " << loai << ": " << dem << " san pham, tong gia tri " << tong << endl; }
    void suaThongTin(string ma) { Node<VPP>* p = ds.getTop(); while (p) { if (p->data.maVPP == ma) { cin >> p->data; cout << "Da sua.\n"; return; } p = p->next; } cout << "Khong tim thay ma.\n"; }
    void xoaToanBo() { ds.clear(); cout << "Da xoa toan bo danh sach.\n"; }
    void docTuFile(const char* file) { ifstream f(file); if (!f) { cout << "Khong mo duoc file\n"; return; } VPP v; while (!f.eof()) { getline(f >> ws, v.maVPP, ';'); getline(f, v.tenVPP, ';'); getline(f, v.loai, ';'); f >> v.soLuong; f.ignore(); f >> v.donGia; f.ignore(); if (!v.maVPP.empty()) ds.push(v); } f.close(); cout << "Doc file thanh cong.\n"; }
    void ghiVaoFile(const char* file) { ofstream f(file); Node<VPP>* p = ds.getTop(); while (p) { f << p->data.maVPP << ";" << p->data.tenVPP << ";" << p->data.loai << ";" << p->data.soLuong << ";" << p->data.donGia << "\n"; p = p->next; } f.close(); cout << "Da ghi file thanh cong.\n"; }
    void hienThiNguoc() { hienThi(); }
};
