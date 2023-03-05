#include <climits>
#include <iostream>
using namespace std;

int kadane(int arr[], int size);

int main() {
    int a[] = {4, -4, 6, -6, 10, -11, 12};
    int n = sizeof(a) / sizeof(a[0]);
    int wrapsum;
    int totalsum = 0;
    for (int i = 0; i < n; i++) {
        totalsum += a[i];
        a[i] = -a[i];
    }
    wrapsum = totalsum + kadane(a, n);
    cout << wrapsum;

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