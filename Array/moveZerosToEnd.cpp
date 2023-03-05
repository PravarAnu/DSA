#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void moveZerosToEnd(vector<int> &arr) {
    int i = 0;
    int j = 1;

    while (j < arr.size()) {
        if (arr[i] == 0) {
            if (arr[j] != 0) {
                arr[i] = arr[j];
                arr[j] = 0;
            } else {
                j++;
            }
        } else {
            i++;
            j++;
        }
    }
}

void moveZerosToEndEfficient(vector<int> &arr) {
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

int main() {

    vector<int> arr = {0, 1, 2, 3, 1, 0, 2, 0, 1, 0, 0};

    moveZerosToEndEfficient(arr);

    for (auto i : arr) {
        cout << i << " ";
    }
    return 0;
}