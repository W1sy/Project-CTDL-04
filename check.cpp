#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <conio.h>
#include "Display.h"
#include <iomanip>
#include <cctype>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define PINK "\033[38;5;207m"
#define YELLOW "\033[38;5;226m"
#define GREEN "\033[38;5;46m"
#define CYAN "\033[36m"
#define RED "\033[31m"

using namespace std;

/*----------------Thông tin lưu trữ-----------------*/

/*1. CLASS HÀNG HÓA*/
class HangHoa {
private:
    string _strMaHang, _strTenHang, _strNoiSanXuat, _strMauSac, _strNgayNhapKho;
    int _iGiaBan, _iSoLuong;
public:
    HangHoa() {
        _strMaHang = "";
        _strTenHang = "";
        _strNoiSanXuat = "";
        _strMauSac = "";
        _iGiaBan = 0;
        _strNgayNhapKho = "";
        _iSoLuong = 0;
    }
    /*Hàm get cho tất cả*/
    string getMaHang() {
        return _strMaHang;
    }
    string getTenHang() {
        return _strTenHang;
    }
    string getNoiSanXuat() {
        return _strNoiSanXuat;
    }
    string getMauSac() {
        return _strMauSac;
    }

    int getGiaBan() {
        return _iGiaBan;
    }
    string getNgayNhapKho() {
        return _strNgayNhapKho;
    }
    int getSoLuong() {
        return _iSoLuong;
    }
    /*Hàm set cho tất cả*/
    void setMaHang(string strMaHang) {
        _strMaHang = strMaHang;
    }
    void setTenHang(string strTenHang) {
        _strTenHang = strTenHang;
    }
    void setNoiSanXuat(string strNoiSanXuat) {
        _strNoiSanXuat = strNoiSanXuat;
    }
    void setMauSac(string strMauSac) {
        _strMauSac = strMauSac;
    }
    void setGiaBan(int iGiaBan) {
        _iGiaBan = iGiaBan;
    }
    void setNgayNhapKho(string strNgayNhapKho) {
        _strNgayNhapKho = strNgayNhapKho;
    }
    void setSoLuong(int iSoLuong) {
        _iSoLuong = iSoLuong;
    }
    /*Nhập Xuất*/
    friend istream& operator >>(istream& is, HangHoa& in) {
        is >> in._strMaHang;
        getline(is, in._strTenHang);
        is >> in._strNoiSanXuat >> in._strMauSac >> in._iGiaBan >> in._strNgayNhapKho >> in._iSoLuong;
        return is;
    }
    friend ostream& operator << (ostream& os, HangHoa out) {
        cout << "XAC NHAN THONG TIN: ";
        os << out._strMaHang << " -> " << out._strTenHang << " -> " << out._strNoiSanXuat << " -> " << out._strMauSac << " -> " << out._iGiaBan << " -> " << out._strNgayNhapKho << " -> " << out._iSoLuong;
        return os;
    }

};

/*2. ĐƠN HÀNG*/
class DonHang {
private:
    vector<string> _vtMaHang;
    vector<int> _vtSoLuong;
    int _iTongTien;
    string _strTenKhachHang, _strDiaChi, _strSoDienThoai, _strNgayDatHang;
public:
    DonHang() {
        _strTenKhachHang = "";
        _strDiaChi = "";
        _strSoDienThoai = "";
        _strNgayDatHang = "";
        _iTongTien = 0;
    }
    /*Hàm get cho tất cả*/
    string getTenKhachHang() {
        return _strTenKhachHang;
    }
    string getDiaChi() {
        return _strDiaChi;
    }
    string getSoDienThoai() {
        return _strSoDienThoai;
    }
    string getNgayDatHang() {
        return _strNgayDatHang;
    }
    int getTongTien() {
        return _iTongTien;
    }
    vector<string> getLoaiHang() {
        return _vtMaHang;
    }
    vector<int> getSoLuong() {
        return _vtSoLuong;
    }
    /*Hàm set cho tất cả*/
    void setTenKhachHang(string strName) {
        _strTenKhachHang = strName;
    }
    void setDiaChi(string strAddress) {
        _strDiaChi = strAddress;
    }
    void setSoDienThoai(string strNumber) {
        _strSoDienThoai = strNumber;
    }
    void setNgayDatHang(string strDate) {
        _strNgayDatHang = strDate;
    }
    void setTongTien(int iSum) {
        _iTongTien = iSum;
    }
    void setLoaiHang(vector<string> vtMaHang) {
        _vtMaHang = vtMaHang;
    }
    void setSoLuong(vector<int> vtSoLuong) {
        _vtSoLuong = vtSoLuong;
    }

};
class DanhSachHangHoa;
class Node {
    HangHoa data;
    Node* _pNext;
    friend DanhSachHangHoa;
public:
    Node(HangHoa a) {
        data = a;
        _pNext = NULL;
    }
};
class DanhSachHangHoa {
private:
    Node* _pHead;
    Node* _pTail;
    int _soLuongMatHang;

public:
    DanhSachHangHoa() {
        _pHead = NULL;
        _pTail = NULL;
        _soLuongMatHang = 0;
    }

