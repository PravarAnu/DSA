#include<iostream>
using namespace std;

int main(){
    int a[] = {0,-9,1,3,-4,5};
    int n = sizeof(a)/sizeof(a[0]);
    int max = a[0];
    cout<<max<<endl;
    for(int i=1;i<n;i++){
        if(max<a[i]) max = a[i];
        cout<<max<<endl;
    }
}