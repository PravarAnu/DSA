#include <iostream>
using namespace std;

void mergeSort(int a[], int low, int high);
void merge(int a[], int lowLeft, int highLeft ,int highRight);
void printArr(int a[], int size);

int main(){
    int n;
    int a[] = {3,2,4,1,6,5,9,8,7};
    n = sizeof(a)/sizeof(a[0]);

    mergeSort(a,0,n-1);
    printArr(a,n-1);

    return 0;
}

void mergeSort(int a[], int low, int high){
    if(low >= high){
        return ; 
    }
    else{
        int mid = (low + high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[], int lowLeft, int highLeft ,int highRight){
    int lowRight,size;
    int iLeft,iRight,iRes;
    int *mergedArr;
    int i,iArr;
    
    lowRight = highLeft + 1;
    size = highRight - lowLeft;
    mergedArr = new int[size];

    iLeft = lowLeft;
    iRight = lowRight;
    iRes = 0;

    while(iLeft <= highLeft && iRight <= highRight){
        if(a[iLeft]<a[iRight]){
            mergedArr[iRes] = a[iLeft];
            iLeft++;
            iRes++;
        }
        else{
            mergedArr[iRes] = a[iRight];
            iRight++;
            iRes++;
        }
    }

    while(iLeft <= highLeft){
        mergedArr[iRes] = a[iLeft];
        iLeft++;
        iRes++;
    }
    while(iRight <= highRight){
        mergedArr[iRes] = a[iRight];
        iRight++;
        iRes++;
    }

    for(i=0,iArr=lowLeft;i<=size;i++,iArr++){
        a[iArr] = mergedArr[i];
    }

    delete []mergedArr;
}

void printArr(int a[], int size){
    for(int i=0; i<=size; i++){
        cout<<a[i]<<" ";
    }
}