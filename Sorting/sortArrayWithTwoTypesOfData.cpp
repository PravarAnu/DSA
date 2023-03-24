#include <iostream>
#include <vector>
using namespace std;

void sortVariationOne(vector<int> &arr){
    int i = 0;

    for(int j=0; j<arr.size(); j++){
        if(arr[j] == 0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

void sortVariationTwo(vector<int> &arr){
    int i = 0;

    for(int j=0; j<arr.size(); j++){
        if(arr[j] < 0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

void sortVariationThree(vector<int> &arr){
    int i = 0;

    for(int j=0; j<arr.size(); j++){
        if(arr[j] % 2 ==  0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

void print(vector<int> arr){
    for(auto i:arr){
        cout<< i<<" ";
    }

    cout<<endl;
}

int main() {
    //variation 1 - array with values 0 and 1 only
    vector<int> arr = {0,0,0,0,1,0,1,1};
    sortVariationOne(arr);
    print(arr);

    // variation 2 - array with values positive and negative
    vector<int> arr1 = {-10, 15,12, -2, 5, -50};
    sortVariationTwo(arr1);
    print(arr1);


    // variation 3 - array with values even and odd
    vector<int> arr2 = {10, 15,12, 2, 5, 3};
    sortVariationThree(arr2);
    print(arr2);

    return 0;
}