    void themCuoi(HangHoa hh) {
        Node* _pNodeMoi = new Node(hh);
        if (_pTail == NULL) {
            _pHead = _pTail = _pNodeMoi;
        }
        else {
            _pTail->_pNext = _pNodeMoi;
            _pTail = _pNodeMoi;
        }
        _soLuongMatHang++;
    }

    void nhapDuLieu(string duongDan) {
        ifstream fileNhap(duongDan);
        HangHoa hh;
        while (!fileNhap.eof()) {
            string dong;
            while (getline(fileNhap, dong)) {
                if (dong[0] == '/' && dong[1] == '/') continue;
                stringstream ss(dong);
                string tu;
                vector<string> hangHoa;
                while (!ss.eof()) {
                    getline(ss, tu, ';');
                    tu.erase(tu.find_last_not_of(" ") + 1);
                    tu.erase(0, tu.find_first_not_of(" "));
                    hangHoa.push_back(tu);
                }
                if (hangHoa.size() >= 7 && hangHoa[0].length() == 4 && hangHoa[1].length() && hangHoa[2].length() && hangHoa[3].length() && hangHoa[4].length()
                    && hangHoa[5].length() && hangHoa[6].length()) {
                    hh.setMaHang(hangHoa[0]);
                    hh.setTenHang(hangHoa[1]);
                    hh.setNoiSanXuat(hangHoa[2]);
                    hh.setMauSac(hangHoa[3]);
                    hh.setGiaBan(stoi(hangHoa[4]));
                    hh.setNgayNhapKho(hangHoa[5]);
                    hh.setSoLuong(stoi(hangHoa[6]));
                    themCuoi(hh);
                }
            }
        }
        fileNhap.close();
    }
    void updateDuLieu(string path) {
        ofstream output;
        output.open(path);
        if (output.is_open()) {
            Node* pTmp = _pHead;
            while (pTmp != NULL) {
                output << pTmp->data.getMaHang() << "; ";
                output << pTmp->data.getTenHang() << "; ";
                output << pTmp->data.getNoiSanXuat() << "; ";
                output << pTmp->data.getMauSac() << "; ";
                output << pTmp->data.getGiaBan() << "; ";
                output << pTmp->data.getNgayNhapKho() << "; ";
                output << pTmp->data.getSoLuong() << endl;
                pTmp = pTmp->_pNext;
            }
        }
        output.close();
    }

    bool kiemTraNhapSoDauVao(int& value) {
        string input;
        cin >> input;

        // Kiểm tra nếu nhập có ký tự không phải số
        for (char c : input) {
            if (!isdigit(c)) {  // Kiểm tra nếu ký tự không phải số
                return false;
            }
        }

        // Chuyển chuỗi thành số nguyên và kiểm tra giá trị
        value = stoi(input);
        return value > 0;  // Kiểm tra số phải lớn hơn 0
    }

    bool laNamNhuan(int nam) {
        return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    }

    bool kiemTraNgayHopLe(int ngay, int thang, int nam) {
        if (nam <= 0 || thang <= 0 || thang > 12 || ngay <= 0) {
            return false;
        }

        int soNgayTrongThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Nếu là năm nhuận, tháng 2 có 29 ngày.
        if (laNamNhuan(nam)) {
            soNgayTrongThang[1] = 29;
        }

        return ngay <= soNgayTrongThang[thang - 1];
    }

