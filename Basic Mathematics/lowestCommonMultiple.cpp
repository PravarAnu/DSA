#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }

    return gcd(b, a%b);
}

int lcm(int a, int b){
    int mul = a*b;
    int hcf = gcd(a,b);
    
    
    return mul/hcf;
}


int main() {

    cout<<lcm(12,18);

    return 0;
}