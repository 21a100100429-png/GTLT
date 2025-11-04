#pragma once
#include "VPP.h"
#include <sstream>

struct NodeVPP_BST {
    VPP data;
    NodeVPP_BST* left;
    NodeVPP_BST* right;
    NodeVPP_BST(VPP v) : data(v), left(nullptr), right(nullptr) {}
};

class QuanLyVPP_BST {
private:
    NodeVPP_BST* root;

    NodeVPP_BST* insert(NodeVPP_BST* node, VPP v) {
        if (node == nullptr) return new NodeVPP_BST(v);
        if (v.maVPP < node->data.maVPP)
            node->left = insert(node->left, v);
        else if (v.maVPP > node->data.maVPP)
            node->right = insert(node->right, v);
        return node;
    }

    NodeVPP_BST* search(NodeVPP_BST* node, string maVPP) {
        if (node == nullptr || node->data.maVPP == maVPP) return node;
        if (maVPP < node->data.maVPP)
            return search(node->left, maVPP);
        return search(node->right, maVPP);
    }

    void destroyTree(NodeVPP_BST* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    void inOrder(NodeVPP_BST* node) {
        if (node) {
            inOrder(node->left);
            node->data.hienThi();
            inOrder(node->right);
        }
    }

    void reverseOrder(NodeVPP_BST* node) {
        if (node) {
            reverseOrder(node->right);
            node->data.hienThi();
            reverseOrder(node->left);
        }
    }

    int countNodes(NodeVPP_BST* node) {
        return (node == nullptr) ? 0 : (1 + countNodes(node->left) + countNodes(node->right));
    }

    double sumValue(NodeVPP_BST* node) {
        if (node == nullptr) return 0;
        double nodeValue = node->data.donGia * node->data.soLuongTon;
        return nodeValue + sumValue(node->left) + sumValue(node->right);
    }

    void writeToFile(NodeVPP_BST* node, ostream& outFile) {
        if (node) {
            writeToFile(node->left, outFile);
            outFile << node->data;
            writeToFile(node->right, outFile);
        }
    }

    NodeVPP_BST* findMin(NodeVPP_BST* node) {
        while (node && node->left != nullptr) node = node->left;
        return node;
    }

    void findMaxPrice(NodeVPP_BST* node, VPP& maxVPP) {
        if (node == nullptr) return;
        if (node->data.donGia > maxVPP.donGia) maxVPP = node->data;
        findMaxPrice(node->left, maxVPP);
        findMaxPrice(node->right, maxVPP);
    }

    void findMinPrice(NodeVPP_BST* node, VPP& minVPP) {
        if (node == nullptr) return;
        if (node->data.donGia < minVPP.donGia) minVPP = node->data;
        findMinPrice(node->left, minVPP);
        findMinPrice(node->right, minVPP);
    }

    void findMaxStock(NodeVPP_BST* node, VPP& maxVPP) {
        if (node == nullptr) return;
        if (node->data.soLuongTon > maxVPP.soLuongTon) maxVPP = node->data;
        findMaxStock(node->left, maxVPP);
        findMaxStock(node->right, maxVPP);
    }

    void findMinStock(NodeVPP_BST* node, VPP& minVPP) {
        if (node == nullptr) return;
        if (node->data.soLuongTon < minVPP.soLuongTon) minVPP = node->data;
        findMinStock(node->left, minVPP);
        findMinStock(node->right, minVPP);
    }

    NodeVPP_BST* deleteNode(NodeVPP_BST* node, string maVPP) {
        if (node == nullptr) return node;
        if (maVPP < node->data.maVPP)
            node->left = deleteNode(node->left, maVPP);
        else if (maVPP > node->data.maVPP)
            node->right = deleteNode(node->right, maVPP);
        else {
            if (node->left == nullptr) {
                NodeVPP_BST* temp = node->right; delete node; return temp;
            }
            else if (node->right == nullptr) {
                NodeVPP_BST* temp = node->left; delete node; return temp;
            }
            NodeVPP_BST* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data.maVPP);
        }
        return node;
    }

    void searchByName(NodeVPP_BST* node, string ten, bool& found) {
        if (node == nullptr) return;
        if (node->data.tenVPP.find(ten) != string::npos) {
            node->data.hienThi(); found = true;
        }
        searchByName(node->left, ten, found);
        searchByName(node->right, ten, found);
    }

    void findByPriceRange(NodeVPP_BST* node, double min, double max, bool& found) {
        if (node == nullptr) return;
        if (node->data.donGia >= min && node->data.donGia <= max) {
            node->data.hienThi(); found = true;
        }
        findByPriceRange(node->left, min, max, found);
        findByPriceRange(node->right, min, max, found);
    }

    void countByType(NodeVPP_BST* node, string loai, int& count) {
        if (node == nullptr) return;
        if (node->data.loaiVPP == loai) {
            count++;
        }
        countByType(node->left, loai, count);
        countByType(node->right, loai, count);
    }

    void applyPriceIncrease(NodeVPP_BST* node, double percent) {
        if (node == nullptr) return;
        node->data.donGia = node->data.donGia * (1.0 + percent / 100.0);
        applyPriceIncrease(node->left, percent);
        applyPriceIncrease(node->right, percent);
    }

public:
    QuanLyVPP_BST() : root(nullptr) {}
    ~QuanLyVPP_BST() { giaiPhongBoNho(); }

    void themMoi(VPP v) {
        root = insert(root, v);
        cout << "Da them VPP " << v.maVPP << " vao cay." << endl;
    }

