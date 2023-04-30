#include <iostream>
using namespace std;

int naivePartiton(int arr[], int size, int index){
    int pivot = arr[index];

    int *sampleArr = new int[size];

    int startIndex = 0;
    int endIndex = size-1;
    for(int i=0; i<size; i++){
        if(arr[i] < pivot){
            sampleArr[startIndex] = arr[i];
            cout<<"Putting "<<arr[i]<<" at index: "<<startIndex<<endl;
            startIndex++;
        }
        else {
            sampleArr[endIndex] = arr[i];
            cout<<"Putting "<<arr[i]<<" at index: "<<endIndex<<endl;
            endIndex--;
        }
    }

    sampleArr[startIndex] = pivot;

    for(int i=0; i<size; i++){
        arr[i] = sampleArr[i];
    }

    return startIndex;
}

int main() {

    int arr[] = {7, 4, 6, 3, 2, 8, 0, 5, 1, 6};
    int size = 10;
    int index = 9;
    cout<<naivePartiton(arr, size, index)<<endl;

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}