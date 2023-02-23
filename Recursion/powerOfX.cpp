#include <iostream>

using namespace std;
typedef long long ll;

ll powerNaive(ll x, ll n){
    if(n==0){
        return 1;
    }

    ll pro = x * powerNaive(x,n-1);

    return pro;
}

ll powerEfficient(ll x, ll n){
    if(n==0){
        return 1;
    }

    if(n==1){
        return x;
    }

    ll small = powerEfficient(x, n/2);

    if(n%2 == 0){
        return small * small;
    }else{
        return small * small * x;
    }
}

ll powerByBinaryExponentiation(ll x, ll n){

    ll res = 1;

    while( n > 0){
        if(n%2 != 0){
            res *= x;
        }
        x *= x;
        n = n/2;
    }

    return res;
}

int main() {
    ll x = 3;
    ll n = 10;

    cout<<powerNaive(x,n)<<endl;

    cout<<powerEfficient(x,n)<<endl;

    cout<<powerByBinaryExponentiation(x,n)<<endl;

    return 0;
}