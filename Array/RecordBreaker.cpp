#include<iostream>
using namespace std;

int main(){
    int a[] = {4, 8, 15, 16, 23, 42};
    int n = sizeof(a)/sizeof(a[0]);
    int mx = 0;
    int ans = 0;

    for(int i=0;i<n;i++){
        int cond = 0;
        if(i==0 || i==n-1){
            cond++;
            if(i==0 && (a[0]>a[1]) ){
                mx = a[i];
                cond++;
            } 
            if(i==n-1 && (a[n-1]>mx) ){
                mx = a[n-1];
                cond++;
            }
        }
        if(i>0 && i<n-1){
            if(a[i]>mx){
                mx=a[i];
                cond++;
            }
            if(a[i]>a[i+1]){
                cond++;
            }
        }
        if(cond == 2){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}