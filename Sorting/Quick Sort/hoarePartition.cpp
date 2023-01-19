#include <iostream>
using namespace std;

int hoarePartition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low-1;
    int j = high+1;

    while(true){
        do{
            i++;
        }while(arr[i]<pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i>=j){
            return j;
        }

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int partition = hoarePartition(arr, low, high);
        quickSort(arr, low, partition);
        quickSort(arr, partition+1, high);
    }
}

int main() {

    int arr[] = {7, 4, 9, 3, 2, 6, 10, 5, 1, 8};
    
    // cout<<hoarePartition(arr, 0, 9)<<endl;

    quickSort(arr, 0, 9);

    for(int i=0; i<=9; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}