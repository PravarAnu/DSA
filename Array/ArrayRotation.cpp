#include <iostream>
using namespace std;

/*
    1st Approach

    // time complexity: O(n * d) auxilary space: O(1)
    n - size of arr
    d - number of rotation
*/
void leftRotation(int a[], int size) {
    int temp = a[0];
    for (int i = 0; i < size - 1; i++) {
        a[i] = a[i + 1];
    }
    a[size - 1] = temp;
}

void arrRotation(int a[], int size, int rotation) {
    if (rotation <= size) {
        for (int i = 0; i < rotation; i++) {
            leftRotation(a, size);
        }
    }
}

/*
    2nd Approach

    time complexity : O(n); space complexity: O(1)
 */
void reverse(int a[], int start, int end) {
    while (start < end) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;

        start++;
        end--;
    }
}

void leftRotationByReversing(int a[], int size, int d) {
    reverse(a, 0, d - 1);
    reverse(a, d, size - 1);
    reverse(a, 0, size - 1);
}

void printArr(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int r = 2;

    // cout<<"Before Rotation: ";
    // printArr(a,n);
    // arrRotation(a,n,r);
    // cout<<"After Rotation: ";
    // printArr(a,n);

    cout << "Before Rotation: ";
    printArr(a, n);
    leftRotationByReversing(a, n, r);
    cout << "After Rotation: ";
    printArr(a, n);
}
