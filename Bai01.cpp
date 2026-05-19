#include <iostream>
#include <string>
using namespace std;
class QuanLyXe {
private:
   string MaSoChuyen, TenTaiXe, soXe;
   double SoKm, DoanhThu;
public:
    void Nhap() {
         cout << "Nhap ma so chuyen: ";
         getline(cin, MaSoChuyen);
         cout << "Nhap ten tai xe: ";
         getline(cin, TenTaiXe);
         cout << "Nhap so xe: ";
         getline(cin, soXe);
         cout << "Nhap so km: ";
         cin >> SoKm;
         cout << "Nhap doanh thu: ";
         cin >> DoanhThu;
         cin.ignore(); 
    }
    void Xuat() {
         cout << "Ma so chuyen: " << MaSoChuyen << endl;
         cout << "Ten tai xe: " << TenTaiXe << endl;
         cout << "So xe: " << soXe << endl;
         cout << "So km: " << SoKm << endl;
         cout << "Doanh thu: " << DoanhThu << endl;
    }
    double GetDoanhThu() const {
        return DoanhThu;
    }
    };  
class QuanLyXeNoiThanh : public QuanLyXe {
    string SoTuyen;
public:
    void Nhap() {
        QuanLyXe::Nhap();
        cout << "Nhap so tuyen: ";
        getline(cin, SoTuyen);
    }
    void Xuat() {
        QuanLyXe::Xuat();
        cout << "So tuyen: " << SoTuyen << endl;
    }
};
class QuanLyXeNgoaiThanh : public QuanLyXe {
    string NoiDen;
public:
    void Nhap() {
        QuanLyXe::Nhap();
        cout << "Nhap noi den: ";
        getline(cin, NoiDen);
    }
    void Xuat() {
        QuanLyXe::Xuat();
        cout << "Noi den: " << NoiDen << endl;
    }
};

int main() {
    cout << "  QUAN LY CHUYEN XE  " << endl << endl;
    
    QuanLyXeNoiThanh dsNoiThanh[2];
    QuanLyXeNgoaiThanh dsNgoaiThanh[2];
    
    double tongDoanhThuNoiThanh = 0;
    double tongDoanhThuNgoaiThanh = 0;
    double tongDoanhThuTongCong = 0;
    
    cout << "\n NHAP CHUYEN XE NOI THANH " << endl;
    for(int i = 0; i < 2; i++) {
        cout << "\n--- Chuyen noi thanh thu " << (i+1) << " ---" << endl;
        dsNoiThanh[i].Nhap();
    }
    
    
    cout << "\n NHAP CHUYEN XE NGOAI THANH " << endl;
    for(int i = 0; i < 2; i++) {
        cout << "\n--- Chuyen ngoai thanh thu " << (i+1) << " ---" << endl;
        dsNgoaiThanh[i].Nhap();
    }
    
    
    for(int i = 0; i < 2; i++) {
        tongDoanhThuNoiThanh += dsNoiThanh[i].GetDoanhThu();
    }
    
    
    for(int i = 0; i < 2; i++) {
        tongDoanhThuNgoaiThanh += dsNgoaiThanh[i].GetDoanhThu();
    }
    
    
    tongDoanhThuTongCong = tongDoanhThuNoiThanh + tongDoanhThuNgoaiThanh;
    
    
    cout << "\n THONG TIN CHUYEN XE NOI THANH " << endl;
    for(int i = 0; i < 2; i++) {
        cout << "\n--- Chuyen thu " << (i+1) << " ---" << endl;
        dsNoiThanh[i].Xuat();
    }
    
    
    cout << "\n THONG TIN CHUYEN XE NGOAI THANH " << endl;
    for(int i = 0; i < 2; i++) {
        cout << "\n--- Chuyen thu " << (i+1) << " ---" << endl;
        dsNgoaiThanh[i].Xuat();
    }
    cout << "\n TONG DOANH THU " << endl;
    cout << "Tong doanh thu chuyen noi thanh: " << tongDoanhThuNoiThanh << " VND" << endl;
    cout << "Tong doanh thu chuyen ngoai thanh: " << tongDoanhThuNgoaiThanh << " VND" << endl;
    cout << "Tong doanh thu tong cong: " << tongDoanhThuTongCong << " VND" << endl;
    
    return 0;
}

