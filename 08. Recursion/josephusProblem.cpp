#include <iostream>
#include <vector>
using namespace std;


void solve(vector<int> v, int k, int index, int &ans);


int josephusProblem(int n, int k){
    vector<int> v(n);
    int index = 0;
    int ans = -1;

    for(int i=0; i<n; i++){
        v[i] = i+1;
    }

    solve(v, k-1, index, ans);

    return ans;
}

void solve(vector<int> v, int k, int index, int &ans){
    if(v.size() == 1){
        ans = v[0];
        return;
    }

    index = (index + k)%v.size();
    v.erase(v.begin()+index);

    solve(v, k, index, ans);
}

int main() {

    int n,k;
    // cin>>n>>k;
    n = 3;
    k = 2;

    cout<< josephusProblem(n,k);

    return 0;
}