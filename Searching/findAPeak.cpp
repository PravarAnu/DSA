#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> &arr){


    if(arr.size() == 1){
        return arr[0];
    }

    if(arr[0] > arr[1]){
        return arr[0];
    }

    if(arr[arr.size()-1] > arr[arr.size()-2]){
        return arr[arr.size() - 1];
    }

    int start = 0;
    int end = arr.size()-1;



    while(start <= end){
        int mid = (start + end)/2;

        if(arr[mid]>= arr[mid+1] && arr[mid] >= arr[mid-1]){
            return arr[mid];
        }

        else if(arr[mid+1] > arr[mid] && arr[mid+1] > arr[mid-1]){
            start = mid+1;
        }
        else if(arr[mid-1] > arr[mid] && arr[mid-1] > arr[mid+1]){
            end = mid-1;
        }
    }

    return -1;
}

int main() {

    vector<int> arr1 = {5, 20, 40, 30, 20, 50, 40};

    cout<<findPeak(arr1);

    return 0;
}