    void themHangHoa() {
        HangHoa hh;
        string maHang, tenHang, noiSanXuat, mauSac;
        int ngay, thang, nam;
        int giaBan, soLuong;

        cout << endl;
        cout << setw(35) << right << PINK << "======= THEM HANG HOA MOI =======" << RESET << endl;
        // Nhập và kiểm tra mã hàng.
        do {
            cout << setw(38) << right << "Nhap ma hang: ";
            cin >> maHang;
            if (maHang.length() != 4) {
                cout << setw(29) << right << RED << "Ma hang phai co 4 ky tu. Vui long nhap lai." << RESET << endl;
            }
            else if (TonTaiHangHoa(maHang)) {
                cout << setw(29) << right << RED << "Ma hang da ton tai. Vui long nhap lai." << RESET << endl;
            }
            else {
                break;
            }
        } while (true);

        // Nhập thông tin còn lại.
        cin.ignore(); // Xóa bộ đệm.
        cout << setw(39) << right << "Nhap ten hang: ";
        getline(cin, tenHang);
        cout << setw(43) << right << "Nhap noi san xuat: ";
        getline(cin, noiSanXuat);
        cout << setw(38) << right << "Nhap mau sac: ";
        getline(cin, mauSac);
        do {
            cout << setw(44) << right << "Nhap ngay nhap kho: " << endl;
            cout << setw(35) << right << "Ngay: "; kiemTraNhapSoDauVao(ngay);
            cout << setw(36) << right << "Thang: "; kiemTraNhapSoDauVao(thang);
            cout << setw(34) << right << "Nam: "; kiemTraNhapSoDauVao(nam);
            
            if (kiemTraNgayHopLe(ngay, thang, nam)) {
                break;
            }
            else {
                cout << setw(29) << right << RED << "Ngay nhap kho khong hop le. Vui long nhap lai." << RESET << endl;
            }
        } while (true);


        // Kiểm tra và nhập giá bán.
        do {
            cout << setw(38) << right << "Nhap gia ban: ";
            kiemTraNhapSoDauVao(giaBan);
            if (giaBan > 0) {
                break;
            }
            else {
                cout << setw(29) << right << RED << "Gia ban phai la so nguyen duong. Vui long nhap lai." << RESET << endl;
            }
        } while (true);

        // Kiểm tra và nhập số lượng.
        while (true) {
            string input;
            cout << setw(39) << right << "Nhap so luong: ";
            cin >> input;

            // Kiểm tra xem người dùng có nhập chữ hoặc ký tự không phải số
            bool isValid = true;
            for (char c : input) {
                if (!isdigit(c)) {  // Kiểm tra nếu ký tự không phải là số
                    isValid = false;
                    break;
                }
            }

            if (!isValid) {
                cout << setw(29) << right << RED << "Nhap sai! Vui long nhap so nguyen duong." << RESET << endl;
            }
            else {
                // Chuyển đổi từ chuỗi sang số nguyên
                soLuong = stoi(input);

                if (soLuong <= 0) {
                    cout << setw(29) << right << RED << "So luong phai la so nguyen duong. Vui long nhap lai." << RESET << endl;
                }
                else {
                    break; // Thoát vòng lặp khi nhập hợp lệ.
                }
            }
        }

        // Cập nhật thông tin hàng hóa vào đối tượng.
        hh.setMaHang(maHang);
        hh.setTenHang(tenHang);
        hh.setNoiSanXuat(noiSanXuat);
        hh.setMauSac(mauSac);
        hh.setNgayNhapKho((ngay < 10 ? "0" : "") + to_string(ngay) + "/" + (thang < 10 ? "0" : "") + to_string(thang) + "/" + to_string(nam));
        hh.setGiaBan(giaBan);
        hh.setSoLuong(soLuong);

        // Thêm hàng hóa vào danh sách.
        themCuoi(hh);
        cout << setw(34) << GREEN << "Them hang hoa thanh cong!" << RESET << endl;
    }

    void searchHangHoa(string tuKhoa) {
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
        Node* _pTemp = _pHead;
        while (_pTemp != NULL) {
            if (_pTemp->data.getMaHang().find(tuKhoa) != string::npos || _pTemp->data.getTenHang().find(tuKhoa) != string::npos) {
                cout << left << setw(10) << _pTemp->data.getMaHang()
                    << setw(25) << _pTemp->data.getTenHang()
                    << setw(20) << _pTemp->data.getNoiSanXuat()
                    << setw(15) << _pTemp->data.getMauSac()
                    << setw(15) << _pTemp->data.getGiaBan()
                    << setw(15) << _pTemp->data.getNgayNhapKho()
                    << setw(10) << _pTemp->data.getSoLuong() << endl;
                cout << string(110, '-') << endl;
                timThay = true;
            }
            _pTemp = _pTemp->_pNext;
        }

        if (!timThay) {
            cout << "Hang hoa khong ton tai." << endl;
        }
    }

