#include <iostream>
using namespace std;

/*
    Here we are using AND operator for finding the given number is odd or even.
    We have to & the number with 1 because in 1 only the LSB(Least Significant
   Bit) is set and in every odd numbers the LSB is always set.
*/

bool isEven(int n) {
    // Check for LSB is set or not
    //  If set then return false.
    //  Otherwise return true.
    if (n & 1 == 1) {
        return false;
    } else {
        return true;
    }
}

int main() {

    int n;
    cin >> n;

    cout << isEven(n) << endl;

    return 0;
}