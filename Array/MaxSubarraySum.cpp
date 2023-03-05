/*********************************************************  KADANE'S ALGORITHM
 * ****************************************************************/

#include <climits>
#include <iostream>
using namespace std;

int kadane(int arr[], int size);

int main() {

    int a[] = {-2, 3, 4, -5, 6};
    int size = sizeof(a) / sizeof(a[0]);
    cout << kadane(a, size);

    return 0;
}

int kadane(int arr[], int size) {
    int max_sum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
        if (sum > max_sum) {
            max_sum = sum;
        }
        if (sum < 0)
            sum = 0;
    }
    return max_sum;
}