#include <climits>
#include <iostream>
using namespace std;

int kadane(int arr[], int size);
int naiveApproach(int a[], int size);
int efficientApproach(int a[], int size);

int main() {
    int a[] = {5,-3,5};
    int n = sizeof(a) / sizeof(a[0]);

    cout << naiveApproach(a, n) << endl;

    cout << efficientApproach(a,n)<<endl;

    return 0;
}

int naiveApproach(int arr[], int size) {
    int res = arr[0];

    for (int i = 0; i < size; i++) {
        int currMax = arr[i];
        int currSum = arr[i];

        for (int j = 1; j < size; j++) {
            currSum += arr[(i + j) % size];
            currMax = max(currMax, currSum);
        }

        res = max(res, currMax);
    }

    return res;
}


int efficientApproach(int a[], int size){
    int maxSum = kadane(a,size);

    if(maxSum<0){
        return maxSum;
    }

    int totalSum = 0;
    for(int i=0; i<size; i++){
        totalSum += a[i];

        a[i] = -a[i];
    }

    int circularSum = totalSum + kadane(a,size);

    return max(maxSum, circularSum);
}

int kadane(int arr[], int size) {
    int max_sum = arr[0];
    int sum = arr[0];
    for (int i = 1; i < size; i++) {
        sum = max(arr[i], arr[i]+sum);
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}