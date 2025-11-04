#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>
#include "QuanLyVPP_BST.h"
#include "QuanLyKH_BST.h"

using namespace std;

QuanLyVPP_BST qlVPP;
QuanLyKH_BST  qlKH;
string fileVPP = "vpp_data_bst.txt";
string fileKH = "khachhang_data_bst.txt";

void pause() {
    cout << "\nNhan Enter de tiep tuc...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void menu_VPP() {
    int luaChon;
    string ma, ten, loai;
    double min, max, phanTram;
    VPP vppMoi;

    do {
        system("cls");
        cout << "\n================= MENU QUAN LY VPP (BST) - 20 CHUC NANG =================\n";
        cout << "--- Nhom CRUD ---" << endl;
        cout << " 1. Them san pham moi" << endl;
        cout << " 2. Sua thong tin san pham (theo Ma)" << endl;
        cout << " 3. Xoa san pham theo ma" << endl;
        cout << " 4. Xoa toan bo danh sach (Giai phong)" << endl;
        cout << "--- Nhom Tim Kiem ---" << endl;
        cout << " 5. Tim kiem san pham theo Ma" << endl;
        cout << " 6. Tim kiem san pham theo Ten" << endl;
        cout << " 7. Tim san pham theo KHOANG GIA" << endl;
        cout << "--- Nhom Hien Thi ---" << endl;
        cout << " 8. Hien thi tang dan (theo Ma - LNR)" << endl;
        cout << " 9. Hien thi giam dan (theo Ma - RNL)" << endl;
        cout << "--- Nhom Thong Ke (Tong/Dem) ---" << endl;
        cout << " 10. Dem so luong san pham" << endl;
        cout << " 11. Tinh tong gia tri ton kho" << endl;
        cout << " 12. Thong ke theo LOAI san pham" << endl;
        cout << "--- Nhom Thong Ke (Min/Max) ---" << endl;
        cout << " 13. Tim san pham GIA CAO nhat" << endl;
        cout << " 14. Tim san pham GIA THAP nhat" << endl;
        cout << "15.Tim san pham TON KHO NHIEU nhat" << endl;
        cout << " 16. Tim san pham TON KHO IT nhat" << endl;
        cout << "--- Nhom Xu Ly Hang Loat ---" << endl;
        cout << " 17. TANG GIA hang loat (%)" << endl;
        cout << "--- Nhom File I/O ---" << endl;
        cout << " 18. Luu danh sach vao file" << endl;
        cout << " 19. Doc du lieu tu file" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        cout << " 0. Quay lai menu chinh" << endl;
        cout << "=======================================================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: cout << "Nhap thong tin:\n"; cin >> vppMoi; qlVPP.themMoi(vppMoi); break;
        case 2: cout << "Nhap ma VPP can sua: "; getline(cin >> ws, ma); qlVPP.suaThongTin(ma); break;
        case 3: cout << "Nhap ma VPP can xoa: "; getline(cin >> ws, ma); qlVPP.xoaTheoMa(ma); break;
        case 4: qlVPP.giaiPhongBoNho(); cout << "Da xoa toan bo cay VPP." << endl; break;
        case 5: cout << "Nhap ma VPP can tim: "; getline(cin >> ws, ma); qlVPP.timVaHienThiTheoMa(ma); break;
        case 6: cout << "Nhap ten VPP can tim: "; getline(cin >> ws, ten); qlVPP.timKiemTheoTen(ten); break;
        case 7:
            cout << "Nhap gia min: "; cin >> min;
            cout << "Nhap gia max: "; cin >> max;
            qlVPP.timTheoKhoangGia(min, max);
            break;
        case 8: qlVPP.hienThi(); break;
        case 9: qlVPP.hienThiNguoc(); break;
        case 10: cout << "Tong so san pham: " << qlVPP.demSoLuong() << endl; break;
        case 11: cout << "Tong gia tri ton kho: " << qlVPP.tinhTongGiaTriTonKho() << endl; break;
        case 12:
            cout << "Nhap loai can thong ke (Vi du: But): "; getline(cin >> ws, loai);
            qlVPP.thongKeTheoLoai(loai);
            break;
        case 13: qlVPP.timMaxGia(); break;
        case 14: qlVPP.timMinGia(); break;
        case 15: qlVPP.timMaxSoLuong(); break;
        case 16: qlVPP.timMinSoLuong(); break;
        case 17:
            cout << "Nhap phan tram can tang (vi du: 10): "; cin >> phanTram;
            qlVPP.tangGiaHangLoat(phanTram);
            break;
        case 18: qlVPP.ghiVaoFile(fileVPP); break;
        case 19: qlVPP.docTuFile(fileVPP); break;
        case 0: cout << "Quay lai..." << endl; break;
        default: cout << "Lua chon khong hop le." << endl;
        }
        if (luaChon != 0) pause();
    } while (luaChon != 0);
}

