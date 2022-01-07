

#include <iostream>
#include <vector>
using namespace std;
 
template <class T>  
class Vector{
	private:
			int N;          //So chieu toi da cua Vector
			T *V;     		//luu tru du lieu
			int n;          //So phan tu hien co trong Vector
	public:
			Vector();
			~Vector();
			int getAtRank(int r, T &o);     // hàm lấy ra 1 phần tử
			int replaceAtRank(int r, T o);  // hàm thay thế 1 phần tử
			int insertAtRank(int r, T o);   // hàm thêm 1 phần tử
			int removeAtRank(int r, T &o);  // hàm xóa 1 phần tử
			int size();                     // hàm kiểm tra kích thước
			int isEmpty();                  // hàm kiểm tra rỗng 
};
template<class T>
Vector<T>::Vector()
{
    V = new T[1];
    N = 1;
    n = 0;
}
template<class T>
Vector<T>::~Vector()
{
    delete V;
}
//Ham insertAtRank
template<class T>
int Vector<T>::insertAtRank(int r, T o)
{  
if(r<0 || r > n )
        return 0;   
if(n==N)
{  //Phat trien mang
    T *A;
    N = 2*N;
    A = new T[N];
    for(int i=0;i<n;i++)
        A[i] = V[i];
    delete V;
    V = A;
    int k = n-1;
    while(k>=r)
    {
        V[k+1] = V[k];
        k--;
    }
    }
    V[r]= o;
    n++;
    return 1;
} 
//Ham lay ra mot phan tu
template<class T>
int Vector<T>::getAtRank(int r, T &o)
{
    if(r<0 || r>n-1)
        return 0;
    o = V[r];
    return 1;
}
//Ham thay the mot phan tu
template<class T>
int Vector<T>::replaceAtRank(int r, T o)
{
    if(r<0 || r>n-1)
        return 0;
    V[r] = o;
    return 1;
}
template<class T>
int Vector<T>::removeAtRank(int r, T &o)
{
    if(r<0 || r>n-1)
        return 0;
    o = V[r];
    int k = r;
    while(k<n-1)
    {
        V[k] =  V[k+1];
        k++;
    }
    n--;
    return 1;
}
template<class T>
int Vector<T>::size(){ return n;}

template<class T>
int Vector<T>::isEmpty()
{
    return n==0;		
}


int main(){
   
    system("pause");
    return 0;
}