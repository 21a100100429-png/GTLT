#ifndef KHACHHANG_MANAGER_H
#define KHACHHANG_MANAGER_H

#include "KhachHang.h"
#include "Stack.h"
#include <fstream>

void themKhachHang(Stack<KhachHang>& stack) {
    KhachHang kh;
    kh.nhap();
    stack.push(kh);
    cout << "Them thanh cong!\n";
}

void xoaKhachHang(Stack<KhachHang>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }
    stack.pop();
    cout << "Xoa thanh cong!\n";
}

void suaKhachHang(Stack<KhachHang>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    string ma;
    cout << "Nhap ma khach hang can sua: ";
    cin >> ma;

    int n;
    KhachHang* arr = stack.toArray(n);
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i].maKH == ma) {
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
        cout << "Khong tim thay ma khach hang!\n";
    }

    delete[] arr;
}

void timKiemTheoMaKH(Stack<KhachHang>& stack) {
    string ma;
    cout << "Nhap ma khach hang: ";
    cin >> ma;

    int n;
    KhachHang* arr = stack.toArray(n);
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i].maKH == ma) {
            cout << "\nThong tin khach hang:\n";
            cout << left << setw(12) << "Ma KH" << setw(25) << "Ten KH"
                << setw(15) << "SDT" << setw(10) << "Diem TL" << endl;
            arr[i].xuat();
            found = true;
            break;
        }
    }

    if (!found) cout << "Khong tim thay!\n";
    delete[] arr;
}

void timKiemTheoTenKH(Stack<KhachHang>& stack) {
    string ten;
    cout << "Nhap ten khach hang: ";
    cin.ignore();
    getline(cin, ten);

    int n;
    KhachHang* arr = stack.toArray(n);
    bool found = false;

    cout << "\nKet qua tim kiem:\n";
    cout << left << setw(12) << "Ma KH" << setw(25) << "Ten KH"
        << setw(15) << "SDT" << setw(10) << "Diem TL" << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i].tenKH.find(ten) != string::npos) {
            arr[i].xuat();
            found = true;
        }
    }

    if (!found) cout << "Khong tim thay!\n";
    delete[] arr;
}

void hienThiKhachHang(Stack<KhachHang>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }
    cout << "\n===== DANH SACH KHACH HANG =====\n";
    cout << left << setw(12) << "Ma KH" << setw(25) << "Ten KH"
        << setw(15) << "SDT" << setw(10) << "Diem TL" << endl;
    stack.display();
}

void demKhachHang(Stack<KhachHang>& stack) {
    cout << "So luong khach hang: " << stack.size() << endl;
}

void sapXepTheoMaKH(Stack<KhachHang>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    KhachHang* arr = stack.toArray(n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].maKH > arr[j].maKH) {
                KhachHang temp = arr[i];
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
    cout << left << setw(12) << "Ma KH" << setw(25) << "Ten KH"
        << setw(15) << "SDT" << setw(10) << "Diem TL" << endl;
    stack.display();
}

void sapXepTheoTenKH(Stack<KhachHang>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    KhachHang* arr = stack.toArray(n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].tenKH > arr[j].tenKH) {
                KhachHang temp = arr[i];
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
    cout << left << setw(12) << "Ma KH" << setw(25) << "Ten KH"
        << setw(15) << "SDT" << setw(10) << "Diem TL" << endl;
    stack.display();
}

void sapXepTheoDiemKH(Stack<KhachHang>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    KhachHang* arr = stack.toArray(n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].diemTichLuy < arr[j].diemTichLuy) {
                KhachHang temp = arr[i];
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
    cout << left << setw(12) << "Ma KH" << setw(25) << "Ten KH"
        << setw(15) << "SDT" << setw(10) << "Diem TL" << endl;
    stack.display();
}

void ghiFileKH(Stack<KhachHang>& stack) {
    ofstream file("KhachHang_data.txt");
    if (!file) {
        cout << "Khong the mo file!\n";
        return;
    }

    int n;
    KhachHang* arr = stack.toArray(n);

    file << n << endl;
    for (int i = 0; i < n; i++) {
        file << arr[i].maKH << endl;
        file << arr[i].tenKH << endl;
        file << arr[i].SDT << endl;
        file << arr[i].diemTichLuy << endl;
    }

    file.close();
    delete[] arr;
    cout << "Ghi file KhachHang_data.txt thanh cong!\n";
}

