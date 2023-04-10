/*
        -----------------------------------------------------Binary
   Search-------------------------------------------------------------
                               (**Binary search only used when the list of
   numbers are already sorted**)

        Algorithm:
                [array, size, key, low, mid, high]
                array -> list of numbers from which we are going to find the
   location size -> length of array key -> number which have to be find low ->
   first index of given array high -> last index of given array mid -> middle
   index of the given array

                function binary_search(Array, size, key) is
                        low := 0
                        high := size
                        while low <= high do
                        mid := (L + R) / 2
                        if Array[mid] < T then
                        low := mid + 1
                        else if A[m] > T then
                        high := mid - 1
                        else:
                        return mid
                return -1

        Time Complexity:
                Worst-case performance	O(log size)
                Best-case performance	O(1)
                Average performance		O(log size)
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int low, mid, high;
    low = 0;
    high = size;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid + 1;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6, 8, 10, 11, 12, 13};
    int size, key;
    size = sizeof(arr) / sizeof(arr[0]);
    cin >> key;
    int pos = binarySearch(arr, size, key);

    if (pos == -1) {
        cout << "Not found";
    } else {
        cout << "Found At: " << pos << " position";
    }

    return 0;
}