    void hienThi() {
        if (root == nullptr) { cout << "Cay rong." << endl; return; }
        cout << "\n--- DANH SACH VPP (SAP XEP TANG DAN THEO MA) ---\n";
        cout << "----------------------------------------------------------------------------------\n";
        cout << left;
        cout << "| " << setw(10) << "Ma VPP" << "| " << setw(25) << "Ten VPP"
            << "| " << setw(15) << "Loai VPP" << "| " << setw(10) << "Don Gia"
            << "| " << setw(8) << "So Luong" << " |" << endl;
        cout << "----------------------------------------------------------------------------------\n";
        inOrder(root);
        cout << "----------------------------------------------------------------------------------\n";
    }

    void hienThiNguoc() {
        if (root == nullptr) { cout << "Cay rong." << endl; return; }
        cout << "\n--- DANH SACH VPP (SAP XEP GIAM DAN THEO MA) ---\n";
        cout << "----------------------------------------------------------------------------------\n";
        cout << left;
        cout << "| " << setw(10) << "Ma VPP" << "| " << setw(25) << "Ten VPP"
            << "| " << setw(15) << "Loai VPP" << "| " << setw(10) << "Don Gia"
            << "| " << setw(8) << "So Luong" << " |" << endl;
        cout << "----------------------------------------------------------------------------------\n";
        reverseOrder(root);
        cout << "----------------------------------------------------------------------------------\n";
    }

    void timVaHienThiTheoMa(string maVPP) {
        NodeVPP_BST* result = search(root, maVPP);
        if (result != nullptr) {
            cout << "Tim thay san pham:" << endl;
            result->data.hienThi();
        }
        else {
            cout << "Khong tim thay san pham voi ma: " << maVPP << endl;
        }
    }

    void xoaTheoMa(string maVPP) {
        if (search(root, maVPP) == nullptr) {
            cout << "Khong tim thay ma " << maVPP << " de xoa." << endl; return;
        }
        root = deleteNode(root, maVPP);
        cout << "Da xoa thanh cong san pham co ma: " << maVPP << endl;
    }

    void suaThongTin(string maVPP) {
        NodeVPP_BST* node = search(root, maVPP);
        if (node == nullptr) {
            cout << "Khong tim thay ma " << maVPP << " de sua." << endl; return;
        }
        cout << "Nhap thong tin moi (KHONG SUA MA):" << endl;
        cout << "Nhap ten VPP moi: ";    getline(cin >> ws, node->data.tenVPP);
        cout << "Nhap loai VPP moi: ";   getline(cin >> ws, node->data.loaiVPP);
        cout << "Nhap don gia moi: ";    cin >> node->data.donGia;
        cout << "Nhap so luong ton moi: "; cin >> node->data.soLuongTon;
        cout << "Cap nhat thanh cong!" << endl;
    }

    int demSoLuong() { return countNodes(root); }
    double tinhTongGiaTriTonKho() { return sumValue(root); }

    void timMaxGia() {
        if (root == nullptr) { cout << "Cay rong." << endl; return; }
        VPP maxVPP = root->data; findMaxPrice(root, maxVPP);
        cout << "San pham co gia cao nhat:" << endl; maxVPP.hienThi();
    }

    void timMinGia() {
        if (root == nullptr) { cout << "Cay rong." << endl; return; }
        VPP minVPP = root->data; findMinPrice(root, minVPP);
        cout << "San pham co gia thap nhat:" << endl; minVPP.hienThi();
    }

    void timMaxSoLuong() {
        if (root == nullptr) { cout << "Cay rong." << endl; return; }
        VPP maxVPP = root->data; findMaxStock(root, maxVPP);
        cout << "San pham co so luong ton nhieu nhat:" << endl; maxVPP.hienThi();
    }

    void timMinSoLuong() {
        if (root == nullptr) { cout << "Cay rong." << endl; return; }
        VPP minVPP = root->data; findMinStock(root, minVPP);
        cout << "San pham co so luong ton it nhat:" << endl; minVPP.hienThi();
    }

    void timKiemTheoTen(string ten) {
        bool found = false; searchByName(root, ten, found);
        if (!found) cout << "Khong tim thay san pham nao co ten chua '" << ten << "'." << endl;
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
            stringstream ss(line); string segment; VPP v;
            getline(ss, segment, ','); v.maVPP = segment;
            getline(ss, segment, ','); v.tenVPP = segment;
            getline(ss, segment, ','); v.loaiVPP = segment;
            getline(ss, segment, ','); v.donGia = (segment.empty() ? 0.0 : stod(segment));
            getline(ss, segment, ','); v.soLuongTon = (segment.empty() ? 0 : stoi(segment));
            root = insert(root, v);
        }
        inFile.close();
        cout << "Da nap du lieu tu file: " << tenFile << endl;
    }

    void giaiPhongBoNho() { destroyTree(root); root = nullptr; }

    void timTheoKhoangGia(double min, double max) {
        bool found = false;
        cout << "Cac san pham co gia tu " << min << " den " << max << ":" << endl;
        findByPriceRange(root, min, max, found);
        if (!found) cout << "Khong tim thay san pham nao." << endl;
    }

    void thongKeTheoLoai(string loai) {
        int count = 0;
        countByType(root, loai, count);
        cout << "Co " << count << " san pham thuoc loai '" << loai << "'." << endl;
    }

    void tangGiaHangLoat(double percent) {
        applyPriceIncrease(root, percent);
        cout << "Da tang gia " << percent << "% cho tat ca san pham." << endl;
    }
};