/*
 Bài 1. Lập hàm đệ quy tính giá trị đa thức
 Bài 2. Lập hàm đệ qui tìm ước số chung của
2 số nguyên dương
 Bài 3. Lập hàm đệ qui tìm giá trị min của một
dãy n số thực
 Bài 4. Viết hàm đệ quy tính lũy thừa x^n
 Bài 5. Viết hàm đệ quy tính số fibonaci
 Bài 6: Viết hàm đệ quy tính tổng của dãy số
*/

#include <iostream>
#include <cmath>
using namespace std;
int static dem = 0;

int GiaTriDaThuc(int *a, int n, int x){
	if(n == 1) return a[0] * pow(x, 0);
	else return GiaTriDaThuc(a, n-1, x) + a[n-1] * pow(x, n-1);
}

int Ucln(int a, int b){
    if(b == 0) return a;
    else return Ucln(b, a % b);
}

int Bcnn(int a, int b){
    return a * b / Ucln(a, b);
}

int Max(int a,int b){return a > b ? a: b;}

int Min(int a, int b){return a < b ? a : b;}

int Min(int A[], int n)
{
	if (n == 0)
		return -1;
	if (n == 1)
		return A[0];
	else
	{
		if (A[n - 1] < Min(A, n - 1))
			return A[n - 1];
		else
			return Min(A, n - 1);
	}
}

int Max(int A[], int n)
{
	if (n == 0)
		return -1;
	if (n == 1)
		return A[0];
	else
	{
		if (A[n - 1] > Max(A, n - 1))
			return A[n - 1];
		else
			return Max(A, n - 1);
	}
}

double LuyThua(int x, int n){
	dem++;
	if( n == 0) return 1;
	if(n%2){
		double y = pow(x, (n-1)/2);
		return x * y * y;
	}
	else{
		double y = pow(x, n/2);
		return y * y;
	}
}

int Fibonaci(int n){
	if(n == 1 || n == 2) return 1;
	return Fibonaci(n-1) + Fibonaci(n-2);
}

int TongdaySo(int * a, int n){
	if(n == 1) return a[0];
	else return TongdaySo(a, n - 1) + a[n-1];
}

int main(){
	int a[] = {2, 1, 3, 5, 6, 9, 15, 12};
	int b[] = {1, 2, 3};
	cout << "Gia tri da thuc: " << GiaTriDaThuc(b, size(b), 2) << endl;
    cout << "Ucln " << Ucln(20, 12) << endl;
    cout << "Bcnn " << Bcnn(10, 25) << endl;
	cout << "Max = " << Max(a, size(a)) << endl;
	cout << "Min = " << Min(a, size(a)) << endl;
	cout << "Luy thua: " << LuyThua(2,18) << "\tSo lan goi ham: " << dem << endl;
	cout << "Fibonaci " << Fibonaci(6) << endl;
	cout << "Tong day so: " << TongdaySo(a, size(a)) << endl;
    system("pause");
    return 0;
}