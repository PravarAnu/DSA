#include <iostream>
using namespace std;

int findPartition(int arr[], int start, int end){
    int pivot = start;
    int low = start+1;
    int high = end;

    while(low<high){
        if(arr[low] < arr[pivot]){
            low++;
        }
        else if(arr[high] > arr[pivot]){
            high--;
        }
        else if(arr[low] > arr[pivot] && arr[high] < arr[pivot]){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }

    int temp = arr[pivot];
    arr[pivot] = arr[high-1];
    arr[high-1] = temp;

    return high-1;
}


int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int count = 0;

    for(int i=start+1;i<=end;i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    int pivotIndex = start + count;
    int temp = arr[start];
    arr[start] = arr[pivotIndex];
    arr[pivotIndex] = temp;

    int low,high;
    low = start;
    high = end;

    while(low<=pivotIndex && high>=pivotIndex){
        while(arr[low] <= pivot){
            low++;
        }
        while(arr[high] > pivot){
            high--;
        }
        if(low < pivotIndex && high > pivotIndex){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }

    return pivotIndex;
}

void quick_Sort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int pi = partition(arr, start, end);
    quick_Sort(arr,start, pi-1);
    quick_Sort(arr, pi+1, end);
}

void quickSort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int partition = findPartition(arr, start, end);
    quickSort(arr,start, partition-1);
    quickSort(arr, partition+1, end);
}

int main() {

    int a[7] = {6,2,20,8,15,3,4};
    int b[8] = {1,2,3,4,5,6,7,8};
    int c[8] = {8,7,6,5,4,3,2,1};

    // quickSort(a,0,6);
    // quickSort(b,0,7);
    // quickSort(c,0,7);

    quick_Sort(a,0,6);
    quick_Sort(b,0,7);
    quick_Sort(c,0,7);
    
    //cout<<findPartition(a,0,6)<<endl;
    cout<<"A: ";
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"B: ";
    for(int i=0;i<8;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    //cout<<partition(c,0,7)<<endl;
    cout<<"C: ";
    for(int i=0;i<8;i++){
        cout<<c[i]<<" ";
    }
    
    return 0;
}