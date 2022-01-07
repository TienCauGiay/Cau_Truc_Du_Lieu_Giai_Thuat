/*

Lập chương trình nhập vào tọa
độ các đỉnh của 1 tam giác bất kỳ trong
mặt phẳng. Tính diện tích và chu vi của
tam giác đó. In kết quả lên màn hình

*/

#include <iostream>
#include <cmath>
using namespace std;

class Diem{
    private:
        float hoanh, tung;
    public:
        Diem(){
            hoanh = 0; tung = 0;
        }
        Diem(float x, float y){
            hoanh = x; tung = y;
        }
        void Nhap(){
            cin >> hoanh >> tung;
        }
        void Xuat(){
            cout << "(" << hoanh << "," << tung << ")" << endl;
        }
        float Kc(Diem b){
            return sqrt(pow(hoanh - b.hoanh, 2) + pow(tung - b.tung, 2));
        }
};

int main(){
    int n;
    cout << "n = "; cin >> n;
    Diem *a = new Diem[n + 1];
    cout << "Nhap toa do cac dinh cua tam giac: " << endl;
    for(int i = 0; i < n; i++)
    {
        a[i].Nhap();
    }
    float cv, dt;
    cv = a[0].Kc(a[1]) + a[1].Kc(a[2]) + a[0].Kc(a[2]);
    cout << "Chu vi = " << cv << endl;
    cv /= 2;
    dt = sqrt(cv * (cv- a[0].Kc(a[1])) * (cv- a[1].Kc(a[2])) * (cv- a[0].Kc(a[2])));
    cout << "Dien tich = " << dt << endl;
    system("pause");
    return 0;
}