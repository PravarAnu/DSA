#include<iostream>
#include<vector>
using namespace std;

void findUnion(int a[], int n, int b[], int m);
bool foundIt(vector<int> &v, int n);

int main(){
    int a[5] = {1,2,3,4,5};
    int b[5] = {3,4,5,6,7};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    findUnion(a,n,b,m);

    return 0;
}

void findUnion(int a[], int n, int b[], int m){
    vector<int> v;
    v.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(!foundIt(v,a[i])){
            v.push_back(a[i]);
        }
    }
    for(int j=0;j<m;j++){
        if(!foundIt(v,b[j])){
            v.push_back(b[j]);
        }
    }

    for(int k=0; k<v.size(); k++){
        cout<<v[k]<<" ";
    }
    cout<<endl;
}

bool foundIt(vector<int> &v, int n){
    for(int i=0; i<v.size(); i++){
        if(v[i]==n){
            return true;
        }
    }
    return false;
}