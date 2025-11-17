#ifndef VPP_MANAGER_H
#define VPP_MANAGER_H
#include "VPP.h"
#include "Stack.h"
#include <fstream>

void themVPP(Stack<VPP>& stack) {
    VPP vpp;
    vpp.nhap();
    stack.push(vpp);
    cout << "Them thanh cong!\n";
}

void xoaVPP(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }
    stack.pop();
    cout << "Xoa thanh cong!\n";
}

void suaVPP(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    string ma;
    cout << "Nhap ma VPP can sua: ";
    cin >> ma;

    int n;
    VPP* arr = stack.toArray(n);
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i].maVPP == ma) {
            cout << "\nThong tin hien tai:\n";
            arr[i].xuat();
            cout << "\nNhap thong tin moi:\n";
            arr[i].nhap();
            found = true;
            break;
        }
    }

    if (found) {
        stack.fromArray(arr, n);
        cout << "Sua thanh cong!\n";
    }
    else {
        cout << "Khong tim thay ma VPP!\n";
    }

    delete[] arr;
}

void timKiemTheoMaVPP(Stack<VPP>& stack) {
    string ma;
    cout << "Nhap ma VPP: ";
    cin >> ma;

    int n;
    VPP* arr = stack.toArray(n);
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i].maVPP == ma) {
            cout << "\nThong tin VPP:\n";
            cout << left << setw(10) << "Ma VPP" << setw(25) << "Ten VPP"
                << setw(15) << "Loai" << setw(10) << "So luong"
                << setw(12) << "Don gia" << endl;
            arr[i].xuat();
            found = true;
            break;
        }
    }

    if (!found) cout << "Khong tim thay!\n";
    delete[] arr;
}

void timKiemTheoTenVPP(Stack<VPP>& stack) {
    string ten;
    cout << "Nhap ten VPP: ";
    cin.ignore();
    getline(cin, ten);

    int n;
    VPP* arr = stack.toArray(n);
    bool found = false;

    cout << "\nKet qua tim kiem:\n";
    cout << left << setw(10) << "Ma VPP" << setw(25) << "Ten VPP"
        << setw(15) << "Loai" << setw(10) << "So luong"
        << setw(12) << "Don gia" << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i].tenVPP.find(ten) != string::npos) {
            arr[i].xuat();
            found = true;
        }
    }

    if (!found) cout << "Khong tim thay!\n";
    delete[] arr;
}

void timKiemTheoLoaiVPP(Stack<VPP>& stack) {
    string loai;
    cout << "Nhap loai VPP: ";
    cin.ignore();
    getline(cin, loai);

    int n;
    VPP* arr = stack.toArray(n);
    bool found = false;

    cout << "\nKet qua tim kiem:\n";
    cout << left << setw(10) << "Ma VPP" << setw(25) << "Ten VPP"
        << setw(15) << "Loai" << setw(10) << "So luong"
        << setw(12) << "Don gia" << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i].loai.find(loai) != string::npos) {
            arr[i].xuat();
            found = true;
        }
    }

    if (!found) cout << "Khong tim thay!\n";
    delete[] arr;
}

void hienThiVPP(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }
    cout << "\n===== DANH SACH VAN PHONG PHAM =====\n";
    cout << left << setw(10) << "Ma VPP" << setw(25) << "Ten VPP"
        << setw(15) << "Loai" << setw(10) << "So luong"
        << setw(12) << "Don gia" << endl;
    stack.display();
}

void demVPP(Stack<VPP>& stack) {
    cout << "So luong VPP: " << stack.size() << endl;
}

void sapXepTheoMaVPP(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    VPP* arr = stack.toArray(n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].maVPP > arr[j].maVPP) {
                VPP temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    stack.fromArray(arr, n);
    delete[] arr;
    cout << "Sap xep thanh cong!\n";

    // Tự động hiển thị sau khi sắp xếp
    cout << "\n===== KET QUA SAU KHI SAP XEP =====\n";
    cout << left << setw(10) << "Ma VPP" << setw(25) << "Ten VPP"
        << setw(15) << "Loai" << setw(10) << "So luong"
        << setw(12) << "Don gia" << endl;
    stack.display();
}

