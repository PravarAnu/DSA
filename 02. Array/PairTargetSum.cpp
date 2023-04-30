#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 3, 4, 5, 8, 9, 10, 11, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 15;
    int low = 0;
    int high = n - 1;
    while (low != high) {
        if (a[low] + a[high] == k) {
            cout << a[low] << " + " << a[high] << " = " << k << endl;
            break;
        }

        else if (a[low] + a[high] > k) {
            high--;
        } else {
            low++;
        }
    }
}