    void HienThiDanhSach() {
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

        Node* _pTemp = _pHead;
        while (_pTemp != NULL) {
            cout << left << setw(10) << _pTemp->data.getMaHang()
                << setw(25) << _pTemp->data.getTenHang()
                << setw(20) << _pTemp->data.getNoiSanXuat()
                << setw(15) << _pTemp->data.getMauSac()
                << setw(15) << _pTemp->data.getGiaBan()
                << setw(15) << _pTemp->data.getNgayNhapKho()
                << setw(10) << _pTemp->data.getSoLuong() << endl;
            cout << string(110, '-') << endl;
            _pTemp = _pTemp->_pNext;
        }
    }

    void HienThiDanhMuc() {
        cout << GREEN;
        cout << setw(60) << right << string(40, '*') << endl;
        cout << setw(21) << right << "*" << CYAN << "     CHUONG TRINH QUAN LY HANG HOA    " << GREEN << "*" << endl;
        cout << GREEN;
        cout << setw(60) << right << "*       1. Hien thi hang hoa           *" << endl;
        cout << setw(60) << right << "*       2. Tim kiem hang hoa           *" << endl;
        cout << setw(60) << right << "*       3. Dat hang                    *" << endl;
        cout << setw(60) << right << "*       4. Quan ly hang hoa            *" << endl;
        cout << setw(60) << right << "*       0. Thoat                       *" << endl;
        cout << setw(60) << right << string(40, '*') << RESET << endl;
        cout << setw(43) << right << "Nhap lua chon: ";
    }

    bool TonTaiHangHoa(string maHang) {
        Node* _pTemp = _pHead;
        while (_pTemp != NULL) {
            if (_pTemp->data.getMaHang() == maHang) {
                return true;
            }
            _pTemp = _pTemp->_pNext;
        }
        return false;
    }

    void Xoa(string x) {
        if (_pHead != nullptr && _pHead->data.getMaHang() == x) {
            Node* pTemp = _pHead;
            _pHead = _pHead->_pNext;
            delete pTemp;
            _soLuongMatHang--;
            return;
        }
        else {
            Node* pWalker = _pHead;
            Node* pTemp = NULL;

            while (pWalker != NULL && pWalker->data.getMaHang() != x) {
                pTemp = pWalker;
                pWalker = pWalker->_pNext;
            }

            if (pWalker == NULL) return;

            if (pTemp != NULL) {
                if (pWalker == _pTail) {
                    _pTail = pTemp;
                    _pTail->_pNext = NULL;
                }
                pTemp->_pNext = pWalker->_pNext;
                delete pWalker;
                _soLuongMatHang--;
            }
        }
    }

    void updateSoLuong(string x, int soluong) {
        Node* pTemp = _pHead;
        while (pTemp != NULL) {
            if (pTemp->data.getMaHang() == x) {
                pTemp->data.setSoLuong(soluong);
                return;
            }
            pTemp = pTemp->_pNext;
        }
    }
    
    int getGiaMatHang(string x) {
        Node* pTemp = _pHead;
        while (pTemp != NULL) {
            if (pTemp->data.getMaHang() == x) {
                return pTemp->data.getGiaBan();
            }
            pTemp = pTemp->_pNext;
        }
        return 0;
    }

    int getSoLuongMatHang(string x) {
        Node* pTemp = _pHead;
        while (pTemp != NULL) {
            if (pTemp->data.getMaHang() == x) {
                return pTemp->data.getSoLuong();
            }
            pTemp = pTemp->_pNext;
        }
        return 0;
    }
};
 