void sapXepTheoTenVPP(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    VPP* arr = stack.toArray(n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].tenVPP > arr[j].tenVPP) {
                VPP temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    stack.fromArray(arr, n);
    delete[] arr;
    cout << "Sap xep thanh cong!\n";
}

void sapXepTheoDonGia(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    VPP* arr = stack.toArray(n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].donGia > arr[j].donGia) {
                VPP temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    stack.fromArray(arr, n);
    delete[] arr;
    cout << "Sap xep thanh cong!\n";
}

void sapXepTheoSoLuong(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    VPP* arr = stack.toArray(n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].soLuong > arr[j].soLuong) {
                VPP temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    stack.fromArray(arr, n);
    delete[] arr;
    cout << "Sap xep thanh cong!\n";
}

void ghiFileVPP(Stack<VPP>& stack) {
    ofstream file("VPP_data.txt");
    if (!file) {
        cout << "Khong the mo file!\n";
        return;
    }

    int n;
    VPP* arr = stack.toArray(n);

    file << n << endl;
    for (int i = 0; i < n; i++) {
        file << arr[i].maVPP << endl;
        file << arr[i].tenVPP << endl;
        file << arr[i].loai << endl;
        file << arr[i].soLuong << endl;
        file << arr[i].donGia << endl;
    }

    file.close();
    delete[] arr;
    cout << "Ghi file VPP_data.txt thanh cong!\n";
}

void docFileVPP(Stack<VPP>& stack) {
    ifstream file("VPP_data.txt");
    if (!file) {
        cout << "Khong the mo file!\n";
        return;
    }

    while (!stack.isEmpty()) stack.pop();

    int n;
    file >> n;
    file.ignore();

    VPP* arr = new VPP[n];
    for (int i = 0; i < n; i++) {
        getline(file, arr[i].maVPP);
        getline(file, arr[i].tenVPP);
        getline(file, arr[i].loai);
        file >> arr[i].soLuong;
        file >> arr[i].donGia;
        file.ignore();
    }

    stack.fromArray(arr, n);
    file.close();
    delete[] arr;
    cout << "Doc file VPP_data.txt thanh cong!\n";
}

void timVPPGiaCaoNhat(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    VPP* arr = stack.toArray(n);
    double maxGia = arr[0].donGia;

    for (int i = 1; i < n; i++) {
        if (arr[i].donGia > maxGia) {
            maxGia = arr[i].donGia;
        }
    }

    cout << "\nVPP co gia cao nhat (" << maxGia << " VND):\n";
    cout << left << setw(10) << "Ma VPP" << setw(25) << "Ten VPP"
        << setw(15) << "Loai" << setw(10) << "So luong"
        << setw(12) << "Don gia" << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i].donGia == maxGia) {
            arr[i].xuat();
        }
    }

    delete[] arr;
}

void canhBaoHetHang(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int nguong;
    cout << "Nhap nguong canh bao: ";
    cin >> nguong;

    int n;
    VPP* arr = stack.toArray(n);
    int dem = 0;

    cout << "\nVPP can nhap them (so luong <= " << nguong << "):\n";
    cout << left << setw(10) << "Ma VPP" << setw(25) << "Ten VPP"
        << setw(15) << "Loai" << setw(10) << "So luong"
        << setw(12) << "Don gia" << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i].soLuong <= nguong) {
            arr[i].xuat();
            dem++;
        }
    }

    cout << "Tong so: " << dem << " mat hang\n";
    delete[] arr;
}

void capNhatSoLuong(Stack<VPP>& stack) {
    string ma;
    int soLuongMoi;
    cout << "Nhap ma VPP: ";
    cin >> ma;
    cout << "Nhap so luong moi: ";
    cin >> soLuongMoi;

    int n;
    VPP* arr = stack.toArray(n);
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i].maVPP == ma) {
            arr[i].soLuong = soLuongMoi;
            found = true;
            break;
        }
    }

    if (found) {
        stack.fromArray(arr, n);
        cout << "Cap nhat thanh cong!\n";
    }
    else {
        cout << "Khong tim thay ma VPP!\n";
    }

    delete[] arr;
}

