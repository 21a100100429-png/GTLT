#pragma once
#include "KhachHang.h"
#include <sstream>

struct NodeKH_BST {
    KhachHang data;
    NodeKH_BST* left;
    NodeKH_BST* right;
    NodeKH_BST(KhachHang v) : data(v), left(nullptr), right(nullptr) {}
};

class QuanLyKH_BST {
private:
    NodeKH_BST* root;

    NodeKH_BST* insert(NodeKH_BST* node, KhachHang v) {
        if (node == nullptr) return new NodeKH_BST(v);
        if (v.maKH < node->data.maKH)
            node->left = insert(node->left, v);
        else if (v.maKH > node->data.maKH)
            node->right = insert(node->right, v);
        return node;
    }

    NodeKH_BST* search(NodeKH_BST* node, string maKH) {
        if (node == nullptr || node->data.maKH == maKH) return node;
        if (maKH < node->data.maKH)
            return search(node->left, maKH);
        return search(node->right, maKH);
    }

    void destroyTree(NodeKH_BST* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    void inOrder(NodeKH_BST* node) {
        if (node) {
            inOrder(node->left);
            node->data.hienThi();
            inOrder(node->right);
        }
    }

    void reverseOrder(NodeKH_BST* node) {
        if (node) {
            reverseOrder(node->right);
            node->data.hienThi();
            reverseOrder(node->left);
        }
    }

    int countNodes(NodeKH_BST* node) {
        return (node == nullptr) ? 0 : (1 + countNodes(node->left) + countNodes(node->right));
    }

    int sumDiem(NodeKH_BST* node) {
        if (node == nullptr) return 0;
        int nodeValue = node->data.diemTichLuy;
        return nodeValue + sumDiem(node->left) + sumDiem(node->right);
    }

    void writeToFile(NodeKH_BST* node, ostream& outFile) {
        if (node) {
            writeToFile(node->left, outFile);
            outFile << node->data;
            writeToFile(node->right, outFile);
        }
    }

    NodeKH_BST* findMin(NodeKH_BST* node) {
        while (node && node->left != nullptr) node = node->left;
        return node;
    }

    void findMaxDiem(NodeKH_BST* node, KhachHang& maxKH) {
        if (node == nullptr) return;
        if (node->data.diemTichLuy > maxKH.diemTichLuy) maxKH = node->data;
        findMaxDiem(node->left, maxKH);
        findMaxDiem(node->right, maxKH);
    }

    void findMinDiem(NodeKH_BST* node, KhachHang& minKH) {
        if (node == nullptr) return;
        if (node->data.diemTichLuy < minKH.diemTichLuy) minKH = node->data;
        findMinDiem(node->left, minKH);
        findMinDiem(node->right, minKH);
    }

    NodeKH_BST* deleteNode(NodeKH_BST* node, string maKH) {
        if (node == nullptr) return node;
        if (maKH < node->data.maKH)
            node->left = deleteNode(node->left, maKH);
        else if (maKH > node->data.maKH)
            node->right = deleteNode(node->right, maKH);
        else {
            if (node->left == nullptr) {
                NodeKH_BST* temp = node->right; delete node; return temp;
            }
            else if (node->right == nullptr) {
                NodeKH_BST* temp = node->left; delete node; return temp;
            }
            NodeKH_BST* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data.maKH);
        }
        return node;
    }

    void searchByName(NodeKH_BST* node, string ten, bool& found) {
        if (node == nullptr) return;
        if (node->data.tenKH.find(ten) != string::npos) {
            node->data.hienThi(); found = true;
        }
        searchByName(node->left, ten, found);
        searchByName(node->right, ten, found);
    }

    void searchBySDT(NodeKH_BST* node, string sdt, bool& found) {
        if (node == nullptr) return;
        if (node->data.sdt == sdt) {
            node->data.hienThi(); found = true;
        }
        searchBySDT(node->left, sdt, found);
        searchBySDT(node->right, sdt, found);
    }

    void findByDiemRange(NodeKH_BST* node, int min, int max, bool& found) {
        if (node == nullptr) return;
        if (node->data.diemTichLuy >= min && node->data.diemTichLuy <= max) {
            node->data.hienThi(); found = true;
        }
        findByDiemRange(node->left, min, max, found);
        findByDiemRange(node->right, min, max, found);
    }

    void addDiem(NodeKH_BST* node, int diemThem) {
        if (node == nullptr) return;
        node->data.diemTichLuy += diemThem;
        addDiem(node->left, diemThem);
        addDiem(node->right, diemThem);
    }

public:
    QuanLyKH_BST() : root(nullptr) {}
    ~QuanLyKH_BST() { giaiPhongBoNho(); }

    void themMoi(KhachHang v) {
        root = insert(root, v);
        cout << "Da them KH " << v.maKH << " vao cay." << endl;
    }

