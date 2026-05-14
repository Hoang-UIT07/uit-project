#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
class GiaoDich {
protected:
    string maGiaoDich;
    int ngay, thang, nam;
    double donGia;
    double dienTich;

public:
    void nhapCoBan() {
        cout << "Nhap ma giao dich: ";
        cin >> maGiaoDich;
        cout << "Nhap ngay thang nam (DD MM YYYY): ";
        cin >> ngay >> thang >> nam;
        cout << "Nhap don gia: ";
        cin >> donGia;
        cout << "Nhap dien tich: ";
        cin >> dienTich;
    }

    void xuatCoBan() const {
        cout << "Ma GD: " << maGiaoDich
             << " | Ngay: " << ngay << "/" << thang << "/" << nam
             << " | Don gia: " << donGia
             << " | Dien tich: " << dienTich;
    }

    int getThang() const { return thang; }
    int getNam() const { return nam; }
};
class GiaoDichDat : public GiaoDich {
private:
    string loaiDat;

public:
    void nhap() {
        nhapCoBan();
        cout << "Nhap loai dat (A/B/C): ";
        cin >> loaiDat;
    }

    double tinhThanhTien() const {
        if (loaiDat == "A")
            return dienTich * donGia * 1.5;
        return dienTich * donGia;
    }

    void xuat() const {
        xuatCoBan();
        cout << " | Loai: " << loaiDat
             << " | Thanh tien: " << fixed << setprecision(2)
             << tinhThanhTien() << endl;
    }
};
class GiaoDichNhaPho : public GiaoDich {
private:
    string loaiNha;
    string diaChi;

public:
    void nhap() {
        nhapCoBan();
        cin.ignore();
        cout << "Nhap loai nha (cao cap/thuong): ";
        getline(cin, loaiNha);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }

    double tinhThanhTien() const {
        if (loaiNha == "cao cap")
            return dienTich * donGia;
        return dienTich * donGia * 0.9;
    }

    void xuat() const {
        xuatCoBan();
        cout << " | Loai: " << loaiNha
             << " | Dia chi: " << diaChi
             << " | Thanh tien: " << fixed << setprecision(2)
             << tinhThanhTien() << endl;
    }
};
class GiaoDichCanHo : public GiaoDich {
private:
    string maCanHo;
    int tang;

public:
    void nhap() {
        nhapCoBan();
        cout << "Nhap ma can ho: ";
        cin >> maCanHo;
        cout << "Nhap tang: ";
        cin >> tang;
    }

    double tinhThanhTien() const {
        if (tang == 1)
            return dienTich * donGia * 2;
        else if (tang >= 15)
            return dienTich * donGia * 1.2;
        return dienTich * donGia;
    }

    void xuat() const {
        xuatCoBan();
        cout << " | Ma can ho: " << maCanHo
             << " | Tang: " << tang
             << " | Thanh tien: " << fixed << setprecision(2)
             << tinhThanhTien() << endl;
    }
};
int main() {
    vector<GiaoDichDat> dsDat;
    vector<GiaoDichNhaPho> dsNhaPho;
    vector<GiaoDichCanHo> dsCanHo;

    int choice;
    do {
        cout << "1. Nhap Giao dich dat\n";
        cout << "2. Nhap Giao dich nha pho\n";
        cout << "3. Nhap Giao dich can ho\n";
        cout << "4. Tong so luong\n";
        cout << "5. TB thanh tien can ho\n";
        cout << "6. Nha pho max\n";
        cout << "7. GD thang 12/2024\n";
        cout << "8. Xuat tat ca\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        if (choice == 1) {
            int n; cin >> n;
            while (n--) {
                GiaoDichDat x;
                x.nhap();
                dsDat.push_back(x);
            }
        }
        else if (choice == 2) {
            int n; cin >> n;
            while (n--) {
                GiaoDichNhaPho x;
                x.nhap();
                dsNhaPho.push_back(x);
            }
        }
        else if (choice == 3) {
            int n; cin >> n;
            while (n--) {
                GiaoDichCanHo x;
                x.nhap();
                dsCanHo.push_back(x);
            }
        }
        else if (choice == 4)        {
            cout << "Dat: " << dsDat.size() << endl;
            cout << "Nha pho: " << dsNhaPho.size() << endl;
            cout << "Can ho: " << dsCanHo.size() << endl;
        }
        else if (choice == 5) {
            double tong = 0;
            for (auto &x : dsCanHo) tong += x.tinhThanhTien();
            if (!dsCanHo.empty())
                cout << tong / dsCanHo.size() << endl;
        }
        else if (choice == 6) {
            if (!dsNhaPho.empty()) {
                int idx = 0;
                for (int i = 1; i < dsNhaPho.size(); i++) { 
                                                  
                    if (dsNhaPho[i].tinhThanhTien() > dsNhaPho[idx].tinhThanhTien())
                        idx = i;
                }
                dsNhaPho[idx].xuat();
            }
        }
        else if (choice == 7) { 
            for (auto &x : dsDat)
                if (x.getThang() == 12 && x.getNam() == 2024) x.xuat();
            for (auto &x : dsNhaPho)
                if (x.getThang() == 12 && x.getNam() == 2024) x.xuat();
            for (auto &x : dsCanHo)
                if (x.getThang() == 12 && x.getNam() == 2024) x.xuat();
        }
        else if (choice == 8) {
            for (auto &x : dsDat) x.xuat();
            for (auto &x : dsNhaPho) x.xuat();
            for (auto &x : dsCanHo) x.xuat();
        }

    } while (choice != 0);

    return 0;
}
