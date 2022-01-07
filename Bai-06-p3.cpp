#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a;
    for(int i = 0; i < 10; i++)
    {
        a.push_back(i);
    }
    cout << "Mang sau khi them la: " << endl;
    for(auto i = a.begin(); i != a.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl << "size = " << a.size() << endl;
    a.resize(4);
    cout << "Mang sau khi thay doi size la: " << endl;
    for(auto i = a.begin(); i != a.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << "size = " << a.size() << endl;
    if(a.empty() == true)
    {
        cout << "Vector rong" << endl;
    }
    else
    {
        cout << "Vector khong rong" << endl;
    }
    system("pause");
    return 0;
}