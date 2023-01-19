#include <iostream>
using namespace std;

int lomutoPartition(int arr[], int low, int high){
    int pivot = arr[high];
    int i=low;
    for(int j=low; j<high; j++){
        if(arr[j]<=pivot){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int partition = lomutoPartition(arr, low, high);
        quickSort(arr, low, partition-1);
        quickSort(arr, partition+1, high);
    }
}

int main() {

    int arr[] = {7, 4, 9, 3, 2, 6, 0, 5, 1, 8};
    
    // cout<<lomutoPartition(arr, 0, 9)<<endl;
    quickSort(arr, 0, 9);

    for(int i=0; i<=9; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}