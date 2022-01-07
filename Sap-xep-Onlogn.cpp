#include<bits/stdc++.h>
using namespace std;

template <class T>
void Swap(T &a, T &b)
{
     T tg =a;
     a= b;
     b=tg;
}

template <class T>
void Partition (T *A, int i, int j, int   &right)
{
     T p = A[i];
     int left = i;
			right = j;
     while( left < right)
     {
	     while(A[left]<=p && left<=right) left++; 
	     while(A[right]>p) right--;
	     if(left < right)
        	 Swap(A[left],A[right]);	
      }
     	if(i!=right)
     	   Swap(A[i],A[right]);	 
 } 
 template <class T>
 void QuickSort(T *a,int i, int j)
 {
      int k;
      if(i<j)
      {
             Partition(a,i,j,k);
             QuickSort(a,i,k-1);
             QuickSort(a,k+1,j);
      }
 }
 
//Thuat toan sap xep tron
template <class T>
void Merge(T *a, int left, int mid, int right)
{
	int *temp; // Khoi tao mang tam de sap xep
	int i = left; // Vi tri phan tu dau tien cua mang con ben trai
	int j = mid + 1; // Vi tri phan tu dau tien cua mang con ben phai

	temp = new int[right - left + 1]; // Khoi tao so luong phan tu cua mang tam

	for (int k = 0; k <= right - left; k++)
	{
		// Kiem phan tu cua mang con ben trai va ben phai
		if (a[i] < a[j]) 
		{
			// Neu a[i] < a[j] thi copy phan tu ben trai vao mang tam
			temp[k] = a[i]; 
			i++; // Vi tri phan tu tiep theo cua mang
		}
		else // Nguoc lai copy phan tu cua mang con ben phai vao mang tam
		{
			temp[k] = a[j];
			j++; // Vi tri phan tu tiep theo cua mang
		}

		// Kiem tra mang con ben trai con phan tu nao khong
		if (i == mid + 1) 
		{
			// Nguoc lai dua cac phan tu con lai cua mang con ben phai vao mang tam
			while (j <= right)
			{
				k++;
				temp[k] = a[j];
				j++;
			}
			break;
		}

		// Kiem tra mang con ben phai con phan tu nao khong
		if (j == right + 1) 
		{
			// Nguoc lai dua cac phan tu con lai cua mang con ben phai vao mang tam
			while (i <= mid)
			{
				k++;
				temp[k] = a[i];
				i++;
			}
			break;
		}
	}

	for (int k = 0; k <= right - left; k++) // Chep mang tam vao mang chinh
		a[left + k] = temp[k];
	delete temp;
}
   
template <class T>
void Mergesort(T *A, int left, int right)
{
     if(left<right)
     {
         int mid=(left+right)/2;
	      Mergesort(A, left, mid);
	      Mergesort(A, mid+1,right);
       	Merge(A, left, mid, right);
      }
}  

//Sap xep heap sort
template<class T>
void Pushdown (T *A, int i, int n)
{
    int j = i; 
    int kt=0;
    int max;
    while (j<=n/2 && kt==0)
    {
       if(2*j==n)
           max = 2*j;
       else 
          if (A[2*j]<=A[2*j+1])
              max = 2*j+1;
          else  
			  max = 2*j;
       if (A[j]<A[max])  
       {
          Swap (A[j], A[max]);
          j = max;
       }
       else 
         kt=1;
     }
  }
  template<class T>
  void HeapSort(T *A, int n)
  {  
     int i;
     
     for(i=(n-1)/2; i>= 0;i--)
        Pushdown(A,i, n-1);
        
     for(i=n-1;i>=2;i--)
     {
        Swap(A[0],A[i]);
	     Pushdown(A,0,i-1);
     }
  } 
  
 int main() {
	int a[] = {3, 6, 8, 9, 0, 10, 11, 40, 23};
	int n = sizeof(a)/sizeof(a[0]);

	Mergesort(a, 0, n-1);
	//QuickSort(a, 0, n-1);
	for (int i=0; i<n;i++)
		cout<<a[i]<<" ";
		
	return 0;
}
 
