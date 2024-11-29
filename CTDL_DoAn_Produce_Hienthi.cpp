#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <limits>
using namespace std;

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define PINK "\033[38;5;207m"
#define YELLOW "\033[38;5;226m"
#define GREEN "\033[38;5;46m"
#define CYAN "\033[36m"
#define RED "\033[31m"

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
    cout << setw(21) << right << "*" << CYAN << "              MENU LUA CHON           " << GREEN << "*" << endl;
    cout << GREEN;
    cout << setw(60) << right << "*          1. Hien thi hang hoa        *" << endl;
    cout << setw(60) << right << "*          2. Tim kiem hang hoa        *" << endl;
    cout << setw(60) << right << "*          3. Dat hang                 *" << endl;
    cout << setw(60) << right << "*          4. Quan ly                  *" << endl;
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

bool kiemTraDangNhap(const string& user, const string& password) {
    ifstream file("Admin.txt");
    if (!file) {
        cout << "Khong the mo file Admin.txt de kiem tra dang nhap.\n";
        return false;
    }

    string fileUser, filePassword;
    while (file >> fileUser >> filePassword) {
        if (fileUser == user && filePassword == password) {
            return true;
        }
    }

    file.close();
    return false;
}

string nhapMatKhau() {
    string password;
    char ch;
    while (true) {
        ch = _getch();
        if (ch == 27) {
            return "EXIT";
        }
        else if (ch == '\r') {
            break;
        }
        else if (ch == '\b') {
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

void hienThiMenuQuanLy() {
    int luaChon;
    do {
        system("cls");
        cout << GREEN;
        cout << setw(60) << right << string(40, '*') << endl;
        cout << setw(21) << right << "*" << CYAN << "            MENU QUAN LY              " << GREEN << "*" << endl;
        cout << GREEN;
        cout << setw(60) << right << "*          1. Xu ly don hang           *" << endl;
        cout << setw(60) << right << "*          2. Quan ly hang hoa         *" << endl;
        cout << setw(60) << right << "*          0. Thoat                    *" << endl;
        cout << setw(60) << right << string(40, '*') << RESET << endl;
        cout << setw(46) << right << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            cout << "Xy ly don hang" << endl;
            break;
        case 2: {
            cout << "Quan ly don hang" << endl;
            break;
        }
        case 0:
            cout << "Tro ve menu lua chon.\n";
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
}

bool dangNhap() {
    string user, password;
    int soLanThu = 0;
    char key;

    while (soLanThu < 3) {
        system("cls");
        cout << YELLOW;
        cout << setw(60) << right << string(40, '*') << endl;
        cout << setw(21) << right << "*" << RESET;
        cout << GREEN << "           DANG NHAP HE THONG         " << RESET;
        cout << YELLOW << "*" << endl;
        cout << setw(60) << right << string(40, '*');
        cout << RESET << endl;
        cout << GREEN;
        
        cout << setw(38) << right << "User: " << RESET;
        key = _getch();
        if (key == 27) {
            cout << "\nThoat khoi he thong.\n";
            return false;
        }
        cin.putback(key);
        cin.ignore();
        cin >> user;
        cout << GREEN << setw(42) << right << "Password: " << RESET;
        password = nhapMatKhau();
        if (password == "EXIT") {
            cout << "\nThoat khoi he thong.\n";
            return false;
        }

        if (kiemTraDangNhap(user, password)) {
            return true;
        }
        else {
            soLanThu++;
            if (soLanThu < 3) {
                cout << RED << "Sai ten dang nhap hoac mat khau.\n" << RESET;
                cout << "Nhan Enter de nhap lai...";
                cin.ignore(10000, '\n');
                key = _getch();
                if (key == 27) {
                    cout << "\nThoat khoi he thong.\n";
                    return false;
                }
            }
        }
    }
    return false;
}

void xoaDanhSach(HangHoa*& danhSach) {
    while (danhSach) {
        HangHoa* temp = danhSach;
        danhSach = danhSach->next;
        delete temp;
    }
}

void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Ẩn con trỏ
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

int main() {
    hideCursor();

    HangHoa* danhSachHangHoa = docHangHoa("Hanghoa.txt");
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
            case 3: {
                cout << "Dat hang" << endl;
                break;
            }
            case 4: {
                system("cls");
                if (!dangNhap()) {
                    cout << "Dang nhap that bai. Quay ve menu lua chon.\n";
                    break;
                }
                hienThiMenuQuanLy();
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
