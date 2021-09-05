#include<iostream>
using namespace std;

void bubbleSort(int a[], int size);
void printArr(int a[], int size);

int main(){
    int a[] = {2,4,1,5,3,9,7,6,8};
    int n =sizeof(a)/sizeof(a[0]);
    cout<<"Before Sorting: ";
    printArr(a,n-1);

    bubbleSort(a,n-1);
    cout<<"After Sorting: ";
    printArr(a,n-1);

    return 0;
}

void bubbleSort(int a[], int size){
    for(int i=0;i<size;i++){
        int j = 0;
        while(j<size){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
            j++;
        }
    }
}

void printArr(int a[], int size){
    for(int i=0; i<=size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}