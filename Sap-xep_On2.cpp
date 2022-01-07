#ifndef SORT_NN_H
#define SORT_NN_H 1
#include"conio.h"
#include<bits/stdc++.h>
using namespace std;

template <class T>
int comp(T a, T b) {
	if (a > b) return 1;
	else return 0;
}

template <class T>
void Swap(T &a, T &b)
{
    T tg =a;
    a= b;
    b=tg;
}

template <class T>
void BubbleSort(T *a, int n, int (*comp)(T,T)){
	  int i, j;
	  for (i=0;i<n-1;i++)
		  for(j=n-1;j>i;j--)
          	  if(comp(a[j-1], a[j]))
				  Swap(a[j],a[j-1]);
}

template<class T>
void SelectionSort(T *a,int n, int (*comp)(T,T)){
     int i,j,min;
     for(i=0;i<=n-2;i++){ 
             min=i;
             for(j=i+1;j<n;j++)
                 if(comp(a[min],a[j])) min=j;
             if(min!=i) 
                 Swap(a[i],a[min]);
     }
}
template<class T>
void InsertionSort(T *a,int n, int (*comp)(T,T)){
     T x;
     int i, j;
     for(i=1; i<=n-1;i++){
        j = i-1;
        x = a[i];
        while(comp(a[j],x) && j>=0){
           a[j+1]=a[j];
           j--;
        }   
        a[j+1]= x;
     }      
}
#endif

int main() {
	int a[] = {3, 6, 8, 9, 0, 10, 11, 40, 23};
	int n = sizeof(a)/sizeof(a[0]);
	InsertionSort(a, n, &comp);
	//BubbleSort(a, n, &comp);
	for (int i=0; i<n;i++)
		cout<<a[i]<<" ";
		
	return 0;
}
