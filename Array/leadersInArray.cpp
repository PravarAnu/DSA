#include <iostream>
#include <vector>
using namespace std;

void findLeaders(vector<int> arr){
    int maxVal = arr[arr.size()-1];
    cout<<maxVal<<" ";

    for(int i = arr.size()-2; i>=0; i--){
        if(arr[i] > maxVal){
            cout<<arr[i]<<" ";
            maxVal = arr[i];
        }
    }
}


int main() {

    vector<int> arr = {7,10,4,3,6,5,2};

    findLeaders(arr);

    return 0;
}