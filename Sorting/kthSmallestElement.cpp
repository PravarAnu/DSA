#include <iostream>
#include <vector>
using namespace std;

//lomuto partition
int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low;

    for(int j = low; j<high; j++){
        if(arr[j] <= pivot){
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

int kthSmallest(vector<int> arr, int k){
    int low = 0;
    int high = arr.size()-1;

    while(low<=high){
        int p = partition(arr, low, high);

        if(p==k-1){
            return arr[p];
        }
        else if(p > k-1){
            high = p-1;
        }
        else{
            low = p;
        }
    }

    return -1;
}

int main() {

    vector<int> arr = {0,1,2,3,4,5,6,7,8,9};
    
    cout<<kthSmallest(arr, 5);
    


    return 0;
}