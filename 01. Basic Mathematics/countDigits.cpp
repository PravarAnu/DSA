#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int n){
    if(n<=0){
        return -1;
    }

    return log10(n)+1;
}

int main() {

    cout<<countDigits(0);

    return 0;
}