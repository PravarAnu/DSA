#include <iostream>
using namespace std;

template <typename T>
T arrMax(T arr[], int size){
    T maximum = arr[0];

    for(int i=1; i<size; i++){
        if(arr[i] > maximum){
            maximum = arr[i];
        }
    }
    return maximum;
}

int main() {

    int iarr[] = {20, 10, 34, 12, 65, 25};
    float farr[] = {20.22, 10.3, 25.34, 34.2, 12.56, 65.90};
    char carr[] = {'c', 'b', 'd', 'w', 'a', 'z',};

    cout<<arrMax<int>(iarr, 6)<<endl;
    cout<<arrMax<float>(farr,6)<<endl;
    cout<<arrMax<char>(carr, 6)<<endl;

    return 0;
}