void docFileKH(Stack<KhachHang>& stack) {
    ifstream file("KhachHang_data.txt");
    if (!file) {
        cout << "Khong the mo file!\n";
        return;
    }

    while (!stack.isEmpty()) stack.pop();

    int n;
    file >> n;
    file.ignore();

    KhachHang* arr = new KhachHang[n];
    for (int i = 0; i < n; i++) {
        getline(file, arr[i].maKH);
        getline(file, arr[i].tenKH);
        getline(file, arr[i].SDT);
        file >> arr[i].diemTichLuy;
        file.ignore();
    }

    stack.fromArray(arr, n);
    file.close();
    delete[] arr;
    cout << "Doc file KhachHang_data.txt thanh cong!\n";
}

void timKHDiemCaoNhat(Stack<KhachHang>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    KhachHang* arr = stack.toArray(n);
    int maxDiem = arr[0].diemTichLuy;

    for (int i = 1; i < n; i++) {
        if (arr[i].diemTichLuy > maxDiem) {
            maxDiem = arr[i].diemTichLuy;
        }
    }

    cout << "\nKhach hang co diem cao nhat (" << maxDiem << " diem):\n";
    cout << left << setw(12) << "Ma KH" << setw(25) << "Ten KH"
        << setw(15) << "SDT" << setw(10) << "Diem TL" << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i].diemTichLuy == maxDiem) {
            arr[i].xuat();
        }
    }

    delete[] arr;
}

void thongKeTheoDiem(Stack<KhachHang>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int min, max;
    cout << "Nhap diem tich luy tu: ";
    cin >> min;
    cout << "Nhap diem tich luy den: ";
    cin >> max;

    int n;
    KhachHang* arr = stack.toArray(n);
    int dem = 0;

    cout << "\nKhach hang co diem tu " << min << " den " << max << ":\n";
    cout << left << setw(12) << "Ma KH" << setw(25) << "Ten KH"
        << setw(15) << "SDT" << setw(10) << "Diem TL" << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i].diemTichLuy >= min && arr[i].diemTichLuy <= max) {
            arr[i].xuat();
            dem++;
        }
    }

    cout << "Tong so: " << dem << " khach hang\n";
    delete[] arr;
}

void xemDinhKH(Stack<KhachHang>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }
    cout << "\nKhach hang tren dinh:\n";
    cout << left << setw(12) << "Ma KH" << setw(25) << "Ten KH"
        << setw(15) << "SDT" << setw(10) << "Diem TL" << endl;
    stack.peek().xuat();
}

void xoaToanBoKH(Stack<KhachHang>& stack) {
    char confirm;
    cout << "Ban co chac chan muon xoa toan bo? (y/n): ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        while (!stack.isEmpty()) stack.pop();
        cout << "Da xoa toan bo!\n";
    }
}

void capNhatDiemTichLuy(Stack<KhachHang>& stack) {
    string ma;
    int diemMoi;
    cout << "Nhap ma khach hang: ";
    cin >> ma;
    cout << "Nhap diem tich luy moi: ";
    cin >> diemMoi;

    int n;
    KhachHang* arr = stack.toArray(n);
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i].maKH == ma) {
            arr[i].diemTichLuy = diemMoi;
            found = true;
            break;
        }
    }

    if (found) {
        stack.fromArray(arr, n);
        cout << "Cap nhat thanh cong!\n";
    }
    else {
        cout << "Khong tim thay ma khach hang!\n";
    }

    delete[] arr;
}

void kiemTraTonTaiKH(Stack<KhachHang>& stack) {
    string ma;
    cout << "Nhap ma khach hang: ";
    cin >> ma;

    int n;
    KhachHang* arr = stack.toArray(n);

    for (int i = 0; i < n; i++) {
        if (arr[i].maKH == ma) {
            cout << "Ma khach hang TON TAI!\n";
            delete[] arr;
            return;
        }
    }

    cout << "Ma khach hang KHONG ton tai!\n";
    delete[] arr;
}

