#include <iostream>
#include <vector>
using namespace std;

void printfvector(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

int main(){
    vector<int> vec;
    vec = {4, 3, 9, 1, 6};
    cout << "In theo kieu bt: " << endl;
    printfvector(vec);
    cout << endl << "In theo kieu auto: " << endl;
    for(auto i = vec.begin(); i != vec.end(); i++)
    {
        cout << *i << " ";
    }
    vec.push_back(10);
    int t = vec.size();
    cout << "Ptu cuoi : " << vec[t-1] << " " << vec.back() << endl; 
    vec.pop_back();
    vec.pop_back();
    cout << "kiem tra rong: " << vec.empty();
    vec.emplace_back(20);
    cout << "Phan tu cuoi: " << vec.back() << endl;
    cout << endl <<  "Phan tu dau:" << vec.at(0) << " " << vec[0] << endl;
    vec.insert(vec.begin() + 2, 50);
    vec.insert(vec.end() - 2, 79);
    for(auto i = vec.begin(); i != vec.end(); i++)
    {
        cout << *i << " ";
    }
    vector<int> b(vec);
    cout << "Vec to b la: " ;
    for(int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    vec.clear();
    cout << endl <<  "ptu dau cua b: " << b.front() << endl;
    cout << "Kiem tra a rong: " << vec.empty() << endl;
    b.push_back(-2);
    b.push_back(-100);
    vector<int> ::iterator it;
    for(it = b.begin(); it != b.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}