void tinhTongGiaTriKho(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    VPP* arr = stack.toArray(n);
    double tongGiaTri = 0;

    for (int i = 0; i < n; i++) {
        tongGiaTri += arr[i].thanhTien();
    }

    cout << "\nTong gia tri kho: " << fixed << setprecision(0)
        << tongGiaTri << " VND\n";

    delete[] arr;
}

void xemDinhVPP(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }
    cout << "\nVPP tren dinh:\n";
    cout << left << setw(10) << "Ma VPP" << setw(25) << "Ten VPP"
        << setw(15) << "Loai" << setw(10) << "So luong"
        << setw(12) << "Don gia" << endl;
    stack.peek().xuat();
}

void thongKeTheoLoai(Stack<VPP>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    VPP* arr = stack.toArray(n);

    string* loaiList = new string[n];
    int* soLuongLoai = new int[n];
    int soLoai = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < soLoai; j++) {
            if (loaiList[j] == arr[i].loai) {
                soLuongLoai[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            loaiList[soLoai] = arr[i].loai;
            soLuongLoai[soLoai] = 1;
            soLoai++;
        }
    }

    cout << "\n===== THONG KE THEO LOAI =====\n";
    cout << left << setw(20) << "Loai" << setw(10) << "So luong" << endl;
    for (int i = 0; i < soLoai; i++) {
        cout << left << setw(20) << loaiList[i]
            << setw(10) << soLuongLoai[i] << endl;
    }

    delete[] loaiList;
    delete[] soLuongLoai;
    delete[] arr;
}

void menuVPP(Stack<VPP>& stack) {
    int choice;
    do {
        cout << "\n========== QUAN LY VAN PHONG PHAM ==========\n";
        cout << "1. Them VPP\n";
        cout << "2. Xoa VPP (Pop)\n";
        cout << "3. Sua thong tin VPP\n";
        cout << "4. Tim kiem theo ma\n";
        cout << "5. Tim kiem theo ten\n";
        cout << "6. Tim kiem theo loai\n";
        cout << "7. Hien thi danh sach\n";
        cout << "8. Dem so luong VPP\n";
        cout << "9. Sap xep theo ma\n";
        cout << "10. Sap xep theo ten\n";
        cout << "11. Sap xep theo don gia\n";
        cout << "12. Sap xep theo so luong\n";
        cout << "13. Ghi vao file\n";
        cout << "14. Doc tu file\n";
        cout << "15. Tim VPP gia cao nhat\n";
        cout << "16. Canh bao het hang\n";
        cout << "17. Cap nhat so luong\n";
        cout << "18. Tinh tong gia tri kho\n";
        cout << "19. Xem phan tu dinh (Peek)\n";
        cout << "20. Thong ke theo loai\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1: themVPP(stack); break;
        case 2: xoaVPP(stack); break;
        case 3: suaVPP(stack); break;
        case 4: timKiemTheoMaVPP(stack); break;
        case 5: timKiemTheoTenVPP(stack); break;
        case 6: timKiemTheoLoaiVPP(stack); break;
        case 7: hienThiVPP(stack); break;
        case 8: demVPP(stack); break;
        case 9: sapXepTheoMaVPP(stack); break;
        case 10: sapXepTheoTenVPP(stack); break;
        case 11: sapXepTheoDonGia(stack); break;
        case 12: sapXepTheoSoLuong(stack); break;
        case 13: ghiFileVPP(stack); break;
        case 14: docFileVPP(stack); break;
        case 15: timVPPGiaCaoNhat(stack); break;
        case 16: canhBaoHetHang(stack); break;
        case 17: capNhatSoLuong(stack); break;
        case 18: tinhTongGiaTriKho(stack); break;
        case 19: xemDinhVPP(stack); break;
        case 20: thongKeTheoLoai(stack); break;
        case 0: break;
        default: cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}

#endif