void menu_KH() {
    int luaChon;
    string ma, ten, sdt;
    int min, max, diemThem;
    KhachHang khMoi;

    do {
        system("cls");
        cout << "\n================= MENU QUAN LY KHACH HANG (BST) - 20 CHUC NANG =================\n";
        cout << "--- Nhom CRUD ---" << endl;
        cout << " 1. Them khach hang moi" << endl;
        cout << " 2. Sua thong tin (theo Ma)" << endl;
        cout << " 3. Xoa khach hang theo ma" << endl;
        cout << " 4. Xoa toan bo danh sach (Giai phong)" << endl;
        cout << "--- Nhom Tim Kiem ---" << endl;
        cout << " 5. Tim kiem khach hang theo Ma" << endl;
        cout << " 6. Tim kiem khach hang theo Ten" << endl;
        cout << " 7. Tim kiem khach hang theo SDT" << endl;
        cout << " 8. Tim khach hang theo KHOANG DIEM" << endl;
        cout << "--- Nhom Hien Thi ---" << endl;
        cout << " 9. Hien thi tang dan (theo Ma - LNR)" << endl;
        cout << " 10. Hien thi giam dan (theo Ma - RNL)" << endl;
        cout << "--- Nhom Thong Ke (Tong/Dem) ---" << endl;
        cout << " 11. Dem so luong khach hang" << endl;
        cout << " 12. Tinh tong diem tich luy" << endl;
        cout << "--- Nhom Thong Ke (Min/Max) ---" << endl;
        cout << " 13. Tim khach hang DIEM CAO nhat" << endl;
        cout << " 14. Tim khach hang DIEM THAP nhat" << endl;
        cout << "--- Nhom Xu Ly Hang Loat ---" << endl;
        cout << " 15. TANG DIEM hang loat" << endl;
        cout << "--- Nhom File I/O ---" << endl;
        cout << " 16. Luu danh sach vao file" << endl;
        cout << " 17. Doc du lieu tu file" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << " 0. Quay lai menu chinh" << endl;
        cout << "==============================================================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: cout << "Nhap thong tin:\n"; cin >> khMoi; qlKH.themMoi(khMoi); break;
        case 2: cout << "Nhap ma KH can sua: "; getline(cin >> ws, ma); qlKH.suaThongTin(ma); break;
        case 3: cout << "Nhap ma KH can xoa: "; getline(cin >> ws, ma); qlKH.xoaTheoMa(ma); break;
        case 4: qlKH.giaiPhongBoNho(); cout << "Da xoa toan bo cay KH." << endl; break;
        case 5: cout << "Nhap ma KH can tim: "; getline(cin >> ws, ma); qlKH.timVaHienThiTheoMa(ma); break;
        case 6: cout << "Nhap ten KH can tim: "; getline(cin >> ws, ten); qlKH.timKiemTheoTen(ten); break;
        case 7: cout << "Nhap SDT can tim: "; getline(cin >> ws, sdt); qlKH.timKiemTheoSDT(sdt); break;
        case 8:
            cout << "Nhap diem min: "; cin >> min;
            cout << "Nhap diem max: "; cin >> max;
            qlKH.timTheoKhoangDiem(min, max);
            break;
        case 9: qlKH.hienThi(); break;
        case 10: qlKH.hienThiNguoc(); break;
        case 11: cout << "Tong so khach hang: " << qlKH.demSoLuong() << endl; break;
        case 12: cout << "Tong diem tich luy: " << qlKH.tinhTongDiem() << endl; break;
        case 13: qlKH.timMaxDiem(); break;
        case 14: qlKH.timMinDiem(); break;
        case 15:
            cout << "Nhap so diem can tang: "; cin >> diemThem;
            qlKH.tangDiemHangLoat(diemThem);
            break;
        case 16: qlKH.ghiVaoFile(fileKH); break;
        case 17: qlKH.docTuFile(fileKH); break;
        case 0: cout << "Quay lai..." << endl; break;
        default: cout << "Lua chon khong hop le." << endl;
        }
        if (luaChon != 0) pause();
    } while (luaChon != 0);
}


int main() {
    int luaChon;
    do {
        system("cls");
        cout << "\n--- CHUONG TRINH QUAN LY BAN HANG VPP (BST) ---";
        cout << "\n---       (DE TAI CTDL & GIAI THUAT)      ---";
        cout << "\n\nCHON DOI TUONG DE QUAN LY:";
        cout << "\n1. Quan ly Van Phong Pham";
        cout << "\n2. Quan ly Khach Hang";
        cout << "\n0. Thoat chuong trinh";
        cout << "\n\nLua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            menu_VPP();
            break;
        case 2:
            menu_KH();
            break;
        case 0:
            cout << "Cam on da su dung chuong trinh. Tam biet!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            pause();
        }
    } while (luaChon != 0);

    return 0;
}