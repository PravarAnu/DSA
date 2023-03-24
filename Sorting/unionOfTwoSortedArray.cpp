#include <iostream>
#include <vector>
using namespace std;

void unionOFSortedArr(vector<int> arr1, vector<int> arr2){
    int i = 0; 
    int j = 0;

    while(i<arr1.size() && j<arr2.size()){
        if(i>0){
            if(arr1[i] == arr1[i-1]){
                i++;
                continue;
            }
            if(arr2[j] == arr2[j-1]){
                j++;
                continue;
            }
        }

        if(arr1[i] == arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }else if(arr1[i] > arr2[j]){
            cout<<arr2[j]<<" ";
            j++;
        }else{
            cout<<arr1[i]<<" ";
            i++;
        }
    }

    while(i<arr1.size()){
        if(arr1[i]!= arr1[i-1]){
            cout<<arr1[i]<<" ";
        }

        i++;
    }

    
    while(j<arr2.size()){
        if(arr2[j]!= arr2[j-1]){
            cout<<arr2[j]<<" ";
        }

        j++;
    }
}

int main() {

    vector<int> arr1 = {2,10,20,20};
    vector<int> arr2 = {3,20,40};


    unionOFSortedArr(arr1,arr2);

    return 0;
}