/*
Ứng dụng cấu trúc dữ liệu Vector đã học trong quản lý sinh viên. 
Giả sử cấu trúc cần quản lý sinh viên bao gồm các thành phần:
MaSv, Họ tên, Ngày, Tháng, Năm sinh, Giới tính, Quê quán. Điểm trung bình tích lũy
Yêu cầu viết một lớp Student bao gồm các phương thức sau:
- Thêm một sinh viên vào cuối danh sách.
- Thêm một sinh viên vào vị trí thứ i.
- Xóa bỏ sinh viên thứ i khỏi danh sách.
- Thay thế sinh viên thứ i bằng một sinh viên mới.
- In ra n sinh viên có điểm trung bình cao nhất.
Xây dựng chương trình để chạy ứng dụng.
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
float Max = 0;

class Sinhvien{
    private:
        string masv, hoten, gioitinh, quequan;
        int ngay, thang, nam;
        float dtb;
    public:
        friend istream& operator>>(istream &is, Sinhvien &a);
        friend ostream& operator<<(ostream &os, Sinhvien &a);
        Sinhvien& operator=(Sinhvien &x){
            masv = x.masv; hoten = x.hoten; gioitinh = x.gioitinh; quequan = x.quequan; ngay = x.ngay; thang = x.thang; nam = x.nam; dtb = x.dtb;
            return (*this);
        }
        float get_dtb(){
            return dtb;
        }
        string& get_ten(){
            return hoten;
        }
        string get_masv(){
            return masv;
        }
};

istream& operator>>(istream &is, Sinhvien &a){
    cout << "Nhap ho ten: "; fflush(stdin); getline(is, a.hoten);
    cout << "Nhap ma sinh vien: "; fflush(stdin); getline(is, a.masv);
    cout << "Nhap ngay thang nam sinh:\n"; is >> a.ngay >> a.thang >> a.nam;
    cout << "Nhap gioi tinh: "; fflush(stdin); getline(is, a.gioitinh);
    cout << "Nhap que quan: "; fflush(stdin); getline(is, a.quequan);
    cout << "Nhap diem trung binh: "; is >> a.dtb;
    return is;
}

ostream& operator<<(ostream &os, Sinhvien &a){
    os << fixed;
    os << setw(20) << a.hoten << setw(7) << a.masv << setw(10) << a.ngay << "/" << a.thang << "/" << a.nam << setw(10) << a.gioitinh << setw(15) << a.quequan << setprecision(2) << setw(7) << a.dtb << endl;
    return os;
}

class Vector{
    private:
        int n, cap;
        Sinhvien *a;
    public:
        Vector(){n = cap = 0; a = 0;}
        ~Vector(){
            if(a) delete [] a;
        }
        void extend(int newcap);
        int size();
        int capacity();
        Sinhvien& operator[](int k);
        void push_bach(Sinhvien x);
        void pop_back();
        void insert(int vtrthem, Sinhvien x);
        void erase(int vtrxoa);
        void emplace(int vtrthay, Sinhvien x);
        void TimKiem(string ten);
        Sinhvien SuaDoi(string ma, string tendoi);
        void Xuat_Theodtb();
        void Nhap_Dssv();
        void Xuat_Dssv();
        void run(Vector v);
};

void Vector::extend(int newcap){
    if(newcap < cap) return;
    cap = newcap;
    Sinhvien *b = new Sinhvien[cap];
    for(int i = 0; i < n; i++)
    b[i] = a[i];
    if(a) delete [] a;
    a = b;
}

int Vector::size(){
    return n;
}

int Vector::capacity(){
    return cap;
}

Sinhvien& Vector::operator[](int k){
    return a[k];
}
void Vector::push_bach(Sinhvien x){
    if(cap == n) extend(2 * cap + 5);
    cin >> x;
    a[n++] = x;
}

void Vector::pop_back(){
    if(n > 0) n--;
}

void Vector::insert(int vtrthem, Sinhvien x){
    if(cap == n) extend(cap * 2 + 5);
    cout << "Nhap vi tri can them: "; cin >> vtrthem;
    cout << "Nhap thong tin sinh vien can them: " << endl;
    cin >> x;
    for(int i = n-1; i >= vtrthem; i--)
        a[i+1] = a[i];
    a[vtrthem] = x;
    n++;
}

void Vector::erase(int vtrxoa){
    cout << "Nhap vi tri can xoa: "; cin >> vtrxoa;
    for(int i = vtrxoa; i < n; i++)
        a[i] = a[i+1];
    n--;
}

void Vector::emplace(int vtrthay, Sinhvien x){
    cout << "Nhap vi tri can thay: "; cin >> vtrthay;
    cout << "Nhap thong tin sinh vien thay the: " << endl;
    cin >> x;
    for(int i = 0; i < n; i++)
    {
        if(i == vtrthay)
            a[i] = x;
    }
}

void Vector::TimKiem(string ten){
    int dem = 0;
    cout << "Nhap ten sinh vien can tim: "; cin.ignore(1); getline(cin, ten);
    for(int i = 0; i < n; i++)
    {
        if(a[i].get_ten() == ten)
        {
            cout << "Tim thay sinh vien co ten " << ten << " trong danh sach" << endl;
            cout << "Thong tin sinh vien ten " << ten << " : " << endl;
            cout << a[i];
            dem++;
        }
    }
    if(dem == 0)
        cout << "Khong tim thay sinh vien co ten " << ten << " trong danh sach" << endl;
}

Sinhvien Vector::SuaDoi(string ma, string tendoi){
    Sinhvien x;
    int y = 0;
    cout << "Nhap ma sinh vien can sua doi ten: "; fflush(stdin); getline(cin, ma);
    cout << "Nhap ten sinh vien muon doi: "; fflush(stdin); getline(cin, tendoi);
    for(int i = 0; i < n; i++)
    {
        if(a[i].get_masv() == ma)
        {
            x = a[i];
            y = i;
        }
    }
    a[y] = x;
    a[y].get_ten() = tendoi;
    return a[y];
}

void Vector::Xuat_Theodtb(){
    Max = a[0].get_dtb();
    for(int i = 0; i < n; i++)
    {
        if(Max <= a[i].get_dtb())
        {
            Max = a[i].get_dtb();
        }
    }
    cout << "Danh sach sinh vien co diem trung binh cao nhat la: " << endl;
    for(int i = 0; i < n; i++)
    {
        if(Max == a[i].get_dtb())
        {
            cout << a[i];
        }
    }
}

void Vector::Xuat_Dssv(){
    cout << setw(20) << "Ho ten" << setw(7) << "Ma sv" << setw(10) << "dd" << "/" << "mm" << "/" << "yy" << setw(10) << "Gioi tinh" << setw(15) << "Que tuan" << setprecision(2) << setw(7) << "DTB" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << a[i];
    }
}

void Vector::run(Vector v){
    Sinhvien themcuoi, chen, thaythe;
    int vtrthem, vtrthay, vtrxoa;
    string c, ten, ma, tendoi;
    while(true){
        cout << " =============== Menu ================" << endl;
        cout << "1. Them 1 sinh vien vao danh sach" << endl;
        cout << "2. Them 1 sinh vien vao vi tri i" << endl;
        cout << "3. Xoa sinh vien thu i khoi danh sach" << endl;
        cout << "4. Thay the sinh vien thu i bang 1 sinh vien moi" << endl;
        cout << "5. Xuat cac sinh vien co diem trung binh cao nhat" << endl;
        cout << "6. Xuat danh sach sinh vien hien tai" << endl;
        cout << "7. Xoa sinh vien cuoi danh sach" << endl;
        cout << "8. Tim kiem sinh vien theo ten" << endl;
        cout << "9. Sua doi ten sinh vien co ma nhap tu ban phim" << endl;
        cout << "0. Ket thuc" << endl;
        cout << " =============== Menu ================" << endl;
        int lc; cout << "Nhap lua chon: "; cin >> lc;
        if(lc < 0 || lc > 9)
        {
            cout << "Nhap sai" << endl;
            system("pause");
        }
        else if(lc == 1)
        {
            do{
                v.push_bach(themcuoi);
                cout << "Ban co muon nhap tiep khong (y/n) : "; fflush(stdin); getline(cin, c);
            }while(c != "n");
        }
        else if(lc == 2)
        {
            v.insert(vtrthem, chen);
        }
        else if(lc == 3)
        {
            v.erase(vtrxoa);
        }
        else if(lc == 4)
        {
            v.emplace(vtrthay, thaythe);
        }
        else if(lc == 5)
        {
            v.Xuat_Theodtb();
        }
        else if(lc == 6)
        {
            v.Xuat_Dssv();
        }
        else if(lc == 7)
        {
            v.pop_back();
        }
        else if(lc == 8)
        {
            v.TimKiem(ten);
        }
        else if(lc == 9)
        {
            v.SuaDoi(ma, tendoi);
        }
        else
        {
            break;
        }
    }
}

int main(){
    Vector a;
    a.run(a);
    system("pause");
    return 0;
}