#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n ==0 || n==1){
        return false;
    }

    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

vector<int> primeFactorsNaive(int n){
    vector<int> ans;

    for(int i=2; i<n; i++){
        if(isPrime(i)){
            
            int x = i;
            while(n%x == 0){
                ans.push_back(i);
                x = x*i;
            }

        }
    }

    return ans;
}


vector<int> primeFactorsEfficient(int n){
    vector<int> ans;

    if(n<=1){
        return ans;
    }

    for(int i=2; i*i<=n; i++){
        while(n%i==0){
            ans.push_back(i);

            n = n/i;
        }
    }

    if(n>1){
        ans.push_back(n);
    }

    return ans;
}

int main() {

    auto ans = primeFactorsEfficient(450);

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}