/*3. CLASS ADMIN*/
class Admin {
private:
    string _user, _password;
    int _soLanThu;
public:
    Admin() : _soLanThu(0) {}
    string getUser() {
        return _user;
    }
    void setUser(const string& user) {
        _user = user;
    }
    string getPassword() {
        return _password;
    }
    void setPassword(const string& password) {
        _password = password;
    }
    int getSoLanThu() {
        return _soLanThu;
    }
    void setSoLanThu(const int& soLanThu) {
        _soLanThu = soLanThu;
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

    void hienThiMenuQuanLy(DanhSachHangHoa &danhSachHangHoa, string duongDanFile) {
        int luaChon;
        do {
            system("cls");
            cout << GREEN;
            cout << setw(60) << right << string(40, '*') << endl;
            cout << setw(21) << right << "*" << CYAN << "            MENU QUAN LY              " << GREEN << "*" << endl;
            cout << GREEN;
            cout << setw(60) << right << "*      1. Them hang hoa moi            *" << endl;
            cout << setw(60) << right << "*      2. Xoa hang hao theo ma         *" << endl;
            cout << setw(60) << right << "*      3. Cap nhat so luong hang hoa   *" << endl;
            cout << setw(60) << right << "*      4. DS hang hoa sau khi update   *" << endl;
            cout << setw(60) << right << "*      0. Quay lai menu chinh          *" << endl;
            cout << setw(60) << right << string(40, '*') << RESET << endl;
            cout << setw(46) << right << "Nhap lua chon: ";
            cin >> luaChon;

            switch (luaChon) {
                case 1:
                    // Thêm hàng hóa mới.
                    danhSachHangHoa.themHangHoa();
                    danhSachHangHoa.updateDuLieu(duongDanFile); // Cập nhật lại file sau khi thêm.
                    break;
                case 2: {
                    // Xóa hàng hóa theo mã.
                    string maHang;
                    cout << "Nhap ma hang muon xoa: ";
                    cin >> maHang;
                    if (danhSachHangHoa.TonTaiHangHoa(maHang)) {
                        danhSachHangHoa.Xoa(maHang);
                        danhSachHangHoa.updateDuLieu(duongDanFile); // Cập nhật lại file sau khi xóa.
                        cout << "Xoa hang hoa thanh cong.\n";
                    }
                    else {
                        cout << "Ma hang khong ton tai.\n";
                    }
                    system("PAUSE");
                    break;
                }
                case 3: {
                    string maHang;
                    int soLuongMoi;
                    cout << "Nhap ma hang muon cap nhat: ";
                    cin >> maHang;
                    if (danhSachHangHoa.TonTaiHangHoa(maHang)) {
                        cout << "Nhap so luong moi: ";
                        cin >> soLuongMoi;
                        danhSachHangHoa.updateSoLuong(maHang, soLuongMoi);
                        danhSachHangHoa.updateDuLieu(duongDanFile); // Cập nhật lại file sau khi sửa.
                        cout << "Cap nhat so luong thanh cong.\n";
                    }
                    else {
                        cout << "Ma hang khong ton tai.\n";
                    }
                    system("PAUSE");
                    break;
                }
                case 4: {
                    // Hiển thị danh sách hàng hóa.
                    danhSachHangHoa.HienThiDanhSach();
                    system("PAUSE"); // Dừng màn hình chờ người dùng bấm phím tiếp tục.
                    break;
                }
                case 0:
                    cout << "Tro ve menu lua chon.\n";
                    break;
                default:
                    cout << "Lua chon khong hop le.\n";
                    system("PAUSE");
                    break;
                }

                if (luaChon != 0) {
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
                cout << "\nDang nhap that bai. Tro ve menu chinh.\n";
                cout << "Press any key to continue....";
                return false;
            }
            cin.putback(key);
            cin.ignore();
            cin >> user;
            cout << GREEN << setw(42) << right << "Password: " << RESET;
            password = nhapMatKhau();
            if (password == "EXIT") {
                cout << "\nDang nhap that bai. Tro ve menu chinh.\n";
                cout << "Press any key to continue....";
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
                        cout << "\nDang nhap that bai. Tro ve menu chinh.\n";
                        cout << "Press any key to continue....";
                        return false;
                    }
                }
            }
        }
        if (soLanThu == 3) {
            cout << "Ban da dang nhap sai 3 lan. Dang nhap that bai. Tro ve menu chinh.\n";
        }
        return false;
    }
};

int main() {
    DanhSachHangHoa danhSachHangHoa;
    int luaChon;
    string duongDanFile = "HangHoa.txt";

    danhSachHangHoa.nhapDuLieu(duongDanFile);
    Admin ad;
    do {
        system("CLS");
        danhSachHangHoa.HienThiDanhMuc();
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            danhSachHangHoa.HienThiDanhSach();
            system("PAUSE"); // Dừng màn hình chờ người dùng bấm phím tiếp tục.
            break;
        case 2: {
            // Tìm kiếm hàng hóa.
            string tuKhoa;
            cout << "Nhap ma hang hoac ten hang muon tim kiem: ";
            cin.ignore(); // Xóa bộ nhớ đệm để tránh lỗi khi nhập chuỗi.
            getline(cin, tuKhoa);
            danhSachHangHoa.searchHangHoa(tuKhoa);
            system("PAUSE");
            break;
        }
        case 3:
            cout << "Dat hang" << endl;
            break;
        case 4:
            system("cls");
            if (!ad.dangNhap()) {
                cin.ignore();
                cin.get();
                break;
            }
            ad.hienThiMenuQuanLy(danhSachHangHoa, duongDanFile);
            break;
        case 0:
            // Thoát chương trình.
            cout << "Cam on ban da su dung chuong trinh. Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
            system("PAUSE");
            break;
        }
    } while (luaChon != 0);

    return 0;
}
