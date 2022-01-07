/*
Sử dụng lớp Vector và lớp bộ lăp của lớp vector
xây dựng chương trình có các chức năng
sau:
1. Chèn 1 phần tử vào vector
2. Xóa 1 phần tử của vector
3. Thay thế một phần tử của vector
4. Lấy giá trị của một phần tử của vector
5. In danh sách các phần tử hiện có trong
vector
*/

#include <iostream>
using namespace std;

template <class T>
class Vector{
    private:
        int cap, n;
        T *V;
    public:
        Vector(){cap = n = 0; V = 0;}
        Vector(int num);
        Vector(int k, T x);
        void extend(int newcap);
        Vector& operator=(Vector a);
        ~Vector();
        int capacity();
        int size();
        bool empty();
        void pop_back();
        void push_back(T x);
        void insert(int k,T x);
        T& back();
        T& operator[](int k);
        void clear();
        void printvector();
        typedef T * iterator;
        iterator begin(){return V;}
        iterator end(){return V + n;}
        void erase(iterator it);
};

template <class T>
Vector<T>::Vector(int num){
    cap = n = num;
    V = new T[n];
    for(int i = 0; i < n; i++) V[i] = 0;
}

template <class T>
Vector<T>::Vector(int k, T x){
    cap = k; n = k;
    V = new T[k];
    for(int i = 0; i < k; i++) V[i] = x;
}

template <class T>
void Vector<T>::extend(int newcap){
    if(newcap <= cap) return;
    cap = newcap;
    T *temp = new T[cap];
    for(int i = 0; i < n; i++)
        temp[i] = V[i];
    if(V) delete []V;
    V = temp;
}

template <class T>
int Vector<T>::capacity(){
    return cap;
}

template <class T>
int Vector<T>::size(){
    return n;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector a){
    cap = a.capacity();
    n = a.size();
    if(cap) V = new T[cap]; 
    for(int i = 0; i < n; i++)
        V[i] = a[i];
    return *this;
}

template <class T>
Vector<T>::~Vector(){
    if(V) delete[]V;
}

template <class T>
bool Vector<T>::empty(){
    return n == 0;
}

template <class T>
void Vector<T>::pop_back(){
    if(n > 0) n--;
}

template <class T>
void Vector<T>::push_back(T x){
    if(n == cap) extend(cap * 2 + 5);
    V[n++] = x;
}

template <class T>
void Vector<T>::insert(int k, T x){
    if(n == cap) extend(cap * 2 + 5);
    for(int i = n-1; i >=k; i--)
        V[i + 1] = V[i];
    V[k] = x;
    n++;
}

template <class T>
T& Vector<T>::operator[](int k){
    return V[k];
}

template <class T>
T& Vector<T>::back(){
    return V[n -1 ];
}

template <class T>
void Vector<T>::clear(){
    n = 0;
}

template <class T>
void Vector<T>::printvector(){
    for(int i = 0; i < n; i++)
    {
        cout << V[i] << " ";
    }
}

template <class T>
void Vector<T>::erase(iterator it){
    while(it + 1 != end())
    {
        *it = *(it + 1);
        it++;
    }
} 

int main(){
    Vector<int> a;
    cout << "Vector sau khi khoi tao la: ";
    a.printvector();
    a.push_back(17);
    a.push_back(5);
    a.push_back(2001);
    cout << endl << "Vector sau khi push_back la: ";
    a.printvector();
    Vector<int> b;
    b = a;
    cout << endl << "Vector b la: ";
    b.printvector();
    cout << endl <<  "So phan tu hien tai va so phan tu toi da cua a: " << a.size() << " " << a.capacity() << endl;
    cout << "Kiem tra a co rong hay k: " << a.empty() << endl;
    a.pop_back();
    cout << "n va cap sau khi xoa: " << a.size() << " " << a.capacity() << endl; 
    cout << "Vector sau khi xoa la: ";
    a.printvector();
    cout << endl << "Phan tu cuoi cua day la la: " << a.back() << endl;
    a.insert(1, 19);
    a.insert(2, 8);
    cout << "Vector a sau khi insert la: ";
    a.printvector();
    a.clear();
    cout << endl << "Vector sau khi xoa la: ";
    a.printvector();
    cout << endl;
    system("pause");
    return 0;
}