    void hienThi() {
        if (root == nullptr) { cout << "Cay rong." << endl; return; }
        cout << "\n--- DANH SACH KHACH HANG (SAP XEP TANG DAN THEO MA) ---\n";
        cout << "-----------------------------------------------------------------------\n";
        cout << left;
        cout << "| " << setw(10) << "Ma KH" << "| " << setw(25) << "Ten KH"
            << "| " << setw(15) << "SDT" << "| " << setw(10) << "Diem" << " |" << endl;
        cout << "-----------------------------------------------------------------------\n";
        inOrder(root);
        cout << "-----------------------------------------------------------------------\n";
    }

    void hienThiNguoc() {
        if (root == nullptr) { cout << "Cay rong." << endl; return; }
        cout << "\n--- DANH SACH KH (SAP XEP GIAM DAN THEO MA) ---\n";
        cout << "-----------------------------------------------------------------------\n";
        cout << left;
        cout << "| " << setw(10) << "Ma KH" << "| " << setw(25) << "Ten KH"
            << "| " << setw(15) << "SDT" << "| " << setw(10) << "Diem" << " |" << endl;
        cout << "-----------------------------------------------------------------------\n";
        reverseOrder(root);
        cout << "-----------------------------------------------------------------------\n";
    }

    void timVaHienThiTheoMa(string maKH) {
        NodeKH_BST* result = search(root, maKH);
        if (result != nullptr) {
            cout << "Tim thay khach hang:" << endl;
            result->data.hienThi();
        }
        else {
            cout << "Khong tim thay khach hang voi ma: " << maKH << endl;
        }
    }

    void xoaTheoMa(string maKH) {
        if (search(root, maKH) == nullptr) {
            cout << "Khong tim thay ma " << maKH << " de xoa." << endl; return;
        }
        root = deleteNode(root, maKH);
        cout << "Da xoa thanh cong khach hang co ma: " << maKH << endl;
    }

    void suaThongTin(string maKH) {
        NodeKH_BST* node = search(root, maKH);
        if (node == nullptr) {
            cout << "Khong tim thay ma " << maKH << " de sua." << endl; return;
        }
        cout << "Nhap thong tin moi (KHONG SUA MA):" << endl;
        cout << "Nhap ten KH moi: ";    getline(cin >> ws, node->data.tenKH);
        cout << "Nhap SDT moi: ";   getline(cin >> ws, node->data.sdt);
        cout << "Nhap diem moi: ";    cin >> node->data.diemTichLuy;
        cout << "Cap nhat thanh cong!" << endl;
    }

    int demSoLuong() { return countNodes(root); }
    int tinhTongDiem() { return sumDiem(root); }

    void timMaxDiem() {
        if (root == nullptr) { cout << "Cay rong." << endl; return; }
        KhachHang maxKH = root->data; findMaxDiem(root, maxKH);
        cout << "Khach hang co diem cao nhat:" << endl; maxKH.hienThi();
    }

    void timMinDiem() {
        if (root == nullptr) { cout << "Cay rong." << endl; return; }
        KhachHang minKH = root->data; findMinDiem(root, minKH);
        cout << "Khach hang co diem thap nhat:" << endl; minKH.hienThi();
    }

    void timKiemTheoTen(string ten) {
        bool found = false; searchByName(root, ten, found);
        if (!found) cout << "Khong tim thay khach hang nao co ten chua '" << ten << "'." << endl;
    }

    void ghiVaoFile(string tenFile) {
        ofstream outFile(tenFile); if (!outFile) return;
        writeToFile(root, outFile); outFile.close();
        cout << "Da luu vao file: " << tenFile << endl;
    }

    void docTuFile(string tenFile) {
        ifstream inFile(tenFile); if (!inFile) return;
        giaiPhongBoNho(); root = nullptr; string line;
        while (getline(inFile, line)) {
            stringstream ss(line); string segment; KhachHang v;
            getline(ss, segment, ','); v.maKH = segment;
            getline(ss, segment, ','); v.tenKH = segment;
            getline(ss, segment, ','); v.sdt = segment;
            getline(ss, segment, ','); v.diemTichLuy = (segment.empty() ? 0 : stoi(segment));
            root = insert(root, v);
        }
        inFile.close();
        cout << "Da nap du lieu tu file: " << tenFile << endl;
    }

    void giaiPhongBoNho() { destroyTree(root); root = nullptr; }

    void timKiemTheoSDT(string sdt) {
        bool found = false;
        cout << "Ket qua tim kiem cho SDT " << sdt << ":" << endl;
        searchBySDT(root, sdt, found);
        if (!found) cout << "Khong tim thay khach hang." << endl;
    }

    void timTheoKhoangDiem(int min, int max) {
        bool found = false;
        cout << "Cac khach hang co diem tu " << min << " den " << max << ":" << endl;
        findByDiemRange(root, min, max, found);
        if (!found) cout << "Khong tim thay khach hang nao." << endl;
    }

    void tangDiemHangLoat(int diemThem) {
        addDiem(root, diemThem);
        cout << "Da them " << diemThem << " diem cho tat ca khach hang." << endl;
    }
};