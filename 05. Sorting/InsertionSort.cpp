/*
    INSERTION-SORT(A)
    for i = 1 to n
        key ← A [i]
        j ← i – 1
        while j > = 0 and A[j] > key
            A[j+1] ← A[j]
            j ← j – 1
        End while 
        A[j+1] ← key
    End for 
*/
#include<iostream>
using namespace std;

void insertionSort(int* a,int size);
void printArray(int *a, int size);

int main(){
    int a[]={3,2,5,6,4,1,8,7,9};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<"Before Sorting:"<<endl;
    printArray(a,size);
    cout<<endl;
    insertionSort(a,size);
    cout<<"After Sorting:"<<endl;
    printArray(a,size);

    return 0;
}

void insertionSort(int* a,int size){
    int key,j;
    for(int i=1;i<size;i++){
        key = a[i];
        j = i-1;

        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void printArray(int *a, int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
}