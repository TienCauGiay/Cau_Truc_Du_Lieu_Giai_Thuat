#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketsort(float arr[], int n){
    vector<float> b[n];
    for(int i = 0; i < n; i++)
    {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }
    for(int i = 0; i < n; i++)
    {
        sort(b[i].begin(), b[i].end());
    }
    int index = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

void XuatMang(int a[], int n){
    for(int i = 0; i < n; i++)
        printf(" %d", a[i]);
}

void bubblesort(int a[], int n){
    for(int i = 1; i < n; i++)
    {
        printf("\ni = %3d: ", i); XuatMang(a, n);
        for(int j = 0; j < n - i; j++)
        if(a[j] > a[j + 1])
        {
            int tg = a[j]; a[j] = a[j + 1]; a[j + 1] = tg;
        }
    }
}

void SWap(int &a, int &b){
    int tg = a; a = b; b = tg;
}

void selectionsort(int a[], int n){
    for(int i = 1; i < n; i++)
    {
        int jmin = i - 1;
        for(int j = i - 1; j < n; j++)
            if(a[j] < a[jmin]) jmin = j;
        if(jmin != i-1) SWap(a[i-1], a[jmin]);
    }
}

void bubblesort_ver2(int a[], int n){
    for(int i = 1; i < n; i++)
    {
        printf("\ni = %3d: ", i); XuatMang(a, n);
        int count = 0;
        for(int j = 0; j < n - i; j++)
        if(a[j] > a[j + 1])
        {
            int tg = a[j]; a[j] = a[j + 1]; a[j + 1] = tg; count++;
        }
        if(count == 0) break;
    }
}

int main(){
    int a[] = {1,3,2,9,5,7,6,8};
    int n = sizeof(a)/sizeof(int);
    printf("n = %d", n);
    printf("\nINPUT: "); XuatMang(a, n); printf("\n");
    selectionsort(a, n);
    printf("\nINPUT: "); XuatMang(a, n);
    return 0;
}