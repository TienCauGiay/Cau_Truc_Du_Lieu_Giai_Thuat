#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec;
    //khai báo vector có 7 phần tử bằng 12
    vec.assign(7, 12);
    //in ra vector
    cout << "Vector da khoi tao la: " << endl;
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    //thêm 24 vào cuối vector
    vec.push_back(24);
    //in ra vector
    cout << endl << "Vector sau khi them 24 vao cuoi la: ";
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    int s = vec.size();
    cout << endl << "Phan tu cuoi cua vector la: " << vec[s-1] << endl;
    //xóa phần tử cuối vector
    vec.pop_back();
    //in ra vetor
    cout << endl << "vector sau khi xoa phan tu cuoi la: ";
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    //chèn phần tử 10 vào đầu 
    vec.insert(vec.begin(), 10);
    //in ra phần tử đầu 
    cout << endl << "Phan tu dau cua vector la: " << vec[0];
    // xóa phần tử đầu rồi in ra phần tử đầu
    vec.erase(vec.begin());
    cout << endl << "Phần tu dau sau khi xoa: " << vec[0] ;
    //thay thế phần tử đầu bằng 5 rồi in ra phần tử đầu
    vec.emplace(vec.begin(), 5);
    cout << endl << "phan tu dau sau khi thay the: " << vec[0];
    //thay thế phần tử cuối bằng 20 rồi in ra phần tử cuối
    vec.emplace_back(20);
    int t = vec.size();
    cout << endl << "Phan tu cuoi: " << vec[t-1];
    //xóa vector
    vec.clear();
    //khởi tạo 2 vector obj1, obj2
    vector<int> obj1, obj2;
    //thêm 2 phần tử cho 2 vector bằng push
    obj1.push_back(1);
    obj1.push_back(2);
    obj2.push_back(4);
    obj2.push_back(7);
    // in ra 2 vector obj1, obj2
    cout << endl << "obj1 ";
    for(int i = 0; i < obj1.size(); i++)
    {
        cout << obj1[i] << " ";
    }
    cout << endl<< "obj2 ";
    for(int i = 0; i < obj2.size(); i++)
    {
        cout << obj2[i] << " ";
    }
    //hoán đổi 2 vector rồi in ra
    obj1.swap(obj2);
    cout << endl << "obj1 ";
    for(int i = 0; i < obj1.size(); i++)
    {
        cout << obj1[i] << " ";
    }
    cout << endl<< "obj2 ";
    for(int i = 0; i < obj2.size(); i++)
    {
        cout << obj2[i] << " ";
    }
    system("pause");
    return 0;
}