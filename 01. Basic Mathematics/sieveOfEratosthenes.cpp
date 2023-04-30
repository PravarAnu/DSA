#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n) {
    int count = 0;
    vector<bool> ans(n + 1, 1);

    if (n == 0 || n == 1) {
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (ans[i] == 1) {
            cout << i << " ";
            count++;
            for (int j = i * i; j <= n; j += i) {
                ans[j] = 0;
            }
        }
    }

    cout << endl;
    cout << "Total number of prime numbers between 0 to " << n
         << " is: " << count << endl;
}

int main() {

    sieveOfEratosthenes(11);

    return 0;
}