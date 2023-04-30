#include <iostream>
using namespace std;

void countingSort(int arr[], int size, int low, int high){
    int *count = new int[high-low+1];
    int *output = new int[size];

    for(int i=0; i<(high-low+1); i++){
        count[i] = 0;
    }

    for(int i=0; i<size; i++){
        count[arr[i]] += 1;
    }

    for(int i=1; i<(high-low+1); i++){
        count[i] += count[i-1];
    }

    for(int i=size-1; i>=0; i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    for(int i=0; i<size; i++){
        arr[i] = output[i];
    }

}

int main() {

    int arr[7] = {1,4,1,2,7,5,2};

    countingSort(arr, 7, 0 , 9);

    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}