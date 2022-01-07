/*
Xây dựng lớp biểu diễn một đoạn thẳng (biết đoạn thẳng được
xác định bởi tọa độ điểm đầu và điểm cuối). Với các cấu tử
không đối, có đối đầy đủ, phương thức nhập, in tọa độ hai đầu
mút, tính độ dài đoạn thẳng
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Diem{
    float hoanh, tung;
};

class DoanThang{
    private:
        Diem dau,cuoi;
    public:
        DoanThang(){
            dau.hoanh = 0; dau.tung = 0; cuoi.hoanh = 0; cuoi.tung = 0;
        }
        DoanThang(float a, float b, float c, float d){
            dau.hoanh = a; dau.tung = c; cuoi.hoanh = b; cuoi.tung = d;
        }
        void Nhap(){
            cout << "Diem dau: " << endl;
            cin >> dau.hoanh >> dau.tung;
            cout << "Diem cuoi: " << endl;
            cin >> cuoi.hoanh >> cuoi.tung;
        }
        void Xuat(){
            cout << "Diem dau: (" << dau.hoanh << "," << dau.tung << ")" << endl;
            cout << "Diem cuoi: (" << cuoi.hoanh << "," << cuoi.tung << ")" << endl;
        }
        float DoDai(){
            return sqrt(pow(dau.hoanh - cuoi.hoanh, 2) + pow(dau.tung - cuoi.tung, 2));
        }
};

int main(){
    DoanThang a;
    cout << "Nhap toa do diem dau va cuoi: " << endl;
    a.Nhap();
    a.Xuat();
    cout << "Do dai doan thang a la: " << a.DoDai() << endl;
    system("pause");
    return 0;
}