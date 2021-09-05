#include<iostream>
using namespace std;

void arrRotation(int a[], int size, int rotation);
void leftRotation(int a[], int size);
void printArr(int a[], int size);

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(a[0]);
    int r = 2;

    cout<<"Before Rotation: ";
    printArr(a,n);
    arrRotation(a,n,r);
    cout<<"After Rotation: ";
    printArr(a,n);
}

void arrRotation(int a[], int size, int rotation){
    if(rotation<=size){
            for(int i=0;i<rotation;i++){
                leftRotation(a,size);
        }
    }
}

void leftRotation(int a[],int size){
    int temp = a[0];
    for(int i=0; i<size-1;i++){
        a[i] = a[i+1];
    }
    a[size - 1] = temp;
}

void printArr(int a[], int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}