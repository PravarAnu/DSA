#include <iostream>
#include <vector>
using namespace std;

void cycleSort(vector<int> &arr){
    int n = arr.size();
    int i = 0;

    int totalSwap = 0;
    while(i<n){
        int num = arr[i];

        int countMin = 0;
        for(int j=0; j<n; j++){
            if(arr[j] < num){
                countMin++;
            }
        }

        if(i == countMin){
            i++;
        }else{
            swap(arr[i], arr[countMin]);
            totalSwap++;
        }
    }

    cout<<totalSwap<<endl;
}

int main() {

    vector<int> arr = {40,20,30};

    cycleSort(arr);

    for(auto i:arr){
        cout<<i<<" ";
    }

    return 0;
}