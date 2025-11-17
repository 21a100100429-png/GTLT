#include "QuanLyKH_Stack.h"
#include "QuanLyVPP_Stack.h"

int main() {
    Stack<KhachHang> stackKH;
    Stack<VPP> stackVPP;

    int choice;
    do {
        cout << "\n========== CHUONG TRINH QUAN LY ==========\n";
        cout << "1. Quan ly Khach Hang \n";
        cout << "2. Quan ly Van Phong Pham \n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            menuKhachHang(stackKH);
            break;
        case 2:
            menuVPP(stackVPP);
            break;
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}