void saoLuuKH(Stack<KhachHang>& stack) {
    ofstream file("khachhang_backup.txt");
    if (!file) {
        cout << "Khong the mo file!\n";
        return;
    }

    int n;
    KhachHang* arr = stack.toArray(n);

    file << n << endl;
    for (int i = 0; i < n; i++) {
        file << arr[i].maKH << endl;
        file << arr[i].tenKH << endl;
        file << arr[i].SDT << endl;
        file << arr[i].diemTichLuy << endl;
    }

    file.close();
    delete[] arr;
    cout << "Sao luu thanh cong vao khachhang_backup.txt!\n";
}

void thongKeTongQuatKH(Stack<KhachHang>& stack) {
    if (stack.isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    int n;
    KhachHang* arr = stack.toArray(n);

    int tongDiem = 0;
    int maxDiem = arr[0].diemTichLuy;
    int minDiem = arr[0].diemTichLuy;

    for (int i = 0; i < n; i++) {
        tongDiem += arr[i].diemTichLuy;
        if (arr[i].diemTichLuy > maxDiem) maxDiem = arr[i].diemTichLuy;
        if (arr[i].diemTichLuy < minDiem) minDiem = arr[i].diemTichLuy;
    }

    cout << "\n===== THONG KE KHACH HANG =====\n";
    cout << "Tong so khach hang: " << n << endl;
    cout << "Tong diem tich luy: " << tongDiem << endl;
    cout << "Diem trung binh: " << (double)tongDiem / n << endl;
    cout << "Diem cao nhat: " << maxDiem << endl;
    cout << "Diem thap nhat: " << minDiem << endl;

    delete[] arr;
}

void menuKhachHang(Stack<KhachHang>& stack) {
    int choice;
    do {
        cout << "\n========== QUAN LY KHACH HANG ==========\n";
        cout << "1. Them khach hang\n";
        cout << "2. Xoa khach hang (Pop)\n";
        cout << "3. Sua thong tin khach hang\n";
        cout << "4. Tim kiem theo ma\n";
        cout << "5. Tim kiem theo ten\n";
        cout << "6. Hien thi danh sach\n";
        cout << "7. Dem so luong khach hang\n";
        cout << "8. Sap xep theo ma\n";
        cout << "9. Sap xep theo ten\n";
        cout << "10. Sap xep theo diem tich luy\n";
        cout << "11. Ghi vao file\n";
        cout << "12. Doc tu file\n";
        cout << "13. Tim khach hang diem cao nhat\n";
        cout << "14. Thong ke theo khoang diem\n";
        cout << "15. Xem phan tu dinh (Peek)\n";
        cout << "16. Xoa toan bo\n";
        cout << "17. Cap nhat diem tich luy\n";
        cout << "18. Kiem tra ton tai\n";
        cout << "19. Sao luu du lieu\n";
        cout << "20. Thong ke tong quat\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1: themKhachHang(stack); break;
        case 2: xoaKhachHang(stack); break;
        case 3: suaKhachHang(stack); break;
        case 4: timKiemTheoMaKH(stack); break;
        case 5: timKiemTheoTenKH(stack); break;
        case 6: hienThiKhachHang(stack); break;
        case 7: demKhachHang(stack); break;
        case 8: sapXepTheoMaKH(stack); break;
        case 9: sapXepTheoTenKH(stack); break;
        case 10: sapXepTheoDiemKH(stack); break;
        case 11: ghiFileKH(stack); break;
        case 12: docFileKH(stack); break;
        case 13: timKHDiemCaoNhat(stack); break;
        case 14: thongKeTheoDiem(stack); break;
        case 15: xemDinhKH(stack); break;
        case 16: xoaToanBoKH(stack); break;
        case 17: capNhatDiemTichLuy(stack); break;
        case 18: kiemTraTonTaiKH(stack); break;
        case 19: saoLuuKH(stack); break;
        case 20: thongKeTongQuatKH(stack); break;
        case 0: break;
        default: cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}

#endif