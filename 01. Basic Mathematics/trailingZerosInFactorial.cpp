#include <cmath>
#include <iostream>
using namespace std;

int trailingZerosInFactorial(int n) {

    int count = 0;
    for (int i = 5; i <= n; i = i * 5) {
        count += n / i;
    }

    return count;
}

int main() {

    cout << trailingZerosInFactorial(25);

    return 0;
}