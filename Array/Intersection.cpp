#include<iostream>
#include<vector>
using namespace std;

void findIntersection(int a[], int n, int b[], int m);

int main(){
    int a[] = {1,2,3,4,5};
    int b[] = {3,4,5,6,7};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    findIntersection(a,n,b,m);
}

void findIntersection(int a[], int n, int b[], int m){
    vector<int> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                v.push_back(a[i]);
            }
        }
    }

    for(int k=0; k<v.size(); k++){
        cout<<v[k]<<" ";
    }
}




int main(){
    int n,m;
    cin>>n>>m;
    int arr[100][100];
    
    int big  = m;
    if(n>m){
        big = n;
    }

    for(int i=0;i<big;i++){
        for(int j=0;j<big;j++){
            arr[i][j] = 1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<big;i++){
        for(int j=0;j<big<j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}