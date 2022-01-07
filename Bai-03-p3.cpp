/*
Xây dựng lớp biểu diễn các thí sinh, biết mỗi thi sinh bao gồm
các thông tin: Số báo danh, Họ tên, năm sinh, giới tính, điểm
toán, điểm lý, điểm hóa. Lơp có các cấu tử, các phương thức
nhập, in, lấy tổng điểm, lấy điểm từng môn
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;

struct Diem{
    float dt, dl, dh, dtb;
};

class Sv{
    private:
        int sbd, namsinh;
        string hoten, gioitinh;
        Diem diem;
    public:
        Sv(){
            sbd = 0; namsinh = 0;
            hoten = ' '; gioitinh = ' ';
            diem.dt = 0; diem.dl = 0; diem.dh = 0; diem.dtb = 0;
        }
        Sv(int sbd, int namsinh, string ten, string gioi, Diem a){
            sbd = sbd; namsinh = namsinh;
            hoten = ten; gioitinh = gioi;
            diem.dt = a.dt; diem.dl = a.dl; diem.dh = a.dh; diem.dtb = get_dtb();
        }
        void Nhap(){
            cout << "Ho ten: ";
            fflush(stdin);
            getline(cin, hoten);  
            cout << "So bao danh: "; cin >> sbd;
            cout << "Nam sinh: "; cin >> namsinh;
            cout << "Gioi tinh: "; 
            fflush(stdin);
            getline(cin, gioitinh);
            cout << "Diem 3 mon: " << endl; cin >> diem.dt >> diem.dl >> diem.dh;
        }
        void Xuat(){
            cout << fixed;
            cout << setw(20) << hoten << setw(5) << sbd << setw(10) << namsinh << setw(10) << gioitinh << setw(5) << setprecision(2) << diem.dt << setw(5) << diem.dl << setw(5) << diem.dh << setw(5) << get_dtb() << endl;

        }
        float get_dtb(){
            return (diem.dt + diem.dl + diem.dh)/3;
        }
        string get_ten(){
            return hoten;
        }
};

int main(){
    int n;
    cout << "So sinh vien can nhap: "; cin >> n;
    Sv *a = new Sv[n + 1];
    for(int i = 0; i < n; i++)
    {
        cout << "Sinh vien thu " << i + 1 << " : " << endl;
        a[i].Nhap();
    }
    cout << "Danh sach sinh vien: " << endl;
    cout << setw(20) << "Ho ten" << setw(5) << "Sbd" << setw(10) << "Namsinh" << setw(10) << "Gioitinh" << setw(5) << "Toan" << setw(5) << "Li" << setw(5) << "Hoa" << setw(5) << "Dtb" << endl;
    for(int i = 0; i < n; i++)
    {
        a[i].Xuat();
    }
    cout << "Danh sach diem trung binh: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << fixed;
        cout << setw(20) << a[i].get_ten() << setw(5) << setprecision(2) << a[i].get_dtb() << endl;
    }
    system("pause");
    delete []a;
    return 0;
}