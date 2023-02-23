#include <iostream>
using namespace std;

void divisorsNaive(int n) {

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void divisorsEfficient(int n) {
    int i;
    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";

            // if(i != n/i){
            //     cout<<n/i<<" ";
            // }
        }
    }

    // Just for getting the factors in ascending order. If not necessary comment
    // this and uncomment above code
    for (; i >= 1; i--) {
        if (n % i == 0 && i != n / i) {
            cout << n / i << " ";
        }
    }

    cout << endl;
}

int main() {

    divisorsNaive(25);
    divisorsEfficient(25);

    return 0;
}