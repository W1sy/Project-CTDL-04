#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define PINK "\033[38;5;207m"
#define YELLOW "\033[38;5;226m"
#define GREEN "\033[38;5;46m"
#define CYAN "\033[36m"

struct HangHoa {
    string maHang;
    string tenHang;
    string noiSanXuat;
    string mauSac;
    string giaBan;
    string ngayNhapKho;
    int soLuong;
    HangHoa* next;
};

HangHoa* taoHangHoa(const string& maHang, const string& tenHang, const string& noiSanXuat,
    const string& mauSac, const string& giaBan, const string& ngayNhapKho, int soLuong) {
    HangHoa* hh = new HangHoa{ maHang, tenHang, noiSanXuat, mauSac, giaBan, ngayNhapKho, soLuong, nullptr };
    return hh;
}

void themHangHoa(HangHoa*& head, HangHoa* hh) {
    if (!head) {
        head = hh;
    }
    else {
        HangHoa* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = hh;
    }
}

HangHoa* docHangHoa(const string& tenFile) {
    HangHoa* danhSach = nullptr;
    ifstream file(tenFile);
    if (!file) {
        cout << "Khong the mo file " << tenFile << endl;
        return nullptr;
    }

    string maHang, tenHang, noiSanXuat, mauSac, giaBan, ngayNhapKho;
    int soLuong;
    while (getline(file, maHang, '|') &&
        getline(file, tenHang, '|') &&
        getline(file, noiSanXuat, '|') &&
        getline(file, mauSac, '|') &&
        getline(file, giaBan, '|') &&
        getline(file, ngayNhapKho, '|') &&
        file >> soLuong) {
        file.ignore();
        HangHoa* hh = taoHangHoa(maHang, tenHang, noiSanXuat, mauSac, giaBan, ngayNhapKho, soLuong);
        themHangHoa(danhSach, hh);
    }
    file.close();
    return danhSach;
}

void hienThiHangHoa(HangHoa* danhSach) {
    if (!danhSach) {
        cout << "Danh sach hang hoa trong!" << endl;
        return;
    }
    cout << endl;
    cout << BOLD << PINK << setw(60) << right << "BANG HANG HOA" << RESET << endl;
    cout << BOLD << YELLOW;
    cout << left << setw(10) << "Ma hang"
        << setw(25) << "Ten hang"
        << setw(20) << "Noi san xuat"
        << setw(15) << "Mau sac"
        << setw(15) << "Gia ban"
        << setw(15) << "Ngay nhap"
        << setw(10) << "So luong" << RESET << endl;
    cout << string(110, '-') << endl;

    HangHoa* temp = danhSach;
    while (temp) {
        cout << left << setw(10) << temp->maHang
            << setw(25) << temp->tenHang
            << setw(20) << temp->noiSanXuat
            << setw(15) << temp->mauSac
            << setw(15) << temp->giaBan
            << setw(15) << temp->ngayNhapKho
            << setw(10) << temp->soLuong << endl;
        cout << string(110, '-') << endl;
        temp = temp->next;
    }
}

void hienThiDanhMuc() {
    cout << GREEN;
    cout << setw(60) << right << string(40, '*') << endl;
    cout << setw(21) << right << "*" << CYAN << "            DANH MUC LUA CHON         " << GREEN << "*" << endl;
    cout << GREEN;
    cout << setw(60) << right << "*          1. Hien thi hang hoa        *" << endl;
    cout << setw(60) << right << "*          2. Tim kiem hang hoa        *" << endl;
    cout << setw(60) << right << "*          0. Thoat                    *" << endl;
    cout << setw(60) << right << string(40, '*') << RESET << endl;
    cout << setw(46) << right << "Nhap lua chon: ";
}

void timKiemHangHoa(HangHoa* danhSach, const string& tuKhoa) {
    if (!danhSach) {
        cout << "Danh sach hang hoa trong!" << endl;
        return;
    }

    cout << "\nKet qua tim kiem:\n";
    cout << BOLD << YELLOW;
    cout << left << setw(10) << "Ma hang"
        << setw(25) << "Ten hang"
        << setw(20) << "Noi san xuat"
        << setw(15) << "Mau sac"
        << setw(15) << "Gia ban"
        << setw(15) << "Ngay nhap"
        << setw(10) << "So luong" << RESET << endl;
    cout << string(110, '-') << endl;

    bool timThay = false;
    HangHoa* temp = danhSach;
    while (temp) {
        if (temp->maHang.find(tuKhoa) != string::npos || temp->tenHang.find(tuKhoa) != string::npos) {
            cout << left << setw(10) << temp->maHang
                << setw(25) << temp->tenHang
                << setw(20) << temp->noiSanXuat
                << setw(15) << temp->mauSac
                << setw(15) << temp->giaBan
                << setw(15) << temp->ngayNhapKho
                << setw(10) << temp->soLuong << endl;
            cout << string(110, '-') << endl;
            timThay = true;
        }
        temp = temp->next;
    }

    if (!timThay) {
        cout << "Khong tim thay hang hoa phu hop." << endl;
    }
}

void xoaDanhSach(HangHoa*& danhSach) {
    while (danhSach) {
        HangHoa* temp = danhSach;
        danhSach = danhSach->next;
        delete temp;
    }
}

int main() {
    HangHoa* danhSachHangHoa = docHangHoa("HangHoa.txt");
    int luaChon;

    do {
        system("cls");
        hienThiDanhMuc();
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            hienThiHangHoa(danhSachHangHoa);
            break;
        case 2: {
            cout << "Nhap ma hoac ten hang hoa de tim kiem: ";
            cin.ignore();
            string tuKhoa;
            getline(cin, tuKhoa);
            timKiemHangHoa(danhSachHangHoa, tuKhoa);
            break;
        }
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le.\n";
            break;
        }

        if (luaChon != 0) {
            cout << "Nhan Enter de tiep tuc...";
            cin.ignore();
            cin.get();
        }
    } while (luaChon != 0);

    xoaDanhSach(danhSachHangHoa);

    return 0;
}