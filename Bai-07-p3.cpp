/*
Xây dựng lớp ứng dụng sử dụng lớp Danh sách liên kết
đơn để lưu trữ 1 danh sách sinh viên. Mỗi sinh viên
gồm các thông tin sau: MaSv, Hoten, Ngay, Thang,
Nam sinh, gioi tinh, que quan.
Yêu cầu lớp có các chức năng sau:
- Thêm một sinh viên vào cuối DS
- Thêm một sinh viên vào đầu DS
- Xóa bỏ một sinh viên thứ i khỏi DS
- Thay thế sinh viên thứ i bằng một sinh viên mới
Xây dựng chương trình để chạy lớp ứng dụng
*/

#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

class SinhVien{
    private:
        string hoten, gioitinh;
        int masv, ngay, thang, nam;
    public:
        friend istream& operator>>(istream& is, SinhVien& a);
        friend ostream& operator<<(ostream& os, SinhVien a);
        int get_masv(){
            return masv;
        }
};

istream& operator>>(istream& is, SinhVien& a){
    cout << "Nhap ho ten: "; fflush(stdin); getline(is, a.hoten);
    cout << "Nhap gioi tinh: "; fflush(stdin); getline(is, a.gioitinh);
    cout << "Nhap ma sv: "; is >> a.masv;
    cout << "Nhap ngay thang nam sinh:\n"; is >> a.ngay >> a.thang >> a.nam;
    return is;
}

ostream& operator<<(ostream& os, SinhVien a){
    os << setw(20) << a.hoten << setw(10) << a.gioitinh << setw(7) << a.masv << setw(15) << a.ngay << "/" << a.thang << "/" << a.nam << endl;
    return os;
}

class Listapp{
    private:
        list<SinhVien> a;
        list<SinhVien>::iterator it;
    public:
        void push_back(SinhVien x){
            cout << "Nhap thong tin sinh vien can them: " << endl;
            cin >> x;
            a.push_back(x);
        }
        void insert(SinhVien x){
            cout << "Nhap thong tin sinh vien can chen: " << endl;
            cin >> x;
            a.insert(it, x);
        }
        int isSize(){
            return a.size();
        }
        int isEmpty(){
            return a.size() == 0;
        }
        void Xuat(){
            cout << "Danh sach sinh vien: " << endl;
            cout << setw(20) << "Ho ten" << setw(10) << "Gioi tinh" << setw(7) << "Ma sv" << setw(15) << "dd/mm/yy" << endl;
            for(it = a.begin(); it != a.end(); it++)
            {
                cout << *it << endl;
            }
        }
};

int main(){
    SinhVien x, y;
    Listapp a;
    a.push_back(x);
    a.push_back(y);
    a.Xuat();
    cout << "Sau khi sap xep: " << endl;
    a.Xuat();
    system("pause");
    return 0;
}