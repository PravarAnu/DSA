#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedSortedArray(vector<int> &arr, int num){
    int start = 0;
    int end = arr.size()-1;


    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == num){
            return mid;
        }
        else if(arr[mid] < arr[end]){
            if(num >= arr[mid] && num <= arr[end]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        else{
            if(num >= arr[start] && num<= arr[mid-1]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
    }

    return -1;
}

int main() {

    vector<int> arr = {10, 12, 15, 25, 2, 5};

    cout<<searchInRotatedSortedArray(arr, 25)<<endl;

    return 0;
}